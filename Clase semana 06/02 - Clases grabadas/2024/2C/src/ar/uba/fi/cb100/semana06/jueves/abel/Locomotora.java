package ar.uba.fi.cb100.semana06.jueves.abel;

public class Locomotora {
	//TODO: pre y post de metodos
	
	//Atriubutos --------------------------------------------------------------------
	public final int CANTIDAD_DE_VAGONES_MAXIMA=10;
	
	//Atributos de clase ------------------------------------------------------------
	private Vagon[] vagones=null;
	
	//Constructor --------------------------------------------------------------------
	
	public Locomotora(int cantidadVagones) throws Exception {
		if(Validaciones.esNatural(cantidadVagones) ||
				cantidadVagones > CANTIDAD_DE_VAGONES_MAXIMA ) {
			throw new Exception("La cantidad de vagones debe estar en el rango 0 - "+CANTIDAD_DE_VAGONES_MAXIMA);
		}
		//ahora creo los vagones pedidos, los creo con carga =  0.0
		vagones=new Vagon[CANTIDAD_DE_VAGONES_MAXIMA];
		for(int i=0;i<this.CANTIDAD_DE_VAGONES_MAXIMA;i++) {
			this.vagones[i]=null;
		}
		//ahora creo los vagones pedidos, los creo con carga =  0.0
		for(int j=0;j<cantidadVagones;j++) {
			vagones[j]=new Vagon(0.0);
		}
	}
	
	//Getters -----------------------------------------------------------------------------
	
	public int getCantidadVagones() {
		return this.vagones.length;
	}
	
	public double getCargaMaximaVagon() {
		double resultado=0;
		for(int i=0;i<this.vagones.length;i++) {
			if(this.vagones[i]!=null) {
				resultado=this.vagones[i].getCargaMaxima();
			}
		}
		return resultado;
	}
	
	//ahora veo si lo saco
	public Vagon[] getVagones() {
		Vagon[] resultado = new Vagon[this.vagones.length];
		for (int i=0;i<this.vagones.length;i++) {
			resultado[i]=this.vagones[i];
		}
		return resultado;
	}
	
	public double getCargaActual() {
		double resultado=0.0;
		for(int i=0;i<this.vagones.length;i++) {
			if(this.vagones[i]!=null) {
			resultado+=this.vagones[i].getCargaActual();
			}
		}
		return resultado;
	}
	
	public double getCargaMaxima() {
		double resultado=0;
		for(int i=0;i<this.vagones.length;i++) {
			if(this.vagones[i]!=null) {
				resultado+=this.vagones[i].getCargaMaxima();
			}
		}
		return resultado;
	}
	
	//Metodos -------------------------------------------------------------------------------------------------------
	
	//solo puedo agregar un vagon vacio
	public void agregarVagon() throws Exception {
		boolean agregado=false;
		int i=0;
		while(!agregado && i<this.vagones.length) {
			if(this.vagones[i]==null) {
				//el vagon se crea vacio
				this.vagones[i]=new Vagon(0.0);
				agregado=true;
			}
			i++;
		}
		if(!agregado) {
			throw new Exception("No se pueden agergar mas vagones, se alcanzo la capacidad maxima: "+this.CANTIDAD_DE_VAGONES_MAXIMA);
		}
	}
	
	public void eliminarVagon(int numeroVagon) throws Exception {
		if(!Validaciones.esMayorAUno(numeroVagon) ||
				numeroVagon>CANTIDAD_DE_VAGONES_MAXIMA) {
			throw new Exception("Numero de vagon fuera de rango. Debe ir de 1 a "+CANTIDAD_DE_VAGONES_MAXIMA);
		}
		if(this.vagones[numeroVagon-1]==null) {
			throw new Exception("El vagon indicado no existe");
		}
		//el numeroVagon-1 es porque tengo que pasar del numero de vagon a su posicion en el vector
		if(this.vagones[numeroVagon-1].getCargaActual()!=0.0) {
			throw new Exception("El vagon no se puede eliminar porque tiene carga restante: 				"+this.vagones[numeroVagon-1].getCargaActual()+" KG");
		}
		//si paso todas las verificaciones el vagon existe y esta dentro del rango asi que lo elimino
		this.vagones[numeroVagon-1]=null;
	}
	
	
	public boolean agregarCarga(double carga) throws Exception {
		boolean agregado=false;
		int i=0;
		while(!agregado && i<this.vagones.length) {
			//puede ser que en el medio quite algun vagon
			if(this.vagones[i]!=null) {
			if(this.vagones[i].getCargaActual()+carga<=this.vagones[i].CARGAMAXIMA) {
				this.vagones[i].agregarCarga(carga);
				agregado=true;
			}
			i++;
			}
		}
		return agregado;
	}
	
	public double eliminarCarga(double cargaAEliminar) throws Exception {
		
		if(!Validaciones.esNatural(cargaAEliminar)){
				throw new Exception("La carga a eliminar debe ser positiva");
				}
		for(int i=0;i<this.vagones.length;i++) {
			if(this.vagones[i]!=null) {
				if(this.vagones[i].getCargaActual() - cargaAEliminar <0) {
					this.vagones[i].vaciarVagon();
					cargaAEliminar -= this.vagones[i].getCargaActual();
				}else {
					this.vagones[i].eliminarCarga(cargaAEliminar);
					cargaAEliminar=0;
				}
			}
		}
			
		return cargaAEliminar;
	}
	
	
}
