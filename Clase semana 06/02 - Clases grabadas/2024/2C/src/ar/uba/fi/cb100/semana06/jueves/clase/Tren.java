package ar.uba.fi.cb100.semana06.jueves.clase;

public class Tren {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	
	private static final int CANTIDAD_MAXIMA_DE_LOCOMOTORAS = 3;
	private static final int CANTIDAD_MAXIMA_DE_VAGONES_POR_LOCOMOTORA = 10;
	
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private int cantidadDeLocomotoras = 0;
	private Vagon[] vagones = null;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @throws Exception
	 * post: deja creado un tren con 1 locomotora y ningun vagon
	 */
	public Tren() throws Exception {
		this(1);
	}
	
	/**
	 * pre: 
	 * @param cantidadDeLocomotoras: debe estar entre 1 y 3 inclusive
	 * @throws Exception da error si la cantidad no esta en rango
	 * post: deja creado un tren con cantidadDeLocomotoras y ningun vagon
	 */
	public Tren(int cantidadDeLocomotoras) throws Exception {
		if ((cantidadDeLocomotoras < 1) ||
		    (cantidadDeLocomotoras > CANTIDAD_MAXIMA_DE_LOCOMOTORAS)) {
			throw new Exception("La cantidad de locomotoras debe ser entre 1 y " + CANTIDAD_MAXIMA_DE_LOCOMOTORAS);
		}
		this.cantidadDeLocomotoras = cantidadDeLocomotoras;
		this.vagones = new Vagon[getCantidadMaximaTeoricaDeVagones()];
		for(int i = 0; i < this.vagones.length; i++) {
			this.vagones[i] = null;
		}
	}
	
//METODOS DE CLASE ----------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @return: devuelve la cantidad de vagones maxima posible, suponiendo que se tienen las
	 *          3 locomotoras.
	 */
	private static int getCantidadMaximaTeoricaDeVagones() {
		return CANTIDAD_MAXIMA_DE_LOCOMOTORAS * CANTIDAD_MAXIMA_DE_VAGONES_POR_LOCOMOTORA;
	}
	
	public static int getCantidadMaximaDeLocomotorasPorTren() {
		return CANTIDAD_MAXIMA_DE_LOCOMOTORAS;
	}
	
//METODOS GENERALES ---------------------------------------------------------------------------------------
	
	@Override
	public String toString() {
		return "Tren de " + this.cantidadDeLocomotoras + " locomotoras y " + this.getCantidadDeVagones() + " vagones";
	}
	
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------

	/**
	 * pre: -
	 * @throws Exception da error si la cantidad de locomotoras no esta entre 1 y CANTIDAD_MAXIMA_DE_LOCOMOTORAS
	 * @return: devuelve la cantidad de locomotoras actuales
	 * post: agrega una locomotora al tren
	 */
	public int agregarLocomotora() throws Exception {
		if (this.cantidadDeLocomotoras >= CANTIDAD_MAXIMA_DE_LOCOMOTORAS) {
			throw new Exception("No se pueden agregar mas locomotoras");
		}
		this.cantidadDeLocomotoras++;
		return this.cantidadDeLocomotoras;
	}
	
	/**
	 * pre: -
	 * @throws Exception da error si la cantidad de locomotoras no esta entre 1 y CANTIDAD_MAXIMA_DE_LOCOMOTORAS
	 * @return: devuelve la cantidad de locomotoras actuales
	 * post: quita una locomotora del tren
	 */
	public int quitarLocomotora() throws Exception {
		if (this.cantidadDeLocomotoras <= 1) {
			throw new Exception("No se pueden quitar mas locomotoras");
		}
		if (getCantidadDeVagones() > (this.cantidadDeLocomotoras-1) * CANTIDAD_MAXIMA_DE_VAGONES_POR_LOCOMOTORA) {
			throw new Exception("No se pueden quitar mas locomotoras hasta no quitar vagones");
		}
		this.cantidadDeLocomotoras--;
		return this.cantidadDeLocomotoras;
	}

	/**
	 * pre: 
	 * @param vagones: son los vagones a agregar, no pueden ser nulos y deben estar sin carga
	 * @throws Exception: da error si los vagones son nulos, estan con carga o son mas de los
	 *         que puede aceptar el tren
	 * post: agregar los vagones al tren
	 */
	public void agregarVagon(Vagon... vagones) throws Exception {
		if (vagones == null) {
			throw new Exception("Los vagones no pueden ser nulos");
		}
		if (this.getCantidadDeVagonesFaltantes() < vagones.length) {
			throw new Exception("El tren no acepta " + vagones.length + " vagones. El maximo es " + this.getCantidadDeVagonesFaltantes());
		}
		for(Vagon vagon: vagones) {
			if (vagon == null) {
				throw new Exception("El vagon no puede ser nulo");
			}
			if (!vagon.estaVacio()) {
				throw new Exception("No se pueden agregar vagones con carga");
			}
			this.vagones[ this.getCantidadDeVagones()] = vagon;
		}		
	}
	
