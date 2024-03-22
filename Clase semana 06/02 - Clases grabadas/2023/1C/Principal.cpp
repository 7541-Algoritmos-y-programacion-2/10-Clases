
#include <stddef.h>
#include <iostream>

#include "Curso.h"
#include "Estudiante.h"

int test() {
	Curso * curso2 = NULL;
	try {
		curso2 = new Curso("a", "a", 1);
		//NO VA
		for(int i = 0; i < curso2->getCantidadDeInscriptos(); i++) {
			curso2->getInscripto(i);
		}

	} catch (...) {
		delete curso2;
		throw "No se puede crear el curso";
	}
	delete curso2;
	return 0;
}

int main(){
	try {
		Estudiante * vector1 = new Estudiante[4];
		//Estudiante vector6[10];
		{
			Estudiante estudiante("Schmidt", "Gustavo", 32334);
			estudiante.getNombre();

			vector1[0] = estudiante;
			vector1[0].setNombre("gus 2");

			int valor = 10;
			int * vector2 = new int[10];
			vector2[0] = valor;
			vector2[0] = 20;

		} //Llama al destructor y libera el stack

		{
			Estudiante * estudiante;
			estudiante = new Estudiante("Schmidt", "Gustavo", 32334);
			estudiante->getNombreCompleto();

			Estudiante ** vector3 = new Estudiante*[10];
			vector3[0] = estudiante;
			vector3[0]->setNombre("gus 3");


			delete estudiante;
		}
		delete vector1;

		//Caso 1:

		Curso * curso = new Curso("", "", 0);
	} catch(...) {
		std::cout << "El curso no tiene nombre";
	}

	Curso * curso2 = new Curso("", "", 0);

	try {
		test();
	} catch (...) {
		std::cout << "El curso no tiene nombre";
	}
}


