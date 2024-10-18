package ar.uba.fi.cb100.semana09.jueves.consultas.tomas;

public class Principal {
	
	/* 
	 * https://github.com/7541-Algoritmos-y-programacion-2/10-Clases/blob/main/Evaluaciones/Parciales/2022%20-%202C%20-%20PARCIAL%20I.pdf
	 * Ejercicio:
	 * Diseñar la especificación e implementar el TDA Colecta. Debe proveer operaciones para:
		• crear la Colecta recibiendo como parámetro el monto [$] considerado como objetivo de la misma 
		   y el monto [$] de la máxima donación individual aceptada.
		• calcularRecaudación: devuelve el monto total [$] recaudado.
		• donar: recibe el monto [$] a donar y lo agrega a la recaudación.
		• contarDonaciones: devuelve la cantidad de donaciones recibidas.
		• calcularDonacionMaxima: devuelve el monto [$] de la máxima donación recibida.
		• calcularRecaudacionFaltante: devuelve el monto [$] que falta recaudar para cumplir con el objetivo de la Colecta, 
		                               o cero [$] en caso de haberse superado.
	 */
	
	public static void main(String[] args) throws Exception {
		
		Colecta colecta = new Colecta(500,50000000);
		colecta.donar(45);
		colecta.donar(5);
		colecta.donar(30);
		colecta.donar(10);
		colecta.donar(50);
		colecta.donar(50);
		colecta.donar(50);
		colecta.donar(50);
		colecta.donar(50);
		colecta.donar(50);
		colecta.donar(50);
		colecta.donar(50);
		colecta.donar(50);
		colecta.donar(50);
		colecta.donar(50);
		
		try {
			System.out.println("Ingrese un monto menor a " + colecta.getMontoDeDonacionMaximo());
			colecta.donar(50000);
		} catch (Exception e) {
			
		}

		System.out.println(colecta.getMontoObjetivo());		
		System.out.println(colecta.calcularRecaudacion());
		System.out.println(colecta.contarDonaciones());
		System.out.println(colecta.calcularDonacionMaxima());
		System.out.println(colecta.calcularRecaudacionFaltante());
	}

}
