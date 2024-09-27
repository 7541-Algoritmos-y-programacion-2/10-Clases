package ar.uba.fi.cb100.semana03.jueves;

public class EjercicioDePunteros {

	public static void funcion3() {
		int k = 0;
	}
	
	public static void funcion2() {
		int k = 0;
		funcion3();
		k = 1;
	}
	
	public static void funcion1() {
		int i = 0;
	}
	
	public static void main(String[] args) {
		int A, C, F = 0; 
		char G; 
		int H;
		int[] L = new int[3];
		int[] M = L;
		funcion1();
		funcion2();
		H = 68; 
		G = 'A'; 
		A = H; 
		L[0] = A; 
		M[1] = L[0]; 
		System.out.println(A + "-" + G + "-" + M[0] + "-" + L[1]);
		
		G = (char) H;
		M[2] = L[0] + A; 

		System.out.println(G + "-" + H + "-" + M[1] + "-" + L[2]);

		while (L[0] > 10) {			
			H--;
			A--;
			C = A;
			System.out.println(C + "-" + H + "-" + M[1] + "-" + F);
			F = A;
			C--;
			M[0] -= 30;
		} 
		//Que hace el garbage collector
	}
}
