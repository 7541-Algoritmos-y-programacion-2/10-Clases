package ar.uba.fi.cb100.semana05.jueves;

public class Ascensor {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private int pisoActual = 0;
	private int[] contadorDeParadas = null;
	private int cantidadDePisosQueSubio = 0;
	private int cantidadDePisosQueBajo = 0;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * pre: 
	 * @param cantidadDePisos: ingresa la cantidad, debe ser 1 o mayor
	 * pos: crea un ascensor con la cantidad de pisos solicitada, 
	 * 		añadiendo la PB. El ascensor se inicia en PB. No hay subsuelos.
	 * @throws Exception 
	 */
	public Ascensor(int cantidadDePisosAdicionales) throws Exception {
		if (cantidadDePisosAdicionales < 1) {
			throw new Exception("La cantidad de pisos debe ser 1 o mayor");
		}
		this.contadorDeParadas = new int[cantidadDePisosAdicionales+1];
		for(int i = 0; i < this.contadorDeParadas.length; i++) {
			this.contadorDeParadas[i] = 0;	
		}
	}
	
//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	/**
	 * pre: 
	 * @param pisoDestino: debe estar entre PB (0) y el ultimo piso
	 * @return devuelve la cantidad de pisos que se movio, o excepcion en caso
	 *         contrario
	 * @throws Exception: si el piso no esta en el rango 
	 */
	public int enviarA(int pisoDestino) throws Exception {
		if ((pisoDestino < 0) ||
		    (pisoDestino > this.getCantidadDePisosEnAltura())) {
			throw new Exception("El piso destino debe estar entre 0 y " + this.getCantidadDePisosEnAltura()); 
		}
		if (this.pisoActual == pisoDestino) {
			return 0;
		}
		int resultado = this.pisoActual - pisoDestino;
		if (resultado > 0) {
			this.cantidadDePisosQueBajo += Math.abs(resultado);
		} else {
			this.cantidadDePisosQueSubio += Math.abs(resultado);
		}
		this.pisoActual = pisoDestino;
		return Math.abs(resultado);
	}
	
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @return devuelve la cantidad de pisos que el ascensor recorre, 
	 * 			incluyendo la PB
	 */
	public int getCantidadDePisos() {
		return this.contadorDeParadas.length;
	}

	/**
	 * pre: -
	 * @return devuelve la cantidad de pisos sin contar la PB
	 */
	public int getCantidadDePisosEnAltura() {
		return this.contadorDeParadas.length - 1;
	}
	
	/**
	 * pre: -
	 * @return devuelve el piso actual donde esta el ascensor
	 */
	public int getPisoActual() {
		return pisoActual;
	}

	/**
	 * pre: - 
	 * @return devuelve la cantidad de pisos que subio de manera acumulada
	 */
	public int getCantidadDePisosQueSubio() {
		return cantidadDePisosQueSubio;
	}

	/**
	 * pre: - 
	 * @return devuelve la cantidad de pisos que bajo de manera acumulada
	 */
	public int getCantidadDePisosQueBajo() {
		return cantidadDePisosQueBajo;
	}
	
	
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	

}
