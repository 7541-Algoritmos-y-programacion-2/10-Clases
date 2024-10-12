package ar.uba.fi.cb100.semana05.miercoles;

@SuppressWarnings("serial")
public class ExcepcionPorEdad extends ExcepcionGeneral {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private int edad = 0;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * 
	 * @param edad
	 */
	public ExcepcionPorEdad(int edad) {
		this.edad = edad;
	}

//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @return devuelve la edad cargada en la excpecion
	 */
	public int getEdad() {
		return edad;
	}
	
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
	
}
