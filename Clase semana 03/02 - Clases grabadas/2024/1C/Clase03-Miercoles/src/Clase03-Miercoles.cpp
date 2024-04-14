//============================================================================
// Name        : Clase03-Miercoles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int funcion3(int entero) {
	if (entero == 10) {
		throw 'A';
	}
	return 0;
}

int funcion2(int entero) {
	try {
		funcion3(entero);
	} catch (exception &e) {

	} catch (...) {
		throw 200;
	}
	return 0;
}

int funcion1(int entero) {
	if (entero == 0) {
		return -1;
	}
	funcion2(entero);
	return 0;
}

int main() {
	try {
		cout << "Es par: " << funcion1(3) << endl;
		cout << "Es par: " << funcion1(3) << endl;
		try {
			cout << "Es par: " << funcion1(10) << endl;
		} catch (int error) {
			cout << "Error antes" << endl;
			throw 'A';
		}
		cout << "Es par: " << funcion1(3) << endl;
	} catch (int) {
		cout << "Error" << endl;
	} catch (char) {
		cout << "Error" << endl;
	} catch (exception &e) {
		cout << "Error" << endl;
	} catch (...) {
		cout << "Error inesperado" << endl;
	}
	return 0; //-1 -2 -3
}
