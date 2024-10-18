package ar.uba.fi.cb100.semana09.jueves.consultas.tomas;

/**
 * checklist:
 * 1) pre y post
 * 2) validar
 * 3) chequear get y sets
 * 4) chequear si esta el conjunto completo de operaciones 
 * 
 * 
 */
public class Colecta {
	//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private double montoObjetivo = 0;									
	private double montoDeDonacionMaximo = 0;
	private int cantidadDeDonaciones = 0;
	private double montoMaximoDonado = 0;
	private double montoRecaudado = 0;
	
	//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * post: creo una colecta con un objetivo y una donacion maxima permitida
	 * @param montoObjetivo: objetivo del monto de la colecta
	 * @param montoMaximaDonacionIndividual: maxima donacion individual permitida
	 * @throws Exception: valida que el monto y la maxima donacion permitida sean mayores a 0 
	 */
	public Colecta(double montoObjetivo, double montoDeDonacionMaximo) throws Exception {
		if (montoObjetivo <= 0) {
			throw new Exception("El objetivo de la colecta debe ser mayor a 0");
		}
		if (montoDeDonacionMaximo <= 0) {
			throw new Exception("La maxima donacion individual debe ser mayor a 0");
		}
		this.montoObjetivo = montoObjetivo;
		this.montoDeDonacionMaximo = montoDeDonacionMaximo;
	}
	
	//METODOS DE CLASE ----------------------------------------------------------------------------------------
	//METODOS GENERALES ---------------------------------------------------------------------------------------
	//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * post: dona un monto a la colecta
	 * @param montoADonar: monto que se donara
	 * @throws Exception: valida que el monto seas mayor a 0 y menor o igual a la maxima donacion individual
	 */
	public void donar(double montoADonar) throws Exception {
		if (montoADonar <= 0 ||
			montoADonar > this.montoDeDonacionMaximo) {
			throw new Exception("El monto a donar debe ser mayor a 0 y menor o igual a " + this.montoDeDonacionMaximo);
		}
		if (montoADonar > this.montoMaximoDonado) {
			this.montoMaximoDonado = montoADonar;
		}
		this.montoRecaudado += montoADonar;
		this.cantidadDeDonaciones += 1;
	}
	
	/**
	 * pre: se realizo una donacion
	 * @return: devuelve la cantidad de donaciones realizadas
	 */
	public int contarDonaciones() {
		return this.cantidadDeDonaciones;
	}
	
	/**
	 * pre: se realizo una donacion
	 * @return: devuelve la donacion maxima realizada
	 */
	public double calcularDonacionMaxima() {
		return this.montoMaximoDonado;
	}
	
	/**
	 * pre: -
	 * @return: devuelve la monto que falta recaudar
	 */
	public double calcularRecaudacionFaltante() {
		if (objetivoAlcanzado()) {
			return 0.0;
		}
		return this.montoObjetivo - this.montoRecaudado;
	}
				
	/**
	 * pre: -
	 * @return: devuelve la cantidad de recaudacion de la colecta
	 */
	public double calcularRecaudacion() {
		return this.montoRecaudado;
	}

	/**
	 * pre: -
	 * @return devuelve verdadero si se alconzo el monto objetivo
	 */
	public boolean objetivoAlcanzado() {
		return this.montoObjetivo <= this.montoRecaudado;
	}
	
	//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @return: devuelve el monto objetivo
	 */
	public double getMontoObjetivo() {
		return this.montoObjetivo;
	}
	
	public double getMontoDeDonacionMaximo() {
		return this.montoDeDonacionMaximo;
	}
	//SETTERS SIMPLES -----------------------------------------------------------------------------------------
}
