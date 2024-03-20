//============================================================================
// Name        : Clase02l.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int test3() {
	int a = 5;
	return a;
}

int test2() {
	int a = 5;
	return a;
}

int test() {
	int a = 5;
	a = 8;
	test2();
	test3();
	return a;
}

void test4(int * pInt) {
	cout << "Contenido de pInt: " << pInt << endl;
	*pInt = 7;
}

void test5(int a) {
	cout << "Contenido de pInt: " << a << endl;
}

int * test6() {
	return new int;
}

struct Alumno {
	int padron;
};

int main() {
	int a = 5;

	test();

	//Imprimo la direccion de a 4 bytes
	cout << "Direccion de a: " << &a << endl;

	//entero
	cout << "Contenido de a: " << a << endl;


	int b = 5;
	test5(b);

	int * pInt = &b;
	int * pInt2 = &b;

	*pInt = (*pInt) * b; //a * b;
	pInt = &a;

	if (pInt != pInt2) {
		test4(pInt);
	}

	cout << "Contenido de a: " << a << endl;
	cout << "Contenido de a: " << *pInt << endl;

	cout << "Contenido de a: " << &a << endl;
	cout << "Contenido de a: " << pInt << endl;
	cout << "Contenido de a: " << &pInt << endl;

	int ** pInt3 = &pInt;
	cout << "Contenido de a: " << **pInt3 << endl;

	char letra = 'A';
	char * pChar = &letra;

	cout << "Contenido de a: " << sizeof(*pInt3) << endl;
	cout << "Contenido de a: " << sizeof(letra) << endl;


	char c1 = 'A';
	int i1 = 65;

	char * p1 = &c1;
	int *  p2 = &i1;

	int * p3 = (int *) p1;
	p3 = reinterpret_cast<int *>(p1);

	cout << "Contenido de c1: " << *p3 << endl; //65
	cout << "Contenido de c1: " << *p1 << endl; //A

	*p3 = 66;

	cout << "Contenido de c1: " << *p3 << endl; //66
	cout << "Contenido de c1: " << *p1 << endl; //B


	int * p4 = new int;
	int * p5 = new int;
	*p4 = 10;

	int * p6 = p5;

	delete p4;
	delete p5;

	int * p6 = NULL; // 0x00000000
	p6 = test6();
	p6 = p5;

	p6= new int;
	*p6 = 10;
	p5 = p6;
	delete p6;

	cout << "Contenido de c1: " << *p5 << endl; //Referencia colgada


	int vector[10];
	int * vector4 = vector;
	vector[0] = 1;

	int largo = 10;

	int * vector1 = new int[largo];
	vector1[1] = 1;
	delete [] vector1;

	int ** vector2 = new int*[largo];
	for(int i = 0; i < 10; i++) {
		vector2[i] = new int[largo];
	}
	vector2[1][1] = 1;

	Alumno * alumno = new Alumno;
	alumno->padron = 432;

	return 0;
}
