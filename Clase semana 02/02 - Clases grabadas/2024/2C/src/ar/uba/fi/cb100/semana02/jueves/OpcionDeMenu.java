package ar.uba.fi.cb100.semana02.jueves;

public enum OpcionDeMenu {
	Punto11,
	Punto12,
	Punto14,
	Salir;
	
	public static OpcionDeMenu getOpcionDeMenu(int valor) {
		if (valor == 1) {
			return Punto11;
		}
		if (valor == 2) {
			return Punto12;
		}
		if (valor == 3) {
			return Punto14;
		}
		return Salir;
	}
}
