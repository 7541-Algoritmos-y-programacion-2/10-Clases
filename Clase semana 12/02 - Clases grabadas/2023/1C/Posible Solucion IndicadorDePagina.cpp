/*
* Autor: Facundo Baratta
* Cuarta version
*/

#include <iostream>
#include "vector.h"

using namespace std;

enum EstadoPagina {LEIDA, NO_LEIDA};

class Pagina {
private:
    unsigned int numeroDePagina;
    EstadoPagina estado;

public:

    // Constructor
    // PRE: Recibe un numero de pagina a asignar mayor a 0
    // POS: Crea una pagina con ese numero de pagina y el estado pagina no pasada
    Pagina(unsigned int numeroDePagina);

    // Destructor
    // PRE: -
    // POS: Destruye la instancia
    ~Pagina() {};

    // PRE: -
    // POS: Devuelve true si la pagina fue pasada, false en caso contrario
    bool estaLeida();

    // PRE: -
    // POS: Devuelve el estado de la pagina
    unsigned int getNumeroDePagina();

    // PRE: -
    // POS: Cambia el estado de la pagina a leida
    void leer();

    // PRE: -
    // POS: Cambia el estado de la pagina a no leida
    void marcarComoNoLeida();
};

Pagina::Pagina(unsigned int numeroDePagina) {
    if (numeroDePagina == 0) {
        throw "El numero de pagina no puede ser 0";
    }
    this->numeroDePagina = numeroDePagina;
    this->estado = NO_LEIDA;
}

bool Pagina::estaLeida() {
    return this->estado == LEIDA;
}

unsigned int Pagina::getNumeroDePagina() {
    return this->numeroDePagina;
}

void Pagina::leer() {
    this->estado = LEIDA;
}

void Pagina::marcarComoNoLeida() {
    this->estado = NO_LEIDA;
}

class IndicadorDePagina {
private:
    Vector<Pagina*> * paginas;
    Pagina *paginaActual;

public:
    // CONSTRUCTOR
    // PRE: Recibe la cantidad de paginas en el libro (mayor a 0)
    // POS: Crea un indicador de pagina para un libro con esa cantidad de paginas
    IndicadorDePagina(unsigned int cantidadTotalDePaginas);

    // CONSTRUCTOR
    // PRE: -
    // POS: Destruye la instancia liberando la memoria
    ~IndicadorDePagina();

    // PRE: -
    // POS: Devuelve true si el indicador ha sido iniciado (se ha pasado una pagina alguna vez), false en caso contrario
    bool estaIniciado();

    // PRE: -
    // POS: La pagina actual ahora es la primera pagina
    void iniciar();

    // PRE: -
    // POS: Devuelve un puntero a la pagina actual.
    Pagina *getPaginaActual();

    // PRE: -
    // POS: Devuelve la cantidad de paginas del libro
    unsigned int getCantidadTotalDePaginas();

    // PRE: -
    // POS: Pasa a la siguiente pagina
    void siguientePagina();

    // PRE: -
    // POS: Pasa a la anterior pagina
    void anteriorPagina();

    // PRE: -
    // POS: Devuelve el procentaje de paginas no pasadas
    double porcentajeSinLeer();
};

IndicadorDePagina::IndicadorDePagina(unsigned int cantidadTotalDePaginas) {
    if (cantidadTotalDePaginas == 0) {
        throw "La cantidad de paginas no puede ser cero";
    }

    this->paginas = new Vector<Pagina*>(cantidadTotalDePaginas, NULL);
    
    for (unsigned int i = 1; i <= cantidadTotalDePaginas; i++) {
        this->paginas->agregar(i, new Pagina(i));
    }
    
    this->paginaActual = NULL;
}

IndicadorDePagina::~IndicadorDePagina() {
    unsigned int totalPaginas = this->paginas->getLongitud();
    
    for (unsigned int i = 1; i <= totalPaginas; i++) {
        delete this->paginas->obtener(i);
    }
    
    delete this->paginas;
}

Pagina *IndicadorDePagina::getPaginaActual() {
    if (!this->estaIniciado()) {
        throw "No hay pagina actual; no se ha iniciado el iterador";
    }

    return this->paginaActual;
}

unsigned int IndicadorDePagina::getCantidadTotalDePaginas() {
    return this->paginas->getLongitud();
}

bool IndicadorDePagina::estaIniciado() {
    return this->paginaActual != NULL;
}

void IndicadorDePagina::iniciar() {
    this->paginaActual = this->paginas->obtener(1);
    this->paginaActual->leer();
}

void IndicadorDePagina::siguientePagina() {
    if (!this->estaIniciado()) {
        throw "El indicador no ha sido iniciado";
    }

    if (this->paginaActual->getNumeroDePagina() == (unsigned int)this->paginas->getLongitud()) { // Pagina actual es la ultima
        throw "No existe pagina siguiente";
    }

    this->paginaActual = this->paginas->obtener(this->paginaActual->getNumeroDePagina() + 1);

    this->paginaActual->leer();
}

void IndicadorDePagina::anteriorPagina() {
    if (!this->estaIniciado()) {
        throw "El indicador no ha sido iniciado";
    }

    if (this->paginaActual->getNumeroDePagina() == 1) { // Pagina actual es la primera
        throw "No existe pagina anterior";
    }

    this->paginaActual = this->paginas->obtener(this->paginaActual->getNumeroDePagina() - 1);

    this->paginaActual->leer();
}

double IndicadorDePagina::porcentajeSinLeer() {
    unsigned int paginasNoLeidas = 0;
    unsigned int totalPaginas = this->paginas->getLongitud();

    for (unsigned int i = 1; i <= totalPaginas; i++) {
        if (!(this->paginas->obtener(i)->estaLeida())) {
            paginasNoLeidas++;
        }
    }

    return 100 * (double)paginasNoLeidas/totalPaginas;    
}

int main() {
    IndicadorDePagina *indicador = new IndicadorDePagina(5);
    indicador->iniciar();
    indicador->siguientePagina(); // Segunda pagina
    indicador->anteriorPagina(); // Primera pagina

    cout << "n° pagina actual: " << indicador->getPaginaActual()->getNumeroDePagina() << endl;
    cout << "Porcentaje sin leer: " << indicador->porcentajeSinLeer() << '%' << endl;

    try {
        indicador->anteriorPagina();
    }

    catch(const char *error) {
        cout << error << endl;
    }

    delete indicador;

    try {
        IndicadorDePagina *indicadorMalo = new IndicadorDePagina(0);
        indicadorMalo->iniciar();
    }

    catch(const char *error) {
        cout << error << endl;
    }
}
