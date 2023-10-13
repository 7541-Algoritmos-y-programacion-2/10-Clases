#include "Tablero.h"

Tablero::Tablero(unsigned int ancho, unsigned int alto, unsigned int largo) {
    validarRango(ancho, alto, largo);

	this->casilleros = new Lista<Lista<Lista<Casillero *> *> *>();
    this->ancho = ancho;
    this->alto = alto;
    this->largo = largo;

	for( int i = 0; i < ancho; i++){
		Lista<Lista<Casillero *> *>* fila = new Lista<Lista<Casillero *>*>();
		for( int j = 0; j < alto; j++) {
			Lista<Casillero *> * columna = new Lista<Casillero *>();
            for( int z = 0; z < largo; z++) {
            	Casillero* casillero = new Casillero( i, j, z);
            	columna->agregar(casillero);
		    }
            fila->agregar(columna);
		}
		casilleros->agregar(fila);
	}
}

Tablero::~Tablero() {
	this->casilleros->iniciarCursor(); 
	while (this->casilleros->avanzarCursor()) {
		Lista<Lista<Casillero *> *> * fila = this->casilleros->obtenerCursor(); 
        fila->iniciarCursor();
        while (fila->avanzarCursor()) {
		    Lista<Casillero *> * columna = fila->obtenerCursor();
            columna->iniciarCursor();
            while (columna->avanzarCursor()) {
                delete columna->obtenerCursor();
            }
            delete columna; 
        }
        delete fila;
	}
	delete this->casilleros;
}

unsigned int Tablero::getAncho() {
	return this->ancho;
}

unsigned int Tablero::getAlto() {
	return this->alto;
}

unsigned int Tablero::getLargo() {
	return this->largo;
}

Casillero * Tablero::getCasillero(unsigned int ancho, unsigned int alto, unsigned int largo) {
	validarRango(ancho, alto, largo);
	return this->casilleros->obtener(ancho)->obtener(alto)->obtener(largo);
}

void Tablero::validarRango(unsigned int ancho, unsigned int alto, unsigned int largo){
    if(ancho < 1){
        throw "El ancho debe ser mayor igual a 0";
    }
    if(alto < 1){
        throw "El alto debe ser mayor igual a 0";
    }
    if(largo < 1){
        throw "El largo debe ser mayor igual a 0";
    }
    if(ancho > this->getAncho()){
        throw "El amcho debe ser menor igual a " +  this->getAncho();
    }
    if(alto > this->getAlto()){
        throw "El alto debe ser menor igual a " +  this->getAlto();
    }
    if(largo > this->getLargo()){
        throw "El largo debe ser menor igual a " + this->getLargo();
    }
}


