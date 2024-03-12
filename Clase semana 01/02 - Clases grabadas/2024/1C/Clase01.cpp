//============================================================================
// Name        : Clase01.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef CLASE01
#define CLASE01

#include <string>
#include <iostream>
#include <sstream>



using namespace std;


static const float PI = 3.14;

enum Color {
	ROJO,
	AZUL,
	VERDE
};

struct Alumno {
	int padron;
	char letra;
	double promedio;
	Color color;
};

int multiplicar(int x, int y) {
	return x * y;
}

void multiplicar2(const int &x, int &y) {
	y = x * y;
}


int main() {
	float miFlotante2 = 0; // el compilador puede poner 0, o dejar la basura

	float miFlotante = miFlotante2 + 1;
	bool booleano = true;

	booleano = !true;
	booleano = !booleano;
	booleano = true || (!booleano);
	booleano = true && (!booleano);
	booleano = true || ( true && (!booleano));

	booleano = (miFlotante == miFlotante2);
	booleano = (miFlotante >= miFlotante2);

	char caracter = 'A';
	unsigned int enteroPositivo = 0;
	int entero2 = 0;
	int entero3 = 0;
	int entero4 = 0;

	entero2 = entero2 + 1;
	entero2 += 1;
	entero2++;
	entero2--;
	entero2 -= 1;

	Alumno alumno;
	alumno.padron = 100020;

	Color color = ROJO;

	/**
	 * cubo 0-2, 0-2, 0-2
	 */
	int cubo[3][3][3];

	if (miFlotante > 10.0f) {
		miFlotante = 5.0f;
	}

	if ((miFlotante > 10.0f) &&
		(miFlotante < 20.0f)) {
			miFlotante = 5.0f;
		}

	switch (color) {
		case ROJO:
			//
			break;
		case VERDE:
			//
			break;
		default:
			break;
	}
	//Comentario

	while (booleano) {
		booleano = !booleano;
	}

	do {
		booleano = !booleano;
	} while (booleano);


	int vector[4];
	for(int i = 0; i < sizeof(vector); i++) {
		vector[i] = 0;
	}

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				cubo[i][j][k] = 0;
			}
		}
	}

	/*
	 * Comentario gran
	 */

	int resultado = multiplicar(entero2, entero3);

	entero2 = 2;
	entero3 = 2;
	multiplicar2(entero2, entero3);

	std::string nombre = "Agustina";
	std::string apellido = "Perez";
	std::string nombreCompleto = nombre + " " + apellido;

	int valor;
	cin >> valor;

	cout << nombreCompleto << std::endl;


	string s = "12345";
	// Variable del tipo stringstream
	stringstream conversor(s); 	// Variable entera X
	int x = 0;
	conversor >> x;
	// Muestro el valor de x
	cout << "Valor de x: " << x;


	x = 1000;
	conversor << x;
	conversor >> s;
	cout << "Valor de s : " << s;


	return 0;
}


#endif
