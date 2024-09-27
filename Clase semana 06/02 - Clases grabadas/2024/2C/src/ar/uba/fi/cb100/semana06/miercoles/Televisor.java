package ar.uba.fi.cb100.semana06.miercoles;

import ar.uba.fi.cb100.semana05.jueves.tarea.timebombv2.Tools;

public class Televisor {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private Canal[] canales = null;
    private Canal canalActual = null;
    private EstadoDeTelevisor estado = null;
    
//CONSTRUCTORES -------------------------------------------------------------------------------------------
    
    /**
     * pre: - 
     * 
     * @param cantidadCanales: un valor entero mayor a 0 que indica la cantidad de canales
     * @throws Exception: si el valor dado como parametro es 0 o negativo
     * 
     * post: Devuelve un televisor con cantidadCanales inicializados, con
     *       volumen actual en 10, canal actual en 1 y no silenciado
     */
    public Televisor(int cantidadCanales) throws Exception {
    	this(cantidadCanales, 10);
    }
    
    /**
     * pre: - 
     * @param cantidadCanales: un valor entero mayor a 0 que indica la cantidad de canales
     * @param volumenActual: un valor entre 0 y 100
     * @throws Exception: si el valor dado como parametro es 0 o negativo
     * 
     * post: Devuelve un televisor con cantidadCanales inicializados, con
     *       volumen actual en volumenActual, canal actual en 1 y no silenciado
     */
    public Televisor(int cantidadCanales, int volumenActual) throws Exception {
        if (!ValidacionesUtiles.esPositivo(cantidadCanales)) {
            throw new Exception("La cantidad de canales debe ser mayor a 0");
        }
        this.canales = new Canal[cantidadCanales];
        for (int i = 0; i < cantidadCanales; i++) {
            this.canales[i] = new Canal(i + 1); // + 1 para que sea empezando en 1 el NUMERO del canal
        }
        this.canalActual = this.canales[0];
        this.canalActual.setVolumen(volumenActual);
        this.estado = EstadoDeTelevisor.NORMAL;
    }
    
//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
    
    /**
     * pre: - 
     *
     * @throws: da error si el canal no es valido
     * post: Sube de canal si es posible o lo pasa al canal 1
     * 
     */
    public void subirCanal() throws Exception {
    	if (this.canalActual.getNumero() >= getCantidadDeCanales()) {
    		establecerCanal(this.canales[0]);
    	} else {
    		establecerCanal(this.canales[this.canalActual.getNumero()]);
    	}
    	
    	//this.canales[0] -> canal 1
    	//this.canales[1] -> canal 2
    	//this.canales[2] -> canal 3
    	//....
    	//this.canales[139] -> canal 140    	
    }
    
    /**
     * pre: - 
     *
     * @throws: da error si el canal no es valido
     * post: Baja de canal
     */
    public void bajarCanal() throws Exception {
    	if (this.canalActual.getNumero() <= 1) {
    		establecerCanal(this.canales[getCantidadDeCanales() - 1]);
    	} else {
    		establecerCanal(this.canales[this.canalActual.getNumero() - 2]);
    	}
    }
    
    /**
     * pre: - 
     *
     * @param canal: no debe ser vacio, debe estar entre el canal 1 y cantidadCanales
     * @throws Exception Cuando el numero del canal es invalido
     * 
     * post: Cambia de canal al indicado como parametro
     */
    public void establecerCanal(Canal canal) throws Exception {
        verificarCanal(canal);
        canal.setVolumen( this.canalActual.getVolumen() );
        this.canalActual = canal;
    }
    
    /**
     * 
     * @param numeroDeCanal
     * @throws Exception
     */
    public void establecerCanal(int numeroDeCanal) throws Exception {
    	verificarNumeroDeCanal(numeroDeCanal);
    	establecerCanal(this.canales[numeroDeCanal]);
    }
    
    /**
     * pre: - post: -
     *
     * @param canal, verifica que sea válido (mayor a 0, menor al máximo)
     * @throws Exception
     */
    private void verificarCanal(Canal canal) throws Exception {
        if (canal == null) {
            throw new Exception("Canal no puede ser vacio");
        }

    }
    
