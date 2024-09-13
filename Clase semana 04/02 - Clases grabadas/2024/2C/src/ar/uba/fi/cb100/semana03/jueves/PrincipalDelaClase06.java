package ar.uba.fi.cb100.semana03.jueves;

import ar.uba.fi.cb100.semana03.jueves.g3.n2.p2.Curso;
import ar.uba.fi.cb100.semana03.jueves.g3.n2.p2.Estudiante;

public class PrincipalDelaClase06 {

	public static void main(String[] args) throws Exception {
		try {
			Rectangulo rectangulo1 = new Rectangulo();
			rectangulo1.setAltura(150);
			rectangulo1.setBase(100);
			System.out.println("El perimetro es: " + rectangulo1.calcularPerimetro() + "mm");
			System.out.println("El area es: " + rectangulo1.calcularArea() + "mm2");

			Rectangulo rectangulo2 = new Rectangulo(101, 151);
			System.out.println("El perimetro es: " + rectangulo2.calcularPerimetro() + "mm");
			System.out.println("El area es: " + rectangulo2.calcularArea() + "mm2");

			Rectangulo rectangulo3 = new Rectangulo(-1, 151);
			System.out.println("El perimetro es: " + rectangulo3.calcularPerimetro() + "mm");
			System.out.println("El area es: " + rectangulo3.calcularArea() + "mm2");
		} catch (Exception e) {
			System.err.println("Error: " + e.getMessage());
			e.printStackTrace();
		}
		
		
		//Estudiante y curso
		Estudiante estudiante = new Estudiante("Gustavo", 50000);
		
		Curso[] cursos = estudiante.listarCursos();
		for(int i = 0; i < cursos.length ; i++) {
			System.out.println("El curso es: " + cursos[i].getNombre());
		}
		
		Curso curso = new Curso("CB100", 70);
		
		for(int i = 0; i < curso.getEstudiantes().length ; i++) {
			System.out.println("El estudiante es es: " + curso.getEstudiantes()[i].getNombre());
		}
		curso.inscribir(estudiante);
		curso.inscribir(estudiante);
	}

}

