/*
 * ComplejoEnC.h
 *
 *  Created on: 03/04/2024
 *      Author: algo2
 */

#ifndef COMPLEJOENC_H_
#define COMPLEJOENC_H_

typedef struct {
	double real;
	double imaginaria;
} ComplejoEnC;

ComplejoEnC construirComplejoEnC();
ComplejoEnC sumar(ComplejoEnC complejo1, ComplejoEnC complejo2);
void setParteReal(ComplejoEnC &complejo, double real);

#endif /* COMPLEJOENC_H_ */
