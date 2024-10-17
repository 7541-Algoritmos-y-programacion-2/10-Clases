package ar.uba.fi.cb100.semana08.miercoles.estructuras;

import ar.uba.fi.cb100.semana07.miercoles.Lista;
import ar.uba.fi.cb100.semana07.miercoles.Nodo;

public class Cola<T> {
	//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	//ATRIBUTOS -----------------------------------------------------------------------------------------------

	private Nodo<T> frente = null;

	private Nodo<T> ultimo = null;

	private int tamanio = 0;

	//CONSTRUCTORES -------------------------------------------------------------------------------------------

	/**
	 * pre:
	 * post: inicializa la cola vacia para su uso
	 */
	public Cola() {
		this.frente = null;
		this.ultimo = null;
		this.tamanio = 0;
	}

	//METODOS DE CLASE ----------------------------------------------------------------------------------------
	//METODOS GENERALES ---------------------------------------------------------------------------------------
	//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------

	/*
	 * post: indica si la cola tiene algún elemento.
	 */
	public boolean estaVacia() {
		return (this.tamanio == 0);
	}

	/*
	 * pre: el elemento no es vacio
	 * post: agrega el elemento a la cola
	 */
	public void acolar(T elemento) {
		Nodo<T> nuevo = new Nodo<T>(elemento);
		if (!this.estaVacia()) {
			this.ultimo.setSiguiente(nuevo);
			this.ultimo = nuevo;
		} else {
			this.frente = nuevo;
			this.ultimo = nuevo;
		}
		this.tamanio++;
	}

	/*
	 * pre: el elemento no es vacio
	 * post: agrega el elemento a la cola
	 */
	void acolar(Lista<T> lista) {
		//validar
		lista.iniciarCursor();
		while (!lista.avanzarCursor()) {
			this.acolar(lista.obtenerCursor());
		}
	}

	/*
	 * pre :
	 * post: devuelve el elemento en el frente de la cola quitandolo.
	 */
	public T desacolar() {
		T elemento = null;
		if (!this.estaVacia()) {
			elemento = this.frente.getDato();
			this.frente = this.frente.getSiguiente();
			this.tamanio--;
			if (estaVacia()) {
				this.ultimo = null;
			}
		}
		return elemento;
	}

	/*
	 * post: devuelve la cantidad de elementos que tiene la cola.
	 */
	public int contarElementos() {

		return this.tamanio;
	}

	//GETTERS SIMPLES -----------------------------------------------------------------------------------------

	/*
	 * pre :
	 * post: devuelve el elemento en el frente de la cola. Solo lectura
	 */
	public T obtener() {
		T elemento = null;
		if (!this.estaVacia()) {
			elemento = this.frente.getDato();
		}
		return elemento;
	}

	//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
}