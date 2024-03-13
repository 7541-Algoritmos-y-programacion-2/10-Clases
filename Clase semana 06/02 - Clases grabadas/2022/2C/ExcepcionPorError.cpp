/*
 * ExcepcionPorError.cpp
 *
 *  Created on: 30/09/2022
 *      Author: algo2
 */

#include "ExcepcionPorError.h"

ExcepcionPorError::ExcepcionPorError() {
	// TODO Auto-generated constructor stub

}

char * ExcepcionPorError::what () {
        return "Custom C++ Exception";
    }
