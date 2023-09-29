#include "Pago.h"

Pago::Pago(double monto) {
    this->monto = monto;
}

void Pago::validarMonto(double monto) {
    if (monto < 0) {
        throw ("El monto debe ser positivo");
    }
}

Pago::~Pago() {
    // Nothing to do here
}

double Pago::getMonto() {
    return this->monto;
}

void Pago::setMonto(double monto) {
    this->monto = monto;
}
