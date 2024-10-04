package ar.uba.fi.cb100.semana07.jueves;

public class Casillero<T> {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private int x = 0;
	private int y = 0;
	private T dato = null;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * pre:
	 * @param x: 1 o mayor
	 * @param y: 1 o mayor
	 * @throws Exception
	 */
	public Casillero(int x, int y) throws Exception {
		if (x < 1) {
			throw new Exception("X debe ser mayor a 0");
		}
		if (y < 1) {
			throw new Exception("Y debe ser mayor a 0");
		}
		this.x = x;
		this.y = y;
	}
	
//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
	
	@Override
	public String toString() {	
		return "Casillero (" + this.x + ", " + this.y + ")";
	}
	
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	public boolean estaOcupado() {
		return this.dato != null;
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
		
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
	public void setDato(T dato) {
		this.dato = dato;		
	}	
}
