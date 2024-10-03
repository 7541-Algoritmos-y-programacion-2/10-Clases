package ar.uba.fi.cb100.semana05.jueves.tarea.timebombv2;

public class Televisor {

    // Atributos -------------------------------------------------------------------------------------------------------
    private Canal[] canales = null;
    private int volumenActual = 0;
    private int canalActual = 1; // El profesor sugiere utilizar un puntero al canal, pero no rompería con la encapsulación? ~Gacitua
    private boolean silenciado = false; // El profesor sugiere un enum, pero creería que un boolean es mejor ~Gacitua
    private final int VOLUMEN_MAXIMO_POSIBLE = 100;

    /**
     * pre: - post: Devuelve un televisor con cantidadCanales inicializados, con
     * volumen actual en 0, canal actual en 1 y no silenciado
     *
     * @param cantidadCanales, un valor entero
     * @throws Exception si el valor dado como parametro es 0 o negativo
     */
    public Televisor(int cantidadCanales) throws Exception {
        if (!(Tools.revisarPositivoEstricto(cantidadCanales))) {
            throw new Exception("Cantidad de canales invalido");
        }
        this.canales = new Canal[cantidadCanales];
        for (int i = 0; i < cantidadCanales; i++) {
            this.canales[i] = new Canal(i + 1); // + 1 para que sea empezando en 1 el NUMERO del canal
        }
    }

    /**
     * pre: - post: Sube de canal
     *
     * @throws Exception Cuando el canal es mayor a cantidadCanales establecido
     * al crear el objeto
     */
    public void canalSubir() throws Exception {
        canalEstablecer(canalActual + 1);
    }

    /**
     * pre: - post: Baja de canal
     *
     * @throws Exception Cuando el canal ya es el minimo posible (1)
     */
    public void canalBajar() throws Exception {
        canalEstablecer(canalActual - 1);
    }

    /**
     * pre: - post: Cambia de canal al indicado como parametro
     *
     * @param canal, El canal al que se desea cambiar. Entre 1 y cantidadCanales
     * establecido al crear el objeto (Inclusivo)
     * @throws Exception Cuando el numero del canal es invalido
     */
    public void canalEstablecer(int canal) throws Exception {
        verificarValidezCanal(canal);
        this.canalActual = canal;
        canales[canal - 1].volumenActualEstablecer(volumenActual);
    }

    /**
     * pre: - post: Sube en 1 el volumen actual
     *
     * @throws Exception Cuando el volumen ya es el maximo (100)
     */
    public void volumenSubir() throws Exception {
        volumenEstablecer(volumenActual + 1);
    }

    /**
     * pre: - post: Baja en 1 l volumen actual
     *
     * @throws Exception Cuando el volumen ya es el minimo (0)
     */
    public void volumenBajar() throws Exception {
        volumenEstablecer(volumenActual - 1);
    }

    /**
     * pre: - post: Cambia el volumen actual al volumen dado
     *
     * @param volumen, El volumen al que se desea cambiar. Entre 0 y 100,
     * inclusivo.
     * @throws Exception Cuando el volumen está fuera del rango dado
     */
    private void volumenEstablecer(int volumen) throws Exception {
        if (silenciado) {
            silenciado = false; // Desmutea
        }
        if (this.volumenActual > 0 || this.volumenActual < VOLUMEN_MAXIMO_POSIBLE) {
            this.volumenActual = volumen;
            canales[canalActual - 1].volumenActualEstablecer(volumenActual);
        } else {
            throw new Exception("El volumen dado no es válido");
        }
    }

    /**
     * pre: - post: Mutea o desmutea el televisor dependiendo de su estado
     * anterior
     */
    public void silencioAlternar() {
        this.silenciado = !this.silenciado;
    }

    /**
     * pre: - post: Devuelve un boolean indicando si el televisor esta
     * silenciado o no
     *
     * @return un booleando true or false
     */
    public boolean silencioObtener() {
        return this.silenciado;
    }

    /**
     * pre: - post: Devuelve una copia del canal actual
     *
     * @return Una copia del canal actual
     */
    public Canal canalActualObtener() {
        Canal canalDevolver = null;
        try {
            canalDevolver = canalObtener(canalActual);
        } catch (Exception e) {
            // No debería suceder nunca
        }
        return canalDevolver;
    }

    /**
     * pre: - post: Devuelve el valor del canal actual
     *
     * @return Un entero que representa el canal actual
     */
    public int canalActualObtenerIndice() {
        return this.canalActual;
    }

    /**
     * pre: - post: -
     *
     * @return devuelve el valor actual del volumen
     */
    public int volumenActualObtener() {
        if (silenciado) {
            return 0;
        }
        return this.volumenActual;
    }

    /**
     * pre: - post: Devuelve una copia del canal que registro el mayor volumen
     *
     * @return una copia del canal que registró el mayor volumen registrado
     */
    public Canal canalDeVolumenMaximoObtener() {
        int maximoEncontrado = 0;
        for (int i = 0; i < this.canales.length; i++) {
            if (this.canales[i].volumenMaximoObtener() > this.canales[maximoEncontrado].volumenMaximoObtener()) {
                maximoEncontrado = i;
            }
        }
        Canal canalDevolver = null;
        try {
            canalDevolver = canalObtener(maximoEncontrado + 1);
        } catch (Exception e) {
            // No debería devolver nunca excepcion
        }
        return canalDevolver;
    }

    /**
     * pre: -
     *
     * @param canal, el numero de canal que se quiere saber el mayor volumen
     * registrado
     * @return un entero
     * @throws Exception
     */
    public int canalObtenerVolumenMaximo(int canal) throws Exception {
        verificarValidezCanal(canal);
        return this.canales[canal - 1].volumenMaximoObtener();
    }

    /**
     * pre: - post: -
     *
     * @param canal, verifica que sea válido (mayor a 0, menor al máximo)
     * @throws Exception
     */
    private void verificarValidezCanal(int canal) throws Exception {
        if (canal < 1 || canal > this.canales.length) {
            throw new Exception("Canal debe estar entre 1 y " + this.canales.length);
        }
    }

    /**
     * pre: - post: - Devuelve una copia del canal en posición
     *
     * @return Una copia del canal en la posición dada
     */
    public Canal canalObtener(int numero) throws Exception {
        if (!(numero > this.canales.length)) {
            Canal canalDevolver = new Canal(numero);
            canalDevolver.volumenActualEstablecer(this.canales[numero - 1].volumenActualObtener());
            canalDevolver.volumenMaximoEstablecer(this.canales[numero - 1].volumenMaximoObtener());
            return canalDevolver;
        } else {
            throw new Exception("El canal dado no existe");
        }
    }
}
