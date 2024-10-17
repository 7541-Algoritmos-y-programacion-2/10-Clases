package ar.uba.fi.cb100.semana06.jueves.clase;

public class Vagon {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private double carga = 0;
	private double capacidadDeCargaMaxima = 0;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @param capacidadDeCargaMaxima: debe ser mayor a 0
	 * @throws Exception
	 */
	public Vagon(double capacidadDeCargaMaxima) throws Exception {
		if (capacidadDeCargaMaxima <= 0) {
			throw new Exception("El vagón debe poder transportar carga");
		}
		this.capacidadDeCargaMaxima = capacidadDeCargaMaxima;
	}

//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	/**
	 * pre: 
	 * @param carga: la carga debe ser mayor a 0, y menor a la carga restante
	 * @throws Exception
	 */
	public void agregarCarga(double carga) throws Exception {
		if (carga > this.getCapacidadDeCargaRestante()) {
			throw new Exception("El vagón no puede cargar más carga de " + this.getCapacidadDeCargaRestante());
		}
		validarCarga(carga);
		this.carga += carga;
	}
	
	/**
	 * pre: 
	 * @param carga: la carga debe ser mayor a 0
	 * @throws Exception: da error si la carga supera la carga actual
	 */
	public void quitarCarga(double carga) throws Exception {
		if (this.carga < carga) {
			throw new Exception("No quites más de lo que el vagón tiene");
		}
		validarCarga(carga);
		this.carga -= carga;
	}	
	
	/**
	 * pre: 
	 * @param carga: -
	 * @throws Exception: valida que la carga no sea negativa
	 */
	private void validarCarga(double carga) throws Exception {
		if (carga < 0) {
			throw new Exception("La carga debe ser mayor a 0");
		}
	}
	
	/**
	 * pre: -
	 * @return devuelve verdadero si la carga es 0
	 */
	public boolean estaVacio() {
		return this.carga == 0;
	}
	
	/**
	 * pre: -
	 * post: vacia la carga del vagon
	 */
	public void vaciarVagon() {
		this.carga = 0.0;
	}
	
//GETTERS SIMPLES -----------------------------------------------------------------------------------------

	/**
	 * pre:
	 * @return devuelve la capacidad restante de carga posible a cargar
	 */
	public double getCapacidadDeCargaRestante() {
		return this.capacidadDeCargaMaxima - this.carga;
	}
	
	/**
	 * pre: -
	 * @return devuelve la carga actual del vagon
	 */
	public double getCarga() {
		return this.carga;
	}

	/**
	 * pre: -
	 * @return: devuelve la capacidad de carga maxima del vagon.
	 */
	public double getCapacidadDeCargaMaxima() {
		return capacidadDeCargaMaxima;
	}
	
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	

}
