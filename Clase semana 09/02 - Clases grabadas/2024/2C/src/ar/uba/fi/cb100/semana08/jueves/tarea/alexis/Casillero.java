package ar.uba.fi.cb100.semana08.jueves.tarea.alexis;

import ar.uba.fi.cb100.semana07.miercoles.Lista;

public class Casillero<T> {
//ATRIBUTOS DE CLASE
//ATRIBUTOS
	
	private int x = 0;
	private int y = 0;
	private T dato;
	//Opcion 1
	private Lista<Casillero<T>> vecinos;
	
	//Opcion 2
	private Casillero<T>[][] vecinos2;
	
//CONSTRUCTORES
	
	/**
	 * pre: -
	 * @param x : Debe ser mayor a 0
	 * @param y : Debe ser mayor a 0
	 * pos: Crea un casillero con las posiciones x e y dadas
	 * @throws Exception
	 */
	public Casillero(int x, int y) throws Exception {
		if(x < 0) {
			throw new Exception("X debe ser mayor a 0");
		}
		if(y < 0 ) {
			throw new Exception("Y debe ser mayor a 0");
		}
		this.x = x;
		this.y = y;
	}
//METODOS DE CLASE
//METODOS GENERALES
	
	@Override
	public String toString() {
		return "Casillero ("+this.x + "," + this.y +")";
	}
	
//METODOS DE COMPORTAMIENTO
	/**
	 * pre:-
	 * 
	 *
	 * @return devuelve verdadero si el casillero esta ocupado y falso si no lo esta.
	 */
	public boolean estaOcupado() {
		return this.dato != null;
	}
//GETTERS SIMPLES
	/**
	 * pre:-
	 * @return devuelve la posicion en x del casillero
	 */
	public int getX() {
		return this.x;
	}
	
	/**
	 * pre:-
	 * @return devuelve la posicion en y del casillero.
	 */
	public int getY() {
		return this.y;
	}
	
	/**
	 * pre:-
	 * @return devuelve el dato que hay en el casillero
	 */
	public T getDato() {
		return this.dato;
	}
	
	public Lista<Casillero<T>> getvecinos(){
		return this.vecinos;
	}
	
	public void setVecinos(Lista<Casillero<T>> casillerosVecinos) {
		this.vecinos = casillerosVecinos;
	}
//SETTERS SIMPLES
	/**
	 * pre:-
	 * @param dato -
	 * pos: pone el dato en el casillero
	 */
	public void setDato(T dato) {
		this.dato = dato;
	}
}
