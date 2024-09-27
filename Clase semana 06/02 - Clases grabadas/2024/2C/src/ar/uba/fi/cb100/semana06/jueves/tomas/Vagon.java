package ar.uba.fi.cb100.semana06.jueves.tomas;

public class Vagon {

	//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	
	private static final int CAPACIDAD_MAXIMA_DE_CARGA = 500; 
	
	//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private int carga = 0;
	
	//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/*
	 * pre: -
	 * post: Crea Vagon con la cantidad de carga entre 0 y CAPACIDAD_MAXIMA_DE_CARGA
	 */
	public Vagon (int carga) throws Exception {
		if (carga < 0 ||
			carga > CAPACIDAD_MAXIMA_DE_CARGA) {
			throw new Exception("La carga del vagon debe estar entre 0 y " + CAPACIDAD_MAXIMA_DE_CARGA);
		}
		this.carga = carga;
	}

	
	//METODOS DE CLASE ----------------------------------------------------------------------------------------
	//METODOS GENERALES ---------------------------------------------------------------------------------------
	//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	/*
	 * pre: -
	 * post: Devuelve la carga actual del vagon
	 */
	
	public int getCarga() {
		return carga;
	}
	
	/*
	 * pre: -
	 * post: Devuelve la carga maxima posible de los vagones
	 */
	
	public static int getCapacidadMaximaDeCarga() {
		return CAPACIDAD_MAXIMA_DE_CARGA;
	}
	
	//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
	
}
