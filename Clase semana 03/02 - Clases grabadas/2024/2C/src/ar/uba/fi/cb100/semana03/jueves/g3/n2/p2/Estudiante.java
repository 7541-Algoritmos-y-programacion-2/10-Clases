package ar.uba.fi.cb100.semana03.jueves.g3.n2.p2;

public class Estudiante {
	
	private final static int CantidadMaximaDeCursos = 4;
	
	private String nombre = null;
	private int padron = 0;
	private Curso[] cursos = null;
	
	/**
	 * pre:
	 * @param nombre: no puede estar vacio
	 * @param padron: debe ser mayor a 0
	 * 
	 * pos: crea un estudiante con el nombre y padron dado y sin cursos. O tira error si los datos no son validos
	 * @throws Exception 
	 */
	public Estudiante(String nombre, int padron) throws Exception {
		if (Herramientas.estaVacio(nombre)) {
			throw new Exception("El nombre no puede estar vacio");
		}
		if (!Herramientas.esPositivo(0)) {
			throw new Exception("El padron no puede ser 0 o menor");
		}
		this.nombre = nombre;
		this.padron = padron;
		this.cursos = new Curso[CantidadMaximaDeCursos];
		for(int i = 0; i < this.cursos.length; i++) {
			this.cursos[i] = null;
		}
	}

	/**
	 * pre: -
	 * pos: imprime en pantalla los cursos
	 */
	public Curso[] listarCursos() {
		Curso[] resultado = new Curso[this.cursos.length];
		for(int i = 0; i < this.cursos.length ; i++) {
			resultado[i] = this.cursos[i];
		}
		return resultado;
	}
	
	public void inscribir(Curso curso) throws Exception {
		if (curso == null) {
			throw new Exception("El curso no puede ser vacio");
		}
		for(int i = 0; i < this.cursos.length; i++) {
			if (this.cursos[i] == null) {
				this.cursos[i] = curso;
				return;
			}
		}
		throw new Exception("No hay mas lugar para cursos");
	}
	
	/**
	 * pre
	 * @param estudiante: -
	 * @return devuelve verdadero si el estudiante tiene el mismo padron o falso en caso contrario
	 */
	public boolean esIgual(Estudiante estudiante) {
		if (estudiante == null) {
			return false;
		}
		return this.padron == estudiante.getPadron();
	}
	
	/**
	 * pre: -
	 * @return devuelve la cantidad de cursos en que el alumno esta inscripto
	 */
	public int getCantidadDeCursosInscriptos() {
		for(int i = 0; i < this.cursos.length; i++) {
			if (this.cursos[i] == null) {
				return i;
			}
		}
		return this.cursos.length;
	}
	
	/**
	 * pre: -
	 * @return devuelve la cantidad de cursos que le restan libres para poder inscribirse
	 */
	public int getCantidadDeCursosLibre() {
		return this.cursos.length - getCantidadDeCursosInscriptos();
	}
	
	/**
	 * 
	 * @return
	 */
	public String getNombre() {
		return nombre;
	}

	/**
	 * pre: -
	 * @return devuelve el padron del estudiante
	 */
	public int getPadron() {
		return padron;
	}
}
