#ifndef EJERCICIOSALGOIIPARTE1_PAGO_H
#define EJERCICIOSALGOIIPARTE1_PAGO_H


class Pago {
private:
    double monto;
    void validarMonto(double monto);
public:
    /*
     * Pre: el monto debe ser positivo
     * Post: crea un pago con el monto indicado
     */
    Pago(double monto);

    /*
     * Pre: existe una instancia creada
     * Post: destruye el pago
     */
    virtual ~Pago();

    /*
     * Pre: existe una instancia creada
     * Post: devuelve el monto del pago
     */
    double getMonto();


    void setMonto(double monto);
};


#endif //EJERCICIOSALGOIIPARTE1_PAGO_H
