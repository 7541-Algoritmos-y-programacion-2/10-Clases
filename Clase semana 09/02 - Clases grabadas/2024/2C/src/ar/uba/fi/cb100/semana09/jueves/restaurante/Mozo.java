package ar.uba.fi.cb100.semana09.jueves.restaurante;

public class Mozo {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private double propinaRecaudada = 0;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	public Mozo() {}

//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	public void agregarPropina(double propina) {
		//validar
		this.propinaRecaudada += propina;
	}
	
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	public double getPropinaRecaudada() {
		return propinaRecaudada;
	}
	
//SETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	public void setPropinaRecaudada(double propinaRecaudada) {
		this.propinaRecaudada = propinaRecaudada;
	}

}
