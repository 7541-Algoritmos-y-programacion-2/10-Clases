package ar.uba.fi.cb100.c2025_02;

import ar.uba.fi.cb100.c2025_02.teclado.Teclado;

public class Guia01 {

	//F5 ingresar en la funcion
	//F6 es paso a paso
	//F7 es salir de la funcion
	//F8 es ejercutar hasta el proximo breakpoint o final
	public static void main(String[] args) {
		Teclado.inicializar();
		
//		ejercicio1();
//		ejercicio7();
//		ejemploDeClaseYObjeto();
		ejercicio23();
		
		Teclado.finalizar();
	}
	
	public static void ejemploDeClaseYObjeto() {
		Alumno alumno1 = new Alumno();
		alumno1.nombre = "Gustavo 1";
		
		Alumno alumno2 = new Alumno();
		alumno2.nombre = "Gustavo 2";
	}

	public static void imprimir(String texto) {
		System.out.println(texto);
	}
	
	/**
	 * Primer ejemplo de Java
	 */
	public static void holaMundo() {
		
		int i = 8;
		i++; // i = i + 1; ++i
		
		if (i > 6) {
			imprimir("El valor de i es: " + i);
		}
		
		String texto = "Hola" + " " + "mundo";
		texto += " cruel. ";
		imprimir(texto + "El valor de i es: " + i++); //i = 9, pero al salir es 10
		imprimir(texto + "El valor de i es: " + ++i); //i = 11
	}
	
	/**
	 * Primer ejercicio de la guia
	 */
    public static void ejercicio1() {
    	imprimir("Guia 1 - Ejercicio 1");
        imprimir("Ingresa un número entero: ");
        int numero = Teclado.teclado.nextInt(); // Leer un entero desde teclado

        imprimir("El número ingresado es: " + numero);
        imprimir("");
    }
    
    public static void ejercicio7() {
    	imprimir("Guia 1 - Ejercicio 1");
    	imprimir("Ingresa el primer punto flotante: ");
        double numero1 = Teclado.teclado.nextDouble(); // Leer un entero desde teclado

        imprimir("Ingresa el segundo punto flotante: ");
        double numero2 = Teclado.teclado.nextDouble();
        
        if (numero1 > numero2) {
        	imprimir(numero1 + " es mayor que " + numero2);
        } else {
        	imprimir(numero2 + " es mayor que " + numero1);
        }        
        imprimir("");
    }

    public static void ejercicio23() {
    	imprimir("Guia 1 - Ejercicio 23");
    	imprimir("Ingresa la cantidad de lotes a leer: ");
    	int cantidadDeLotes = Teclado.teclado.nextInt();
    	
    	int[][] lotes = new int[cantidadDeLotes][2];
    	    	
    	for(int i = 0; i < cantidadDeLotes; i++) {
    		int valor;
    		lotes[i][0] = 0;
    		lotes[i][1] = 0;
    		do {
    			imprimir("Ingrese el valor " + (lotes[i][1] + 1) + " del lote " + (i + 1));
    			valor = Teclado.teclado.nextInt();
    			if (valor != 0) {
    				lotes[i][0] += valor;
    				lotes[i][1]++;
    			}
    		} while (valor != 0); 
    	}
    	
    	double mediaTotal = 0;
    	for(int i = 0; i < cantidadDeLotes; i++) {
    		double media = 0;
    		if (lotes[i][1] > 0) {
    			media = lotes[i][0] / lotes[i][1];
    		}
    		imprimir("La media del lote " + (i + 1) + " es: " + media);
    		mediaTotal += media;
    	}
    	
    	imprimir("La media de todos los lotes es " + (mediaTotal / cantidadDeLotes) );
    	imprimir(System.lineSeparator());
    }
    
    public static void ejercicio20() {

        System.out.print("Ingrese la cantidad de personas: ");
        int cantidadDePersonas = Teclado.teclado.nextInt();
        
        PersonaConSalario[] personasConSalario = new PersonaConSalario[cantidadDePersonas];


        // Cargar datos
        cargarDatos(personasConSalario); //tarea

        // Procesar para obtener máximo y mínimo
        PersonaConSalario personaConSalarioMaxima = null;
        PersonaConSalario personaConSalarioMinimo = null;
        double salarioMaximo = 0;
        double salarioMinimo = Double.MAX_VALUE;
        
        for (int i = 1; i < personasConSalario.length; i++) {
        	PersonaConSalario personaActual = personasConSalario[i];
            if (personaActual.salario > salarioMaximo) {
            	salarioMaximo = personaActual.salario;
            	personaConSalarioMaxima = personaActual;
            }
            if (personaActual.salario < salarioMinimo) {
            	salarioMinimo = personaActual.salario;
            	personaConSalarioMinimo = personaActual;
            }
        }

        // Mostrar resultados
        System.out.println("\n--- Resultados ---");
        System.out.println("Salario máximo: " + personaConSalarioMaxima.salario + " ( " + personaConSalarioMaxima.nombre + " )");
        System.out.println("Salario mínimo: " + personaConSalarioMinimo.salario + " ( " + personaConSalarioMinimo.nombre + " )");

    }

	private static void cargarDatos(PersonaConSalario[] personaConSalario) {
	
	}
}
