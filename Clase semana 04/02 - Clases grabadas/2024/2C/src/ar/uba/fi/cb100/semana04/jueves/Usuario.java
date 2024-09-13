package ar.uba.fi.cb100.semana04.jueves;

public class Usuario {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private String nombre = null;
	private String dni = null;
	private CuentaBancaria[] cuentasBancarias = null;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------

	/**
	 * pre: 
	 * @param nombre: no puede ser vacio y debe tener 3 caracteres minimos
	 * @param dni: no puede ser vacio, debe tener 5 caracteres
	 * @param cantidadDeCuentasBancarias: debe ser mayor a 0
	 * 
	 * pos: crea un Usuario con los valores dados
	 * @throws Exception 
	 */
	public Usuario(String nombre, String dni, int cantidadDeCuentasBancarias) throws Exception {
		if (!Validador.tieneLongitudMinima(nombre, 3)) {
			throw new Exception("El nombre debe tener minimo 3 caracteres");
		}
		if (!Validador.tieneLongitudMinima(dni, 5)) {
			throw new Exception("El dni debe tener minimo 5 caracteres");
		}
		if (cantidadDeCuentasBancarias <= 0) {
			throw new Exception("La cantidad de cuentas bancarias debe ser mayor a 0");
		}
		this.nombre = nombre;
		this.dni = dni;		
		this.cuentasBancarias = new CuentaBancaria[cantidadDeCuentasBancarias];
		for (int i = 0; i < this.cuentasBancarias.length; i++) {
			this.cuentasBancarias[i] = null;			
		}
	}
	
//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
	
	@Override
	public String toString() {
		return this.nombre + " (DNI:" + this.dni + ")";
	}
	
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
	
	/**
	 * pre: -
	 * @return devuelve el sado del usuario, sumando todas las cuentas corrientes activas.
	 */
	public double getSaldo() {
		double saldo = 0;
		for(int i = 0; i < this.cuentasBancarias.length; i++) {
			if (this.cuentasBancarias[i] != null) {
				saldo += this.cuentasBancarias[i].getSaldo();
			}
		}
		return saldo;
	}
	
	/**
	 * pre: 
	 * @param cuentaBancaria: la cuenta bancaria no puede ser nula
	 * @throws Exception 
	 */
	public void agregarCuentaBancaria(CuentaBancaria cuentaBancaria) throws Exception {
		if (cuentaBancaria == null) {
			throw new Exception("La cuenta bancaria no puede ser nula");
		}
		if (tieneLaCuentaBancaria(cuentaBancaria)) {
			throw new Exception("La cuenta bancaria ya existe en el usuario");
		}
		for(int i = 0; i < this.cuentasBancarias.length; i++) {
			if (this.cuentasBancarias[i] == null) {
				this.cuentasBancarias[i]= cuentaBancaria;
				return;
			}
		}
		throw new Exception("No se pueden agregar mas de " + this.cuentasBancarias.length + " cuentas bancarias");
	}
	
	/**
	 * pre: 
	 * @param cuentaBancaria: la cuenta bancaria no puede ser nula
	 * @return devuelve verdadero si la cuenta existe en el usuario
	 * @throws Exception 
	 */
	public boolean tieneLaCuentaBancaria(CuentaBancaria cuentaBancaria) throws Exception {
		if (cuentaBancaria == null) {
			throw new Exception("La cuenta no puede ser nula");
		}
		for(int i = 0; i < this.cuentasBancarias.length; i++) {
			if ((this.cuentasBancarias[i] != null) &&
			   (this.cuentasBancarias[i].equals(cuentaBancaria))) {
				return true;				
			}
		}
		return false;
	}

	public void transferir(String cuentaOrigen, String cuentaDestino) {
		
	}
	
	public void depositar(CuentaBancaria cuentaBancaria, double monto) throws Exception {
		if (!tieneLaCuentaBancaria(cuentaBancaria)) {
			throw new Exception("EL usuario no tiene la cuenta " + cuentaBancaria);
		}
		if (monto <= 0) {
			throw new Exception("EL monto debe ser mayor a 0");
		}
		cuentaBancaria.acreditar(monto);
	}
	
	/**
	 * pre: 
	 * @param cuentaOrigen: no puede ser vacia y debe existir en el usuario
	 * @param cuentaDestino: no puede ser vacia y debe existir en el usuario
	 * @param monto: mayor a 0 y en $
	 * @throws Exception 
	 */
	public void transferir(CuentaBancaria cuentaOrigen, CuentaBancaria cuentaDestino, double monto) throws Exception {
		if (!tieneLaCuentaBancaria(cuentaOrigen)) {
			throw new Exception("EL usuario no tiene la cuenta " + cuentaOrigen);
		}
		if (!tieneLaCuentaBancaria(cuentaDestino)) {
			throw new Exception("EL usuario no tiene la cuenta " + cuentaDestino);
		}
		if (monto <= 0) {
			throw new Exception("EL monto debe ser mayor a 0");
		}
		if (cuentaOrigen.getSaldo() < monto) {
			throw new Exception("La cuenta de origen " + cuentaOrigen + " no tiene saldo. Disponible " + cuentaOrigen.getSaldo());
		}
		cuentaOrigen.retirar(monto);
		cuentaOrigen.acreditar(monto);
	}
	
//GETTERS SIMPLES -----------------------------------------------------------------------------------------

	/**
	 * pre: -
	 * @return devuelve el nombre del usuario
	 */
	public String getNombre() {
		return nombre;
	}

	/**
	 * pre: -
	 * @return devuelve el dni del usuario
	 */
	public String getDni() {
		return dni;
	}
	
	/**
	 * pre: -
	 * @return devuelve las cuentas bancarias 
	 */
	public CuentaBancaria[] getCuentasBancarias() {
		CuentaBancaria[] resultado = new CuentaBancaria[this.cuentasBancarias.length];
		for(int i = 0; i < this.cuentasBancarias.length; i++) {
			resultado[i] = this.cuentasBancarias[i];
		}
		return resultado;
	}
//SETTERS SIMPLES -----------------------------------------------------------------------------------------	
}
