package ar.uba.fi.cb100.semana09.miercoles.tarea.abel;

public class Comentario {
	private int calificacion;
	private String contenido;
	
	public Comentario(String contenido) {
	this.contenido=contenido;	
	}
	
	public String getContenido() {
		return this.contenido;
	}
	
	public int getCalificacion() {
		return this.calificacion;
	}
	
	public void calificar(int calificar) {
		this.calificacion=calificar;
	}

	/*
	 * pre: -
	 * post: devuelve verdadero si el comentario fue calificado
	 */
	public boolean estaCalificado() {
		return this.calificacion > 0;
	}
	
}
