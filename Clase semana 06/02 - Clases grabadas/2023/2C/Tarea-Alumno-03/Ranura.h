#ifndef RANURA_H
#define RANURA_H

#include <iostream>
#include "Vector.h"

enum EstadoDeRanura{
    LIBRE,
    TOSTANDO,
};

class Ranura{
    private:
        int numeroRanura;
        unsigned int panesTostados;
        EstadoDeRanura estado;

    public:

        /**
         * pre: -
         * post: Crea ranura en estado libre.
        */
        Ranura(unsigned int numero){
            this->numeroRanura=numero;
            this->estado=LIBRE;
            this->panesTostados=0;
        }

        /**
         * pre: -
         * post: -
        */
        virtual ~Ranura();

        /**
         * pre: -
         * post: Setea el id de la ranura.
        */
        void setNumeroRanura(int id){
            this->numeroRanura=id;
        }

        /**
         * pre: -
         * post: Devuelve el id de la ranura seleccionada.
        */
        int getNumeroRanura(){
            return this->numeroRanura;
        }

        /**
         * pre: -
         * post: Devuelve los panes tostador por una ranura.
        */
        int getPanesTostados(){
            return this->panesTostados;
        }

        /**
         * pre: -
         * post: Empieza a tostar, cambia el estado.
        */
        void tostar(){
            this->estado=TOSTANDO;
        }

        /**
         * pre: La ranura debe estar tostando.
         * post: Deja de tostar.
        */
        void dejarDeTostar(){
            if(this->estado==TOSTANDO){
                this->estado=LIBRE;
                this->panesTostados=this->panesTostados+1;
            }
            else{
                throw "La ranura ya estaba libre.";
            }
        }

        /**
         * pre: -
         * post: Devuelve si la ranura está tostando.
        */
        bool estaTostando(){
            return this->estado==TOSTANDO;
        }
};

#endif

