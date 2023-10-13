#include "Casillero.h"

Casillero::Casillero(unsigned int x, unsigned int y, unsigned int z) {
	validarRango( x, z, y);

	this->x = x;
	this->y = y;
    this->z = z;
	this->ficha = ' ';
}

Casillero::~Casillero() {
	// TODO Auto-generated destructor stub
}

unsigned int Casillero::getX() {
	return this->x;
}

unsigned int Casillero::getY() {
	return this->y;
}

unsigned int Casillero::getZ() {
	return this->z;
}

void Casillero::setFicha(char ficha) {
	this->ficha = ficha;
}

char Casillero::getFicha() {
	return this->ficha;
}

void Casillero::validarRango(unsigned int x, unsigned int y, unsigned int z){
    if(x < 0){
        throw "El x debe ser mayor igual a 0";
    }
    if(y < 0){
        throw "El y debe ser mayor igual a 0";
    }
    if(z < 0){
        throw "El z debe ser mayor igual a 0";
    }
    if(x > this->getX()){
        throw "El amcho debe ser menor igual a " +  this->getX();
    }
    if(y > this->getY()){
        throw "El y debe ser menor igual a " +  this->getY();
    }
    if(z > this->getZ()){
        throw "El z debe ser menor igual a " + this->getZ();
    }
}