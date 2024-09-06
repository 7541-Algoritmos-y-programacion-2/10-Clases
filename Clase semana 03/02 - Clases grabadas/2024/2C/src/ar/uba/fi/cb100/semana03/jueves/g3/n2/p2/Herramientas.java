package ar.uba.fi.cb100.semana03.jueves.g3.n2.p2;

public class Herramientas {

	/**
	 * pre: -
	 * @param texto: cualquier valor
	 * @return devuelve verdadero si texto es nulo o vacio o son espacios
	 */
	public static boolean estaVacio(String texto) {
		return ((texto == null) || 
				(texto.trim().isEmpty()));
	}
	
	public static boolean esPositivo(int valor) {
		return valor > 0;
	}
}
