package ar.uba.fi.cb100.semana04.miercoles;

public class Fraccion extends Numero {

	private int fraccion = 0;
	
	/**
	 * pre: -
	 * post: imprime en consola el numero 
	 */
	@Override
	public void imprimir() {
		System.out.println("La fraccion es: " + this.getParteReal() + " / " + fraccion);
	}
}
