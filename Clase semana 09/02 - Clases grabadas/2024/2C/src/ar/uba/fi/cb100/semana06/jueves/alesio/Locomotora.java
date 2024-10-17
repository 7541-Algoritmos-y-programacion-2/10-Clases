package ar.uba.fi.cb100.semana06.jueves.alesio;

public class Locomotora {
	private int MAXIMO_DE_VAGONES = 10;
	private Vagon prim = null;
	private Vagon ult = null;
	private int cantidadDeVagones = 0;

	public Locomotora() {
	}

	public void agregarVagon(Vagon vagon) throws Exception {
		if (vagon.getCapacidadActual() > 0) {
			throw new Exception("Solo los vagones vacíos se pueden añadir");
		}
		if (this.cantidadDeVagones >= MAXIMO_DE_VAGONES) {
			throw new Exception("No queda espacio para más vagones");
		}
		if (this.prim == this.ult) {
			if (this.prim == null) {
				this.prim = vagon;
				this.ult = vagon;
			} else {
				this.prim.setProximo(vagon);
				this.prim = vagon;
			}
		} else {
			this.prim.setProximo(vagon);
			this.prim = vagon;
		}
		this.cantidadDeVagones += 1;
	}

	public Vagon quitarVagon() throws Exception {
		if (this.prim == this.ult) {
			if (this.prim == null) {
				throw new Exception("No hay vagones");
			}
		}
		Vagon res = this.ult;
		if (res.getCapacidadActual() > 0) {
			throw new Exception("Solo los vagones vacíos se pueden quitar");
		}
		this.ult = this.ult.getProximo();
		if (this.ult == null) {
			this.prim = this.ult;
		}
		this.cantidadDeVagones -= 1;
		return res;
	}
	
	public void agregarCarga(int cargaInicial) throws Exception {
		int cargaActual = cargaInicial;
		Vagon act = this.ult;
		while (act != null) {
			try {
				act.sumarCarga(cargaActual);
				cargaActual = 0;
				break;
			} catch (Exception e) {
				int resto = act.getCapacidadRestante();
				cargaActual -= resto;
				act.sumarCarga(resto);
				act = act.getProximo();
				if (cargaActual == 0) {
					break;
				}
			}
		}
		if (cargaActual > 0) {
			throw new Exception("No hubo espacio en esta Locomotora");
		}
	}
	
	public void quitarCarga(int cargaInicial) throws Exception {
		int cargaActual = cargaInicial;
		Vagon act = this.ult;
		while (act != null) {
			try {
				act.restarCarga(cargaActual);
				cargaActual = 0;
				break;
			} catch (Exception e) {
				int sobra = act.getCapacidadActual();
				cargaActual -= sobra;
				act.restarCarga(sobra);
				act = act.getProximo();
				if (cargaActual == 0) {
					break;
				}
			}
		}
		if (cargaActual > 0) {
			throw new Exception("No se pudo descargar lo pedido");
		}
		
	}

	public int getCapacidadActual() {
		int res = 0;
		Vagon act = this.ult;
		while (act != null) {
			res += act.getCapacidadActual();
			act = act.getProximo();
		}
		return res;
	}

	public int getCapacidadMaxima() {
		int res = 0;
		Vagon act = this.ult;
		while (act != null) {
			res += act.getCapacidadMaxima();
			act = act.getProximo();
		}
		return res;
	}

	public int getCapacidadRestante() {
		int res = 0;
		Vagon act = this.ult;
		while (act != null) {
			res += act.getCapacidadRestante();
			act = act.getProximo();
		}
		return res;
	}
	
	public int getCantidadDeVagones() {
		return this.cantidadDeVagones;
	}
}
