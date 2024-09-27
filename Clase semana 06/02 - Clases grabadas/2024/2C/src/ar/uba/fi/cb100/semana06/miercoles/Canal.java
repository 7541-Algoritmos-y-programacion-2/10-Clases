package ar.uba.fi.cb100.semana06.miercoles;

public class Canal {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	
	public static final int VOLUMEN_MAXIMO_POSIBLE = 100;
	
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
    private int numero = 0;
    private int volumenMaximo = 0;
    private int volumen = 0;
    
//CONSTRUCTORES -------------------------------------------------------------------------------------------

    /**
     * pre: -
     * @param numero, entero que representa el numero del canal. Mayor a 0.
     * post: Crea el canal con el numero indicado
     */
    public Canal(int numero) throws Exception {
        if (!ValidacionesUtiles.esPositivo(numero)) {
            throw new Exception("Numero de canal invalido. Debe ser mayor a 0");
        }
        this.numero = numero;
    }
    
//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
    
    @Override
	public String toString() {
		return "Canal " + this.numero;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Canal other = (Canal) obj;
		return numero == other.numero;
	}
    
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
//GETTERS SIMPLES -----------------------------------------------------------------------------------------

	/**
     * pre: -
     * @return Devuelve el numero del canal
     */
    public int getNumero() {
        return numero;
    }
    
    /**
     * pre: -
     * @return Devuelve el volumen maximo registrado en este canal
     */
    public int getVolumenMaximo() {
        return volumenMaximo;
    }
    
    /**
     * pre: -
     * @return Devuelve el valor del volumen actual
     */
    public int getVolumen() {
        return volumen;
    }
    
//SETTERS SIMPLES -----------------------------------------------------------------------------------------

    /**
     * pre : - 
     * @param volumen: el volumen a cambiar debe estar entre 0 y 100
     * @throws Exception si el volumen no esta en rango.
     * 
     * post: Actualiza el volumen actual del canal. Si es el volumen máximo, 
     *       también lo actualiza.
     */
    public void setVolumen(int volumen) throws Exception {
        if (!ValidacionesUtiles.esPositivo(volumen) || 
           (volumen > Canal.VOLUMEN_MAXIMO_POSIBLE)) {
            throw new Exception("Volumen debe estar entre 0 y " + Canal.VOLUMEN_MAXIMO_POSIBLE);
        }
        if (volumen > this.volumenMaximo) {
        	this.volumenMaximo = volumen;
        }
        this.volumen = volumen;
    }

}