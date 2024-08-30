package ar.uba.fi.cb100.semana02.jueves;

import java.util.Random;

public class Punto12 {

	public static double promedio(int[] vector) throws Exception {
		if ((vector == null) ||
		    (vector.length == 0)) {
			throw new Exception("El vector no puede estar vacio");
		}
		
		double resultado = 0;
		for(int i = 0; i < vector.length; i++) {
			resultado += vector[i];
		}
		return resultado / vector.length;
	}
	
	public static String imprimir(int[] vector) throws Exception {
		//Vamos a imprimir [1, 3, 848, 68]
		if ((vector == null) || 
		    (vector.length == 0)) {
			return "esta vacio";
		}
		String salida = "[";
		for (int i = 0; i < vector.length; i++) {
			salida += vector[i] + ", ";
		}
		return "es: " + salida.substring(0, salida.length()-2) + "]";
	}
	
	public static void ejecutar() {
		try {
			int[] vector = new int[5];
			Random random = new Random();
			for (int i = 0; i < vector.length; i++) {
				vector[i] = random.nextInt(1000);
			}
			
			if (Punto11.vector != null) {
				System.out.println("Seleccione que vector utilizar:");
				System.out.println("1 - " + imprimir(vector));
				System.out.println("2 - " + imprimir(Punto11.vector));
				
				int opcion = Teclado.leerEntero();
				if (opcion == 1) {
					System.out.println("El promedio es: " + promedio(vector));		
				} else {
					System.out.println("El promedio es: " + promedio(Punto11.vector));
				}
			} else {
				System.out.println("El promedio del vector " + imprimir(vector) + " es " + promedio(vector));
			}
		} catch (Exception e) {
			System.out.println("El vector no es correcto");
		}
	}
}
