#include "Tostadora.h"
#include "Vector.h"


Tostadora::Tostadora(unsigned int cantidadRanuras){
    validarPositivo((int)cantidadRanuras);
    this->ranuras = new Vector<Ranura *>(cantidadRanuras);
    for (unsigned int i = 1; i <= cantidadRanuras; i++){
        this->ranuras->setDato(i, new Ranura(i));
    }
    this->temperatura = 0;
    this->tiempoDeCoccion = 0;
    this->estado = APAGADA;
    this->cantidadRanuras = cantidadRanuras;
}

Tostadora::~Tostadora(){
    for (unsigned int i = 1; i <= this->cantidadRanuras; i++){
        this->ranuras->getDato(i)->~Ranura();
    }
    this->ranuras->~Vector();
}

void Tostadora::validarPositivo(int valor){
    if (valor < 0){
        throw "El valor ingresado es negativo. No puedo realizar esta operación.";
    }
}

void Tostadora::validarNumeroRanura(unsigned int numeroRanura){
    if (numeroRanura < 1){
        throw "La ranura ingresada no está en el rango de ranuras.";
    }
    if (numeroRanura > this->cantidadRanuras){
        throw "La ranura ingresada no está en el rango de ranuras.";
    }
}

unsigned int Tostadora::obtenerTemperatura(){
    return this->temperatura;
}

unsigned int Tostadora::obtenerTiempoDeCoccion(){
    return this->tiempoDeCoccion;
}

bool Tostadora::obtenerEstado(){
    return this->estado;
}

void Tostadora::cambiarTemperatura(unsigned int temperatura){
    validarPositivo(temperatura);
    this->temperatura = temperatura;
}

void Tostadora::cambiarTiempoDeCoccion(unsigned int tiempoDeCoccion){
    validarPositivo(tiempoDeCoccion);
    this->tiempoDeCoccion = tiempoDeCoccion;
}

void Tostadora::cambiarEstado(Estado estado){
    this->estado = estado;
}

void Tostadora::iniciarTostado(unsigned int ranura){
    validarNumeroRanura(ranura);
    this->ranuras->getDato(ranura)->iniciarTostado(); //El método iniciarTostado ya valida si la ranura está libre o no.
    if (this->estado == APAGADA){
        this->estado = ENCENDIDA;
    }
}

/*
pre: recibe la ranura en la que se finaliza el tostado. El valor debe ser un valor que esté en el rango de las ranuras existentes.
post: Cambia el estado de la tostadora a APAGADO si no hay otra ranura tostando y libera la ranura para poder tostar otro pan.
*/
void Tostadora::finalizarTostado(unsigned int ranura){
    if (this->estado == APAGADA){
        throw "La tostadora está apagada. No se puede finalziar un tostado";
    }
    validarNumeroRanura(ranura);
    this->ranuras->getDato(ranura)->finalizarTostado(); //Este método ya valida que se esté realizando un tostado.
    if(this->cantidadDeRanurasLibres() == 0){
        this->estado = APAGADA;
    }
}

unsigned int Tostadora::cantidadDeRanurasLibres(){
    unsigned int contador = this->cantidadRanuras;
    for (unsigned int i = 1; i <= this->cantidadRanuras; i++){
        if (!this->ranuras->getDato(i)->obtenerEstaLibre()){
            contador -= 1;
        }
    }
    return contador;
}

unsigned int Tostadora::ranuraMasUsada(){
    unsigned int cantidadUsos = 0;
    unsigned int ranuraMasUsada = 0;
    for (unsigned int i = 1; i <= this->cantidadRanuras; i++){
        if (this->ranuras->getDato(i)->obtenerCantidadDeUsos() > cantidadUsos){
            cantidadUsos = this->ranuras->getDato(i)->obtenerCantidadDeUsos();
            ranuraMasUsada = i;
        }
    }
    return ranuraMasUsada;
}


