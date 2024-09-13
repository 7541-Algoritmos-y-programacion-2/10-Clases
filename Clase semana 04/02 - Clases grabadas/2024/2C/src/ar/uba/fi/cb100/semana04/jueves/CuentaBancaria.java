package ar.uba.fi.cb100.semana04.jueves;

import java.time.LocalDateTime;

public class CuentaBancaria {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
	
	private static int numeroDeCuentaActual = 1;
	
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private String numero = null;
	private Transaccion[] transacciones = null;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * pre: 
	 * @param numero: debe tener mas de 3 caracteres alfanumericos
	 * @param cantidadMaximaDeTransacciones: debe ser mayor a 0
	 * 
	 * pos: crea una cuenta bancaria con numero y la cantidad maxima de transacciones.
	 * @throws Exception 
	 */
	public CuentaBancaria(String numero, int cantidadMaximaDeTransacciones) throws Exception {
		if (!Validador.tieneLongitudMinima(numero, 3)) {
			throw new Exception("El numero es invalido: " + numero + ". Debe tener minimo 4 caracteres alfanumericos");
		}
		if (cantidadMaximaDeTransacciones <= 0) {
			throw new Exception("La cantidad maxima de transacciones debe ser mayor a 0");
		}
		this.numero = numero;
		this.transacciones = new Transaccion[cantidadMaximaDeTransacciones];
		for(int i = 0; i < this.transacciones.length; i++) {
			this.transacciones[i] = null;
		}
	}

//METODOS DE CLASE ----------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @return devuelve un numero de cuenta libre
	 */
	public static int getNumeroDeCuentaActual() {
		return numeroDeCuentaActual++;
	}
	
//METODOS GENERALES ---------------------------------------------------------------------------------------
	
	@Override
	public String toString() {
		return "La cuenta es: " + this.numero;
	}
	
	@Override
	public boolean equals(Object obj) {
		if (obj instanceof CuentaBancaria) {
			CuentaBancaria cuentaBancaria = (CuentaBancaria) obj;
			return this.numero.equals(cuentaBancaria.getNumero());
		}
		return false;
	}
	
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @return devuelve el saldo de la cuenta corriente
	 */
	public double getSaldo() {
		double saldo = 0;
		for(int i = 0; i < this.transacciones.length; i++) {
			if (this.transacciones[i] != null) {
				switch (this.transacciones[i].getTipoDeTransaccion() ) {	
					case INGRESO:
						saldo += this.transacciones[i].getMonto();
						break;
					case EGRESO:
						saldo -= this.transacciones[i].getMonto();
						break;
				}
			}
		}
		return saldo;
	}
	
	/**
	 * 
	 * @param monto
	 * @throws Exception
	 */
	public void retirar(double monto) throws Exception {
		if (monto <= 0) {
			throw new Exception("EL monto debe ser mayor a 0");
		}
		if (this.getSaldo() <= monto) {
			throw new Exception("EL monto debe ser menor al saldo. Disponible " + this.getSaldo());
		}
		Transaccion transaccion = new Transaccion(LocalDateTime.now(), monto, TipoDeTransaccion.EGRESO);
		agregarTransaccion(transaccion);
	}
	
	/**
	 * 
	 * @param monto
	 * @throws Exception
	 */
	public void acreditar(double monto) throws Exception {
		if (monto <= 0) {
			throw new Exception("EL monto debe ser mayor a 0");
		}
		Transaccion transaccion = new Transaccion(LocalDateTime.now(), monto, TipoDeTransaccion.INGRESO);
		agregarTransaccion(transaccion);
	}
	
	/**
	 * pre
	 * @param transaccion no puede ser vacia
	 * @throws Exception
	 */
	private void agregarTransaccion(Transaccion transaccion) throws Exception {
		for(int i = 0; i < this.transacciones.length; i++) {
			if (this.transacciones[i]== null) {
				this.transacciones[i] = transaccion;
				return;
			}
		}
		throw new Exception("No hay mas lugar para transacciones, se llego al maximo de " + this.transacciones.length);
	}
	
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @return devuelve el numero de cuenta bancaria
	 */
	public String getNumero() {
		return numero;
	}

//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
}
