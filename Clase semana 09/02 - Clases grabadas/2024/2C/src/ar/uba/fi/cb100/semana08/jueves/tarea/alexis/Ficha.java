package ar.uba.fi.cb100.semana08.jueves.tarea.alexis;

public class Ficha {
//ATRIBUTOS DE CLASE
//ATRIBUTOS
	private char simbolo;
//CONSTRUCTORES
	/**
	 * pre:
	 * @param simbolo deb
	 * e ser un simbolo X mayuscula(X) o la letra O mayuscula(O)
	 * @throws Exception
	 * pos:Crea una ficha con el simbolo dado
	 */
	public Ficha(char simbolo)throws Exception {
		if(!(simbolo == 'X' || simbolo == 'O')) {
			throw new Exception("No es un simbolo valido");
		}
		this.simbolo = simbolo;
	}
//METODOS DE CLASE
//METODOS GENERALES
	@Override
	public String toString() {
		return ""+this.simbolo;
	}
//METODOS DE COMPORTAMIENTO
	
//GETTERS SIMPLES
	/**
	 * pre:
	 * @return devuelve el simbolo de la ficha
	 */
	public char getSimbolo() {
		return this.simbolo;
	}
	
//SETTERS SIMPLES
}
