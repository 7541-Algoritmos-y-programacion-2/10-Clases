package ar.uba.fi.cb100.semana09.jueves.consultas.alexis;

import ar.uba.fi.cb100.semana08.jueves.tarea.franco.Casillero;
import ar.uba.fi.cb100.semana08.jueves.tarea.franco.Direccion;
import ar.uba.fi.cb100.semana08.jueves.tarea.franco.Ficha;
import ar.uba.fi.cb100.semana08.jueves.tarea.franco.Movimiento;
import ar.uba.fi.cb100.semana08.jueves.tarea.franco.Tablero;

public class Tateti {
	//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	//ATRIBUTOS -----------------------------------------------------------------------------------------------

	private Tablero<Ficha> tablero = null;
	//demas cosas, jugadores, cartas, etc

	//CONSTRUCTORES -------------------------------------------------------------------------------------------

	public Tateti() throws Exception {
		this.tablero = new Tablero<Ficha>(3, 3);

		//new Ficha("X");
		//new Ficha("X");
		//new Ficha("X");
	}

	//METODOS DE CLASE ----------------------------------------------------------------------------------------
	//METODOS GENERALES ---------------------------------------------------------------------------------------
	//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------

	/**
	 * pre: 
	 * @param ficha: indica la ficha a mover
	 * @param movimiento: indica el movimiento a realizar
	 * @throws Exception: si no se puede mover, da error 
	 *  mueve la ficha de una posicion a otra, quedando el casillero vacio en el origen y la ficha en el 
	 *   casillero destino
	 */
	public void mover(Ficha ficha, Movimiento movimiento) throws Exception {
		Casillero<Ficha> casillero = this.tablero.getCasillero(ficha);
		if (!casillero.existeElVecino(movimiento)) {
			throw new Exception("No existe el movimiento");
		}
		if (casillero.getCasilleroVecino(movimiento).estaOcupado()) {
			throw new Exception("No existe el movimiento");
		}
		this.tablero.mover(casillero, casillero.getCasilleroVecino(movimiento), ficha);
		verificarGanador(casillero.getCasilleroVecino(movimiento));
	}

	public void verificarGanador(Casillero<Ficha> casillero) throws Exception {
		//validar
		int cantidadFichas = 3; //longitud del tateti


		//suponemos direccion horizontal                           // casillero de la izquierda                                                                //casillero de la derecha
		int cantidadDeFichasSeguidas = contarFichasSeguidas(casillero, Direccion.ARRIBA, casillero.getDato()) + 
										contarFichasSeguidas(casillero, Direccion.ABAJO, casillero.getDato());
		if(cantidadDeFichasSeguidas >= cantidadFichas) {
			//hay ganador
		}

		cantidadDeFichasSeguidas = contarFichasSeguidas(casillero, Direccion.IZQUIERDA, casillero.getDato()) + 
									contarFichasSeguidas(casillero, Direccion.DERECHA, casillero.getDato());
		if(cantidadDeFichasSeguidas >= cantidadFichas) {
			//hay ganador
		}

		cantidadDeFichasSeguidas = contarFichasSeguidas(casillero, Direccion.IZQUIERDA_ARRIBA, casillero.getDato()) + 
									contarFichasSeguidas(casillero, Direccion.DERECHA_ABAJO, casillero.getDato());
		if(cantidadDeFichasSeguidas >= cantidadFichas) {
			//hay ganador
		}
		cantidadDeFichasSeguidas = contarFichasSeguidas(casillero, Direccion.IZQUIERDA_ABAJO, casillero.getDato()) + 
									contarFichasSeguidas(casillero, Direccion.DERECHA_ARRIBA, casillero.getDato());
		if(cantidadDeFichasSeguidas >= cantidadFichas) {
			//	hay ganador
		}
	}

	public int contarFichasSeguidas(Casillero<Ficha> casillero, Direccion direccion, Ficha ficha) throws Exception {
		if(casillero == null) {
			return 0;
		}
		if(!casillero.getDato().esElMismoSimbolo(ficha)) {
			return 0;
		}
		return 1 + contarFichasSeguidas(casillero.getCasilleroVecino(direccion), direccion, ficha);
	}

	//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
}
