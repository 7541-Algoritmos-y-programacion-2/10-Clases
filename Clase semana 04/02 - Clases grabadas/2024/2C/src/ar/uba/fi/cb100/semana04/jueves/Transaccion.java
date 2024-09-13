package ar.uba.fi.cb100.semana04.jueves;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Transaccion {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private LocalDateTime fecha = null;
	private double monto = 0.0;
	private TipoDeTransaccion tipoDeTransaccion = null;

//CONSTRUCTORES -------------------------------------------------------------------------------------------
	
	/**
	 * pre:
	 * @param fecha: no puede ser vacia
	 * @param monto: monto en $ y mayor a 0
	 * 
	 * pos: crea una transaccion de egreso con los valores dados
	 * @throws Exception 
	 */
	public Transaccion(LocalDateTime fecha, double monto) throws Exception {
		this(fecha, monto, TipoDeTransaccion.EGRESO);
	}
	
	/**
	 * pre:
	 * @param fecha
	 * @param monto en $ y mayor a 0
	 * @param tipoDeTransaccion
	 * 
	 * pos: crea una transaccion con los valores dados
	 * @throws Exception 
	 */
	public Transaccion(LocalDateTime fecha, double monto, TipoDeTransaccion tipoDeTransaccion) throws Exception {
		if (fecha == null) {
			throw new Exception("La fecha no puede ser vacia");
		}
		if (monto <= 0) {
			throw new Exception("El monto debe ser mayor a $0");
		}
		if (tipoDeTransaccion == null) {
			throw new Exception("El tipo de transaccion no puede ser vacio");
		}
		this.fecha = fecha;
		this.monto = monto;
		this.tipoDeTransaccion = tipoDeTransaccion; 
	}

//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
	
	@Override
	public String toString() {
		String resultado = "";
		switch (this.tipoDeTransaccion) {
			case EGRESO: resultado += "Egreso de ";
				break;
			case INGRESO: resultado += "Ingreso de "; 
				break;
		}
		DateTimeFormatter formatoDeFecha = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		return resultado + "$" + this.monto + " en el " + this.fecha.format(formatoDeFecha);
	}
	
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	/**
	 * pre: - 
	 * @return devuelve la fecha de la transaccion
	 */
	public LocalDateTime getFecha() {
		return fecha;
	}
	
	/**
	 * pre: - 
	 * @return devuelve el monto de la transaccion
	 */
	public double getMonto() {
		return monto;
	}
	
	/**
	 * pre: - 
	 * @return devuelve el tipo de transaccion de la transaccion (INGRESO o EGRESO)
	 */
	public TipoDeTransaccion getTipoDeTransaccion() {
		return tipoDeTransaccion;
	}
	
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	

}
