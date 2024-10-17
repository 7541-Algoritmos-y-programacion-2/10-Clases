package ar.uba.fi.cb100.semana09.miercoles.tarea.abel;

import ar.uba.fi.cb100.semana07.miercoles.Lista;

public class Editor {

	/**
	 * pre: 
	 * @param imagenesDisponibles, Lista de imagenes, no puede ser nula
	 * @param cantidadComentarios, numero entero mayor o igual a 0
	 * @return las 5 imagenes con el mayor promedio de calificacion o vacia si no hay ninguna imagen que cumpla con la 			
	 *          cantidad indicada de comentarios
	 * @throws Exception 
	 */
	public Imagen[] selecionarImagenes(Lista<Imagen> imagenesDisponibles, int cantidadComentarios) throws Exception {
		if (imagenesDisponibles == null) {
			throw new Exception("La lista de imagenes no puede ser nula");
		}
		if (cantidadComentarios < 0) {
			throw new Exception("La cantidad de comentarios debe ser 0 o mayor");
		}
		
		Imagen[] imagenesSelecionadas = new Imagen[5];

		imagenesDisponibles.iniciarCursor();

		while(imagenesDisponibles.avanzarCursor()) {

			//Bajo un nivel, paso de tenes N imagenes a tener 1
			Imagen imagenARevisar= imagenesDisponibles.obtenerCursor();

			Lista<Comentario> comentariosARevisar=imagenARevisar.obtenerComentariosCalificados();

			//si cumple que posee la cantidad necesaria de comentarios, hago el promedio
			if(comentariosARevisar.getLongitud() >= cantidadComentarios) {
				imagenesSelecionadas = unificarImagenesConMayoresPromedios(imagenesSelecionadas, imagenARevisar);
			}
		}

		// devuelvo la imagen que tenga el mayor promedio o en caso contrario null
		return imagenesSelecionadas;
	}
	
	/**
	 * 
	 * @param imagenes
	 * @param imagenAIngresar
	 * @return devuelve la mayor cantidad de imagenes con el mayor promedio. Si vienen 6, devuelve 5. Si vienen menos, 
	 *         devuelve todas
	 * @throws Exception
	 */
	public Imagen[] unificarImagenesConMayoresPromedios(Imagen[] imagenes, Imagen imagenAIngresar) throws Exception {
		if (imagenes == null) {
			throw new Exception("El vector no puede ser vacio");
		}
		if (imagenAIngresar == null) {
			return imagenes;
		}
		Imagen[] resultado = new Imagen[5];
		double promedioMinimo = imagenAIngresar.getPromedio();
		for(int i = 0; i < imagenes.length; i++) {
			if ((imagenes[i] != null) &&
			    (imagenes[i].getPromedio() < promedioMinimo)) {
				promedioMinimo = imagenes[i].getPromedio();
			} else {
				promedioMinimo = -1;
			}
		}
		int indice = 0;
		for(int i = 0; i < imagenes.length; i++) {
			if ((imagenes[i] != null) &&
			    (imagenes[i].getPromedio() > promedioMinimo)) {
				resultado[indice++] = imagenes[i];
			}
		}
		if (imagenAIngresar.getPromedio() > promedioMinimo) {
			resultado[indice++] = imagenAIngresar;
		}
		return resultado;
	}

	/**
	 * pre: 
	 * @param imagenesDisponibles, Lista de imagenes, no puede ser nula
	 * @param cantidadComentarios, numero entero mayor o igual a 0
	 * @return una imagen con el mayor promedio de calificacion o null si no hay ninguna imagen que cumpla con la 			
	 * cantidad indicada de comentarios
	 * @throws Exception 
	 */
	public Imagen selecionarImagen(Lista<Imagen> imagenesDisponibles, int cantidadComentarios) throws Exception {
		if (imagenesDisponibles == null) {
			throw new Exception("La lista de imagenes no puede ser nula");
		}
		if (cantidadComentarios < 0) {
			throw new Exception("La cantidad de comentarios debe ser 0 o mayor");
		}
		
		Imagen imagenSelecionada = null;
		double promedioMaximo = 0.0;

		imagenesDisponibles.iniciarCursor();

		while(imagenesDisponibles.avanzarCursor()) {

			//Bajo un nivel, paso de tenes N imagenes a tener 1
			Imagen imagenARevisar= imagenesDisponibles.obtenerCursor();

			Lista<Comentario> comentariosARevisar=imagenARevisar.obtenerComentariosCalificados();

			//si cumple que posee la cantidad necesaria de comentarios, hago el promedio
			if(comentariosARevisar.getLongitud() >= cantidadComentarios) {
				//modularizo
				double promedio = imagenARevisar.getPromedio();

				//si el promedio de la imagen supera al maximo, cambio la imagen que devuelvo como resultado
				if ((imagenSelecionada == null) ||
				    (promedio > promedioMaximo)) {
					promedioMaximo = promedio;
					imagenSelecionada = imagenARevisar;
				}
			}
		}

		// devuelvo la imagen que tenga el mayor promedio o en caso contrario null
		return imagenSelecionada;
	}


}
