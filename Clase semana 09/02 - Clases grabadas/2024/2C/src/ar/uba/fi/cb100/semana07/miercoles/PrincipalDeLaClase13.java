package ar.uba.fi.cb100.semana07.miercoles;

public class PrincipalDeLaClase13 {

	public static void main(String[] args) throws Exception {
		Vector<Animal> granja = new Vector<Animal>(10, null);
		granja.agregar(new Perro().validar());
		
		Lista<Animal> lista = new Lista<Animal>();
		lista.agregar(new Perro());
		lista.agregar(new Perro());
		lista.agregar(new Perro());
		lista.agregar(2, new Perro());
		
		lista.iniciarCursor();
		while (lista.avanzarCursor()) {
			System.out.println("El animal es: " + lista.obtenerCursor().getEdad());
		}
		
		lista.remover(2);
		
		Animal animal = new Perro();
		animal.hacerSonido();
		animal.imprimir();
	}
}
