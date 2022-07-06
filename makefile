.PHONY: FingVMB

all: FingVMB
		./FingVMB

FingVMB: 
	g++ -Wall -g -c FingVMB.cpp -o obj/FingVMB.o
	g++ -Wall -g -c src/Classes/FechaSistema.cpp -o obj/FechaSistema.o
	g++ -Wall -g -c src/Datatypes/DtFecha.cpp -o obj/DtFecha.o
	g++ -Wall -g -c src/Classes/Reserva.cpp -o obj/Reserva.o
	g++ -Wall -g -c src/Datatypes/DtComentario.cpp -o obj/DtComentario.o
	g++ -Wall -g -c src/Classes/SubscripcionNotificacion.cpp -o obj/SubscripcionNotificacion.o
	g++ -Wall -g -c src/Datatypes/DtServicio.cpp -o obj/DtServicio.o
	g++ -Wall -g -c src/Classes/Empleado.cpp -o obj/Empleado.o
	g++ -Wall -g -c src/Classes/Hostal.cpp -o obj/Hostal.o
	g++ -Wall -g -c Fabrica.cpp -o obj/Fabrica.o
	g++ -Wall -g -c src/Classes/ReservaIndividual.cpp -o obj/ReservaIndividual.o
	g++ -Wall -g -c src/Classes/Servicio.cpp -o obj/Servicio.o
	g++ -Wall -g -c src/Controllers/ControladorUsuario.cpp -o obj/ControladorUsuario.o
	g++ -Wall -g -c src/Datatypes/DtReservaGrupal.cpp -o obj/DtReservaGrupal.o
	g++ -Wall -g -c src/Classes/Habitacion.cpp -o obj/Habitacion.o
	g++ -Wall -g -c src/Datatypes/DtNotificacion.cpp -o obj/DtNotificacion.o
	g++ -Wall -g -c src/Datatypes/DtCalificacion.cpp -o obj/DtCalificacion.o
	g++ -Wall -g -c src/Datatypes/DtHabitacion.cpp -o obj/DtHabitacion.o
	g++ -Wall -g -c src/Classes/ReservaGrupal.cpp -o obj/ReservaGrupal.o
	g++ -Wall -g -c src/Controllers/ControladorEstadia.cpp -o obj/ControladorEstadia.o
	g++ -Wall -g -c src/Controllers/ControladorHostal.cpp -o obj/ControladorHostal.o
	g++ -Wall -g -c src/Datatypes/DtEstadia.cpp -o obj/DtEstadia.o
	g++ -Wall -g -c src/Classes/Estadia.cpp -o obj/Estadia.o
	g++ -Wall -g -c src/Classes/Calificacion.cpp -o obj/Calificacion.o
	g++ -Wall -g -c src/Datatypes/DtHostal.cpp -o obj/DtHostal.o
	g++ -Wall -g -c src/Classes/Usuario.cpp -o obj/Usuario.o
	g++ -Wall -g -c src/Controllers/ControladorHabitacion.cpp -o obj/ControladorHabitacion.o
	g++ -Wall -g -c src/Datatypes/DtReservaIndividual.cpp -o obj/DtReservaIndividual.o
	g++ -Wall -g -c src/Datatypes/DtEmpleado.cpp -o obj/DtEmpleado.o
	g++ -Wall -g -c src/Classes/Huesped.cpp -o obj/Huesped.o
	g++ -Wall -g -c src/Datatypes/DtReserva.cpp -o obj/DtReserva.o
	g++ -Wall -g -c src/Datatypes/DtUsuario.cpp -o obj/DtUsuario.o
	g++ -Wall -g -c src/Controllers/ControladorServicio.cpp -o obj/ControladorServicio.o
	g++ -Wall -g -c src/Classes/Comentario.cpp -o obj/Comentario.o
	g++ -Wall -g -c src/Controllers/ControladorReserva.cpp -o obj/ControladorReserva.o
	g++ -Wall -g -c src/Datatypes/DtHuesped.cpp -o obj/DtHuesped.o
	g++ -Wall -g -c src/Classes/Notificacion.cpp -o obj/Notificacion.o
	g++ -Wall -g -c Test.cpp -o obj/Test.o

	g++ -g obj/Notificacion.o obj/FechaSistema.o obj/DtFecha.o obj/Reserva.o obj/DtComentario.o obj/SubscripcionNotificacion.o obj/DtServicio.o obj/Empleado.o obj/Hostal.o obj/Fabrica.o obj/ReservaIndividual.o obj/Servicio.o obj/ControladorUsuario.o obj/DtReservaGrupal.o obj/Habitacion.o obj/DtNotificacion.o obj/DtCalificacion.o obj/DtHabitacion.o obj/ReservaGrupal.o obj/FingVMB.o obj/ControladorEstadia.o obj/ControladorHostal.o obj/DtEstadia.o obj/Estadia.o obj/Calificacion.o obj/DtHostal.o obj/Usuario.o obj/ControladorHabitacion.o obj/DtReservaIndividual.o obj/DtEmpleado.o obj/Huesped.o obj/DtReserva.o obj/DtUsuario.o obj/ControladorServicio.o obj/Comentario.o obj/ControladorReserva.o obj/DtHuesped.o obj/Test.o -o FingVMB

clean:
	rm obj/*
	rm FingVMB
