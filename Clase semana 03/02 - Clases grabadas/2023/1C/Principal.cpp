
#include <iostream>

/**
 * Ejercicio de recursividad:
 *
 *  Calcular la potencia positiva de n
 *
 *  Problema 1: se va de rango
 *
 *  El numero maximo a calcular es MAX_LONG
 */

int potencia(int base, unsigned int potencia) {
	//Condicion de corte
	if (potencia == 0) {
		return 1;
	}
	//Mejora para optimizar la ultima llamada recursiva
//	if (potencia == 1) {
//		return base;
//	}
	return potencia(base, potencia-1) * base;

	//potencia(base, potencia-1)
	//base
	//*
	//return;
}

void intercambiarLetra(char * texto, int longitud, int indice) {
	char auxiliar = texto[indice];
	texto[indice] = texto[longitud-indice];
	texto[longitud-indice] = auxiliar;
	if (indice < (longitud / 2)) {
		intercambiarLetra(texto, longitud, indice + 1);
	}
}

void intercambio(char *texto, int longitud) {
	int indice = 0;
	intercambiarLetra(texto, longitud, indice);
}


int main(){
	// potencia(2, 3) = 2 * 2 * 2 = 8
	long base = 2;
	long potencia = 3;
	potencia(base, potencia); // 8

	potencia(base, 0); // 1

	potencia(23423908472093, 2342347283); //MAX_LONG


	char * texto = NULL;
	//........
	int longitud = 10;
	texto = new char[longitud];
	intercambio(texto, longitud);
	delete [] texto;


	int H = 65;
	int J = H;
	J = 67;
	int * K = &J;
	*K = 68;
	int * M = new int[10];
	delete [] M;
	M = NULL;

}


