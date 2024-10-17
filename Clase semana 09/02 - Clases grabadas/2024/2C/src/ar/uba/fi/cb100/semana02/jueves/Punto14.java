package ar.uba.fi.cb100.semana02.jueves;

public class Punto14 {

	public static String invertirCadena(String cadena) {
		String cadenaInvertida = "";
		
		for(int i = cadena.length(); i > 0; i--) {
			cadenaInvertida += cadena.charAt(i-1);
		}		
		return cadenaInvertida;
	}
	
	public static void ejecutar() {
		System.out.println("Ingrese la cadena a invertir ");
		String cadena = Teclado.leerLinea();
		System.out.println("La cadena invertida es: " + invertirCadena(cadena));
	}
}
