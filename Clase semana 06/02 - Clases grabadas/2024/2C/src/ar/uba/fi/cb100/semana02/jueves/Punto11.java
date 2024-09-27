package ar.uba.fi.cb100.semana02.jueves;

public class Punto11 {

	public static int CANTIDAD_MAXIMA = 5;
	public static int[] vector = null;
	
	public static void ejecutar() {
		vector = new int[CANTIDAD_MAXIMA];

		for(int i = 0; i < vector.length; i++) {
			System.out.println("Ingrese el numero de la posicion " + (i + 1) + ": ");
			vector[i] = Teclado.leerEntero();
		}
		
		//Opcion 1
		for(int i = vector.length; i > 0 ; i--) {
			System.out.println("El valor de la posicion " + i + " es " + vector[i-1]);
		}
		
//		//Opcion 2
//		for(int i = (vector.length - 1); i >= 0 ; i--) {
//			System.out.println("El valor de la posicion " + (i+1) + " es " + vector[i]);
//		}
//		
//		//Opcion 3 - no la recomiendo
//		for(int i = 0; i < vector.length; i++) {
//			System.out.println("El valor de la posicion " + (vector.length-i) + " es " + vector[vector.length-i-1]);
//		}
		
	}

}
