package ar.uba.fi.cb100.semana07.miercoles;

public class Vector<T extends Object> {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------

	private T[] datos = null;
	private T datoInicial;

//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * pre: 
	 * @param longitud: entero mayor a 0, determina la cantiadad de elementos del vector
	 * @param datoInicial: valor inicial para las posiciones del vector
	 * @throws Exception: da error si la longitud es invalida
	 * post: inicializa el vector de longitud de largo y todos los valores inicializados
	 */
	public Vector(int longitud, T datoInicial) throws Exception {
		if (longitud < 1) {
			throw new Exception("La longitud debe ser mayor o igual a 1");
		}
		this.datos = crearVector(longitud);
		this.datoInicial = datoInicial;
		for(int i = 0; i < this.getLongitud(); i++){
			this.datos[i] = datoInicial;
		}
	}
	
//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	/**
	 * pre:
	 * @param posicion: valor entre 1 y el largo del vector (no redimensiona)
	 * @param dato: -
	 * @throws Exception: da error si la posicion no esta en rango
	 * post: guarda la el dato en la posicion dada 
	 */
	public void agregar(int posicion, T dato) throws Exception {
		validarPosicion(posicion);
		this.datos[posicion - 1] = dato;
	}

	/**
	 * pre: -
	 * @param posicion: valor entre 1 y el largo del vector
	 * @return devuelve el valor en esa posicion
	 * @throws Exception: da error si la posicion no esta en rango
	 */
	public T obtener(int posicion) throws Exception {
		validarPosicion(posicion);
		return this.datos[posicion - 1];
	}

	/**
	 * pre: -
	 * @param posicion: valor entre 1 y el largo del vector
	 * @throws Exception: da error si la posicion no esta en rango
	 * post: remueve el valor en la posicion y deja el valor inicial
	 */
	public void remover(int posicion) throws Exception {
		if ((posicion < 1) ||
				(posicion > this.getLongitud())) {
			throw new Exception("La " + posicion + " no esta en el rango 1 y " + this.getLongitud() + " inclusive");
		}
		this.datos[posicion - 1] = this.datoInicial;
	}

	/**
	 * pre: 
	 * @param dato: valor a guardar
	 * @return devuelve la posicion en que se guardo
	 * @throws Exception
	 * post: guarda el dato en la siguiente posicion vacia
	 */
	public int agregar(T dato) throws Exception  {
		//validar dato;
		for(int i = 0; i < this.getLongitud(); i++) {
			if (this.datos[i] == this.datoInicial) {
				this.datos[i] = dato;
				return i + 1;
			}
		}		
		T[] temp = crearVector(this.getLongitud() * 2);
		for(int i = 0; i < this.getLongitud(); i++) {
			temp[i] = this.datos[i];
		}
		int posicion = this.getLongitud(); 
		this.datos = temp;
		this.datos[posicion] = dato;
		for(int i = posicion +1; i < this.getLongitud(); i++) {
			this.datos[i] = this.datoInicial;	
		}
		return posicion + 1;
	}
	
	/**
	 * pre: -
	 * @param posicion: valor entre 1 y el largo del vector
	 * @throws Exception: da error si la posicion no esta en rango
	 * post: valida la posicion que este en rango
	 */
	private void validarPosicion(int posicion) throws Exception {
		if ((posicion < 1) ||
			(posicion > this.getLongitud())) {
			throw new Exception("La " + posicion + " no esta en el rango 1 y " + this.getLongitud() + " inclusive");
		}
	}

	/**
	 * pre: 
	 * @param longitud: -
	 * @return devuelve un vector del tipo y longitud deseado
	 * @throws Exception 
	 */
	
	@SuppressWarnings("unchecked")
	private T[] crearVector(int longitud) throws Exception {
		if (longitud <= 0) {
			throw new Exception("La longitud debe ser mayor o igual a 1");
		}
		return (T[]) new Object[longitud];
	}
		
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	public int getLongitud() {
		return this.datos.length;
	}
	
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	



	













}