#include "Test.h"
void CargarDatos(Fabrica* f, FechaSistema* fecha)
{
	IControladorUsuario* u = f->getIControladorUsuario();
	IControladorHostal* h = f->getIControladorHostal();
	IControladorEstadia* e = f->getIControladorEstadia();
	IControladorHabitacion* hab = f->getIControladorHabitacion();
	IControladorReserva* r = f->getIControladorReserva();

//Empleados (Alta de Usuario)
	u->registrarUsuario("Emilia", "emilia@mail.com", "123");
	u->ingresarCargo(Recepcion);
	u->confirmarUsuario(0);

	u->registrarUsuario("Leonardo", "leo@mail.com", "123");
	u->ingresarCargo(Recepcion);
	u->confirmarUsuario(0);

	u->registrarUsuario("Alina", "alina@mail.com", "123");
	u->ingresarCargo(Administracion);
	u->confirmarUsuario(0);

	u->registrarUsuario("Barliman", "barli@mail.com", "123");
	u->ingresarCargo(Recepcion);
	u->confirmarUsuario(0);

//Huespedes (Alta de Usuario)
	u->registrarUsuario("Sofia", "sofia@mail.com", "123");
	u->setEsFinger(1);
	u->confirmarUsuario(1);

	u->registrarUsuario("Frodo", "frodo@mail.com", "123");
	u->setEsFinger(1);
	u->confirmarUsuario(1);

	u->registrarUsuario("Sam", "sam@mail.com", "123");
	u->setEsFinger(0);
	u->confirmarUsuario(1);

	u->registrarUsuario("Merry", "merry@mail.com", "123");
	u->setEsFinger(0);
	u->confirmarUsuario(1);

	u->registrarUsuario("Pippin", "pippin@mail.com", "123");
	u->setEsFinger(0);
	u->confirmarUsuario(1);

	u->registrarUsuario("Seba", "seba@mail.com", "123");
	u->setEsFinger(1);
	u->confirmarUsuario(1);


//Hostels (Alta de Hostal)
	h->ingresarHostal("La posada del finger", "Av de la playa 123, Maldonado", "099111111");
	h->confirmarHostal();

	h->ingresarHostal("Mochileros", "Rambla Costanera 333, Rocha, Maldonado", "42579512");
	h->confirmarHostal();

	h->ingresarHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");
	h->confirmarHostal();

	h->ingresarHostal("Altos de Fing", "Av del Toro 1424", "099892992");
	h->confirmarHostal();

	h->ingresarHostal("Caverna Lujosa", "Amaya 2515", "233233235");
	h->confirmarHostal();


//Habitaciones (Alta de Habitacion)
	hab->seleccionarHostal("La posada del finger");
	hab->ingresarHabitacion(1, 40, 2);
	hab->crearHabitacion();

	hab->seleccionarHostal("La posada del finger");
	hab->ingresarHabitacion(2, 10, 7);
	hab->crearHabitacion();

	hab->seleccionarHostal("La posada del finger");
	hab->ingresarHabitacion(3, 30, 3);
	hab->crearHabitacion();

	hab->seleccionarHostal("La posada del finger");
	hab->ingresarHabitacion(4, 5, 12);
	hab->crearHabitacion();

	hab->seleccionarHostal("Caverna Lujosa");
	hab->ingresarHabitacion(1, 3, 2);
	hab->crearHabitacion();

	hab->seleccionarHostal("El Pony Pisador");
	hab->ingresarHabitacion(1, 9, 5);
	hab->crearHabitacion();


//Asignacion de empleados a hostels (Asignar empleado a hostal)
	h->seleccionarHostal("La posada del finger");
	h->asignarEmpleado("emilia@mail.com", Recepcion);

	h->seleccionarHostal("Mochileros");
	h->asignarEmpleado("leo@mail.com", Recepcion);

	h->seleccionarHostal("Mochileros");
	h->asignarEmpleado("alina@mail.com", Administracion);

	h->seleccionarHostal("El Pony Pisador");
	h->asignarEmpleado("barli@mail.com", Recepcion);


//Reserva (Realizar Reserva)
	r->seleccionarHostal("La posada del finger");
	r->seleccionarHabitacion(1);
	r->seleccionarUsuario("sofia@mail.com");
	r->realizarReservaIndividual(
			DtFecha(14, 1, 5, 2022),
			DtFecha(10, 10, 5, 2022));
	r->confirmarReserva(true);

	// ----------------------

	r->seleccionarHostal("El Pony Pisador");
	r->seleccionarHabitacion(1);

	map<string, string> listaDeHuespedes;
	listaDeHuespedes["frodo@mail.com"] = "frodo@mail.com";
	listaDeHuespedes["sam@mail.com"] = "sam@mail.com";
	listaDeHuespedes["merry@mail.com"] = "merry@mail.com";
	listaDeHuespedes["pippin@mail.com"] = "pippin@mail.com";

	r->realizarReservaGrupal(
			DtFecha(20, 4, 1, 2001),
			DtFecha(2, 5, 1, 2001),
			listaDeHuespedes,
			"pippin@mail.com",
			1);
	r->confirmarReserva(true);

	// ----------------------

	r->seleccionarHostal("La posada del finger");
	r->seleccionarHabitacion(1);
	r->seleccionarUsuario("sofia@mail.com");
	r->realizarReservaIndividual(
			DtFecha(14, 7, 6, 2022),
			DtFecha(11, 30, 6, 2022));
	r->confirmarReserva(true);

	// ----------------------

	r->seleccionarHostal("Caverna Lujosa");
	r->seleccionarHabitacion(1);
	r->seleccionarUsuario("seba@mail.com");
	r->realizarReservaIndividual(
			DtFecha(14, 10, 6, 2022),
			DtFecha(11, 30, 6, 2022));
	r->confirmarReserva(true);


//Estadias (Registrar Estadia)
	e->seleccionarReserva(1);
	fecha->setFecha(18, 1, 5, 2022);
	e->registrarEstadia("sofia@mail.com");

	e->seleccionarReserva(2);
	fecha->setFecha(21, 4, 1, 2001);
	e->registrarEstadia("frodo@mail.com");

	e->seleccionarReserva(2);
	fecha->setFecha(21, 4, 1, 2001);
	e->registrarEstadia("sam@mail.com");

	e->seleccionarReserva(2);
	fecha->setFecha(21, 4, 1, 2001);
	e->registrarEstadia("merry@mail.com");

	e->seleccionarReserva(2);
	fecha->setFecha(21, 4, 1, 2001);
	e->registrarEstadia("pippin@mail.com");

	e->seleccionarReserva(4);
	fecha->setFecha(18, 7, 6, 2022);
	e->registrarEstadia("seba@mail.com");

//Finalizacion de estadias (Finalizar Estadia)
	fecha->setFecha(9, 10, 5, 2022);
	e->finalizarEstadia("sofia@mail.com", "La posada del finger");

	fecha->setFecha(2, 5, 1, 2001);
	e->finalizarEstadia("frodo@mail.com", "El Pony Pisador");

	fecha->setFecha(22, 15, 6, 2022);
	e->finalizarEstadia("seba@mail.com", "Caverna Lujosa");

//Calificar estadia (Calificar Estadia)
	e->seleccionarHostal("La posada del finger");
	e->seleccionarEstadia(1);
	fecha->setFecha(18, 11, 5, 2022);
	e->enviarCalificacion(
			3,
			"Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo.",
			"sofia@mail.com");

	e->seleccionarHostal("El Pony Pisador");
	e->seleccionarEstadia(2);
	fecha->setFecha(3, 5, 1, 2001);
	e->enviarCalificacion(
			2,
			"Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos.",
			"frodo@mail.com");

	e->seleccionarHostal("Caverna Lujosa");
	e->seleccionarEstadia(6);
	fecha->setFecha(23, 15, 6, 2022);
	e->enviarCalificacion(
			1,
			"Había pulgas en la habitación. Que lugar más mamarracho!!",
			"seba@mail.com");

//Comentar calificacionPromedio (Comentar Calificacion)
	e->seleccionarEmpleado("barli@mail.com");
	e->ingresarRespuestaComentario("Desapareció y se fue sin pagar.", 2);
}

