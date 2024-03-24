//============================================================================
// Name        : Clase02-mie.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef struct {
	int padron;
} Alumno ;


int main() {
	int a = 3;

	int * pInt = &a;

	a = 4;

	int * pInt1 = pInt;

	cout << "Es igual: " << (pInt == pInt1) << endl;
	//Direcciones de a
	cout << "La direccion de a es: " << &a << endl; // prints AEFE:1023 > 0xAEFE1023
	cout << "El direccion de a es: " << pInt << endl;
	cout << "El direccion de a es: " << pInt1 << endl;

	int ** ppInt = &pInt;

	//Valores de a
	cout << "El valor de a es: " << a << endl; // 4
	cout << "El valor de a es: " << *pInt1 << endl; // 4 equivalente a la variable a
	cout << "El valor de a es: " << *pInt << endl;
	cout << "El valor de a es: " << **ppInt << endl;


	char letra = 'A';
	char * pLetra = &letra;

	cout << "El valor es: " << *pLetra << endl;
	cout << "El valor es: " << letra << endl; //Imprime A

	int * pInt3 = (int *) pLetra;
	pInt3 = static_cast<int *>(pLetra);

	cout << "El valor es: " << *pInt3 << endl;//Imprime 65

	int * pInt4 = new int;
	*pInt4 = 3;

	delete pInt4;

	int entero1 = 0; //
	int * pInt4 = NULL; //0 1 0 1
	if (pInt4 == NULL) {
		pInt4 = &entero1;
	}

	Alumno * alumno = new Alumno();
	alumno->padron = 4;
	(*alumno).padron = 5;


	int lon = 4;
	int vector[4];
	sizeof(vector);
	for(int i = 0; i< sizeof(vector); i++) {
		vector[i] = 0;
	}

	int * vector1 = new int[lon];
	sizeof(vector1); //devuelve el tamaño del puntero
	for(int i = 0; i < lon; i++) {
		vector1[i] = 0;
	}
	delete [] vector1;


	int ** vector2 = new int*[lon];
	for(int i = 0; i < lon; i++) {
		vector2[i] = new int[lon];
		for(int j = 0; j < lon; j++) {
			vector2[i][j] = 0;
		}
	}

	vector2[3][3] = 1;
	for(int i = 0; i < lon; i++) {
		delete [] vector2[i];
	}
	delete [] vector2;





	return 0;
}
