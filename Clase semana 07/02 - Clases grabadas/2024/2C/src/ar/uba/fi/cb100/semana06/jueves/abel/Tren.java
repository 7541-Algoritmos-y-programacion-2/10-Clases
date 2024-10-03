package ar.uba.fi.cb100.semana06.jueves.abel;

public class Tren {
	//TODO: pre y post
	//Atributos -----------------------------------------------------------------------------------------------------------
	private final int CANTIDADMAXIMALOCOMOTORAS=3;
	//Atributos de clase --------------------------------------------------------------------------------------------------
	private Locomotora[] locomotoras=null;
	
	//Constructor ---------------------------------------------------------------------------------------------------------
	public Tren(int cantidadLocomotoras) throws Exception {
		if(!Validaciones.esMayorAUno(cantidadLocomotoras) ||
				cantidadLocomotoras>this.CANTIDADMAXIMALOCOMOTORAS) {
			throw new Exception("El numero de locomotoras debe estar en el rango 1 - "+ this.CANTIDADMAXIMALOCOMOTORAS);
		}
		this.locomotoras=new Locomotora[cantidadLocomotoras];
		for(int i=0;i<this.CANTIDADMAXIMALOCOMOTORAS;i++) {
			this.locomotoras[i]=null;
		}
		for(int j=0;j<cantidadLocomotoras;j++) {
			this.locomotoras[j]=new Locomotora(0);
		}
	}
	
	//Getters -------------------------------------------------------------------------------------------------------------
	
	public int getCantidadLocomotoras() {
		return this.locomotoras.length;
	}
	
	public Locomotora[] getLocomotoras() {
		Locomotora[] resultado=new Locomotora[this.locomotoras.length];
		for(int i=0;i<this.locomotoras.length;i++) {
			resultado[i]=this.locomotoras[i];
		}
		return resultado;
	}
	
	public double getCargaMaximaVagon() {
		double resultado=0;
		for(int i=0;i<this.locomotoras.length;i++) {
			if(this.locomotoras[i]!=null) {
				resultado=this.locomotoras[i].getCargaMaximaVagon();
			}
		}
		return resultado;
	}
	
	public double getCargaMaximaTren() {
		double resultado=0.0;
		for(int i=0;i<this.locomotoras.length;i++) {
			if(this.locomotoras[i]!=null) {
				resultado+=this.locomotoras[i].getCargaMaxima();
			}
		}
		return resultado;
	}
	
	public double getCargaActualTren() {
		double resultado=0.0;
		for(int i=0;i<this.locomotoras.length;i++) {
			if(this.locomotoras[i]!=null) {
				resultado+=this.locomotoras[i].getCargaActual();
			}
		}
		return resultado;
	}
	
	public double getCapacidadRestanteTren() {
		return getCargaMaximaTren() - getCargaActualTren();
	}
	
	//Metodos -------------------------------------------------------------------------------------------------------------
	
		public void agregarCarga(double carga) throws Exception {
			if(!Validaciones.esNatural(carga) || 
					carga>getCargaMaximaVagon()) {
				throw new Exception("La carga debe estar en el rango 1 - "+getCargaMaximaVagon()+"KG");
			}
			boolean agregado=false;
			int i=0;
			while(!agregado && i<this.locomotoras.length) {
				if(this.locomotoras[i]!=null) {
					agregado=this.locomotoras[i].agregarCarga(carga);
				}
				i++;
			}
			if(!agregado) {
				throw new Exception("No se pudo agregar la carga sobrepasa la capacidad de los vagones");
			}
		}
		
		public void eliminarCarga(double carga) throws Exception {
			if(!Validaciones.esNatural(carga) ||
					carga>getCargaActualTren()) {
				throw new Exception("La carga a eliminar debe estar en el rango 1 - "+getCargaActualTren()+ " KG");
			}
			
			//si paso la verificacion significa que puedo quitar el peso ingresado
			boolean eliminada=false;
			int i=0;
			double restante=carga;
			
			while(!eliminada && i<this.locomotoras.length) {
				if(this.locomotoras[i]!=null) {
					this.locomotoras[i].eliminarCarga(carga);
					if(restante==0) {
						eliminada=true;
					}
					i++;
				}
			}
			
		}
		
}
