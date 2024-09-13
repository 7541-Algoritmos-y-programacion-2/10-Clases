package ar.uba.fi.cb100.semana04.jueves;

public class Validador {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
//CONSTRUCTORES -------------------------------------------------------------------------------------------
//METODOS DE CLASE ----------------------------------------------------------------------------------------
	
	/**
	 * pre
	 * @param texto: cualquier texto
	 * @param longitudMinima: mayor o igual a 0
	 * @return devuelve verdadero si el texto no es nulo y tiene mas caracteres que longitud minima, o falso
	 *         en caso contrario
	 */
	public static boolean tieneLongitudMinima(String texto, int longitudMinima) {
		if (texto == null) {
			return false;
		}
		return texto.length() >= longitudMinima;
	}
	
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
}
