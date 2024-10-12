package ar.uba.fi.cb100.semana08.miercoles;

import ar.uba.fi.cb100.semana08.miercoles.estructuras.Cola;
import ar.uba.fi.cb100.semana08.miercoles.estructuras.Lista;
import ar.uba.fi.cb100.semana08.miercoles.estructuras.ListaCircularDoblementeEnlazada;
import ar.uba.fi.cb100.semana08.miercoles.estructuras.ListaCircularSimplementeEnlazada;
import ar.uba.fi.cb100.semana08.miercoles.estructuras.ListaDoblementeEnlazada;
import ar.uba.fi.cb100.semana08.miercoles.estructuras.ListaSimplementeEnlazada;
import ar.uba.fi.cb100.semana08.miercoles.estructuras.Pila;

public class PrincipalDeLaClase15 {

	public static void main(String[] args) {

		Lista<String> ejemplo = null;
		
		ejemplo = new ListaSimplementeEnlazada<String>();
		ejemplo = new ListaDoblementeEnlazada<String>();
		ejemplo = new ListaCircularSimplementeEnlazada<String>();
		ejemplo = new ListaCircularDoblementeEnlazada<String>();		
		
		Pila<String> pila = new Pila<String>();
		pila.apilar("-----");
		pila.apilar("Hola");
		pila.apilar(" ");
		pila.apilar("Mundo");
		pila.apilar("-----");
		
		System.out.println("PILA");
		while (!pila.estaVacia()) {
			System.out.println("Valor: " + pila.desapilar());
		}
		
		System.out.println("\n\nCola");
		Cola<String> cola = new Cola<String>();
		cola.acolar("-----");
		cola.acolar("Hola");
		cola.acolar(" ");
		cola.acolar("Mundo");
		cola.acolar("-----");
		
		while (!cola.estaVacia()) {
			System.out.println("Valor: " + cola.desacolar());
		}
	}
}
 