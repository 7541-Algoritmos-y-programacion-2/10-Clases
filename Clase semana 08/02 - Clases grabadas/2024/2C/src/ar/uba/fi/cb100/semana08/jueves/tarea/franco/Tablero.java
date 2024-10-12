package ar.uba.fi.cb100.semana08.jueves.tarea.franco;

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
			this.tablero.agregar(fila);
			for(int j = 1; j <= alto; j++) {
				Casillero<T> nuevoCasillero = new Casillero<T>(i, j);
				fila.agregar(nuevoCasillero);
				
				//Estoy en (i, j), tengo que asignar (i-1, j + 0), (i-1, j-1), (i, j-1)
				for(int k = -1; k <= 1; k++) {
					if (this.existeElCasillero(i-1, k)) {
						relacionarCasillerosVecinos(this.getCasillero(i-1, k), nuevoCasillero, -1, k);					
					}
				}
				if (this.existeElCasillero(i, j-1)) {
					relacionarCasillerosVecinos(this.getCasillero(i, j-1), nuevoCasillero, 0, -1);
				}
			}
			
			//Avanzo a siguiente fila para la busqueda de vecinos
			this.tablero.avanzarCursor();	
		}
	}

	/**
	 * pre:
	 * @param casillero1: no puede ser vacio
	 * @param casillero2: no puede ser vacio
	 * @param i: rango entre -1, 0 y 1
	 * @param j: rango entre -1, 0 y 1
	 * post: relaciona los dos vecinos en sus matrices de vecinos, en el casillero1 como i y j, y en casillero2
	 *       como el opuesto
	 */
	public void relacionarCasillerosVecinos(Casillero<T> casillero1, Casillero<T> casillero2, int i, int j) {
		//Validar
		casillero2.setCasilleroVecino(casillero1, i, j);
		casillero1.setCasilleroVecino(casillero2, Casillero.invertirCoordenadaDeVecino(i), Casillero.invertirCoordenadaDeVecino(j));
	}

	public boolean existeElCasillero(int i, int j) throws Exception {
		if ((i < 1) ||
		    (j < 1)) {
			   return false;
		   }
		if ((i > this.tablero.getLongitud()) ||
			(j > this.tablero.obtener(i).getLongitud())) {
			return false;
		}
		return true;
	}

	public void agregar(int x, int y, T ficha) throws Exception {
		Casillero<T> casillero = getCasillero(x, y);
		casillero.setDato(ficha);
	}

	public Casillero<T> getCasillero(int x, int y) throws Exception {
		//validar
		return this.tablero.obtener(x).obtener(y);
	}
	
	/**
	 * 
	 * @param x
	 * @param y
	 * @return
	 * @throws Exception
	 * post: devuelve el dato que hay en el casillero
	 */
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
