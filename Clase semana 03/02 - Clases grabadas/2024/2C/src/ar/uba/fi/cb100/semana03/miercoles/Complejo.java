package ar.uba.fi.cb100.semana03.miercoles;

public class Complejo {

	private double parteReal;
	private double parteImaginaria;

	public Complejo() {
		this.parteReal = 0;
		this.parteImaginaria = 0;
	}
	
	public Complejo(double parteReal) {
		this.parteReal = parteReal;
		this.parteImaginaria = 0;
	}
	
	public Complejo(String parteReal) {
		this.parteReal = Double.valueOf(parteReal);
		this.parteImaginaria = 0;
	}
	
	public Complejo(double parteReal, double parteImaginaria) {		
		this.parteReal = parteReal;
		this.parteImaginaria = parteImaginaria;
	}
	
	public double getParteReal() {
		return parteReal;
	}
	
	public void setParteReal(double parteReal) {
		this.parteReal = parteReal;
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
		return new Complejo(this.parteReal + complejo.getParteReal(), this.parteImaginaria + complejo.getParteImaginaria());
	}
	
	/**
	 * pre: no hay  
	 * @param parteReal valor a sumar
	 * @return devuelve la suma del complejo actual mas la parte real. La parte imaginaria queda como esta. 
	 */
	public Complejo sumar(double parteReal) {
		return new Complejo(this.parteReal + parteReal, this.parteImaginaria);
	}

}
