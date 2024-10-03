package ar.uba.fi.cb100.semana05.jueves.tarea.timebomb;

public class Canal {
	
	// Atributos de clase ------------------------------------------------------------------------------
	private int numeroCanal=0;
	private int volumenMaximo=0;
	private int volumenActual=0;

	// Constructores -----------------------------------------------------------------------------------
	public Canal(int numeroCanal) throws Exception {
		if (!Tools.checkPositiveStrict(numeroCanal)) {
			throw new Exception("Numero de canal invalido.");
		}
		this.numeroCanal = numeroCanal;
	}
	
	// Metodos --------------------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @return El valor entero del volumen actual del canal
	 */
	public int getVolumenActual() {
		return volumenActual;
	}

	/**
	 * pre : - 
	 * post: Actualiza el volumen actual del canal. Si es el volumen máximo, también lo actualiza.
	 * @param volumenActual, entero que represente el volumen del canal
	 * @throws Exception si el volumen es invalido (mayor a 100 o menor a 0)
	 */
	public void setVolumenActual(int volumenActual) throws Exception {
		if (!Tools.checkPositive(volumenActual) || volumenActual > 100) {
			throw new Exception("Volumen debe estar entre 0 y 100.");
		}
		changeVolumen(volumenActual);
	}

	/**
	 * pre: - 
	 * @return Devuelve el numero del canal actual
	 */
	public int getNumeroCanal() {
		return numeroCanal;
	}

	/**
	 * pre: -
	 * @return Devuelve el volumen maximo registrado en este canal
	 */
	public int getVolumenMaximo() {
		return volumenMaximo;
	}
	
	/**
	 * pre: - 
	 * post: Actualiza el volumen del canal y si es mayor al mayore registrado, tambien lo actualiza
	 * @param volumen, entero que represente el volumen
	 */
	public void changeVolumen(int volumen) {
		if (volumen > this.volumenMaximo) {
			this.volumenMaximo = volumen;
		}
		this.volumenActual = volumen;
	}
}