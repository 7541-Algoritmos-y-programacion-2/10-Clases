package ar.uba.fi.cb100.semana06.miercoles;

public class ValidacionesUtiles {


    /**
     * pre: - 
     * @param value: cualquier entero
     * @return booleano: devuelve verdadero si el numero es mayor o igual a 0
     */
    public static boolean esPositivoOCero(Integer value) {
    	if ((value == null) ||
    	    (value < 0)) {
    		return false;
    	}
        return true;
    }

    /**
     * pre: - 
     * @param value: cualquier entero
     * @return booleano: devuelve verdadero si el numero es mayor a 0
     */
    public static boolean esPositivo(int value) {
        return value > 0;
    }
}
