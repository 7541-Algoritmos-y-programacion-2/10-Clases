package ar.uba.fi.cb100.semana05.jueves.tarea.timebomb;

public class Tools {
	
	/**
	 * pre: -
	 * post: Devuelve un booleano (true) indicando si es positivo o 0 el valor dado como dato
	 * @param value, valor entero
	 * @return booleano true or false
	 */
	public static boolean checkPositive(int value) {
		return value >= 0;
	}
	
	/**
	 * pre: -
	 * post: Devuelve un booleano (true) indicando si el valor dado como parametro es positivo estricto
	 * @param value, un valor entero
	 * @return booleano true or false
	 */
	public static boolean checkPositiveStrict(int value) {
		return value > 0;
	}
}
