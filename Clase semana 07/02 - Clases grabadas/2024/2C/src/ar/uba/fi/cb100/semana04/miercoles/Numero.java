package ar.uba.fi.cb100.semana04.miercoles;

import ar.uba.fi.cb100.semana03.miercoles.Complejo;

public class Numero {

	private double parteReal = 0;
	
	public Numero() {}
	
	/**
	 * pre: -
	 * @param parteReal: cualquier numero flotante
	 * 
	 * post: crear un numero con parte real como parteReal
	 */
	public Numero(double parteReal) {
		this.parteReal = parteReal;
	}
	
	/**
	 * pre: -
	 * pos: suma la parte real dada por parametro al objeto actual
	 * @param parteReal valor flotante
	 * 
	 * interface: public void sumarParteReal(double parteReal)
	 * nombre del metodo: sumarParteReal
	 * firma: sumarParteReal(double) (una sola por clase)
	 */
	public void sumarParteReal(double parteReal) {
		this.parteReal += parteReal;
	}
	
	/**
	 * pre: -
	 * pos: suma la parte real dada por parametro al objeto actual
	 * @param parteReal valor flotante
	 * 
	 * interface: public void sumarParteReal(Complejo complejo)
	 * nombre del metodo: sumarParteReal
	 * firma: sumarParteReal(Complejo) (una sola por clase)
	 */
	public void sumarParteReal(Numero numero) {
		this.sumarParteReal( numero.getParteReal() );
	}
	
	/**
	 * pre: -
	 * post: imprime en consola el numero 
	 */
	public void imprimir() {
		System.out.println("El numero es: " + this.parteReal);
	}
	
	public void sumar(int parteReal) {
		this.parteReal += parteReal;
	}
		
	public double getParteReal() {
		return parteReal;
	}
	
	public void setParteReal(double parteReal) {
		this.parteReal = parteReal;
	}

	public void sumar(Numero numero) {
		//hacer la suma		
	}
}
