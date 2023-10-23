#include "Tablero.h"

Tablero::Tablero(unsigned int ancho, unsigned int alto, unsigned int largo) {
    validarRango(ancho, alto, largo);

	this->casilleros = new Lista<Lista<Lista<Casillero *> *> *>();
    this->ancho = ancho;
    this->alto = alto;
    this->largo = largo;

	for( unsigned int i = 0; i < ancho; i++){
		Lista<Lista<Casillero *> *>* fila = new Lista<Lista<Casillero *>*>();
		for( unsigned int j = 0; j < alto; j++) {
			Lista<Casillero *> * columna = new Lista<Casillero *>();
            for( unsigned int z = 0; z < largo; z++) {
            	Casillero* casillero = new Casillero( i, j, z);
            	columna->agregar(casillero);
		    }
            fila->agregar(columna);
		}
		casilleros->agregar(fila);
	}

	//Tarea:
	//Optimizar este algoritmo while / cursor
	for( unsigned int x = 1; x <= ancho; x++){
		for( unsigned int y = 1; y <= alto; y++) {
			for( unsigned int z = 1; z <= largo; z++) {
				//Por cada casillero
				Casillero * casillero = getCasillero(x, y, z); //recorriendo x * y * z * 13
				//Los vecinos
				for( unsigned int i = -1; i <= 1; i++){
					for( unsigned int j = -1; j <= 1; j++){
						for( unsigned int k = -1; k <= 1; k++){
							if (existeCasillero(x+i, y+j, z+k)) {
								//si (0, 0, 0); casillero->setVecino( casillero, 0,0,0);
								if (casillero->tieneElVecino(i, j, k)) {
									Casillero * vecino = getCasillero(x+i, y+j, z+k);
									casillero->setVecino(vecino, i, j, k);
									vecino->setVecino(casillero, -1 *i, -1 *j, -1 *k);
								}
							}
						}
					}
				}
			}
		}
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

bool Tablero::existeCasillero(unsigned int ancho, unsigned int alto, unsigned int largo) {
	return ((ancho >= 1) &&
			(ancho <= this->ancho) &&
			(alto >= 1) &&
			(alto <= this->alto) &&
			(largo >= 1) &&
			(largo <= this->largo));
}
