package ar.uba.fi.cb100.semana05.jueves.tarea.timebomb;

public class Televisor {
	
	// Atributos -------------------------------------------------------------------------------------------------------
	
	private Canal[] canales = null;
	private int volumenActual = 0;
	//inicializamos el valor en 1 indicando el primer canal
	private int canalActual = 1;
	private boolean silenciado = false;
	
	/**
	 * pre: -
	 * post: Devuelve un televisor con cantidadCanales inicializados, con volumen actual en 0, canal actual en 1 y no silenciado
	 * @param cantidadCanales, un valor entero
	 * @throws Exception si el valor dado como parametro es 0 o negativo
	 */
	public Televisor(int cantidadCanales) throws Exception {
		if(!(Tools.checkPositiveStrict(cantidadCanales))) {
			throw new Exception("Cantidad de canales invalido");
		}
		this.canales = new Canal[cantidadCanales];
		for (int i = 0; i < cantidadCanales; i++) {
			this.canales[i] = new Canal(i + 1); // + 1 para que sea empezando en 1.
		}
	}
	
	/**
	 * pre: -
	 * post: Sube de canal
	 * @throws Exception si estamos en el canal maximo
	 */
	public void subirCanal() throws Exception {
		setCanal(canalActual + 1);
	};
	
	/**
	 * pre: -
	 * post: Baja de canal
	 * @throws Exception si estamos en el canal 1
	 */
	public void bajarCanal() throws Exception {
		setCanal(canalActual - 1);
	};
	
	/**
	 * pre: -
	 * post: Cambia de canal al indicado como parametro
	 * @param canal, un valor entero que sea el canal al que se quiera cambiar
	 * @throws Exception si es un canal invalido
	 */
	public void setCanal(int canal) throws Exception {
		verificarValidezCanal(canal);
		this.canalActual = canal;
		//cambiamos el volumen del canal al que cambiamos
		actualizarVolumenCanalActual();
	};
	
	/**
	 * pre: -
	 * post: Sube en 1 el volumen actual
	 * @throws Exception si el volumen es maximo (100)
	 */
	public void subirVolumen() throws Exception {
		if (silenciado) {
            silenciado = false; // desmutea
        }
		if (this.volumenActual < 100) {
			this.volumenActual += 1;
			actualizarVolumenCanalActual();
		} else {
			throw new Exception("Volumen no puede ser mayor a 100.");
		}
	};
	
	/**
	 * pre: -
	 * post: Baja el volumen
	 * @throws Exception si el volumen es minimo
	 */
	public void bajarVolumen() throws Exception {
		if (silenciado) {
            silenciado = false; // desmutea
        }
		if (this.volumenActual > 0) {
			this.volumenActual -= 1;
			actualizarVolumenCanalActual();
		} else {
			throw new Exception("Volumen no puede ser menor a 0.");
		}
	};
	
	/**
	 * pre: -
	 * post: Mutea o desmutea el televisor viendo su estado anterior
	 */
	public void switchSilencio() {
		this.silenciado = !this.silenciado;
	};
	
	/**
	 * pre: -
	 * post: devuelve un booleano indicando si el televisor esta muteado o en estado normal
	 * @return un booleando true or false
	 */
	public boolean getSilencio() {
		return this.silenciado;
	}
	
	/**
	 * pre: -
	 * post: Devuelve el valor del canal actual
	 * @return un entero que representa el canal actual
	 */
	public int getCanalActual() {
		return this.canalActual;
	}
	
	/**
	 * pre: -
	 * post: -
	 * @return devuelve el valor actual del volumen
	 */
	public int getVolumenActual() {
		if (silenciado) {
			return 0;
		}
		return this.volumenActual;
	}
	
	/**
	 * pre: -
	 * post: Devuelve el numero del canal que registro el mayor volumen
	 * @return un entero que representa el numero del canal con mayor volumen registrado
	 */
	public int getCanalMaxVol() {
		int maximoEncontrado = 0;
		for (int i = 0; i < this.canales.length; i++) {
			if (this.canales[i].getVolumenMaximo() > this.canales[maximoEncontrado].getVolumenMaximo()) {
				maximoEncontrado = i;
			}
		}
		return maximoEncontrado + 1;
	}
	
	/**
	 * pre: -
	 * @param canal, el numero del canal el cual quiere saber el volumen actual
	 * @return el volumen del canal dado como parametro
	 * @throws Exception 
	 */
	public int getVolumenCanal(int canal) throws Exception {
		verificarValidezCanal(canal);
		return this.canales[canal - 1].getVolumenActual();
	};
	
	/**
	 * pre: -
	 * @param canal, el numero de canal que se quiere saber el mayor volumen registrado
	 * @return un entero 
	 * @throws Exception 
	 */
	public int getVolumenMaxCanal(int canal) throws Exception {
		verificarValidezCanal(canal);
		return this.canales[canal - 1].getVolumenMaximo();
	}
	
	/**
	 * pre: -
	 * post: - 
	 * @param canal, verifica que sea válido (mayor a 0, menor al máximo)
	 * @throws Exception
	 */
	private void verificarValidezCanal(int canal) throws Exception {
		if (canal < 1 || canal > this.canales.length) {
			throw new Exception("Canal debe estar entre 1 y " + this.canales.length);
		}
	}
	
	/**
	 * pre: -
	 * post: -
	 * Actualiza el volumen del canal actual
	 * @throws Exception
	 */
    private void actualizarVolumenCanalActual() throws Exception {
        canales[canalActual - 1].changeVolumen(volumenActual);
    }
}
