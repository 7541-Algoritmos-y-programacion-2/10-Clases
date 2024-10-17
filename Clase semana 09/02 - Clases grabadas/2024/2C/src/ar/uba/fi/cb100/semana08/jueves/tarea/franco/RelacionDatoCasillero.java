package ar.uba.fi.cb100.semana08.jueves.tarea.franco;

public class RelacionDatoCasillero<T> {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private T dato = null;
	private Casillero<T> casillero = null;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	public RelacionDatoCasillero() {}
	
	public RelacionDatoCasillero(Casillero<T> casillero, T dato) {
		this.casillero = casillero;
		this.dato = dato;
	}
	
//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
//GETTERS SIMPLES -----------------------------------------------------------------------------------------

	public T getDato() {
		return dato;
	}
	public Casillero<T> getCasillero() {
		return casillero;
	}
	
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
	
	public void setDato(T dato) {
		this.dato = dato;
	}
	public void setCasillero(Casillero<T> casillero) {
		this.casillero = casillero;
	}
}
