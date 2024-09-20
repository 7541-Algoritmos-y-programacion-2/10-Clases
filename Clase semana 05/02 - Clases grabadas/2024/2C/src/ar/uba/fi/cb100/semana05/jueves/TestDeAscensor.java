package ar.uba.fi.cb100.semana05.jueves;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import ar.uba.fi.cb100.semana03.miercoles.Complejo;

public class TestDeAscensor {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
//CONSTRUCTORES -------------------------------------------------------------------------------------------
//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------

	/**
	 * 
	 * @throws Exception
	 */
	@Test
	public void testDeAscensor() throws Exception {
		//Testeo el constructor por cantidad de pisos 
		Assertions.assertThrows(Exception.class, ()-> {
			new Ascensor(-1);	
		}, "El constructor no tiro error");
		
		//Creo el ascensor
		Ascensor ascensor = new Ascensor(15);
		int cantidadDePisosMovidos = ascensor.enviarA(5);
		
		//Testo que se movio 5 pisos
		Assertions.assertEquals(5, cantidadDePisosMovidos, "El ascensor no se movio 5 pisos");
		Assertions.assertEquals(5, ascensor.getCantidadDePisosQueSubio(), "El ascensor no subio 5 pisos");

		//Testo moverlo al mismo piso
		Assertions.assertEquals(0, ascensor.enviarA(5), "El ascensor conto mal la cantidad de pisos al moverse");
		//Testo moverlo a un piso por encima del edificio
		Assertions.assertThrows(Exception.class, ()-> {
			ascensor.enviarA(25);	
		}, "El error es incorrecto");

		//Controlo la cantidad de pisos
		Assertions.assertEquals(16, ascensor.getCantidadDePisos(), "El ascensor no guarda la cantidad de pisos");
	}
	
	@Test
	public void testDeComplejo() throws Exception {
		Complejo complejo = Complejo.construir(10, 10);
		Assertions.assertEquals(10, complejo.getParteReal(), "El complejo no guarda la parte imaginaria");
	}
	

	

		
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	

	
}
