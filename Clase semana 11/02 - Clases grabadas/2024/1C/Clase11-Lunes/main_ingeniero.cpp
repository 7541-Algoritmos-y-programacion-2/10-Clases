/*
 * main_ingeniero.cpp
 *
 *  Created on: 18/05/2024
 *      Author: algo2
 */

#include "Lista.h"
#include "Solucion.h"
#include "Compuesto.h"

#include <iostream>

using namespace std;


int main(){

	Solucion * agua = new Solucion("Agua");
	Compuesto *oxigeno = new Compuesto("Oxigeno",LITRO);
	agua->agregarCompuesto(oxigeno);


	cout << agua->obtenerCodigo() << endl;
	return 0;
}
