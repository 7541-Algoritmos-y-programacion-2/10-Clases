package ar.uba.fi.cb100.semana06.jueves.tomas;

public class Locomotora {

	//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	
	private static final int CANTIDAD_MAXIMA_DE_VAGONES = 10;
	
	//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private Vagon[] vagones = null;
	
	//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/*
	 * pre:- 
	 * post: Creo una locomotora
	 */
	
	public Locomotora() {
		
	}
	
	//METODOS DE CLASE ----------------------------------------------------------------------------------------
	//METODOS GENERALES ---------------------------------------------------------------------------------------
	//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	/*
	 * pre: -
	 * post: agrega x cantidad de vagones a la locomotora
	 * cantidadDeVagone: parametro entero de cantidad de vagones a agregar
	 */
	
	public void agregarVagones(int cantidadDeVagones) throws Exception {
		if (cantidadDeVagones < 0 ||
			cantidadDeVagones > CANTIDAD_MAXIMA_DE_VAGONES) {
			throw new Exception("La cantidad de vagones a agregar debe estar entre 0 y 10");
		}
		if ((vagones.length + cantidadDeVagones) > CANTIDAD_MAXIMA_DE_VAGONES) {
			throw new Exception("Si agrega " + cantidadDeVagones + "de vagones supera la cantidad maxima");
		}
		for (int i = 0; i < (cantidadDeVagones - 1); i++) {
			this.vagones[i] = new Vagon(0);
		}
	}
	
	/*
	 * pre: -
	 * post: elimina x cantidad de vagones a la locomotora
	 * cantidadDeVagone: parametro entero de cantidad de vagones a eliminar
	 */
	
	public void sacarVagones(int cantidadDeVagones) throws Exception {
		if (cantidadDeVagones < 1 ||
			cantidadDeVagones > CANTIDAD_MAXIMA_DE_VAGONES) {
			throw new Exception("La cantidad de vagones a sacar debe estar entre 1 y 10");
		}
		if (cantidadDeVagones > vagones.length) {
			throw new Exception("No puede sacar " + cantidadDeVagones + "vagones, ya que tiene " + vagones.length);
		}
		if (cantidadDeVagonesVacios() >= cantidadDeVagones) {
			for (int i = 0; i < (this.vagones.length - 1) ; i++) {
				if (this.vagones[i].getCarga() == 0) {
					this.vagones[i] = null;
				}
			}	
		}
	}
	
	/*
	 * pre: -
	 * post: devuelve la cantidad de vagones vacios de la locomotora
	 */
	
	public int cantidadDeVagonesVacios() {
		int vagonesVacios = 0;
		for (int i = 0; i < (this.vagones.length - 1) ; i++) {
			if (this.vagones[i].getCarga() == 0) {
				vagonesVacios += 1;
			}
		}
		return vagonesVacios;
	}

	//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	public Vagon[] getVagones() {
		return vagones;
	}

	public static int getCantidadMaximaDeVagones() {
		return CANTIDAD_MAXIMA_DE_VAGONES;
	}
	
	//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
}
