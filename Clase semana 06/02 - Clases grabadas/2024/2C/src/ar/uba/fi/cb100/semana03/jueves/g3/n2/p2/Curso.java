package ar.uba.fi.cb100.semana03.jueves.g3.n2.p2;

public class Curso {

	private String nombre = null;
	private int cupo = 0;
	private Estudiante[] estudiantes = null;
	
	/**
	 * pre:
	 * @param nombre: no puede ser vacio
	 * @param cupo: debe ser mayor a 0
	 * @throws Exception: si los parametros no validan, tira excepcion
	 * 
	 * crea un curso con los parametros dados y la cantidad maxima de estudiante en cupo
	 */
	public Curso(String nombre, int cupo) throws Exception {
		this.setNombre(nombre);
		this.setCupo(cupo);
		this.estudiantes = new Estudiante[cupo];
		for(int i = 0; i < this.estudiantes.length; i++) {
			this.estudiantes[i] = null;
		}
	}
	
	/**
	 * pre:
	 * @param estudiante: no puede ser vacio
	 * @throws Exception valida el estudiante que no sea vacio, que no este ya inscripto, que tenga cursos libres
	 *                   y que el curso tenga cupo
	 */
	public void inscribir(Estudiante estudiante) throws Exception {
		if (estudiante == null) {
			throw new Exception("El estudiante no puede ser vacio");
		}
		for(int i = 0; i < this.estudiantes.length; i++) {			
			if (this.estudiantes[i] == null) {
				if (estudiante.getCantidadDeCursosLibre() <= 0) {
					throw new Exception("El estudiante ya no tiene cursos libres para ser inscripto");
				}
				this.estudiantes[i] = estudiante;
				estudiante.inscribir(this);
			} else {
				if (this.estudiantes[i].esIgual(estudiante)) {
					throw new Exception("El estudiante ya esta inscripto");
				}
			}
		}
		throw new Exception("No hay cupo");
	}
	
	/**
	 * 
	 * @return
	 */
	public String getNombre() {
		return nombre;
	}
	
	/**
	 * 
	 * @return
	 */
	public int getCupo() {
		return cupo;
	}
	
	/**
	 * 
	 * @return
	 */
	public Estudiante[] getEstudiantes() {
		return estudiantes;
	}
	
	/**
	 * 
	 * @param nombre
	 * @throws Exception 
	 */
	public void setNombre(String nombre) throws Exception {
		if (Herramientas.estaVacio(nombre)) {
			throw new Exception("El nombre no puede ser vacio");
		}
		this.nombre = nombre;
	}
	
	/**
	 * 
	 * @param cupo
	 * @throws Exception 
	 */
	public void setCupo(int cupo) throws Exception {
		if (!Herramientas.esPositivo(cupo)) {
			throw new Exception("No puede ser menor a 1");
		}
		if (cupo <= this.estudiantes.length) {
			throw new Exception("No puede ser menor a la cantidad de estudiantes " + this.estudiantes.length);
		}
		Estudiante[] estudiantesTemporal = new Estudiante[cupo];
		for(int i = 0; i < cupo; i++) {
			estudiantesTemporal[i] = this.estudiantes[i];
		}
		this.estudiantes = estudiantesTemporal;
		this.cupo = cupo;
	}
	
	/**
	 * 
	 * @param estudiantes
	 */
	public void setEstudiantes(Estudiante[] estudiantes) {
		this.estudiantes = estudiantes;
	}
	
	
	
	
}
