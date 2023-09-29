#include "Pago.h"
#include <iostream>

Pago::Pago(double monto) {
    this->validarMonto(monto);
    this->monto = monto;
}

void Pago::validarMonto(double monto) {
    if (monto < 0) {
        throw std::invalid_argument("El monto debe ser positivo");
    }
}

Pago::~Pago() {
}

double Pago::getMonto() {
    return this->monto;
}

void Pago::setMonto(double monto) {
    this->validarMonto(monto);
    this->monto = monto;
}
