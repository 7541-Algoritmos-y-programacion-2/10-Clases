package ar.uba.fi.cb100.semana06.jueves.alesio;

public class Vagon {
	private int capacidad = 0;
	private int capacidadMaxima = 0;
	
	private Vagon prox = null;
	
	public Vagon(int capacidadMaxima) throws Exception {
		if (capacidad < 1) {
			throw new Exception("El vagón debe poder transportar carga");
		}
		this.capacidadMaxima = capacidadMaxima;
	}
	
	public void sumarCarga(int carga) throws Exception {
		if (this.capacidad + carga > this.capacidadMaxima) {
			throw new Exception("El vagón no puede cargar más carga");
		}
		this.capacidad += carga;
	}
	
	public void restarCarga(int carga) throws Exception {
		if (this.capacidad - carga < 0) {
			throw new Exception("No busques más de lo que el vagón tiene");
		}
		this.capacidad -= carga;
	}
	
	public int getCapacidadActual() {
		return this.capacidad;
	}
	
	public int getCapacidadMaxima() {
		return this.capacidadMaxima;
	}
	
	public int getCapacidadRestante() {
		return this.capacidadMaxima - this.capacidad;
	}
	
	public Vagon getProximo() {
		return this.prox;
	}
	
	public void setProximo(Vagon vagon) {
		this.prox = vagon;
	}
}
