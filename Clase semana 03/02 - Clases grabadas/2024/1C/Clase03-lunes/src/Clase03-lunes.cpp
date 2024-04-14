//============================================================================
// Name        : Clase03-lunes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int funcion3(int operacion) {
	if (operacion <= 1) {
		int error = -1;
		throw error;
	}
	if (operacion == 2) {
		char error = 'A';
		throw error;
	}
	return 0;
}

int funcion2(int operacion) {
	funcion3(operacion);
	return 0;
}

int funcion1(int operacion) {
	try {
		funcion2(operacion);
	} catch (...) {
		std::cout << "Error";
		throw 1;
	}
	return 0;
}

int main() {
	try {
		int i = 1;
		try {
			funcion1(1);
		} catch (int) {
			std::cout << "Error main";
		}
		try {
			funcion1(2);
		} catch (int) {

		}
	} catch (exception &e) {
		std::cout << "Error global " << e.what();
	}
	return 0;
}
