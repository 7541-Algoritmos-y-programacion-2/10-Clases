#ifndef TOSTADORA_H 
#define TOSTADORA_H 

#include "Vector.h"
#include "Ranura.h"

/*

Diseñar la especificación e implementar el TDA Tostadora. Debe proveer operaciones para:
• Construir de la cantidad de ranuras para panes que tiene. Cada ranura se identifica con un número.
• Iniciar tostado de pan, indicando la ranura a utilizar.
• Finalizar el tostado de pan, indicando la ranura a utilizar.
• Indicar el nivel de calor de la tostadora, de 1 a 10.
• contarRanurasLibres: indica la cantidad de ranuras no ocupadas.
• Devolver la ranura que más panes tostó.
• La tostadora puede estar apagada o encendida
Reglas:
La tostadora es manual, no tiene automatizado el tiempo de cocción.
Hacer un mail para testear

*/

enum Estado{
    ENCENDIDA,
    APAGADA
};

class Tostadora{
private:
    unsigned int temperatura; //La temperatura está medida en grados centígrados.
    unsigned int tiempoDeCoccion; //El tiempo de cocción está medido en segundos.
    bool estado; //indica si está encendida o apagada.
    unsigned int cantidadRanuras;
    Vector<Ranura *> *ranuras; //Las ranuras están numeradas de 1 a cantidadRanuras.

    /*
    pre: -
    post: Valida si el número ingresado es positivo. En caso de no serlo devuelve error.
    */
    void validarPositivo(int valor);

    /*
    pre: -
    post: Valida si el número ingresado está en el rando de cantidadRanuras.
    */
    void validarNumeroRanura(unsigned int valor);
    

public:
    /*
    pre: La cantidad de ranuras de la tostadora debe ser un numero entero positivo.
    post: Crea la tostadora con la cantidad de ranuras indicada. La temperatura inicial es 0 grados centígrados, el tiempo de cocción es 0 s y el estado es APAGADO.
    */
    Tostadora(unsigned int cantidadRanuras); // Constructor;

    /*
    pre:-
    post: Libera la memoria alocada.
    */
    virtual ~Tostadora(); // Destructor;

    /*
    pre: -
    post: Devuelve la temperatura a la que está seteada la tostadora.
    */
    unsigned int obtenerTemperatura();

    /*
    pre: -
    post: Devuelve el tiempo de cocción al que está seteada la tostadora.
    */
    unsigned int obtenerTiempoDeCoccion();

    /*
    pre: 
    post: Devuelve si la tostadora está apagada o encendida.
    */
    bool obtenerEstado();

   /*
   pre: La temperatura ingresada debe ser un número positivo.
   post: Cambia la temperatura de tostado a la ingresada.
   */
    void cambiarTemperatura(unsigned int temperatura);

    /*
    pre: El tiempo de coccion debe ser un valor positivo medido en segundos.
    post: Cambia el tiempo de cocción.
    */
    void cambiarTiempoDeCoccion(unsigned int tiempoDeCoccion);

    /*
    pre: El estado ingresado debe ser APAGADA o ENCENDIDA.
    post: Cambia el estado de la tostadora al ingresado.
    */
    void cambiarEstado(Estado estado);

    /*
    pre: recibe la ranura en la que se va a realizar el tostado. El valor debe ser un valor que esté en el rango de las ranuras existentes.
    post: Cambia el estado de la tostadora a ENCENDIDO y arranca a tostar el pan en la ranura indicada.
    */
    void iniciarTostado(unsigned int ranura);

    /*
    pre: recibe la ranura en la que se finaliza el tostado. El valor debe ser un valor que esté en el rango de las ranuras existentes.
    post: Cambia el estado de la tostadora a APAGADO si no hay otra ranura tostando y libera la ranura para poder tostar otro pan.
    */
    void finalizarTostado(unsigned int ranura);

    /*
    pre: -
    post: Devuelve la cantidad de ranuras libres.
    */
    unsigned int cantidadDeRanurasLibres();

    /*
    pre: -
    post: Devuelve la ranura que más pan tostó. En caso de que ninguna ranura haya sido usada devuelve 0. Si hay más de una ranura que tostó el máximo de panes, devuelve la primera que encontró
    */
    unsigned int ranuraMasUsada();
};

#endif