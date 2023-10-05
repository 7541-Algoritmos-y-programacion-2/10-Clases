#include <iostream>

#include "Ranura.h"
#include "Tostadora.h"

int main(){
    Tostadora *tostadora = new Tostadora(3);
    std::cout << "La tostadora tiene " << tostadora->cantidadDeRanurasLibres() << " ranuras sin usar." << std::endl;

    tostadora->cambiarTemperatura(100);
    tostadora->cambiarTiempoDeCoccion(60);
    std::cout << "La temperatura de la tostadora es " << tostadora->obtenerTemperatura() << " grados centígrados.";
    std::cout << " El tiempo de cocción de la tostadora es " << tostadora->obtenerTiempoDeCoccion() << " segundos." << std::endl;
    
    tostadora->iniciarTostado(1);
    std::cout << "Se inició el tostado en la ranura 1" << std::endl;
    std::cout << "La tostadora tiene " << tostadora->cantidadDeRanurasLibres() << " ranuras sin usar." << std::endl;
    
    tostadora->iniciarTostado(2);
    std::cout << "Se inició el tostado en la ranura 2" << std::endl;
    std::cout << "La tostadora tiene " << tostadora->cantidadDeRanurasLibres() << " ranuras sin usar." << std::endl;

    tostadora->finalizarTostado(1);
    std::cout << "Se finalizó el tostado en la ranura 1" << std::endl;
    std::cout << "¿La tostadora está en uso? " << tostadora->obtenerEstado() << std::endl;

    tostadora->finalizarTostado(2);
    std::cout << "Se finalizó el tostado en la ranura 2" << std::endl;

    tostadora->iniciarTostado(3);
    std::cout << "Se inició el tostado en la ranura 3" << std::endl;

    tostadora->finalizarTostado(3);
    std::cout << "Se finalizó el tostado en la ranura 3" << std::endl;

    std::cout << "La ranura más usada es la ranura " << tostadora->ranuraMasUsada() << std::endl;

    tostadora->iniciarTostado(2);
    std::cout << "Se inició el tostado en la ranura 2" << std::endl;

    tostadora->finalizarTostado(2);
    std::cout << "Se finalizó el tostado en la ranura 2" << std::endl;

    std::cout << "La ranura más usada es la ranura " << tostadora->ranuraMasUsada() << std::endl;

    try{
        tostadora->iniciarTostado(4);
    } catch (...){
        std::cout << "No existe la ranura 4. No se puede iniciar el tostado en ella." << std::endl;
    }
    try{
        tostadora->finalizarTostado(1);
    } catch (...){
        std::cout << "La ranura 1 no se está usando. No se puede finalizar el tostado en esta ranura." << std::endl;
    }
    return 0;
}