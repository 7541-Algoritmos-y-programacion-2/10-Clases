package ar.uba.fi.cb100.semana03.jueves;

public class Rectangulo {

	private double base = 1;
	private double altura = 1;
	
	/**
	 * pre: -
	 * pos: crea un rectaungulo de 1mm de base por 1 mm de alto
	 */	
	public Rectangulo() {}

	/**
	 * pre: base y altura deben ser mayores a 0mm
	 * pos: crea un rectaungulo de base mm de base por altura mm de alto
	 * @throws Exception 
	 */	
	public Rectangulo(int base, int altura) throws Exception {
		this.validarMedida(base);
		this.validarMedida(altura);
		this.base = base;
		this.altura = altura;
	}

	/**
	 * pre: -
	 * @return devuelve el perimetro del rectanculo en mm (base * 2 + altura * 2)
	 */
	public double calcularPerimetro() {
		return this.base * 2 + this.altura * 2;
	}
	
	/**
	 * pre: -
	 * @return devuelve el area del rectangulo en mm2 (base * altura)
	 */
	public double calcularArea() {
		return this.base * this.altura;
	}
	
	/**
	 * pre: -
	 * @return devuelve la base del rectangulo en mm
	 */
	public double getBase() {
		return this.base;
	}

	/**
	 * pre: -
	 * @return devuelve la altura del rectangulo en mm
	 */
	public double getAltura() {
		return this.altura;
	}

	/**
	 * pre: la base debe ser mayor a 0mm
	 * pos: cambia la base del rectangulo o tira excepcion si no es mayor a 0mm
	 * @throws Exception 
	 */
	public void setBase(double base) throws Exception {
		this.validarMedida(base);		
		this.base = base;
	}

	/**
	 * pre: la altura debe ser mayor a 0mm
	 * pos: cambia la altura del rectangulo o tira excepcion si no es mayor a 0mm
	 * @throws Exception 
	 */
	public void setAltura(double altura) throws Exception {
		this.validarMedida(altura);	
		this.altura = altura;
	}
	
	/**
	 * pre: -
	 * pos: valida que la medida sea mayor a 0mm o tira excepcion en caso contrario
	 * @throws Exception 
	 */
	private void validarMedida(double medida) throws Exception {
		if (medida <= 0) {
			throw new Exception("La medida debe ser mayor a 0mm");
		}		
	}
	
	
}
