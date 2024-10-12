package ar.uba.fi.cb100.semana08.jueves.tarea.alexis;

import ar.uba.fi.cb100.semana07.miercoles.Lista;

public class Tablero <T>{
//ATRIBUTOS DE CLASE
//ATRIBUTOS
	private Lista<Lista<Casillero<T>>> tablero = null;
	private int ancho = 0;
	private int alto = 0;
//CONSTRUCTORES
	
	/**
	 * pre: -
	 * @param ancho el ancho del tablero debe ser mayor a 0
	 * @param alto el alto del tablero debe ser mayor a 0
	 * pos: crea un tablero de ancho x alto(caso 1 x 1 seria un cuadrado solo);
	 * @throws Exception
	 */
	public Tablero(int ancho, int alto)throws Exception{
		if(ancho < 1 || alto < 1) {
			throw new Exception("EL ancho y el largo deben ser mayor o igual que 1");
		}
		this.ancho=ancho;
		this.alto=alto;
		this.tablero=new Lista<Lista<Casillero<T>>>();
		for(int i = 1 ; i <= ancho ; i++) {
			Lista<Casillero<T>> fila = new Lista<Casillero<T>>();
			for(int j = 1 ; j <= alto ; j++) {
				fila.agregar(new Casillero<T>(i,j));
			}
			this.tablero.agregar(fila);
		}
		
		for(int i = 1 ; i <= ancho ; i++) {
			for(int j = 1;j <= alto; j++) {
				Casillero<T> casillero = this.getCasillero(i, j);
				asignarCasillerosVecinos(casillero,i,j);
			}
		}
	}
//METODOS DE CLASE
//METODOS GENERALES
//METODOS DE COMPORTAMIENTO
	
	private void asignarCasillerosVecinos(Casillero<T> casillero, int x, int y) throws Exception {
		int[][] direcciones = {{0,1},{0,-1},{1,0},{-1,0}};
		Lista<Casillero<T>> casillerosVecinos = new Lista<Casillero<T>>();
		for(int[] dire : direcciones) {
			int nuevoX = x + dire[0];
			int nuevoY = y + dire[1];
			
			if(nuevoX >= 1  && nuevoX <= this.getAncho() && nuevoY >= 1 && nuevoY <= this.getAlto() ) {
				Casillero<T> casilleroVecino = this.getCasillero(nuevoX, nuevoY);
				casillerosVecinos.agregar(casilleroVecino);
			}
		}
		//casillero.setVecinos(casillerosVecinos);
	}
	
	
	public void agregar(int x, int y , T ficha)throws Exception {
		if(x < 1 || x > this.ancho) {
			throw new Exception("La posicion x debe estar entre 1 y " + this.ancho);
		}
		if(y < 1 || y > alto) {
			throw new Exception("La posicion y debe estar entre 1 y "+ this.alto);
		}
		Casillero<T> casillero = getCasillero(x,y);
		casillero.setDato(ficha);
	}
	
	public Casillero<T> getCasillero(int x , int y)throws Exception{
		if(x < 1 || x > this.ancho) {
			throw new Exception("La posicion x debe estar entre 1 y " + this.ancho);
		}
		if(y < 1 || y > alto) {
			throw new Exception("La posicion y debe estar entre 1 y "+ this.alto);
		}
		return this.tablero.obtener(x).obtener(y);
	}
	
	public T obtenerDato(int x, int y) throws Exception{
		if(x < 1 || x > this.ancho) {
			throw new Exception("La posicion x debe estar entre 1 y " + this.ancho);
		}
		if(y < 1 || y > alto) {
			throw new Exception("La posicion y debe estar entre 1 y "+ this.alto);
		}
		return getCasillero(x, y).getDato();
		
	}
//GETTERS SIMPLES
	
	public int getAncho() {
		return this.ancho;
	}
	
	public int getAlto() {
		return this.alto;
	}
//SETTERS SIMPLES
}