    /**
     * 
     * @param numeroDeCanal: -
     * @throws Exception: da error si el numero no esta entre 1 y cantidad de canales
     */
    private void verificarNumeroDeCanal(int numeroDeCanal) throws Exception {
        if (numeroDeCanal <= 0) {
        	throw new Exception("El canal tiene un numero invalido");
        }
        if (numeroDeCanal > getCantidadDeCanales()) {
        	throw new Exception("El canal debe estar entre 1 y " + this.getCantidadDeCanales());
        }
    }
    
    /**
     * pre: - 
     *
     * @throws Exception Cuando el volumen ya es el maximo (100)
     * post: Sube en 1 el volumen actual
     */
    public void subirVolumen() throws Exception {
    	establecerVolumen(this.canalActual.getVolumen() + 1);
    }
    
    /**
     * pre: - 
     *
     * @throws Exception Cuando el volumen ya es el minimo (0)
     * post: Baja en 1 l volumen actual
     */
    public void bajarVolumen() throws Exception {
    	establecerVolumen(this.canalActual.getVolumen() - 1);
    }
    
    /**
     * pre: - 
     *
     * @param volumen: El volumen al que se desea cambiar. Entre 0 y 100,
     * inclusivo.
     * @throws Exception Cuando el volumen está fuera del rango dado
     * post: Cambia el volumen actual al volumen dado
     */
    private void establecerVolumen(int volumen) throws Exception {        
        this.canalActual.setVolumen(volumen);
        this.estado = EstadoDeTelevisor.NORMAL;
    }
    
    /**
     * pre: -
     * @return: devuelve verdadero si esta silenciado o falso en caso contrario
     */
    public boolean estaSilenciado() {
    	return this.estado == EstadoDeTelevisor.SILENCIADO;
    }
    
    /**
     * pre: -
     * post: Mutea o desmutea el televisor dependiendo de su estado 
     *       anterior
     */
    public void silenciar() {
    	this.estado = EstadoDeTelevisor.SILENCIADO;
    }
    
    /**
     * pre: -
     * post: Mutea o desmutea el televisor dependiendo de su estado 
     *       anterior
     */
    public void dessilenciar() {
    	this.estado = EstadoDeTelevisor.NORMAL;
    }
    
    /**
     * pre: -
     * post: Mutea o desmutea el televisor dependiendo de su estado 
     *       anterior
     */
    public void invertirSilenciado() {
    	if (estaSilenciado()) {
    		this.estado = EstadoDeTelevisor.NORMAL;
    	} else {
    		this.estado = EstadoDeTelevisor.SILENCIADO;
    	}
    }
    
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
    
    /**
     * pre: -
     * @return: devuelve la cantidad de canales actuales
     */
    public int getCantidadDeCanales() {
    	return this.canales.length;
    }
    
    /**
     * pre: - post: Devuelve una copia del canal actual
     *
     * @return Una copia del canal actual
     */
    public Canal getCanalActual() {
        return this.canalActual;
    }

    /**
     * pre: - 
     *
     * @return devuelve el valor actual del volumen
     */
    public int getVolumen() {
        if (estaSilenciado()) {
            return 0;
        }
        return this.canalActual.getVolumen();
    }
    
    /**
     * pre - 
     * @param numeroDeCanal: debe estar entre 1 y cantidad de canales
     * @return: devuelve el canal
     * @throws Exception: da error si el numero de canal no esta en rango
     */
    public Canal getCanal(int numeroDeCanal) throws Exception {
    	if ((numeroDeCanal <=1) ||
    	   (numeroDeCanal > getCantidadDeCanales())) {
    		throw new Exception("El numero de canal debe estar entre 1 y " + this.getCantidadDeCanales());
    	}
        return this.canales[numeroDeCanal-1];
    }
    
    /**
     * pre: -
     * @return: devuelve el canal con volumen maximo
     */
    public Canal getCanalConMayorVolumen() {
    	Canal resultado = this.canales[0];
    	for(int i = 1; i < this.getCantidadDeCanales(); i++) {
    		if (resultado.getVolumenMaximo() < this.canales[i].getVolumenMaximo()) {
    			resultado = this.canales[i];
    		}
    	}
    	return resultado;
    }
    
//SETTERS SIMPLES -----------------------------------------------------------------------------------------
}