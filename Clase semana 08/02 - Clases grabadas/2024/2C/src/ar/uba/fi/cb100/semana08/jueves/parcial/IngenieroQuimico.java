package ar.uba.fi.cb100.semana08.jueves.parcial;

import ar.uba.fi.cb100.semana08.miercoles.estructuras.Lista;
import ar.uba.fi.cb100.semana08.miercoles.estructuras.ListaSimplementeEnlazada;

public class IngenieroQuimico {

	/**
	 * pre: 
	 * @param solucionRequerida
	 * @param solucionesDisponibles
	 * @return busca en soluciones disponibles las soluciones que tenga los mismo compuesto que 
	 *         solucionRequerida con cantidad iguales o superiores pero menores (o igual) al doble
	 * @throws Exception 
	 */
	Lista<Solucion> buscarSolucionesEquivalentes(Solucion solucionRequerida,
			                                     Lista<Solucion> solucionesDisponibles) throws Exception {
		//Completar pre y post
		//validar
		Lista<Solucion> resultado = new ListaSimplementeEnlazada<Solucion>();	
		
		//Recorrido con curso
		solucionesDisponibles.iniciarCursor();
		while (solucionesDisponibles.avanzarCursor()) {
			Solucion solucionesDisponible = solucionesDisponibles.obtenerCursor();
			//condiciones
			if ((solucionesDisponible.getCompuestos().getTamanio() == solucionRequerida.getCompuestos().getTamanio()) &&
			   this.esSolucionEquivalente(solucionRequerida, solucionesDisponible, 1, 2)) {

				//agregar al resultado
				resultado.agregar(solucionesDisponible);
			}
		}
		return resultado;
	}

	
	public boolean esSolucionEquivalente(Solucion solucionRequerida, Solucion solucionesDisponible) {
		return esSolucionEquivalente(solucionRequerida, solucionesDisponible, 1, 1);
	}
	
	/**
	 * pre:
	 * @param solucionRequerida
	 * @param solucionesDisponible
	 * @return
	 */
	public boolean esSolucionEquivalente(Solucion solucionRequerida, Solucion solucionesDisponible, double rangoMenor, double rangoMayor) {
		//validar
		solucionRequerida.getCompuestos().iniciarCursor();
		while( solucionRequerida.getCompuestos().avanzarCursor()) {
			Compuesto compuesto = solucionRequerida.getCompuestos().obtenerCursor();
			if (!this.esCompuestoEquivalente(compuesto, solucionesDisponible.getCompuestos(), rangoMenor, rangoMayor)) {
				return false;
			}
		}
		return true;
	}

	/**
	 * 
	 * @param compuesto
	 * @param compuestos
	 * @return
	 */
	public boolean esCompuestoEquivalente(Compuesto compuesto, Lista<Compuesto> compuestos, double rangoMenor, double rangoMayor) {
		//pre y post
		//validar
		compuestos.iniciarCursor();
		while(compuestos.avanzarCursor()) {
			Compuesto compuestoEquivalente = compuestos.obtenerCursor();
			if (this.esCompuestoEquivalente(compuesto, compuestoEquivalente, rangoMenor, rangoMayor)) {
				return true;
			}
		}
		return false;
	}

	public boolean esCompuestoEquivalente(Compuesto compuesto, Compuesto compuestoEquivalente, double rangoMenor, double rangoMayor) {
		//pre post
		//validar
		if (compuesto.getNombre().equals(compuestoEquivalente.getNombre())) {
			return ((rangoMenor * compuesto.getCantidad() >= compuestoEquivalente.getCantidad()) &&
				 	(rangoMayor * compuesto.getCantidad() <= compuestoEquivalente.getCantidad()));
		}
		return false;
	}
}
