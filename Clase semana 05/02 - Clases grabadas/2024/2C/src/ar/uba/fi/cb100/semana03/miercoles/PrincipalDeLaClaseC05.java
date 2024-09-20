package ar.uba.fi.cb100.semana03.miercoles;

public class PrincipalDeLaClaseC05 {
	
	public static void main(String[] args) throws Exception {
		{
			Complejo complejo1 = Complejo.construir(0, 0);
			Complejo complejo2 = Complejo.construir(10, 10);
			complejo1.sumar(complejo2);			
		}
		{
			Complejo complejo3 = Complejo.construir(0, 0);
			complejo3.sumar(5);
		}
		
		
	}

}
