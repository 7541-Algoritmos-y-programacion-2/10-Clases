/*
 * Principal1.cpp
 *
 *  Created on: 15/05/2024
 *      Author: algo2
 */

#include "Tren.h"

int main(int argc, char **argv) {
	Tren * tren = new Tren(2);

	tren->agregarVagon(new Vagon(100));

	double carga= 1000;
	while (carga > 0) {
		carga = tren->agregarCarga(carga);
		if (carga > 0) {
			tren->agregarVagon(new Vagon(100));
		}
	}
	tren->arrancar();

	//imprimir los valores actuales

	tren->detener();
	carga = tren->descargar(500);
}
