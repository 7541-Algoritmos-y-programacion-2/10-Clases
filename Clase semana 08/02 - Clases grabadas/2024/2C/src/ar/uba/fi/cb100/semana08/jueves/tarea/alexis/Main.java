package ar.uba.fi.cb100.semana08.jueves.tarea.alexis;


import ar.uba.fi.cb100.semana07.miercoles.Lista;

public class Main {

	public static void main(String[] args) throws Exception {
		Tablero<Ficha> tablero = new  Tablero<Ficha>(3,3);
		tablero.agregar(2,2, new Ficha('O'));
		tablero.agregar(3, 3, new Ficha('O'));
		tablero.agregar(1, 1, new Ficha('O'));
		
		for(int i = 1; i<=tablero.getAncho();i++) {
			for(int j= 1; j<=tablero.getAlto();j++) {
				Casillero<Ficha> casillero = tablero.getCasillero(i, j);
				System.out.println("Es el " + casillero);
				if(casillero.estaOcupado()) {
					System.out.println("Esta ocupado por " + casillero.getDato().getSimbolo());
				}
			}
		}
		System.out.println("Los casilleros vecinos del (1,1) son : ");
		Lista<Casillero<Ficha>> vecinos = null; //tablero.getCasillero(1, 1).getvecinos();
		vecinos.iniciarCursor();
		while(vecinos.avanzarCursor()) {
			System.out.println(vecinos.obtenerCursor());
		}
		
	}

}
