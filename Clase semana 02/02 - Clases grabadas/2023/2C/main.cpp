
#import <iostream>
#import "RegistroTP1.h"

using namespace std;

static const int LONGITUD = 10;




void inicializarRegistro(Registro registro) {
	registro.ocupada = false;
}

/**
 * Inicializa la matriz en 0
 */
void inicializarMatriz(int **matriz, int ancho, int alto) {
	//itero por las filas
	for(int numeroDeFila = 0; numeroDeFila < 10; numeroDeFila++) {
		for(int columna = 0; columna < 10; columna++) {
			matriz[numeroDeFila][columna] = 0;
		}
	}
}

void imprimir1(int &indice) {
	std::cout << indice << std:endl;
	indice = 10;
}

void imprimir2(int * indice) {
	std::cout << *indice << std:endl;
	(*indice) = 15;
}

int main() {
	int indice = 0;
	int cantidad = 0;
	int &indice2 = indice;

	int * indice3 = NULL;
	indice3 = &indice;

	(*indice3) = 9;
	indice = 9;

	imprimir1(indice2);
	imprimir1(*indice3);

	imprimir2(&indice);

	int * indice4 = new int;
	*indice4 = 0;
	indice4[0];
	*indice4;

	indice3 = indice4;

	indice4 = NULL;
	indice3 = indice4;

	int longitud = 100;
	int vector1[LONGITUD];
	vector1[3] = 1;

	for(int i = 0; i < sizeof(vector1); i++) {
		vector1[i] = 0;
	}

	int * vector2 = new int[longitud];
	for(int i = 0; i < longitud; i++) {
		vector2[i] = 0;
	}

	Registro matriz1[LONGITUD][LONGITUD];
	int ** indice5 = NULL;
	indice5 = new int*;
	*indice5 = new int;
	**indice5 = 10;

	int ** indice6 = NULL;
	indice6 = new int*[20];
	for(int i = 0; i < 20; i++) {
		indice6[i] = new int[20];
		for(int j = 0; j < 20; j++) {
			indice6[i][j] = 0;
		}
	}

	for(int i = 0; i < 20; i++) {
		delete [] indice6[i];
	}
	delete [] indice6;

	Registro ** matriz2 = new Registro[longitud][longitud];
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			matriz2[i][j] = 0;
		}
	}
	delete [] matriz2;


	int matriz3[LONGITUD][LONGITUD];  //no TP 1
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			matriz2[i][j] = 0;
		}
	}


	char caracter = 'A';
	bool impreso = false;

	indice++;
	cout << indice++ << std::endl;
	std::cout << indice++ << std::endl;

	indice = indice +1 + 1 + 2;

	for(int numeroDeFila = 0; numeroDeFila < 5; numeroDeFila++) {
		for(int columna = 5; columna < 10; columna++) {
			std::cout << numeroDeFila << std::endl;
		}
		std::cout << std::endl;
	}

	std::cin >> indice;

	std::string texto = "Hola";


	int matriz[LONGITUD][LONGITUD];

	for(int numeroDeFila = 0; numeroDeFila < 10; numeroDeFila++) {
		vector[numeroDeFila] = 0;
	}

	if (indice > 10) {
		std::cout << std::endl;
	}


	std::cin >> indice;

	Registro registro;
	inicializarRegistro(registro);

	Registro registro1;
	inicializarRegistro(registro1);

	delete indice3;


	//Main ideal
	TesoroBinario * tesoroBinario = inicializarTesoroBinario();
	iniciarJuego(tesoroBinario);
	jugar(tesoroBinario);
	finalizar(tesoroBinario);


    return 0;
}
