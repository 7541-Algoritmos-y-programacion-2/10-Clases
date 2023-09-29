#include "Deuda.h"
#include <iostream>


void mostrarDeuda(Deuda *deuda) {
    std::cout << "Importe original: "
              << deuda->obtenerImporte()
              << std::endl;
    std::cout << "Deuda remanente: "
              << deuda->obtenerSaldo()
              << std::endl;
}

int main() {

    Deuda *miDeuda= new Deuda(1000, 4);
    mostrarDeuda(miDeuda);
    miDeuda->pagar(100);
    mostrarDeuda(miDeuda);
    miDeuda->pagar(200);
    mostrarDeuda(miDeuda);
    miDeuda->pagar(600);
    mostrarDeuda(miDeuda);
    std::cout << "El pago promedio es: "
              << miDeuda->calcularPagoPromedio()
              << std::endl;

    return 0;
}