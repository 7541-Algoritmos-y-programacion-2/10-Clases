package ar.uba.fi.cb100.semana06.miercoles;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;



public class TesteoDeTelevisor {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	
	private final int CANTIDAD_MAXIMA_DE_CANALES = 140;
	
//ATRIBUTOS -----------------------------------------------------------------------------------------------

	private Televisor televisor = null;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
	
    @BeforeEach
    public void inicializarTelevisor() throws Exception {
        //crea un televisor con 140 canales
        televisor = new Televisor(CANTIDAD_MAXIMA_DE_CANALES);
    }
    
    @Test
    public void testeoCanalYVolumen() throws Exception {
        //prueba setear un canal e ir subiendo y bajando de canal y volumen
        televisor.establecerCanal(4);
        assertEquals(4, televisor.getCanalActual().getNumero());  //(int esperado, int que te da el programa)
        assertEquals(0, televisor.getVolumen());

        for (int i = 0; i < 50; i++) {
            televisor.subirVolumen();
        }
        assertEquals(50, televisor.getVolumen());

        for (int i = 0; i < 12; i++) {
            televisor.subirCanal();
            televisor.bajarVolumen();
        }
        assertEquals(16, televisor.getCanalActual().getNumero());
        assertEquals(38, televisor.getVolumen());
        
    }

    @Test
    public void testeoSilenciar() {
        //prueba el silenciar el televisor
        televisor.silenciar();
        assertTrue(televisor.estaSilenciado()); //acá está silenciado
        televisor.invertirSilenciado();
        assertFalse(televisor.estaSilenciado()); //acá no está silenciado
    }

    @Test
    public void testeoCambioDeCanal() throws Exception {
        //más pruebas con bucles
        for (int i = 0; i < 100; i++) {
            televisor.subirCanal();
        }
        while (televisor.getCanalActual().getNumero() > 99) {
            televisor.bajarCanal();
        }
        
        assertEquals(99, televisor.getCanalActual().getNumero(), "No anda bien al subir o bajar el canal");
    }

    @Test
    public void testeoExcepciones() {
		Assertions.assertThrows(Exception.class, ()-> {
			televisor.establecerCanal( televisor.getCantidadDeCanales() + 1);
		}, "No valido irse de rango con el numero de canal");

		Assertions.assertThrows(Exception.class, ()-> {
            for (int i = 0; i < 300; i++) {
                televisor.subirVolumen();
            }
		}, "No valido irse de rango con el volumen");


		Assertions.assertThrows(Exception.class, ()-> {
            for (int i = 0; i < 300; i++) {
                televisor.bajarVolumen();
            }
		}, "No valido irse de rango con el volumen");
    }
    
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
//SETTERS SIMPLES -----------------------------------------------------------------------------------------
}
