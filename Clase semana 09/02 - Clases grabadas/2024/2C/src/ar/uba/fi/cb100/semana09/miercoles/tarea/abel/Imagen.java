package ar.uba.fi.cb100.semana09.miercoles.tarea.abel;

import ar.uba.fi.cb100.semana07.miercoles.Lista;

public class Imagen {
	private String url;
	private Lista<Comentario> comentarios;
	private Double promedio = null;
	
	public Imagen(String url) {
	this.url=url;	
	}
	
	public String getUrl() {
		return this.url;
	}
	
	public Lista<Comentario> obtenerComentarios() {
		return this.comentarios;
	}
	
	/**
	 * pre: -
	 * @return devuelve una copia de la lista de comentarios con los comentarios calificados
	 * @throws Exception 
	 */
	public Lista<Comentario> obtenerComentariosCalificados() throws Exception {
		Lista<Comentario> resultado = new Lista<Comentario>();
		obtenerComentarios().iniciarCursor();
		while (obtenerComentarios().avanzarCursor()) {
			if (obtenerComentarios().obtenerCursor().estaCalificado()) {
				resultado.agregar(obtenerComentarios().obtenerCursor());
			}
		}
		return resultado;
	}
	
	/**
	 * post: Devuelve el promedio de las calificaciones de la lista de comentarios
	 * @param comentarios, Lista de Comentarios
	 * @return double que indica el promedio de la calificacion de los comentarios, sin contar los comentarios sin 	 		
	 *         calificacion o devuelve 0 sino hay comentarios 
	 */
	public double getPromedio() throws Exception {
		if (promedio == null) {
			if (this.obtenerComentariosCalificados().estaVacia()) {
				promedio = 0.0;
			}
			double resultado=0;

			int cantidadComentarios = 0;
			comentarios.iniciarCursor();

			//tengo que ir a cada comentario y buscar su calificacion, y ademas tengo un contador de la cantidad de 			comentarios
			while(comentarios.avanzarCursor()) {
				Comentario comentario =comentarios.obtenerCursor();
				if(comentario.estaCalificado()) {
					resultado += comentario.getCalificacion();
					cantidadComentarios++;
				}
			}

			promedio = resultado / cantidadComentarios;
		}
		return this.promedio;
	}
}
