package ar.uba.fi.cb100.semana07.miercoles;

public class Perro extends Animal {

	public Perro() {}
	
	@Override
	public void hacerSonido() {
		System.out.println("El perro ladra");
	}
	
	
	public static void main(String[] args) {
		Animal animal = new Animal();
		animal.setEdad(8);
		animal.hacerSonido(); //"Cada animal hace su propio sonido"
		
		Perro perro = new Perro();
		perro.setEdad(10);
		perro.hacerSonido(); //"El perro ladra"
		
		Animal animalPerro = new Perro();
		animalPerro.setEdad(15);
		animalPerro.hacerSonido();//"El perro ladra"
	}
}
