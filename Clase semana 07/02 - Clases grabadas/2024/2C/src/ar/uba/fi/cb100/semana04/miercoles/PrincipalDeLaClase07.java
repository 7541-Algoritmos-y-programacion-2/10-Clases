package ar.uba.fi.cb100.semana04.miercoles;

import ar.uba.fi.cb100.semana03.miercoles.Complejo;

public class PrincipalDeLaClase07 {	

	public static void imprimir(Numero numero) {
		numero.imprimir();
	}
	
	
	public static void main(String[] args) {
		Complejo complejo1 = Complejo.construir(10, 3);
		complejo1.sumarParteReal(10.0);		
		complejo1.sumarParteReal(new Numero(10.0));		
		complejo1.sumarParteReal(10, 20, 30, 20, 12);
		complejo1.sumarParteReal(Complejo.construir(15, 10));
		
		complejo1.setParteReal(50);
		//Antes de implementar imprimir en complejo:
		complejo1.imprimir(); //out: "El numero es: " + 50
		
		complejo1.setParteImaginaria(75);
		//Despues de implementar imprimir en complejo
		complejo1.imprimir(); //"El numero complejo es: 50 + 75i");
		
		{
			Numero numero = new Numero(10);
			numero.imprimir();
		}
		{
			Complejo complejo2 = Complejo.construir(10, 3);
			complejo2.imprimir();
		}
		{
			Numero numero = Complejo.construir(10, 3);
			numero.imprimir();
			numero.sumar(Complejo.construir(10.0, 100.0));
			imprimir(numero);
		}
		
		imprimir(complejo1);
		imprimir(new Numero());
		imprimir(new Fraccion());		
	}
	
}
