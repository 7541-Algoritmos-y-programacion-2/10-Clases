package ar.uba.fi.cb100.semana08.jueves.tarea.franco;

public class Casillero<T> {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	public static int CANTIDAD_DE_VECINOS = 3;
	
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private int x = 0;
	private int y = 0;
	private T dato = null;
	private Casillero<T>[][] vecinos;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * pre:
	 * @param x: 1 o mayor
	 * @param y: 1 o mayor
	 * @throws Exception
	 */
	@SuppressWarnings("unchecked")
	public Casillero(int x, int y) throws Exception {
		if (x < 1) {
			throw new Exception("X debe ser mayor a 0");
		}
		if (y < 1) {
			throw new Exception("Y debe ser mayor a 0");
		}
		this.x = x;
		this.y = y;
		this.vecinos = new Casillero[CANTIDAD_DE_VECINOS][CANTIDAD_DE_VECINOS];
		for(int i = 0; i < this.vecinos.length; i++) {
			for(int j= 0; j < this.vecinos.length; j++) {
				this.vecinos[i][j] = null;
			}
		}
		this.vecinos[1][1] = this; //definirlo
	}
	
//METODOS DE CLASE ----------------------------------------------------------------------------------------
	
	public static int invertirCoordenadaDeVecino(int i) {
		return i * -1;
	}
	
//METODOS GENERALES ---------------------------------------------------------------------------------------
	
	@Override
	public String toString() {	
		return "Casillero (" + this.x + ", " + this.y + ")";
	}
	
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	public boolean estaOcupado() {
		return this.dato != null;
	}
	
	/**
	 * pre:
	 * @param dato: no puede ser vacio
	 * @return: devuelve verdadero si el dato es el mismo
	 * @throws Exception 
	 */
	public boolean tiene(T dato) throws Exception {
		if (dato == null) {
			throw new Exception("El dato no puede ser vacio");
		}
		return this.dato.equals(dato);
	}
	
	/**
	 * pre:
	 * @param movimiento: un movimiento en 2d, no puede ser nulo
	 * @return devuelve verdadero si existe el casillero vecino en esa direccion o falso si no existe (por ejemplo en el 
	 *         borde) 
	 */
	public boolean existeElVecino(Movimiento movimiento) {
		switch (movimiento) {
			case ABAJO:
				return this.vecinos[2][1] != null;
			case ARRIBA:
				return this.vecinos[0][1] != null;
			case DERECHA:
				return this.vecinos[1][2] != null;
			case IZQUIERDA:
				return this.vecinos[1][0] != null;
			default:
				break;		
		}
		return false;
	}
	
	/**
	 * pre:
	 * post: remueve la ficha del casillero
	 */
	public void vaciar() {
		this.setDato(null);		
	}
	
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	public int getX() {
		return x;
	}
	public int getY() {
		return y;
	}

	public T getDato() {
		return this.dato;
	}

	/**
	 * pre: 
	 * @param x: -1 0 y 1, para indicar izquierda centro o derecho respectivamente
	 * @param y: -1 0 y 1, para indicar arriba centro o abajo respectivamente
	 * @return devuelve el casilero
	 */
	public Casillero<T> getCasilleroVecino(int x, int y) {
		//validar rangos
		return this.vecinos[x+1][y+1];
	}

	public Casillero<T> getCasilleroVecino(Movimiento movimiento) throws Exception {
		switch (movimiento) {
			case ABAJO:
				return this.vecinos[2][1];
			case ARRIBA:
				return this.vecinos[0][1];
			case DERECHA:
				return this.vecinos[1][2];
			case IZQUIERDA:
				return this.vecinos[1][0];
		}
		throw new Exception("No se encontro la posicion vecina");
	}
	
	/**
	 * Devuelve una matriz con los vecinos, y el casillero actual en el centro
	 * @return
	 */
	@SuppressWarnings("unchecked")
	public Casillero<T>[][] getCasillerosVecinos() {
		Casillero<T>[][] matriz = new Casillero[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				matriz[i][j] = this.vecinos[i][j];
			}
		}
		return matriz;
	}
		
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
	public void setDato(T dato) {
		this.dato = dato;		
	}
	
	/**
	 * pre: 
	 * @param x: -1 0 y 1, para indicar izquierda centro o derecho respectivamente
	 * @param y: -1 0 y 1, para indicar arriba centro o abajo respectivamente
	 * @return devuelve el casilero
	 */
	public void setCasilleroVecino(Casillero<T> casillero, int i, int j) {
		//validar
		this.vecinos[i+1][j+1] = casillero;
	}

}
