package ar.uba.fi.cb100.semana07.jueves;

import ar.uba.fi.cb100.semana07.miercoles.Lista;

public class Tablero<T> {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private Lista<Lista<Casillero<T>>> tablero = null;
	private int ancho = 0;
	private int alto = 0;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * 
	 * @param ancho
	 * @param alto
	 * @throws Exception 
	 * post: crea un tablero de ancho 'ancho' contando de 1 a ancho inclusive
	 */
	public Tablero(int ancho, int alto) throws Exception {
		//tarea validar > 0
		this.ancho = ancho;
		this.alto = alto;
		this.tablero = new Lista<Lista<Casillero<T>>>();
		for( int i = 1; i <= ancho; i++) {
			Lista<Casillero<T>> fila = new Lista<Casillero<T>>();
			for(int j = 1; j <= alto; j++) {
				fila.agregar(new Casillero<T>(i, j));
			}
			this.tablero.agregar(fila);	
		}
	}

	public void agregar(int x, int y, T ficha) throws Exception {
		Casillero<T> casillero = getCasillero(x, y);
		casillero.setDato(ficha);
	}

	public Casillero<T> getCasillero(int x, int y) throws Exception {
		//validar
		return this.tablero.obtener(x).obtener(y);
	}
	
	public T obtener(int x, int y) throws Exception {
		return getCasillero(x, y).getDato();
	}

//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
//GETTERS SIMPLES -----------------------------------------------------------------------------------------


	public int getAncho() {
		return ancho;
	}

	public int getAlto() {
		return alto;
	}
	
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
}
