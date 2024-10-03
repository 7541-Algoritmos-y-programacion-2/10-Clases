package ar.uba.fi.cb100.semana03.miercoles;

import ar.uba.fi.cb100.semana04.miercoles.Numero;

public class Complejo extends Numero {
	
	private double parteImaginaria;

	public static Complejo construir(double parteReal, double parteImaginaria) {
		return new Complejo(parteReal, parteImaginaria);
	}
	
	private Complejo() {
		this(0.0, 0.0);
	}

	private Complejo(String parteReal) {
		this(Double.valueOf(parteReal), 0.0);
	}

	/**
	 * pre - 
	 * @param parteReal: cualquier valor flotante
	 * @param parteImaginaria: cualquier valor flotante
	 * 
	 * pos: crea el complejo con la partereal e imaginaria dadas
	 */
	private Complejo(double parteReal, double parteImaginaria) {		
		super(parteReal);
		this.parteImaginaria = parteImaginaria;
	}
	
	/**
	 * pre: -
	 * pos: suma la parte real dada por parametro al objeto actual
	 * @param parteReal valor entera
	 * 
	 * interface: public void sumarParteReal(int parteReal)
	 * nombre del metodo: sumarParteReal
	 * firma: sumarParteReal(int) (una sola por clase)
	 */
	public void sumarParteReal(int parteReal) {
		this.sumarParteReal( parteReal );
	}
	
	public void sumarParteReal(String parteReal) {
		this.sumarParteReal( Double.valueOf(parteReal) );
	}
	
	/**
	 * pre: -
	 * pos: suma la parte real dada por parametro al objeto actual
	 * @param parteReal valor entera
	 * 
	 * interface: public void sumarParteReal(int[] parteReal)
	 * nombre del metodo: sumarParteReal
	 * firma: sumarParteReal(int[]) (una sola por clase)
	 */
	public void sumarParteReal(int ... partesReales) {
		for(int i = 0; i < partesReales.length; i++) {
			this.sumarParteReal( partesReales[i] );
		}
	}
	
	/**
	 * pre: -
	 * post: imprime el complejo
	 */
	@Override
	public void imprimir() {
		System.out.println("El numero complejo es: " + this.getParteReal() + " + " + this.getParteImaginaria() + "i");
	}
	
	public void sumarParteReal(Complejo ... complejos) {
		for(int i = 0; i < complejos.length; i++) {
			this.sumarParteReal( complejos[i] );
		}
	}
	
	public double getParteImaginaria() {
		return parteImaginaria;
	}
	
	public void setParteImaginaria(double parteImaginaria) {
		this.parteImaginaria = parteImaginaria;
	}
	
	/**
	 * pre: complejo no puede ser nulo
	 * post: va a sumar en un nuevo complejo, el complejo actual y complejo por parametro.
	 * @param complejo: valor a sumar
	 * @return
	 * @throws Exception 
	 */
	public Complejo sumar(Complejo complejo) throws Exception {
		if (complejo == null) {
			throw new Exception("El parametro no puede ser nulo");
		}
		return new Complejo(this.getParteReal() + complejo.getParteReal(), this.parteImaginaria + complejo.getParteImaginaria());
	}
	
	@Override
	public void sumar(Numero numero) {
		//hacer la suma		
	}
	
	/**
	 * pre: no hay  
	 * @param parteReal valor a sumar
	 * @return devuelve la suma del complejo actual mas la parte real. La parte imaginaria queda como esta. 
	 */
	public Complejo sumar(double parteReal) {
		return new Complejo(this.getParteReal() + parteReal, this.parteImaginaria);
	}

}
