package ar.uba.fi.cb100.semana07.miercoles;

public abstract class Animal {

	private int edad = 0;
	
	public Animal() {}

	public abstract void hacerSonido();
	
	public Animal validar() {
		//if validado
		return this;
	}

	public void imprimir() {
		System.out.println("El animal tiene " + edad + " años de edad");
	}

	public void imprimir(int edadMaxima) {
		System.out.println("El animal tiene " + this.edad + " años de edad (" + this.edad / edadMaxima + ")");
	}
	
	public int getEdad() {
		return edad;
	}

	public void setEdad(int edad) {
		this.edad = edad;
	}
		
}
