package ar.uba.fi.cb100.semana07.jueves;

import java.util.Date;
import java.util.Random;

import ar.uba.fi.cb100.semana07.miercoles.Animal;
import ar.uba.fi.cb100.semana07.miercoles.Lista;

public class PrincipalDeLaClase14 {

	
	public static void ejercicioGuia5Punto2() throws Exception {
		Lista<Integer> lista = new Lista<Integer>();
		Random random = new Random();
		for(int i = 0; i < 1000; i++) {
			lista.agregar( random.nextInt(100));
		}
		
		lista.iniciarCursor();
		while( lista.avanzarCursor()) {
			System.out.println(lista.obtenerCursor());
		}
		
		System.out.println("Existe el 10: " + (lista.existe(10) ? "SI" : "NO") + " " + lista.contarOcurrencias(10));
		System.out.println("Existe el 101: " + (lista.existe(101) ? "SI" : "NO") + " " + lista.contarOcurrencias(101));
	}
	
	public static void ejercicioGuia5Punto6() throws Exception {
		Lista<String> lista = new Lista<String>();
		lista.agregar("Hola-mundo-lindo");
		lista.agregar("Mundo");
		lista.agregar("moto");
		lista.agregar("Cruel");
		
		lista.remover("Cruel");
		
		System.out.println("Existe el Hola: " + (lista.existe("Hola") ? "SI" : "NO"));
		System.out.println("Existe el hola: " + (lista.existe("hola") ? "SI" : "NO"));
		System.out.println("Existe el Cruel: " + (lista.existe("Cruel") ? "SI" : "NO"));
		
		String palabraABuscar = "o";
		lista.iniciarCursor();
		while( lista.avanzarCursor()) {
			String dato = lista.obtenerCursor();
			if ((dato + " ").split(palabraABuscar).length >= 0) {
				System.out.println(dato + " contiene a " + palabraABuscar + " " + ((dato + " ").split(palabraABuscar).length -1) + " veces");		
			}
		}
		
		//*************STRING**********
		//contiene
		//Hola ola: si
		//Hola kola: no
		//Hola Hola: si
		//Hola hola: no
		
		//una parte en comun
		//Hola nene: no
		//Hola Humo: si
		
		Lista<Animal> animales = new Lista<Animal>();
	}
	
	
	public static void ejercicioGuia5Punto18() throws Exception {
		{
			Tablero<Ficha> tablero = new Tablero<Ficha>(3, 3);
			tablero.agregar(1, 1, new Ficha('X'));
			tablero.agregar(2, 2, new Ficha('O'));
			
			for(int i = 1; i <= tablero.getAncho(); i++) {
				for(int j = 1; j <= tablero.getAlto(); j++) {
					Casillero<Ficha> casillero = tablero.getCasillero(i, j);
					System.out.println("Es el " + casillero.toString());
					if (casillero.estaOcupado()) {
						System.out.println("Esta ocupado " + casillero.getDato().toString());
					}
				}
			}
		}
		{
			Tablero<Character> tablero = new Tablero<Character>(3, 3);
			tablero.agregar(1, 1, Character.valueOf('H'));
		}
	}
	
	public static void main(String[] args) throws Exception {
		ejercicioGuia5Punto18();
		
		Date dia = new Date(10, 10, 2024);
		Lista<Casillero> miLista = new Lista();
	}
}
