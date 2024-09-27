package ar.uba.fi.cb100.semana06.jueves.alesio;

public class Tren {
	private int MINIMO_DE_LOCOMOTORAS = 1;
	private int MAXIMO_DE_LOCOMOTORAS = 3;
	private Locomotora[] locomotoras = null;
	
	public Tren(int locomotoras) throws Exception {
		if ((locomotoras < MINIMO_DE_LOCOMOTORAS) ||
			(locomotoras > MAXIMO_DE_LOCOMOTORAS)) {
			throw new Exception("El tren debe tener de 1 a 3 locomotoras");
		}
		this.locomotoras = new Locomotora[locomotoras];
		for (int i = 0; i < this.locomotoras.length; i++) {
			this.locomotoras[i] = new Locomotora();
		}
	}
	
	public int getCapacidadActual() {
		int res = 0;
		for (int i = 0; i < this.locomotoras.length; i++) {
			res += this.locomotoras[i].getCapacidadActual();
		}
		return res;
	}
	
	public int getCapacidadMaxima() {
		int res = 0;
		for (int i = 0; i < this.locomotoras.length; i++) {
			res += this.locomotoras[i].getCapacidadMaxima();
		}
		return res;
	}
	
	public int getCapacidadRestante() {
		int res = 0;
		for (int i = 0; i < this.locomotoras.length; i++) {
			res += this.locomotoras[i].getCapacidadRestante();
		}
		return res;
	}
}