	/**
	 * pre: -
	 * @throws Exception
	 * post: quita el ultimo vagon
	 */
	public Vagon quitarVagon() throws Exception {
		if (getCantidadDeVagones() <= 1) {
			throw new Exception("El tren no tiene mas vagones para quitar");
		}
		if (!this.vagones[this.getCantidadDeVagones() -1].estaVacio()) {
			throw new Exception("No se puede quitar un vagon con carga");
		}
		Vagon resultado = this.vagones[this.getCantidadDeVagones() -1];
		this.vagones[this.getCantidadDeVagones() -1] = null;
		return resultado;
	}
	
	/**
	 * pre: 
	 * @param carga: debe ser mayor a 0
	 * @throws Exception: da error si la carga supera la capicidad
	 * post: reparte la carga en los vagones que tiene disponible
	 */
	public void agregarCarga(double carga) throws Exception {
		if (this.getCapacidadDeCargaRestante() < carga) {
			throw new Exception("El tren tiene disponible como maximo: " + this.getCapacidadDeCargaRestante());
		}
		for(Vagon vagon: this.vagones) {
			if (vagon != null) {
				double cargaRestante = vagon.getCapacidadDeCargaRestante();
				if (cargaRestante > carga) {
					vagon.agregarCarga(carga);
					return;
				}
				vagon.agregarCarga(cargaRestante);
				carga -= cargaRestante;
			}
		}
	}
	
	/**
	 * pre: 
	 * @param cargaAEliminar: debe ser mayor a 0 y menor a lo disponible
	 * @throws Exception: da error si la carga a quitar no esta en rango
	 * post: descuenta la carga del ultimo vagon al primero
	 */
	public void quitarCarga(double cargaAQuitar) throws Exception {
		if (cargaAQuitar <= 0) {
			throw new Exception("La carga a eliminar debe ser positiva");
		}
		if (getCarga() < cargaAQuitar) {
			throw new Exception("El tren tiene como maximo " + getCarga() + " de carga");
		}
		for(int i = this.vagones.length-1; i >= 0; i--) {
			Vagon vagon = this.vagones[i];
			if (cargaAQuitar <= 0) {
				return;
			}
			if (vagon != null){
				double cargaActual = vagon.getCarga();
				if (cargaActual < cargaAQuitar) {
					vagon.vaciarVagon();
					cargaAQuitar -= cargaActual;
				} else {
					vagon.quitarCarga(cargaAQuitar);
					cargaAQuitar = 0;
				}
			}
		}
	}
	
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * post: devuelve la cantidad de vagones actuales
	 */
	public int getCantidadDeVagones() {
		int resultado = 0;
		for(int i = 0; i < this.vagones.length; i++) {
			if (this.vagones[i] != null) {
				resultado++;
			}
		}
		return resultado;
	}
	
	/**
	 * pre: -
	 * @return: devuelve la capacidad de vagones que faltan agregar para llegar al maximo
	 */
	public int getCantidadDeVagonesFaltantes() {
		return this.getCantidadMaximaDeVagones() - this.getCantidadDeVagones();
	}
	
	/**
	 * pre: -
	 * post: devuelve la cantidad de vagones maxima
	 */
	public int getCantidadMaximaDeVagones() {
		return this.cantidadDeLocomotoras * CANTIDAD_MAXIMA_DE_VAGONES_POR_LOCOMOTORA;
	}

	/**
	 * pre: -
	 * @return devuelve la carga del tren, la suma de la carga de los vagones
	 */
	public double getCarga() {
		double resultado = 0;
		for(Vagon vagon: this.vagones) {
			if (vagon != null) {
				resultado += vagon.getCarga();
			}
		}
		return resultado;
	}
	
	/**
	 * pre:
	 * @return devuelve la capacidad restante de carga posible a cargar
	 */
	public double getCapacidadDeCargaRestante() {
		double resultado = 0;
		for(Vagon vagon: this.vagones) {
			if (vagon != null) {
				resultado += vagon.getCapacidadDeCargaRestante();
			}
		}
		return resultado;
	}

	/**
	 * pre: -
	 * @return: devuelve la capacidad de carga maxima del vagon.
	 */
	public double getCapacidadDeCargaMaxima() {
		double resultado = 0;
		for(Vagon vagon: this.vagones) {
			if (vagon != null) {
				resultado += vagon.getCapacidadDeCargaMaxima();
			}
		}
		return resultado;
	}
	
	/**
	 * pre: -
	 * @return devuelve la cantidad de locomotoras
	 */
	public int getCantidadDeLocomotoras() {
		return this.cantidadDeLocomotoras;
	}
	
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	

}
