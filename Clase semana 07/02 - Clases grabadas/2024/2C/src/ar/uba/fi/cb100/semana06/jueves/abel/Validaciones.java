package ar.uba.fi.cb100.semana06.jueves.abel;

public class Validaciones {
		//TODO: pre y post
	
		public  static boolean esPositivo(double valor) {
			return (valor>=0);
		}
		
		public static boolean esNatural(double valor) {
			return (valor>0);
		}
		
		public static boolean esMayorAUno(int valor) {
			return valor>1;
		}
	}
