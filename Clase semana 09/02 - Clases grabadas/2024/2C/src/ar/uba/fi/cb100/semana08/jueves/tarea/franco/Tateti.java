package ar.uba.fi.cb100.semana08.jueves.tarea.franco;

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
	}
	
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
}
