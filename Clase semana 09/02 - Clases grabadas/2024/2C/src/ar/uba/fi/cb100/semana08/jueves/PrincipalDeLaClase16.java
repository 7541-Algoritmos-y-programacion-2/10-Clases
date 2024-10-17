package ar.uba.fi.cb100.semana08.jueves;

import ar.uba.fi.cb100.semana08.jueves.tarea.franco.Tablero;

public class PrincipalDeLaClase16 {

	public static void main(String[] args) throws Exception {
		
		Tablero<String> tablero = new Tablero<String>(4, 4);
		
		System.out.println(tablero.getCasillero(2, 2));
		System.out.println("Tablero de " + tablero.getAlto() + " x " + tablero.getAncho());
		
		//Tarea:
		//Decir si se puede mover o no en alto o ancho
		//Decir si se formo o no tateti de 3
		//Pasar el tablero a cubo
	}
}
