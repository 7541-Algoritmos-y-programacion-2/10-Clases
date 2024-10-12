package ar.uba.fi.cb100.semana05.jueves.tarea.timebombv2;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;


public class MainTesteo {

	private Televisor televisor;
	private final int CANTIDAD_MAXIMA_DE_CANALES = 140;
	private final int VOLUMEN_MAXIMO = 100;

    @BeforeEach
    public void inicializarTelevisor() throws Exception {
        //crea un televisor con 140 canales
        televisor = new Televisor(CANTIDAD_MAXIMA_DE_CANALES);
    }

    @Test
    public void testeoCanalYVolumen() throws Exception {
        //prueba setear un canal e ir subiendo y bajando de canal y volumen
        televisor.canalEstablecer(4);
        assertEquals(4, televisor.canalActualObtenerIndice());  //(int esperado, int que te da el programa)
        assertEquals(0, televisor.volumenActualObtener());

        for (int i = 0; i < 50; i++) {
            televisor.volumenSubir();
        }
        assertEquals(50, televisor.volumenActualObtener());

        for (int i = 0; i < 12; i++) {
            televisor.canalSubir();
            televisor.volumenBajar();
        }
        assertEquals(16, televisor.canalActualObtenerIndice());
        assertEquals(38, televisor.volumenActualObtener());
    }

    @Test
    public void testeoSilenciar() {
        //prueba el silenciar el televisor
        televisor.silencioAlternar();
        assertTrue(televisor.silencioObtener()); //acá está silenciado
        televisor.silencioAlternar();
        assertFalse(televisor.silencioObtener()); //acá no está silenciado
    }

    @Test
    public void testeoCambioDeCanal() throws Exception {
        //más pruebas con bucles
        for (int i = 0; i < 100; i++) {
            televisor.canalSubir();
        }
        while (televisor.canalActualObtener().numeroObtener() > 99) {
            televisor.canalBajar();
        }
        
        assertEquals(99, televisor.canalActualObtenerIndice());
    }

    @Test
    public void testeoExcepciones() {
        //prueba excepciones
        Exception exception;

        	//intentar un canal inválido
        exception = assertThrows(Exception.class, () -> {
        	televisor.canalEstablecer(1000);
        });
        assertEquals("Canal debe estar entre 1 y " + CANTIDAD_MAXIMA_DE_CANALES, exception.getMessage());

        	//subir demasiadas veces un canal
        exception = assertThrows(Exception.class, () -> {
            for (int i = 0; i < 10000; i++) {
                televisor.canalSubir();
            }
        });
        assertEquals("Canal debe estar entre 1 y " + CANTIDAD_MAXIMA_DE_CANALES, exception.getMessage());

        	//subir el volumen demasiado
        exception = assertThrows(Exception.class, () -> {
            for (int i = 0; i < 300; i++) {
                televisor.volumenSubir();
            }
        });
        assertEquals("Volumen debe estar entre 0 y " + VOLUMEN_MAXIMO, exception.getMessage());

        	//bajar el volumen demasiado
        exception = assertThrows(Exception.class, () -> {
            for (int i = 0; i < 300; i++) {
                televisor.volumenBajar();
            }
        });
        assertEquals("Volumen debe estar entre 0 y " + VOLUMEN_MAXIMO, exception.getMessage());
    }
}