//Pre: Recibe una especialidad, dos horarios, sabiendo que uno debe ser mayor que otro y un modelo
//Post: Devuelve falso si alguno de estos datos no existe o si los horarios no cumplen lo que dicen cumplir, verdadero en caso contrario.
bool datosValidos(string especialidad,unsigned int horaDesde,unsigned int horaHasta, string modeloDeAuto){
	bool noCumpleRequisitos=false;
	if (especialidad==NULL || modeloDeAuto==NULL || horaDesde==NULL || horaHasta== NULL || horaDesde>horaHasta){
		noCumpleRequisitos=true;
	}
	return noCumpleRequisitos;
}

//Pre: Recibe una especialidad y una lista de especialidades
//Post: Devuelve verdadero si alguno de las especialidad es igual a la recibida
bool atiendeEspecialidad(string especialidad,Lista<String*>* especialidadesAtendidas ){
	especialidadesAtendidas->reiniciarCursor();
	bool atiendeEspecialidad=false;
	while(especialidadesAtendidas->avanzarCursor() && !atiendeEspecialidad){
		if(especialidadesAtendidas->obtenerCursor==string){
			atiendeEspecialidad=true;
		}

	}
	return perteneceALista;
	
}
//Pre: Recibe un modelo y una lista de modelos
//Post: Devuelve verdadero si alguno de los modelos es igual al recibido
bool tieneElModelo(string modelo,Lista<String*>* modelos ){
	modelos->reiniciarCursor();
	bool tieneModelo=false;
	while(modelos->avanzarCursor() && !tieneModelo){
		if(modelos->obtenerCursor==modelo){
			tieneModelo=true;
		}

	}
	return tieneModelo;
	
}

//Pre:  Recibe una lista de turnos y un horario pedido
//Post: Devuelve verdadero si tiene turno  algun turno desocupado tiene ese horario, falso en caso contrario
bool tieneTurnoDisponible(Lista<Turno*>* turnosDelTaller, unsigned int horaDesdeSolicitada, unsigned  int horaHastaSolicitada){
	bool tieneTurno=false, turnoOcupado, horaDesdeDisponible, horaHastaDisponible; 
	turnosDelTaller->reiniciarCursor();
	 

	Turno* turnoActual;
	while (turnosDelTaller->avanzarCursor() &&  !tieneTurno){
		turnoActual=turnosDelTaller->obtenerCursor();
		horaDesdeDisponible= turnoActual->obtenerHoraDesde() <=horaDesdeSolicitada;
		horaHastaDisponible= turnoActual->obtenerHoraHasta() >=horaHastaSolicitada;
		turnoOcupado=turnoActual->estaOcupado();
		if (horaDesdeDisponible && horaHastaDisponible && !turnoOcupado){
			tieneTurno=true;
		}

	}
	return tieneTurno;
}

//Pre:
//Recibe una Cola de Talleres, una especialidad, un modelo de auto y un horario en el que se puede ir al taller
/*Post::
 Devuelve una Lista con todos aquellos talleres en la cola que que atendian la especialidad, el modelo, 
y estaban desocupados en el horario pedido.*/
Lista <Taller*>* buscarTallerConTurnoLibre(Cola<Taller*>* talleresDisponibles, string especialidad,
					    unsigned int horaDesde,unsigned int horaHastas, string modeloDeAuto){
if (!datosValidos(especialidad,horaDesde,horaHasta,modeloDeAuto)){
	throw "datos Invalidos."
}
Lista <Taller*>* talleresConTurnoLibre=new Lista<Taller*>*;

while(!talleresDisponibles->vacia()){
	Taller* tallerActual=talleresDisponibles->desacolar();
	
	if (atiendeEspecialidad(especialidad,tallerActual->obtenerEspecialidades() && !tieneElModelo(tallerActual->modelosNoAtendidos(),modeloDeAuto)&&
				tieneTurnoDisponible(tallerActual->obtenerTurnos(),horaDesde,horaHasta)){
		talleresConTurnoLibre->add(tallerActual);
				
		}
	}
	return talleresConTurnoLibre;
}
					
