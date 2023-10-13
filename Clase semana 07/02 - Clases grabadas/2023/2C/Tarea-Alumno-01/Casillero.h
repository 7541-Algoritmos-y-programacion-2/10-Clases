#ifndef CASILLERO_H_
#define CASILLERO_H_

class Casillero {
private:
	char ficha;
	unsigned int x;
	unsigned int y;
	unsigned int z;

public:
	/**
	 * pre: las posicion deber ser iguales o mayor a 0
	 * pos: deja un casillero vacio creado de las coordenadas dadas 
	 */
	Casillero(unsigned int x, unsigned int y, unsigned int z);

	/**
	 * pos: elimina el casillero
	 */
	virtual ~Casillero();

	/**
	 * pos: devuelve la coordenada x del casillero
	 */
	unsigned int getX();

	/**
	 * pos: devuelve la coordenada y del casillero
	 */
	unsigned int getY();

	/**
	 * pos: devuelve la coordenada z del casillero
	 */
	unsigned int getZ();

	/**
	 * post: devuelve la ficha vinculada con el casillero
	 */
	char getFicha();

	/**
	 * post: cambia el tipo de casillero
	 */
	void setFicha(char ficha);

	private:
    /*
    pos: si los valores no estan en rango, tira una excepcion
    */
    void validarRango(unsigned int x, unsigned int y, unsigned int z);
};

#endif /* CASILLERO_H_ */