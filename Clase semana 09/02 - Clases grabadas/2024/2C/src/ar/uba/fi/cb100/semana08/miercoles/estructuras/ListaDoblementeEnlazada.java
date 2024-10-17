package ar.uba.fi.cb100.semana08.miercoles.estructuras;

public class ListaDoblementeEnlazada<T> extends Lista<T> {
	//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	//ATRIBUTOS -----------------------------------------------------------------------------------------------

	private NodoDoblementeEnlazado<T> ultimo = null;

	//CONSTRUCTORES -------------------------------------------------------------------------------------------

	/**
	 * pre:
	 * pos: crea una lista vacia
	 */
	public ListaDoblementeEnlazada() {
		super();
		this.ultimo = null;
	}

	//METODOS DE CLASE ----------------------------------------------------------------------------------------
	//METODOS GENERALES ---------------------------------------------------------------------------------------
	//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------

	/**
	 * pre: posición pertenece al intervalo: [1, contarElementos() + 1]
	 * pos: agrega el elemento en la posición indicada.
	 */
	public void agregar(T elemento, int posicion) throws Exception {
		validarPosicion(posicion);
		NodoDoblementeEnlazado<T> nuevo = new NodoDoblementeEnlazado<T>(elemento);
		if (posicion == 1) {
			nuevo.setSiguiente( this.getPrimero());
			this.setPrimero( nuevo );
			if (estaVacia()) {
				this.ultimo = nuevo;
			}
		} else {
			NodoDoblementeEnlazado<T> anterior = (NodoDoblementeEnlazado<T>) this.getNodo(posicion -1);
			nuevo.setSiguiente( anterior.getSiguiente());
			nuevo.setAnterior(anterior);
			anterior.setSiguiente( nuevo );
			if (posicion == getTamanio()) {
				this.ultimo = nuevo;
			}
		}
		this.aumentarTamanio();
	}

	/*
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * post: remueve de la Lista el elemento en la posición indicada.
	 */
	public void remover(int posicion) throws Exception {
		validarPosicion(posicion);
		this.iniciarCursor();
		NodoDoblementeEnlazado<T> removido = null;
		if (posicion == 1) {
			removido = (NodoDoblementeEnlazado<T>) this.getPrimero();
			this.setPrimero(removido.getSiguiente());
			if (getTamanio() == 1) {
				this.ultimo = null;
			}		
		} else {
			NodoDoblementeEnlazado<T> anterior = (NodoDoblementeEnlazado<T>) this.getNodo(posicion -1);
			removido = (NodoDoblementeEnlazado<T>) anterior.getSiguiente();
			anterior.setSiguiente( removido.getSiguiente());
			((NodoDoblementeEnlazado<T>) removido.getSiguiente()).setAnterior(anterior);
		}
		this.disminuirTamanio();
	}

	//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
}

