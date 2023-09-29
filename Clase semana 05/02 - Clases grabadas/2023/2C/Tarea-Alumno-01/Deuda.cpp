#include "Deuda.h"
#include <iostream>


Deuda::Deuda(double importe, int cantidadPagos) {
    this->total = importe;
    this->pagos = new Vector<Pago *>(cantidadPagos);
    for (int i = 0; i < cantidadPagos; ++i) {
        this->pagos->setDato(i, new Pago(0));
        // Se va a usar el NULL para indicar que no hay pago
        // El usuario se encarga de reservar memoria y liberarla
    }
}

Deuda::~Deuda() {
    if (this->pagos) {
        for (int i = 0; i < pagos->getLongitud(); i++) {
            if (pagos->getDato(i) != NULL) {
                delete pagos->getDato(i);
            }
        }
        delete this->pagos;
    }
}

double Deuda::sumarPagos() {
    double suma = 0;
    for (int i = 0; i < this->pagos->getLongitud(); i++) {
        suma += this->pagos->getDato(i)->getMonto();
    }
    return suma;
}

double Deuda::obtenerSaldo() {
    return this->total - sumarPagos();
}

double Deuda::obtenerImporte() {
    return this->total;
}

void Deuda::pagar(double monto) {
    if (monto > this->total) {
        throw std::invalid_argument("El pago no puede ser mayor al total");
    } else if (monto + sumarPagos() > this->total) {
        throw std::invalid_argument("El pago no puede excederse del total");
    } else if (monto < 0) {
        throw std::invalid_argument("El pago no puede ser menor a cero");
    } else if (contarPagos() >= this->pagos->getLongitud()) {
        throw std::invalid_argument("Has alcanzado la cantidad de pagos maxima");
    }
    this->pagos->getDato(contarPagos())->setMonto(monto);
}

int Deuda::contarPagos() {
    // 0 < 2
    int i = 0;
    while (i < this->pagos->getLongitud() && this->pagos->getDato(i)->getMonto() != 0) {
        i++;
    }
    return i;
}

double Deuda::calcularPagoPromedio() {
    return sumarPagos() / contarPagos();
}
