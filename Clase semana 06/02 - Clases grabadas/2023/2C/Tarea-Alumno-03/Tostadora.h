#ifndef TOSTADORA_H
#define TOSTADORA_H

#include <iostream>
#include "Vector.h"
#include "Ranura.h"

enum EstadoTostadora{
    ENCENDIDA,
    APAGADA,
};

class Tostadora{
    private:
        Vector<Ranura*> *ranuras;
        unsigned int nivelDeCalor;
        EstadoTostadora estado;

        /**
         * pre: -
         * post: El indice debe estar dentro del rango. Devuelve error si no lo está.
        */
        void validarNivel(unsigned int nivel){
            if(nivel<1){
                throw "El nivel indicado no existe, debe ser igual o mayor a 1.";
            }
            if(nivel>10){
                throw "El nivel indicado se encuentra fuera de rango. 1 - 10.";
            }
        }

        /**
         * pre: -
         * post: El indice debe estar dentro del rango. Devuelve error si no lo está.
        */
        void validarRanura(unsigned int indice){
            if(indice<1){
                throw "La cantidad de ranuras especificadas debe ser mayor o igual a 1.";
            }
            if(indice>this->ranuras->getLongitud()){
                throw "La cantidad de ranuras colocadas es superior a la existente.";
            }
        }

    public:

        /**
         * pre: El índice debe ser mayor a 0.
         * post: Deja asentado una tostadora con nivel de calor en mínimo y apagada.
        */
        Tostadora(unsigned int cantidadDeRanuras){
            this->ranuras=new Vector <Ranura*>(cantidadDeRanuras);
            for(int i=1;i<=this->ranuras->getLongitud();i++){
                this->ranuras->setDato(i, new Ranura(i));
            }
            this->nivelDeCalor=1;
            this->estado=APAGADA;
        }

        /**
         * pre: -
         * post: Libera memoria de Tostadora.
        */
        virtual ~Tostadora(){
            delete this->ranuras;
        };

        /**
         * pre: -
         * post: Obtiene la cantidad de ranuras de la tostadora.
        */
        int getCantidadDeRanuras(){
            return this->ranuras->getLongitud();
        }

        /**
         * pre: Nivel debe estar dentro del rango.
         * post: Setea el nivel de calor de la tostadora.
        */
        void setNivelDeCalor(unsigned int nivel){
            validarNivel(nivel);
            this->nivelDeCalor=nivel;
        }

        /**
         * pre: -
         * post: Devuelve el nivel de calor seteado.
        */
        int getNivelDeCalor(){
            return this->nivelDeCalor;
        }

        /**
         * pre: -
         * post: Enciende la tostadora.
        */
        void encender(){
            this->estado=ENCENDIDA;
        }
        
        /**
         * pre: -
         * post: Apaga la tostadora.
        */
        void apagar(){
            this->estado=APAGADA;
        }

        /**
         * pre: Indice debe estar dentro del rango.
         * post: Devuelve un puntero a Ranura.
        */
        Ranura* getRanura(unsigned int indice){
            validarRanura(indice);
            return this->ranuras->getDato(indice);
        }

        /**
         * pre: Indice debe estar dentro del rango.
         * post: Devuelve la cantidad de panes tostados por una ranura.
        */
        int getCantidadDePanesTostadosEnTotal(){
            int cantidad=0;
            for(int i=1;i<=this->getCantidadDeRanuras();i++){
                cantidad=cantidad + this->getRanura(i)->getPanesTostados();
            }
            return cantidad;
        }

        /**
         * pre: Indice debe estar dentro del rango. La tostadora debe estar encendida.
         * post: Empieza a tostar pan en una ranura.
        */
        void calentarPan(unsigned int indice){
            validarRanura(indice);
            if(this->estado==APAGADA){
                throw "La tostadora no esta encendida.";
            }
            this->getRanura(indice)->tostar();
        }

        /**
         * pre: Indice debe estar dentro del rango.
         * post: Deja de calentar pan en una ranura.
        */
        void dejarDecalentarPan(unsigned int indice){
            if(this->estado=APAGADA){
                throw "La tostadora debe estar encendida";
            }
            this->getRanura(indice)->dejarDeTostar();
        }

        /**
         * pre: -
         * post: Devuelve la ranura que mas tostó.
        */
        Ranura* getRanuraQueMasTosto(){
            Ranura* aux=this->getRanura(1);
            for(int i=1;i<=this->getCantidadDeRanuras();i++){
                if(this->getRanura(i)->getPanesTostados()>aux->getPanesTostados()){
                    aux=this->getRanura(i);
                }
            }
            return aux;
        }

        /**
         * pre: -
         * post: Devuelve la cantidad de ranuras libres.
        */
        int getRanurasLibres(){
            int resultado=0;
            for(int i=1;i<=this->ranuras->getLongitud();i++){
                if(!(this->getRanura(i)->estaTostando())){
                    resultado++;
                }
            }
            return resultado;
        }

        /**
         * pre: -
         * post: Devuelve si la tostadora está encendida.
        */
        bool estaEncendida(){
            return this->estado==ENCENDIDA;
        }
};

#endif
