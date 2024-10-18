package ar.uba.fi.cb100.semana09.jueves.restaurante;

import java.util.Random;

/**
 * Ejercicio: https://github.com/7541-Algoritmos-y-programacion-2/10-Clases/blob/main/Evaluaciones/Parciales/2022%20-%202C%20-%20PARCIAL%20II.pdf
 */
public class Restaurante {
//ATRIBUTOS DE CLASE --------------------------------------------------------------------------------------
//ATRIBUTOS -----------------------------------------------------------------------------------------------
	
	private Mozo[] mesas = null;
	private Mozo[] mozos = null;
	private double mayorPropina = 0.0;
	
//CONSTRUCTORES -------------------------------------------------------------------------------------------
		
	/**
	 * 
	 * @param cantidadMaximaDeMesas
	 */
	public Restaurante(int cantidadMaximaDeMesas) {
		//validar
		this.mesas = new Mozo[cantidadMaximaDeMesas];
		this.mozos = new Mozo[cantidadMaximaDeMesas];
		for(int i = 0; i < this.mesas.length; i++) {
			this.mesas[i] = null;
			this.mozos[i] = null;
		}
	}
	
	/**
	 * 
	 * @return
	 * @throws Exception 
	 */
	public int ingresarMozo() throws Exception {
		return ingresarMozo(new Mozo());
	}
	
	public int ingresarMozo(Mozo mozo) throws Exception {
		//validar
		for(int i = 0; i < this.mozos.length; i++) {
			if (this.mozos[i] == null) {
				this.mozos[i] = mozo;
				return (i+1);
			}
		}
		throw new Exception("No hay mas lugar");
	}
	
	public int solicitarMesa() throws Exception {
		for(int i = 0; i < this.mesas.length; i++) {
			if (this.mesas[i] == null) {
				this.mesas[i] = this.getMozoLibreOAlAzar();
				return (i+1);
			}
		}
		throw new Exception("No hay mas lugar");
	}
	
	public void cerrarMesa(int numeroDeMesa, double propina) {
		//validar
		this.mesas[numeroDeMesa-1].agregarPropina(propina);
		this.mesas[numeroDeMesa-1] = null;
		if (propina >= this.mayorPropina) {
			this.mayorPropina = propina;
		}
	}
	
//METODOS DE CLASE ----------------------------------------------------------------------------------------
//METODOS GENERALES ---------------------------------------------------------------------------------------
//METODOS DE COMPORTAMIENTO -------------------------------------------------------------------------------
//GETTERS SIMPLES -----------------------------------------------------------------------------------------
	
	public double getMayorPropina() {
		return this.mayorPropina;
	}
	
	private Mozo getMozoLibreOAlAzar() {
		//validar this.getCantidadDeMozos()
		for(int i = 0; i < this.getCantidadDeMozos(); i++) {
			boolean ocupado = false;
			for(int j =0; i < this.mesas.length; j++) {
				if ((this.mesas[j] != null) &&
				    (this.mesas[j] == this.mozos[i])) {
					ocupado = true;
					break;
				}
			}
			if (!ocupado) {
				return this.mozos[i];
			}
		}
		return this.mozos[new Random().nextInt(this.getCantidadDeMozos())];
	}
	
	public int getCantidadDeLugaresParaMozos() {
		return this.mozos.length;
	}
	
	public int getCantidadDeMozos() {
		for(int i = 0; i < this.mozos.length; i++) {
			if (this.mozos[i] == null) {
				return i;
			}
		}
		return this.mozos.length;
	}
	
//SETTERS SIMPLES -----------------------------------------------------------------------------------------
	
}
