package ar.uba.fi.cb100.semana05.miercoles;

public class PrincipalDeLaClase09 {

	public static void sacarRegistro(int edad) throws ExcepcionPorEdad {
		if (edad < 16) {
			throw new ExcepcionPorEdad(edad);
		}
	}
	
	public static void funcion4(Object parametro) throws ExcepcionPorEdad {
		
	}
	
	public static void funcion4(ExcepcionPorEdad parametro) throws ExcepcionPorEdad {
		
	}
	public static void funcion1(int i) throws Exception {
		try {
			//System.out.println("La division es: " + funcion2(i));
			//cerrar archivo aca no 
		} catch (ArithmeticException e) {
			e.printStackTrace();			
		} catch (RuntimeException e) {
			e.printStackTrace();			
		}
	}
	public static void main(String[] args) {
		try {
			System.out.println("Sacar registro para 15 años");
			sacarRegistro(17);
			
			System.out.println("Sacar registro para 21 años");
			sacarRegistro(21);
		} catch (RuntimeException e) {
			
		} catch (ExcepcionPorEdad e) {
			System.err.println("No se puede sacar registro para la edad de " + e.getEdad());		
		} finally {
			System.err.println("Termino la sentencia");
		}
	}

}
