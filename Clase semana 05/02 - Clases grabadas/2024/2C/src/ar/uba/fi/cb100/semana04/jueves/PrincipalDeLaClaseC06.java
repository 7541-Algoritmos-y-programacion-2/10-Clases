package ar.uba.fi.cb100.semana04.jueves;

import java.time.LocalDateTime;

public class PrincipalDeLaClaseC06 {
	
	public static void main(String[] args) throws Exception {

		Transaccion transaccion = new Transaccion(LocalDateTime.now(), 100);
		System.out.println("La transaccion: " + transaccion.toString());
		
		
		Usuario usuario = new Usuario("Gustavo", "10115424", 5);
		usuario.agregarCuentaBancaria( new CuentaBancaria( CuentaBancaria.getNumeroDeCuentaActual() + "/15", 100));
		usuario.agregarCuentaBancaria( new CuentaBancaria( CuentaBancaria.getNumeroDeCuentaActual() + "/15", 100));
		
		
		CuentaBancaria[] cuentas = usuario.getCuentasBancarias();
		if (cuentas.length >= 2) {
			usuario.depositar(cuentas[0], 1000.0);
			usuario.transferir(cuentas[0], cuentas[1], 100.0);
		}
		
		
	}

}
