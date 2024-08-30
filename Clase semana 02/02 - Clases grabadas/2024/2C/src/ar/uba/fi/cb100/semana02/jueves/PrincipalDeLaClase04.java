package ar.uba.fi.cb100.semana02.jueves;

import java.util.Scanner;

public class PrincipalDeLaClase04 {

//	//Tarea: abrir y cerrar el Scanner
//	Scanner ingresoPorTeclado = new Scanner(System.in);
//	{
//		int numero1 = ingresoPorTeclado.nextInt();			
//		System.out.println("El numero es: " + numero1);
//	}
//	{
//		String numero1 = ingresoPorTeclado.next();
//		System.out.println("El numero es: " + numero1);
//	}
//	ingresoPorTeclado.close();
	
	//Leer hasta el espacio o fin de linea
	
	public static void main(String[] args) throws Exception {
		int opcion = 0;
		while (opcion != 4) {
			System.out.println("Seleccione la opcion:");
			System.out.println("1 - para ejecutar el punto 11");
			System.out.println("2 - para ejecutar el punto 12");
			System.out.println("3 - para ejecutar el punto 14");
			System.out.println("4 - salir");
			
			if (Teclado.tieneEntero()) {
				opcion = Teclado.leerEntero();
				switch (OpcionDeMenu.getOpcionDeMenu(opcion)) {
					case Punto11:
						Punto11.ejecutar();
						break;
					case Punto12:
						Punto12.ejecutar();
						break;
					case Punto14:
						Punto14.ejecutar();
						break;
					case Salir:
						System.out.println("El programa ha finalizado");
						break;
					default:
						throw new Exception("La opcion " + opcion + " no fue implementada");
				}
			} else {
				System.out.println("Entrada no válida. Por favor, ingresa un número.");
				Teclado.leer(); 
			}
		}
		Teclado.finalizar();
	}
}
