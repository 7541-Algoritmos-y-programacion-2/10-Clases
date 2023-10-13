#ifndef TABLERO_H_
#define TABLERO_H_
#include "Casillero.h"
#include "Lista.h"

class Tablero {
private:
	Lista<Lista<Lista<Casillero *> *> *> * casilleros;
    unsigned int ancho; 
    unsigned int alto; 
    unsigned int largo;

public:
    /**
    pre: las dimensiones deber ser iguales o mayor a 0
    pos: deja un tablero creado de las dimensiones dadas con todos los casillas vacias
    */
	Tablero(unsigned int ancho, unsigned int alto, unsigned int largo);

    /*
    pos: elimina el tablero
    */
	virtual ~Tablero();

	/*
    pos: devuelve el ancho del tablero
    */
	unsigned int getAncho();

	/*
    pos: devuelve el alto del tablero
    */
	unsigned int getAlto();

	/*
    pos: devuelve el largo del tablero
    */
	unsigned int getLargo();

    /*
    pre: las dimensiones deber ser iguales o mayor a 0 y menos o igual al maximo asignado
    pos: devuelve el casillero indicado
    */
    Casillero * getCasillero(unsigned int ancho, unsigned int alto, unsigned int largo);

    private:
    /*
    pos: si los valores no estan en rango, tira una excepcion
    */
    void validarRango(unsigned int ancho, unsigned int alto, unsigned int largo);
};

#endif /* TABLERO_H_ */
