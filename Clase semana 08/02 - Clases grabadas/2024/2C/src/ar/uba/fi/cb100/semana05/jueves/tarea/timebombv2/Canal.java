package ar.uba.fi.cb100.semana05.jueves.tarea.timebombv2;

public class Canal {

    // Atributos de clase ------------------------------------------------------------------------------
    private int numero = 0;
    private int volumenMaximo = 0;
    private int volumenActual = 0;
    private final int VOLUMEN_MAXIMO_POSIBLE = 100;

    // Constructores -----------------------------------------------------------------------------------
    /**
     * pre: - post: Crea el canal con el numero indicado
     *
     * @param numero, entero que representa el numero del canal
     */
    public Canal(int numero) throws Exception {
        if (!Tools.revisarPositivoEstricto(numero)) {
            throw new Exception("Numero de canal invalido.");
        }
        this.numero = numero;
    }

    // Metodos --------------------------------------------------------------------------------------------------
    /**
     * pre: -
     *
     * @return El valor entero del volumen actual del canal
     */
    public int volumenActualObtener() {
        return volumenActual;
    }

    /**
     * pre : - post: Actualiza el volumen actual del canal. Si es el volumen
     * máximo, también lo actualiza.
     *
     * @param volumenActual, entero que represente el volumen del canal
     * @throws Exception si el volumen es invalido (mayor al maximo o menor a 0)
     */
    public void volumenActualEstablecer(int volumenActual) throws Exception {
        if (!Tools.revisarPositivo(volumenActual) || volumenActual > VOLUMEN_MAXIMO_POSIBLE) {
            throw new Exception("Volumen debe estar entre 0 y " + VOLUMEN_MAXIMO_POSIBLE);
        }
        volumenEstablecer(volumenActual);
    }

    /**
     * pre: -
     *
     * @return Devuelve el numero del canal actual
     */
    public int numeroObtener() {
        return numero;
    }

    /**
     * pre: -
     *
     * @return Devuelve el volumen maximo registrado en este canal
     */
    public int volumenMaximoObtener() {
        return volumenMaximo;
    }

    /**
     * pre: - post: Actualiza el volumen del canal y si es mayor al maximo
     * registrado, tambien lo actualiza
     *
     * @param volumen, entero que represente el volumen
     * @throws Exception si el volumen es invalido (mayor a 100 o menor a 0)
     */
    public void volumenEstablecer(int volumen) throws Exception {
        if (!Tools.revisarPositivo(volumen) || volumen > VOLUMEN_MAXIMO_POSIBLE) {
            throw new Exception("Volumen debe estar entre 0 y " + VOLUMEN_MAXIMO_POSIBLE);
        } else {
            if (volumen > this.volumenMaximo) {
                volumenMaximoEstablecer(volumen);
            }
            this.volumenActual = volumen;
        }
    }

    /**
     * pre: - post: Actualiza el volumen maximo del canal
     *
     *
     * @param volumen, entero que represente el volumen
     * @throws Exception si el volumen es invalido (mayor a 100 o menor a 0)
     */
    public void volumenMaximoEstablecer(int volumen) throws Exception {
        if (!Tools.revisarPositivo(volumen) || volumen > VOLUMEN_MAXIMO_POSIBLE) {
            throw new Exception("Volumen debe estar entre 0 y " + VOLUMEN_MAXIMO_POSIBLE);
        } else {
            this.volumenMaximo = volumen;
        }
    }
}
