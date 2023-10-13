#include <iostream>
#include "Tostadora.h"

int main(void){

    Tostadora* prueba=new Tostadora(3);
    std::cout << prueba->getCantidadDeRanuras() << std::endl;
    for(int i=1;i<=prueba->getCantidadDeRanuras();i++){
        std::cout << prueba->getRanura(i)->getNumeroRanura() << std::endl;
    }
    prueba->getRanura(2)->setNumeroRanura(20);
    prueba->getRanura(3)->setNumeroRanura(5);
    for(int i=1;i<=prueba->getCantidadDeRanuras();i++){
        std::cout << prueba->getRanura(i)->getNumeroRanura()<< std::endl;
    }
    prueba->encender();
    prueba->calentarPan(1);
    std::cout << prueba->getRanurasLibres() << std::endl;
    prueba->dejarDecalentarPan(1);
    std::cout << prueba->getCantidadDePanesTostadosEnTotal() << std::endl;
    prueba->apagar();

    delete prueba;
}

