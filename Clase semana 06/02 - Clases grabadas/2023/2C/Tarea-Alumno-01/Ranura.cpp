#include "Ranura.h"


Ranura::Ranura(unsigned int numeracion){
    validaNumeracion(numeracion);
    this->cantidadDeUsos = 0;
    this->numeracion = numeracion;
    this->estaLibre = true;
}

Ranura::~Ranura(){} 

void Ranura::validaNumeracion (unsigned int numeracion){
    if (numeracion < 0){
        throw "La numeración de la ranura no puede ser negativa";
    }
}

unsigned int Ranura::obtenerNumeracion(){
    return this->numeracion;
}

unsigned int Ranura::obtenerCantidadDeUsos(){
    return this->cantidadDeUsos;
}

bool Ranura::obtenerEstaLibre(){
    return this->estaLibre;
}

void Ranura::cambiarNumeracion(unsigned int numeracion){
    this->numeracion = numeracion;
}

void Ranura::cambiarEstaLibre(bool estado){
    this->estaLibre = estado;
}

void Ranura::aumentarCantidadDeUsos(){
    this->cantidadDeUsos += 1;
}

void Ranura::disminuirCantidadDeUsos(){
    if (this->cantidadDeUsos == 0){
        throw "La cantidad de usos de la ranura es 0. No puedes disminuirlos.";
    }
    this->cantidadDeUsos -= 1;
}

void Ranura::iniciarTostado(){
    if (!this->estaLibre){
        throw "La ranura está ocupada. No puedo iniciar un tostado.";
    }
    cambiarEstaLibre(false);
    aumentarCantidadDeUsos();
}

void Ranura::finalizarTostado(){
    if (this->estaLibre){
        throw "La ranura está libre. No puedo finalizar un tostado.";
    }
    cambiarEstaLibre(true);
}