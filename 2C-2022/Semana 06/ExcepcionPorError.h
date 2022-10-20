/*
 * ExcepcionPorError.h
 *
 *  Created on: 30/09/2022
 *      Author: algo2
 */

#ifndef EXCEPCIONPORERROR_H_
#define EXCEPCIONPORERROR_H_

#include <exception>

class ExcepcionPorError: public std::exception {

public:
	ExcepcionPorError();

	char * what ();
};

#endif /* EXCEPCIONPORERROR_H_ */
