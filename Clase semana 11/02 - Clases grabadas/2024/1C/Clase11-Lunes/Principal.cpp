/*
 * Principal.cpp
 *
 *  Created on: 20/05/2024
 *      Author: algo2
 */



// Implementar la clase FiltroDeNoticias a partir de las siguientes especificaciones:
#ifndef FILTRODENOTICIAS_H
#define FILTRODENOTICIAS_H
#include <iostream>
#include "Lista.h"

using namespace std;

class Categoria{
public:
    /**
     * Post: inicializa la categoria con el nombre y la descripcion indicadas
    */
    Categoria(std::string nombre, std::string descripcion);

    /**
     * Post: devuelve el nombre que la identifica
    */
    std::string getNombre();

    /**
     * Post: devuelve la descripcion de la categoria
    */
    std::string getDescripcion();

    bool esIgual(Categoria*);
};

class Noticia {
public:
    /**
     * Post: inicializa la noticia con el titulo y cuerpo indicados, sin categorias asociadas
    */
    Noticia(std::string titulo, std::string cuerpo);

    /**
     * Post: devuelve el titulo de la noticia
    */
    std::string getTitulo();

    /**
     * Post: devuelve el cuerpo de la noticia
    */
    std::string getCuerpo();

    /**
     * Post: devuelve las categorias asociadas a la noticia
    */
    Lista<Categoria*>* getCategorias();

};

class FiltroDeNoticias{
public:
    /**
     * Pre: La lista de la noticia no puede ser vacia ni la categoria a buscar
     * Post: Devuelve verdadero si la categoria de conCategorias pertenece a las categorias de la noticia si no falso.
    */
    bool perteneceACategorias(Categoria* categoria, Lista<Categoria*>* categorias){
        if(categorias == NULL || categoria == NULL){
            throw "No puede ser vacio";
        }

        categorias->iniciarCursor();
        while(categorias->avanzarCursor()){
            Categoria * categoriaActual = categorias->obtenerCursor();
            if(categoriaActual->esIgual(categoria)){
                return true;
            }
        }
        return false;

    }

    /**
     * Pre: La noticia no puede ser vacia, ni las categorias
     * Post: Devuelve verdadero si contiene todas las categorias de 'conCategorias' y sino falso
    */
    bool tieneAConCategorias(Noticia* noticiaActual, Lista<Categoria*>* conCategorias){
        if(noticiaActual == NULL){
            throw "noticiaActual No puede ser vacio";
        }
        if (conCategorias == NULL) {
        	throw "conCategorias no puede ser vacio";
        }

        conCategorias->iniciarCursor();
        while (conCategorias->avanzarCursor()){
            Categoria* categoriaActual = conCategorias->obtenerCursor();
            if(!perteneceACategorias(categoriaActual, noticiaActual->getCategorias())){
                return false;
            }
        }
        return true;
    }



    /**
     * Post: remueve de noticias aquellas Noticias que tengan asociada TODAS
     *       las categorias dadas en conCategorias
    */
    void removerNoticias(Lista<Noticia*>* noticias, Lista<Categoria*>* conCategorias){
        if(noticias == NULL || conCategorias == NULL){
            throw "No pueden ser vacias";
        }

        unsigned int posicion = 1;

        noticias->iniciarCursor();
        while(noticias->avanzarCursor()){
            Noticia* noticiaActual = noticias->obtenerCursor();
            if(tieneAConCategorias(noticiaActual, conCategorias)){
                noticias->remover(posicion);
            } else {
            	posicion++;
            }
        }
    }
};
#endif
