package ar.uba.fi.cb100.semana01.jueves;

import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;

public class PrincipalDeLaClase02 {

	public static void imprimirHolaMundo(int i) {
		System.out.println("Hola mundo. El valor de i es " + i);	
	}
	
	public static int sumar(int numero1, int numero2) {
		return numero1 + numero2;
	}
	
	public static int restar(int numero1, int numero2) {
		return numero1 - numero2;
	}
	
	public static int multiplicar(int numero1, int numero2) {
		return numero1 * numero2;
	}
	
	public static double dividir(int numero1, int numero2) throws Exception {
		if (numero2 == 0) {
			throw new Exception("No se puede dividir por 0");
		}
		
		return Integer.valueOf(numero1).doubleValue() / 
			   Integer.valueOf(numero2).doubleValue();
	}
	
	public static void main(String[] args) throws Exception {
		/*
		//F5: paso a paso (ingresa a metodos)
		//F6: paso a paso (no ingresa a metodos)
		//F8: ejecuta hasta el final o proximo breakpoint
		
		int numero3 = 0;
		imprimirHolaMundo(numero3);
		
		
		Scanner ingresoPorTeclado = new Scanner(System.in);
		int numero1 = ingresoPorTeclado.nextInt();
		int numero2 = ingresoPorTeclado.nextInt();
		
		System.out.println("La suma es: " + sumar(numero1, numero2));
		System.out.println("La resta es: " + restar(numero1, numero2));
		System.out.println("La multiplicacion es: " + multiplicar(numero1, numero2));
		
		//Opcion 1
		try {
			System.out.println("La division es: " + dividir(numero1, numero2));
			System.out.println("No se ejecuta si es numero2 = 0");
		} catch (Exception e) {
			e.printStackTrace();
			System.err.println("No se puede dividir por 0");
		} finally {
			System.out.println("Fin de las operaciones");
		}
		
		//Opcion 2
		if (numero2 != 0) {
			System.out.println("La division es: " + dividir(numero1, numero2));
		} else {
			System.out.println("No se puede dividir por 0");
		}
		
		ingresoPorTeclado.close();
		*/
		//Leer archivo de texto.
		long tiempoInicial = System.currentTimeMillis();
		int[] valores = AdministradorDeArchivosDeTexto.leerLineasDeTexto("datos.txt");
		for(int i = 0; i< valores.length; i++) {
			System.out.print(valores[i] + ((i == (valores.length - 1))? System.getProperty("line.separator"): ", "));		
		}
		long tiempoFinal = System.currentTimeMillis();
		long diferenciaDeTiempo = tiempoFinal - tiempoInicial;
		System.out.println("Se tardo " + diferenciaDeTiempo + " milisegundos");
		
		
		LocalDateTime fechaHoraActual = LocalDateTime.now();
		DateTimeFormatter formatoHora = DateTimeFormatter.ofPattern("HH-mm-ss");
		
		AdministradorDeArchivosDeTexto.escribirLineasDeTexto("datos-salida-burbujeo-" + fechaHoraActual.format(formatoHora) + ".txt", valores, "Se tardo " + diferenciaDeTiempo + " milisegundos");
	}

}
