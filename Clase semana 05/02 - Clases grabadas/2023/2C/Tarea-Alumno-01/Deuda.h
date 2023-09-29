/*
 * Crear la Deuda recibiendo como parametro su importe
 * obtenerSaldo: devuelve el importe aun no pagado de la Deuda
 * obetenerImporte: devuelve el importe inicial de la Deuda
 * pagar: recibe un pago y lo aplica a la Deuda
 * contarPagos: devuelve la cantidad de pagos aplicados a la Deuda
 * calcularPagoPromedio: devuelve el promedio de los pagos aplicados a la Deuda
 */
#ifndef EJERCICIOSALGOIIPARTE1_DEUDA_H
#define EJERCICIOSALGOIIPARTE1_DEUDA_H

#include "Vector.h"
#include "Pago.h"

class Deuda {
private:
    double total;
    Vector<Pago *> * pagos;
public:
    /*
     * Pre: 0 < importe total
     * Pos: Crea una instancia de Deuda con el importe indicado
     *      y una cantidad maxima de pagos que admite
     */
    Deuda(double, int);

    /*
     * Pre: La instancia fue creada
     * Pos: Destruye la instancia y libera la memoria de todos los pagos
     */
    virtual ~Deuda();

    /*
     * Pre: La instancia fue creada
     * Pos: Retorna el saldo pendiente
     */
    double obtenerSaldo();

    /*
     * Pre: La instancia fue creada
     * Pos: Retorna el importe inicial de la deuda
     */
    double obtenerImporte();

    /*
     * Pre: La instancia fue creada. No se llego al maximo num de pagos y
     *      0 < pago < importeTotal
     * Post: Se ha realizado el pago y descontado la deuda
     */
    void pagar(double);

    /*
     * Pre: La instancia fue creada.
     * Pos: Retorna la suma de todos los pagos
     */
    double sumarPagos();

    /*
     * Pre: La instancia fue creada.
     * Pos: Retorna la cantidad de pagos realizados
     */
    int contarPagos();

    /*
     * Pre: La instancia fue creada.
     * Pos: Retorna el promedio de pagos realizado
     */
    double calcularPagoPromedio();
};


#endif //EJERCICIOSALGOIIPARTE1_DEUDA_H
