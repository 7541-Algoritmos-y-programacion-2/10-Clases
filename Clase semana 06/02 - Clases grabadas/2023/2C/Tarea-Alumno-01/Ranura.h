#ifndef RANURA_H 
#define RANURA_H 


class Ranura{
private:
    unsigned int numeracion; //almacena una numeración a la ranura.
    unsigned int cantidadDeUsos; //Almacena la cantidad de panes que lleva tostados.
    bool estaLibre;

    /*
    pre: 
    post: Valida que el número ingresado sea un entero positivo.
    */
   void validaNumeracion (unsigned int numeracion);

public:
    /*
    pre: La numeración ingresada debe ser positiva.
    post: Crea una ranura con numeración ingresada 0, sin usos y liberada.
    */
    Ranura(unsigned int numeracion); // Constructor;

    /*
    pre: -
    post: -
    */
    virtual ~Ranura(); // Destructor;

    /*
    pre: -
    post: Devuelve el número asignado a la ranura.
    */
    unsigned int obtenerNumeracion();

    /*
    pre: -
    post: devuelve la cantidad de usos de la ranura.
    */
    unsigned int obtenerCantidadDeUsos();

    /*
    pre: -
    post: devuelve si la ranura está libre o no.
    */
    bool obtenerEstaLibre();

    /*
    pre: Debe recibir un número entero positivo.
    post: Cambia la numeración de la ranura.
    */
    void cambiarNumeracion(unsigned int numeracion);

    /*
    pre: Recibe true o false.
    post: Cambia el estado de la ranura.
    */
    void cambiarEstaLibre(bool estado);

    /*
    pre: -
    post: Aumenta en 1 el contador de la cantidad de usos de la ranura
    */
    void aumentarCantidadDeUsos();

    /*
    pre: La cantidad de usos de la ranura debe ser mayor a cero.
    post: Disminuye en 1 la cantidad de usos de la ranura.
    */
    void disminuirCantidadDeUsos();

    /*
    pre: la ranura debe estar libre.
    post: Cambia el estado de la ranura a ocupado. Aumenta la cantidad de usos en 1.
    */
    void iniciarTostado();

    /*
    pre: la ranura debe estar ocupada.
    post: Cambia el estado de la ranura a Libre.
    */
    void finalizarTostado();
};

#endif