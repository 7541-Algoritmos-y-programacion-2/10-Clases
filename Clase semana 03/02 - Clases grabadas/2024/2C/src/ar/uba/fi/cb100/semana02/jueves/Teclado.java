package ar.uba.fi.cb100.semana02.jueves;

import java.util.Scanner;

public class Teclado {

	private static Scanner scanner = null;

	private static void inicializar() {
		if (scanner == null) {
			scanner = new Scanner(System.in);
		}
	}

	public static boolean tieneEntero() {
		if (scanner == null) { 			
			inicializar();
		}
		return scanner.hasNextInt();		
	}
	
	public static String leer() {
		if (scanner == null) {
			inicializar();
		}
		return scanner.next();
	}
	
	public static String leerLinea() {
		if (scanner == null) {
			inicializar();
		}
		return scanner.next();
	}
	
	public static int leerEntero() {
		if (scanner == null) {
			inicializar();
		}
		return scanner.nextInt();
	}

	public static void finalizar() {
		if (scanner != null) {
			scanner.close();
		}
	}
}
