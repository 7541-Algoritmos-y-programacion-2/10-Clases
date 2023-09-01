/*
 * RegistroTP1.h
 *
 *  Created on: 31/08/2023
 *      Author: algo2
 */

#ifndef REGISTROTP1_H_
#define REGISTROTP1_H_

enum {
	OCUPADA,
	TESORO,
	ESPIA,
	NO_DISPONIBLE,
	LIBRE
} EstadoDeRegistro;

typedef struct {
	bool ocupada;
	EstadoDeRegistro estado;
} Registro;

void inicializarRegistro(Registro &registro);


#endif /* REGISTROTP1_H_ */
