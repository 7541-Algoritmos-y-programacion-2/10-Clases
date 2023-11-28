#include <iostream>


class Ingrediente {

  public:

    /* post: queda inicializado con el nombre y cantidad
     *       indicados.
     */
    Ingrediente(std::string nombre, float cantidad);

    ~Ingrediente();

    /* post: devuelve el nombre del Ingrediente.
     */
    std::string getNombre();

    /* post: devuelve la cantidad del Ingrediente.
     */
    float getCantidad();
};


class Receta {

  public:

    /* post: inicializa la Receta sin Ingredientes asignados.
     */
    Receta(std::string nombre);

    /* post: elimina todos los Ingrediente de la Receta.
     */
    ~Receta();

    /* post: devuelve todos los Ingredientes de la Receta.
     */
    Lista<Ingrediente*>* getIngredientes();

    /* post: devuelve el nombre que identifica a la Receta.
     */
    std::string getNombre();
};


class Chef {
  public:

	bool contieneSuficienteIngrediente( Lista<Ingrediente*>* ingredientesDisponibles,
										Ingrediente * ingrediente) {
		ingredientesDisponibles->iniciarCursor();
		while (ingredientesDisponibles->avanzarCursor()) {
			if ((ingredientesDisponibles->obtenerCursor()->getNombre() == ingrediente->getNombre()) &&
				(ingredientesDisponibles->obtenerCursor()->getCantidad() >= ingrediente->getCantidad())) {
				return true;
			}
		}
		return false;
	}

	/**
	 * Pre: tarea
	 * Pos: tarea
	 */
    bool esRecetaPosible(Receta * receta,
    					 Lista<Ingrediente*>* ingredientesDisponibles) {
    	//validar: tarea
    	receta->getIngredientes()->iniciarCursor();
    	while(receta->getIngredientes()->avanzarCursor()) {
    		if (!contieneSuficienteIngrediente(ingredientesDisponibles,
    								receta->getIngredientes()->obtenerCursor())) {
    			return false;
    		}
    	}
    	return true;
    }

    /* post: busca en la lista recetas aquellas Recetas que pueden ser preparadas con los Ingredientes que se encuentran
     *       en ingredientesDisponibles y tengan mas ingredientes que cantidadDeIngredientesMinima. Considera que todos los Ingredientes de la Receta deben estar en
     *       ingredientesDisponibles comparando su nombre y validando que la cantidad sea la suficiente.
     *       Devuelve una nueva Lista con todos las Recetas en esta condición. */
    Lista<Receta*>* buscarRecetasPosibles(Lista<Receta*>* recetas,
    								Lista<Ingrediente*>* ingredientesDisponibles,
    								int cantidadDeIngredientesMinima) {
    	//TIPS:
    	//Validar
    	//Modularizar
    	//Resolver
    	//1 solo while x metodo
    	//Cumplir con TDA: pre post y ubicar los metodos en la clase correspondiente
    	//                 nombrar bien
    	//Todo con punteros
    	//Recorrido de lista con cursor (no for, no [])
    	//Utilizar el template de la catedra (no tiene buscar o comparar o contiene)

    	/**
    	 * validar: tarea para el hogar
    	 */

    	Lista<Receta*>* resultado = new Lista<Receta*>();
    	recetas->iniciarCursor();
    	while (recetas->avanzarCursor()) {
    		Receta * receta = recetas->obtenerCursor();
    		if ((receta->getIngredientes()->contarElementos() > cantidadDeIngredientesMinima) &&
    			esRecetaPosible(receta, ingredientesDisponibles)) {
    			resultado->agregar(receta);
    		}
    	}
    	return resultado;
    }

};



int main() {
    Juego juegoNuevo;
    juegoNuevo.iniciarJuego();
    return 0;
}
