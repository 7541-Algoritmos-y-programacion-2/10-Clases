package ar.uba.fi.cb100.semana05.jueves.tarea.timebomb;

public class MainTesteo {

	public static void main(String[] args) throws Exception {
		//Crea un televisor con 140 canales
		Televisor televisor = new Televisor(140);
		
		//Prueba setear un canal e ir subiendo y bajando de canal y volumen
		televisor.setCanal(4);
		System.out.println("El canal actual es " + televisor.getCanalActual() + " y el volumen actual es " + televisor.getVolumenActual());
		for (int i = 0; i < 50; i++) {
			televisor.subirVolumen();
		}
		System.out.println("El volumen del canal actual es " + televisor.getVolumenCanal(televisor.getCanalActual()));
		System.out.println("Ahora el volumen actual es " + televisor.getVolumenActual());
		
		for (int i = 0; i < 12; i++) {
			televisor.subirCanal();
			televisor.bajarVolumen();
		}
		System.out.println("");
		System.out.println("Subí el canal varias veces y bajé el volumen, ahora el canal al que se cambió es el " + televisor.getCanalActual() + " y el volumen es " + televisor.getVolumenCanal(televisor.getCanalActual()));
		System.out.println("");
		
		//Prueba el silenciar el televisor
		System.out.println("¿El Televisor está silenciado? -> " + televisor.getSilencio());
		televisor.switchSilencio();
		System.out.println("¿Y ahora? -> " + televisor.getSilencio());
		System.out.println("Entonces el volumen actual es: " + televisor.getVolumenActual());
		televisor.switchSilencio();
		System.out.println("Ya no está silenciado, entonces su volumen es: " + televisor.getVolumenActual());
		System.out.println("");
		
		//Más pruebas con bucles
		for (int i = 0; i < 100; i++) {
			televisor.subirCanal();
		}
		while (televisor.getCanalActual() > 99) {
			televisor.bajarCanal();
		}
		System.out.println("El canal al que se cambió es el " + televisor.getCanalActual());
		System.out.println("");
		
		//Prueba al silenciar, subir el volumen y desilenciar
		System.out.println("El volumen es " + televisor.getVolumenActual());
		televisor.switchSilencio();
		televisor.subirVolumen();
		System.out.println("Tras silenciar y subir el volumen, debería desilenciarse y subir uno. Entonces el volumen es: " + televisor.getVolumenActual());
		System.out.println("");
		
		//Prueba de excepciones
			//Intentar un canal inválido
        try {
            televisor.setCanal(1000);
        } catch (Exception e) {
            System.out.println("Error al cambiar de canal: " + e.getMessage());
        }
        
        	//Subir demasiadas veces un canal
        try {
            for (int i = 0; i < 10000; i++) {
            	televisor.subirCanal();
            }
        } catch (Exception e) {
            System.out.println("Error al subir el canal: " + e.getMessage());
        }
        
        	//Subir el volumen demasiado
        try {
        	for (int i = 0; i < 300; i++) {
        		televisor.subirVolumen();
            }
        } catch (Exception e) {
            System.out.println("Error al subir el volumen: " + e.getMessage());
        }
        
        	//Bajar el volumen demasiado
        try {
        	for (int i = 0; i < 300; i++) {
        		televisor.bajarVolumen();
            }
        } catch (Exception e) {
            System.out.println("Error al bajar el volumen: " + e.getMessage());
        }
	}

}
