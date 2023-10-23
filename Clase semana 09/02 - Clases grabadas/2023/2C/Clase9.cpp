//============================================================================
// Name        : Clase9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Cola.h"
#include "Lista.h"

enum Enum1 {
	ACTIVO
};

enum Enum2 {
	ACTIVOS
};

class Producto {

public:

	/* post: Producto con el nombre y la categoría
	*	indicados.
	*/
	Producto(std::string nombre, std::string categoria);

	/* post: devuelve el nombre del Producto.
	*/
	std::string obtenerNombre();

	/* post: devuelve la categoría del Producto.
	*/
	std::string obtenerCategoria();
};


class Sucursal {

public:

	Sucursal();

	/* post: devuelve las categorias de productos que vende.
	*/
	Lista<std::string>* obtenerCategorias();

	/* post: devuelve todos los Productos que tiene la sucursal.
	*/
	Lista<Producto*>* obtenerProductos();

	/* post: libera todos los Productos.
	*/
	~Sucursal();

	/**
	 * pre:
	 * post:
	 */
	bool contieneLaCategoria(std::string categoria) {
		this->obtenerCategorias()->iniciarCursor();
		while(this->obtenerCategorias()->avanzarCursor()) {
			std::string categoriaActual = this->obtenerCategorias()->obtenerCursor();
			if (categoriaActual == categoria) {
				return true;
			}
		}
		return false;
	}
};

class Distribuidor {

public:
	/**
	 * pre:
	 * pos: si puede distribuir, devuelve true
	 */
	bool distribuirProductoEnSucursales(Producto* producto,
									Lista<Sucursal*>* sucursalesExistentes) {
		//VALIDAR
		sucursalesExistentes->iniciarCursor();
		while(sucursalesExistentes->avanzarCursor()) {
			Sucursal * sucursal = sucursalesExistentes->obtenerCursor();
			if (sucursal->contieneLaCategoria(producto->obtenerCategoria())) {
				sucursal->obtenerProductos()->agregar(producto);
				return true;
			}
		}
		return false;
	}

	/* post: remueve los Productos de la cola ‘productosDisponibles’ y los agrega a alguna Sucursal de
	*	‘sucursalesExistentes’ que tenga la categoria del Producto.
	*	Aquellos Productos que no pueden ser agregados a ninguna Sucursal se devuelven a la cola
	*	‘productosDisponibles’.
	*/
	void distribuirProductosEnSucursales(Cola<Producto*>* productosDisponibles,
								Lista<Sucursal*>* sucursalesExistentes) {
		//VERSION 1: NO ACEPTADA
		//VALIDAR PARAMETROS
		Cola<Producto*>* productosSobrantes = new Cola<Producto *>();
		while (!productosDisponibles->estaVacia()) {
			Producto * producto = productosDisponibles->desacolar();
			sucursalesExistentes->iniciarCursor();
			while(sucursalesExistentes->avanzarCursor()) {
				Sucursal * sucursal = sucursalesExistentes->obtenerCursor();

				sucursal->obtenerCategorias()->iniciarCursor();
				while(sucursal->obtenerCategorias()->avanzarCursor()) {
					std::string categoria = sucursal->obtenerCategorias()->obtenerCursor();
					if (categoria == producto->obtenerCategoria()) {
						sucursal->obtenerProductos()->agregar(producto);
						producto = NULL;
					}
				}
			}
			if (producto != NULL) {
				productosSobrantes->acolar(producto);
			}
		}

		//Version 2
		Cola<Producto*>* productosSobrantes = new Cola<Producto *>();
		while (!productosDisponibles->estaVacia()) {
			Producto * producto = productosDisponibles->desacolar();
			if (!distribuirProductoEnSucursales(producto, sucursalesExistentes)) {
				productosSobrantes->acolar(producto);
			}
		}
		productosDisponibles->acolarTodos(productosSobrantes);
		delete productosSobrantes;
	}
};


int main() {
	//Tarea:
	//Terminar el parcial: pre post, ejecutarlo
	//Hacer el main e imprimir el resultado

	return 0;
}
