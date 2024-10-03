package ar.uba.fi.cb100.semana02.miercoles;

public class PrincipalDeLaClase03 {

	public static void funcion1(Entero entero) {
		entero.valor = 10;
	}
	
	public static void main(String[] args) {
		Entero entero = new Entero();
		Entero entero2 = entero;
		
		if (entero2 == entero) {
			System.out.println(entero.valor);	
		}
		
		if (entero2 != entero) {
			System.out.println(entero.valor);	
		}
		
		entero.valor = 8;
		funcion1(entero);
		System.out.println(entero.valor);
		
		entero = new Entero();
		
		entero = null;
		int i = 0;
		
		entero.valor = 15;
		
		System.out.println(entero);
		
		byte byte1 = 65;
		char char1 = (char) byte1; //A=65
		System.out.println(byte1); //65
		System.out.println(char1); //A
		
		boolean valor = true; //true or false
		Boolean valor2 = null; //true, false o null
		Boolean valor3 = true;
		Boolean valor4 = Boolean.TRUE;
		//Boolean valor5 = new Boolean(true);
		Boolean valor6 = Boolean.valueOf(true);
		
		i -= 10;
		i = i - 10;
	}
}
