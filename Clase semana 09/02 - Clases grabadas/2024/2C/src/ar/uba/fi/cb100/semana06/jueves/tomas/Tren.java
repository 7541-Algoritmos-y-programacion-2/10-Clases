package ar.uba.fi.cb100.semana06.jueves.tomas;

public class Tren {

	//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	
	private static final int CANTIDAD_MAXIMA_DE_LOCOMOTORAS = 3;
	
	//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private Locomotora[] locomotora = null;
	
	//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/*
	 * pre: -
	 * post: Creo un tren con 1 locomotora sin vagones
	 */
	
	public Tren() {
		this.locomotora[0] = new Locomotora();
	}
	
	//METODOS DE CLASE ----------------------------------------------------------------------------------------
	//METODOS GENERALES ---------------------------------------------------------------------------------------
	//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	/*
	 * pre: -
	 * post: Agrega x cantidad de locomotoras al tren
	 * cantidadDeLocomotoras: Cantidad de locomotoras a agregar
	 */
	
	public void agregarLocomotoras(int cantidadDeLocomotoras) throws Exception {
		if (cantidadDeLocomotoras < 1 ||
			cantidadDeLocomotoras >= CANTIDAD_MAXIMA_DE_LOCOMOTORAS) {
			throw new Exception("La cantidad de locomotoras a agregar debe ser 1 o 2");
		}
		if ((cantidadDeLocomotoras + this.locomotora.length) > CANTIDAD_MAXIMA_DE_LOCOMOTORAS) {
			throw new Exception("Si agrega " + cantidadDeLocomotoras + " locomotoras supera la cantidad maxima");
		}
		for (int i = 0; i < (cantidadDeLocomotoras - 1); i++) {
			this.locomotora[i] = new Locomotora(); 
		}
	}

	//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	

	public Locomotora[] getLocomotora() {
		return locomotora;
	}

	public static int getCantidadMaximaDeLocomotoras() {
		return CANTIDAD_MAXIMA_DE_LOCOMOTORAS;
	}
	
	//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
		
}


