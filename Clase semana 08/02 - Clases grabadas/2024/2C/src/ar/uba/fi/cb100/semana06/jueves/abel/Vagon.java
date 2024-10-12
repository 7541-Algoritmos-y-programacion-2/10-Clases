package ar.uba.fi.cb100.semana06.jueves.abel;

public class Vagon {
	//TODO: pre y post de metodos
	
	//Atributos ----------------------------------------------------------------------
	public final double CARGAMAXIMA=1000.0;
	
	//Atributos de clase --------------------------------------------------------------
	private double cargaActual=0.0;
	
	//Constructor ---------------------------------------------------------------------
	public Vagon(double cargaInicial) throws Exception {
		if(!Validaciones.esPositivo(cargaInicial) ||
				cargaInicial>CARGAMAXIMA) {
			throw new Exception("La carga debe estar en el intervalo 0 - "+CARGAMAXIMA+" KG");
		}
		this.cargaActual=cargaInicial;
	}
	
	//Getters -------------------------------------------------------------------------
	
	public double getCargaActual() {
		return this.cargaActual;
	}
	
	public double getCargaMaxima() {
		return this.CARGAMAXIMA;
	}
	
	//Metodos --------------------------------------------------------------------------
	
	public void agregarCarga(double carga) throws Exception {
		if(!Validaciones.esNatural(carga) ||
				carga>this.CARGAMAXIMA) {
			throw new Exception("La carga debe estar en el rango 1 a "+this.CARGAMAXIMA +" KG");
		}
		if(this.cargaActual+carga>this.CARGAMAXIMA) {
			throw new Exception("El vagon no puede recibir mas carga sobrepasa los "+this.CARGAMAXIMA+" KG");
		}
		this.cargaActual+=carga;
	}
	
	public void eliminarCarga(double carga) throws Exception {
		if(!Validaciones.esNatural(carga)) {
			throw new Exception("La carga debe ser positiva");
		}
		if(this.cargaActual-carga<0) {
			throw new Exception("La carga a eliminar supera la capacidad del vagon");
		}
		this.cargaActual-=carga;
	}
	
	public void vaciarVagon() {
		this.cargaActual=0.0;
	}
	
}
