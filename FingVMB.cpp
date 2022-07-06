#include <iostream>

#include "Fabrica.h"
#include "include/Classes/FechaSistema.h"
#include "include/Datatypes/DtHuesped.h"
#include "include/Datatypes/DtReservaIndividual.h"
#include "include/Datatypes/DtReservaGrupal.h"
#include "include/Datatypes/DtUsuario.h"
#include "include/Datatypes/DtCalificacion.h"
#include "include/Datatypes/DtFecha.h"
#include "Test.h"

#include <string>
#include <map>
using namespace std;

void AltaDeHabitacionCasoDeUso(IControladorHabitacion* controladorHabitacion);
void AltaDeUsuarioCasoDeUso(IControladorUsuario* controladorUsuario);
void ConsultaDeUsuarioCasoDeUso(IControladorUsuario* controladorUsuario);
void AsignarEmpleadoAHostalCasoDeUso(IControladorHostal* controladorHostal);
void RealizarReservaCasoDeUso(IControladorReserva* controladorReserva, FechaSistema* fecha);
void ModificarFechaDelSistemaCasoDeUso(FechaSistema* fechaSistema);
void AltaDeHostalCasoDeUso(IControladorHostal* controladorHostal);
void ConsultarTop3HostalesCasoDeUso(IControladorHostal* controladorHostal);
void RegistrarEstadiaCasoDeUso(IControladorEstadia* controladorEstadia);
void FinalizarEstadiaCasoDeUso(IControladorEstadia* controladorEstadia);
void CalificarEstadiaCasoDeUso(IControladorEstadia* controladorEstadia);
void ComentarCalificacionCasoDeUso(IControladorEstadia* controladorEstadia);
void ConsultaDeHostalCasoDeUso(IControladorHostal* controladorHostal);
void ConsultaDeReservaCasoDeUso(IControladorReserva* controladorReserva);
void ConsultaDeEstadiaCasoDeUso(IControladorEstadia* controladorEstadia);
void BajaDeReservaCasoDeUso(IControladorReserva* controladorReserva);
void SuscribirseANotificacionesCasoDeUso(IControladorUsuario* controladorUsuario);
void ConsultaDeNotificacionesCasoDeUso(IControladorUsuario* controladorUsuario);
void EliminarSuscripcionCasoDeUso(IControladorUsuario* controladorUsuario);
void ListarHabitaciones(IControladorHabitacion* controladorHabitacion);
void ListarReservas(IControladorReserva* controladorReserva);
void ListarEstadias(IControladorEstadia* controladorEstadia);
void ListarHostalesRegistrados(IControladorHostal* controladorHostal);
void ListarCalificaciones(IControladorEstadia* controladorEstadia);

// Menú de opciones
void opciones(int& opc)
{
	cout << "+------------------------------------------------------------------+" << endl;
	cout << "| Bienvenido/a.                                                    |" << endl;
	cout << "| Elija una de las siguientes opciones digitandola.                |" << endl;
	cout << "| Luego, pulse la tecla Intro.                                     |" << endl;
	cout << "|                                                                  |" << endl;
	cout << "|   1) Modificar Fecha del Sistema   2) Alta de Usuario            |" << endl;
	cout << "|   3) Alta de Hostal                4) Alta de Habitación         |" << endl;
	cout << "|   5) Realizar Reserva              6) Registrar Estadia          |" << endl;
	cout << "|   7) Finalizar Estadia             8) Calificar Estadia          |" << endl;
	cout << "|   9) Asignar Empleado a Hostal    10) Suscribirse a Notificación |" << endl;
	cout << "|  11) Consulta de Notificaciones   12) Comentar Calificacion      |" << endl;
	cout << "|  13) Consulta de Usuario          14) Consulta de Hostal         |" << endl;
	cout << "|  15) Consulta de Reserva          16) Consulta de Estadía        |" << endl;
	cout << "|  17) Consultar top 3 de hostales  18) Eliminar Suscripcion       |" << endl;
	cout << "|  19) Baja de Reserva              20) Listar Hostales*           |" << endl;
	cout << "|  21) Listar Habitaciones*         22) Listar Reservas*           |" << endl;
	cout << "|  23) Listar Estadias*             24) Listar Calificaciones*     |" << endl;
	cout << "|  25) Cargar Datos                  0) Salir                      |" << endl;
	cout << "+------------------------------------------------------------------+\n" << endl;

	cout << "Opción a elegir: " << endl;
	cin >> opc;
	while (cin.fail())
	{
		cout << "Opción a elegir: " << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> opc;
	}
	cout << endl;
}

// Sobrecarga de operador << para EstadoReserva
ostream& operator<<(ostream& os, enumEstado t)
{
	if (t == Abierta)
		os << "Abierta";
	else if (t == Cerrada)
		os << "Cerrada";
	else if (t == Cancelada)
		os << "Cancelada";

	return os;
}

// Sobrecarga de operador << para DtFecha
ostream& operator<<(ostream& os, DtFecha f)
{
	if (f.getDia() < 10)
		os << "0";
	os << f.getDia() << "/";
	if (f.getMes() < 10)
		os << "0";
	os << f.getMes() << "/" << f.getAnio() << " " << f.getHora() << "hs ";

	return os;
}

// Sobrecarga de operador << para enumCargo
ostream& operator<<(ostream& os, enumCargo c)
{
	if (c == Administracion)
		os << "Administracion";
	else if (c == Limpieza)
		os << "Limpieza";
	else if (c == Recepcion)
		os << "Recepcion";
	else if (c == Infraestructura)
		os << "Infraestructura";
	return os;
}

int main()
{
	Fabrica* f = new Fabrica();

	IControladorHabitacion* controladorHabitacion = f->getIControladorHabitacion();
	IControladorEstadia* controladorEstadia = f->getIControladorEstadia();
	IControladorUsuario* controladorUsuario = f->getIControladorUsuario();
	IControladorHostal* controladorHostal = f->getIControladorHostal();
	IControladorReserva* controladorReserva = f->getIControladorReserva();

	FechaSistema* fecha = FechaSistema::getInstancia();

	int opc = -1;
	opciones(opc);
	while (opc != 0)
	{
		switch (opc)
		{
		case 1:
		{
			ModificarFechaDelSistemaCasoDeUso(fecha);
			break;
		}
		case 2:
		{
			AltaDeUsuarioCasoDeUso(controladorUsuario);
			break;
		}
		case 3:
		{
			AltaDeHostalCasoDeUso(controladorHostal);
			break;
		}
		case 4:
		{
			AltaDeHabitacionCasoDeUso(controladorHabitacion);
			break;
		}
		case 5:
		{
			RealizarReservaCasoDeUso(controladorReserva, fecha);
			break;
		}
		case 6:
		{
			RegistrarEstadiaCasoDeUso(controladorEstadia);
			break;
		}
		case 7:
		{
			FinalizarEstadiaCasoDeUso(controladorEstadia);
			break;
		}
		case 8:
		{
			CalificarEstadiaCasoDeUso(controladorEstadia);
			break;
		}
		case 9:
		{
			AsignarEmpleadoAHostalCasoDeUso(controladorHostal);
			break;
		}
		case 10:
		{
			SuscribirseANotificacionesCasoDeUso(controladorUsuario);
			break;
		}
		case 11:
		{
			ConsultaDeNotificacionesCasoDeUso(controladorUsuario);
			break;
		}
		case 12:
		{
			ComentarCalificacionCasoDeUso(controladorEstadia);
			break;
		}
		case 13:
		{
			ConsultaDeUsuarioCasoDeUso(controladorUsuario);
			break;
		}
		case 14:
		{
			ConsultaDeHostalCasoDeUso(controladorHostal);
			break;
		}
		case 15:
		{
			ConsultaDeReservaCasoDeUso(controladorReserva);
			break;
		}
		case 16:
		{
			ConsultaDeEstadiaCasoDeUso(controladorEstadia);
			break;
		}
		case 17:
		{
			ConsultarTop3HostalesCasoDeUso(controladorHostal);
			break;
		}
		case 18:
		{
			EliminarSuscripcionCasoDeUso(controladorUsuario);
			break;
		}
		case 19:
		{
			BajaDeReservaCasoDeUso(controladorReserva);
			break;
		}
		case 20:
		{
			ListarHostalesRegistrados(controladorHostal);
			break;
		}
		case 21:
		{
			ListarHabitaciones(controladorHabitacion);
			break;
		}
		case 22:
		{
			ListarReservas(controladorReserva);
			break;
		}
		case 23:
		{
			ListarEstadias(controladorEstadia);
			break;
		}
		case 24:
		{
			ListarCalificaciones(controladorEstadia);
			break;
		}
		case 25:
		{
			CargarDatos(f, fecha);
			break;
		}
		default:
		{
		}
		}
		cout << endl;
		opciones(opc);
	} // FIN WHILE OPC
	cout << "Muchas gracias por usar FingVMB. Hasta la próxima." << endl;

	delete f;
	delete fecha;
}

void AltaDeUsuarioCasoDeUso(IControladorUsuario* controladorUsuario)
{
	string nombre;
	cout << "Ingrese nombre: ";
	getline(cin >> ws, nombre);
	string email;
	cout << "Ingrese email: ";
	cin >> email;
	bool deseaContinuarAgregandoEmail = true;
	while (controladorUsuario->existeMailUsuario(email) && deseaContinuarAgregandoEmail)
	{
		cout << "El mail ingresado ya existe, ¿Desea continuar? 1 sí, 0 no " << endl;
		cin >> deseaContinuarAgregandoEmail;
		cin.clear();
		cin.ignore(10000, '\n');

		if (deseaContinuarAgregandoEmail)
		{
			cout << "Ingrese un mail valido: ";
			cin >> email;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	if (deseaContinuarAgregandoEmail)
	{
		string password;
		cout << "Ingrese password: ";
		getline(cin >> ws, password);

		cout << "Ingrese 1 si es huesped o 0 si es empleado: ";
		bool esHuesped;
		cin >> esHuesped;
		if (esHuesped)
		{
			//  AGREGAR UN HUESPED
			bool esFinger;

			cout << "Ingrese 1 si es finger o 0 si no lo es: ";
			cin >> esFinger;
			controladorUsuario->registrarUsuario(nombre, email, password);
			controladorUsuario->setEsFinger(esFinger);
			controladorUsuario->confirmarUsuario(esHuesped);
		}
		else
		{
			// AGREGAR UN EMPLEADO
			string cargo;
			enumCargo cargos;
			controladorUsuario->registrarUsuario(nombre, email, password);
			bool cargoCorrecto = false;
			while (!cargoCorrecto)
			{
				cout
						<< "Ingrese el cargo del empleado (Administracion, Limpieza, Recepcion o Infraestructura): ";
				string cargo;
				cin >> cargo;
				if (cargo == "Administracion")
				{
					cargos = Administracion;
					cargoCorrecto = true;
				}
				if (cargo == "Limpieza")
				{
					cargos = Limpieza;
					cargoCorrecto = true;
				}
				if (cargo == "Recepcion")
				{
					cargos = Recepcion;
					cargoCorrecto = true;
				}
				if (cargo == "Infraestructura")
				{
					cargos = Infraestructura;
					cargoCorrecto = true;
				}
			}
			controladorUsuario->ingresarCargo(cargos);
			controladorUsuario->confirmarUsuario(esHuesped);
		}
	}
}

void AltaDeHostalCasoDeUso(IControladorHostal* controladorHostal)
{
	string nombreNuevoHostal;
	string direccionNuevoHostal;
	string telefonoNuevoHostal;

	cout << "Ingrese nombre del hostal: ";
	getline(cin >> ws, nombreNuevoHostal);
	cout << "Ingrese dirección del hostal: ";
	getline(cin >> ws, direccionNuevoHostal);
	cout << "Ingrese telefono del hostal: ";
	cin >> telefonoNuevoHostal;
	controladorHostal->ingresarHostal(nombreNuevoHostal, direccionNuevoHostal, telefonoNuevoHostal);

	if (!controladorHostal->verificarHostal(nombreNuevoHostal))
	{
		controladorHostal->confirmarHostal();
	};
}

void AltaDeHabitacionCasoDeUso(IControladorHabitacion* controladorHabitacion)
{
	try
	{
		map<string, DtHostal*> hostalesRegistrados = controladorHabitacion->listarHostalesRegistrados();
		cout << "Hostales registrados: " << endl;
		for (auto& hostal : hostalesRegistrados)
		{
			cout << hostal.second->getNombre() << endl;
		}
		string nombreHostal;

		bool hostalSeleccionado = false;
		while (!hostalSeleccionado)
		{
			try
			{
				cout << "Seleccione un hostal: " << endl;
				getline(cin >> ws, nombreHostal);
				cin.clear();
				controladorHabitacion->seleccionarHostal(nombreHostal);
				hostalSeleccionado = true;
			}
			catch (invalid_argument& err)
			{
				// No existe hostal con ese nombre
				cout << err.what() << endl;
			}
		}

		int numero;
		int precio;
		int capacidad;
		bool darAlta;

		cout << "Ingrese numero de la habitacion: " << endl;
		cin >> numero;
		cout << "Ingrese precio de la habitacion: " << endl;
		cin >> precio;
		cout << "Ingrese capacidad de la habitacion: " << endl;
		cin >> capacidad;
		cout << "Desea confirmar el ingreso de la habitacion 1 si 0 no: " << endl;
		cin >> darAlta;

		controladorHabitacion->ingresarHabitacion(numero, precio, capacidad);
		if (darAlta)
			try
			{
				controladorHabitacion->crearHabitacion();
			}
			catch (invalid_argument& err)
			{
				// Ya hay una habitacion con ese cantDeEstadiasCreadas
				cout << err.what() << endl;
			}
		else
			controladorHabitacion->cancelarIngresoHabitacion();
	}
	catch (invalid_argument& err)
	{
		// No hay hostales registrados
		cout << err.what() << endl;
	};

}

void AsignarEmpleadoAHostalCasoDeUso(IControladorHostal* controladorHostal)
{
	try
	{
		map<string, DtHostal*> listaHostales = controladorHostal->listarHostalesRegistrados();
		cout << "Hostales registrados: " << endl;
		cout << endl;
		for (auto& hostal : listaHostales)
		{
			cout << "Nombre del hostal: " << hostal.second->getNombre() << endl;
			cout << endl;
		}
		try
		{
			cout << "Ingrese nombre de hostal: ";
			string nombreDeHostal;
			getline(cin >> ws, nombreDeHostal);
			controladorHostal->seleccionarHostal(nombreDeHostal);

			try
			{
				cout << "Empleados sin asignar a hostal: " << endl;
				cout << endl;
				map<string, DtEmpleado*> listaEmpleadosSinAsignar = controladorHostal->listarEmpleadosSinAsignar();

				for (auto& empleado : listaEmpleadosSinAsignar)
				{
					cout << "Email del empleado: " << empleado.second->getEmail() << endl;
					cout << endl;
				}

				bool continuarAgregando = true;
				while (continuarAgregando && listaEmpleadosSinAsignar.size() >= 1)
				{
					try
					{
						bool seleccionaMailCorrectamente = false;
						string emailEmpleado;
						while (!seleccionaMailCorrectamente)
						{
							cout << "Ingrese email de empleado: ";
							cin >> emailEmpleado;
							cin.clear();
							cin.ignore(10000, '\n');
							seleccionaMailCorrectamente = listaEmpleadosSinAsignar.count(emailEmpleado);
						}
						enumCargo cargos;
						bool cargoCorrecto = false;
						while (!cargoCorrecto)
						{
							cout
									<< "Ingrese el cargo del empleado (Administracion, Limpieza, Recepcion o Infraestructura): ";
							string cargo;
							cin >> cargo;
							if (cargo == "Administracion")
							{
								cargos = Administracion;
								cargoCorrecto = true;
							}
							if (cargo == "Limpieza")
							{
								cargos = Limpieza;
								cargoCorrecto = true;
							}
							if (cargo == "Recepcion")
							{
								cargos = Recepcion;
								cargoCorrecto = true;
							}
							if (cargo == "Infraestructura")
							{
								cargos = Infraestructura;
								cargoCorrecto = true;
							}
						}
						cout << "Desea confirmar la asignacion del empleado al hostal 1 si 0 no: " << endl;
						bool asignarEmp;
						cin >> asignarEmp;
						if (asignarEmp)
						{
							controladorHostal->asignarEmpleado(emailEmpleado, cargos);
							listaEmpleadosSinAsignar.erase(emailEmpleado);
						}
						if (!listaEmpleadosSinAsignar.empty())
						{
							cout << "Desea continuar agregando empleados al hostal 1 si 0 no: " << endl;
							cin >> continuarAgregando;
						}

					}
					catch (invalid_argument& err)
					{
						// No existe usuario
						cout << err.what() << endl;
					}
				}
			}
			catch (invalid_argument& err)
			{
				// No hay empleados sin asignar
				cout << err.what() << endl;
			}
		}
		catch (invalid_argument& err)
		{
			// No existe ese hostal
			cout << err.what() << endl;
		}

	}
	catch (invalid_argument& err)
	{
		// No hay hostales registrados
		cout << err.what() << endl;
	}
}

void RealizarReservaCasoDeUso(IControladorReserva* controladorReserva, FechaSistema* fecha)
{
	string nombreHostal;
	string emailHuesped;
	int hora;
	int dia;
	int mes;
	int anio;
	int numeroDeHabitacion;
	bool esReservaIndivudal;
	bool confirmarReserva;
	int cantHuespedesDisponibles = 0;

	try
	{
		map<string, DtHostal*> hostalesRegistrados = controladorReserva->listarHostalesRegistrados();
		for (auto& hostal : hostalesRegistrados)
		{
			cout << "Nombre del hostal: " << hostal.second->getNombre() << endl;
			cout << "Direccion del hostal: " << hostal.second->getDireccion() << endl;
			if (hostal.second->getCalificacion() != 0)
			{
				cout << "Calificacion del hostal: " << hostal.second->getCalificacion() << endl;
			}
			cout << endl;
		}

		cout << endl;
		bool hostalSeleccionado = false;
		while (!hostalSeleccionado)
		{
			try
			{
				cout << "Ingrese nombre de hostal : " << endl;
				getline(cin >> ws, nombreHostal);
				cin.clear();
				controladorReserva->seleccionarHostal(nombreHostal);
				hostalSeleccionado = true;
			}
			catch (invalid_argument& err)
			{
				// No existe hostal con ese nombre
				cout << err.what() << endl;
			}
		}
		// Pide el checkin
		cout << endl;
		DtFecha checkIn;
		bool hayFechaCheckIn = false;
		while (!hayFechaCheckIn)
		{
			cout << "Ingrese fecha del check in : " << endl;
			cout << endl;
			cout << "Hora: ";
			cin >> hora;
			while ((hora < 0) || (hora > 23))
			{
				cout << "Hora no valida re ingrese la hora: " << endl;
				cin >> hora;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cout << "Dia: ";
			cin >> dia;
			while ((dia < 0) || (dia > 31))
			{
				cout << "Dia no valido re ingrese el dia: " << endl;
				cin >> dia;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cout << "Mes: ";
			cin >> mes;
			while ((mes < 0) || (mes > 12))
			{
				cout << "Mes no valido re ingrese el mes: " << endl;
				cin >> mes;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cout << "Año: ";
			cin >> anio;
			while (anio < 1900)
			{
				cout << "Año no valido re ingrese el año: " << endl;
				cin >> anio;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cin.clear();
			cin.ignore(10000, '\n');
			try
			{
				checkIn = DtFecha(hora, dia, mes, anio);
				if (fecha->esFechaPosterior(checkIn))
					hayFechaCheckIn = true;
			}
			catch (invalid_argument& err)
			{
				// La fecha de check in no es posterior a la del sistema
				cout << err.what() << endl;
			}
		}

		// Pide el check Out
		DtFecha checkOut;
		bool hayFechaCheckOut = false;
		while (!hayFechaCheckOut)
		{
			cout << "Ingrese fecha del check Out : " << endl;
			cout << "Hora: ";
			cin >> hora;
			while ((hora < 0) || (hora > 23))
			{
				cout << "Hora no valida re ingrese la hora: " << endl;
				cin >> hora;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cout << "Dia: ";
			cin >> dia;
			while ((dia < 0) || (dia > 31))
			{
				cout << "Dia no valido re ingrese el dia: " << endl;
				cin >> dia;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cout << "Mes: ";
			cin >> mes;
			while ((mes < 0) || (mes > 12))
			{
				cout << "Mes no valido re ingrese el mes: " << endl;
				cin >> mes;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cout << "Año: ";
			cin >> anio;
			while (anio < 1900)
			{
				cout << "Año no valido re ingrese el año: " << endl;
				cin >> anio;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cin.clear();
			cin.ignore(10000, '\n');
			try
			{
				checkOut = DtFecha(hora, dia, mes, anio);
				if (checkIn.esPosterior(checkOut))
					hayFechaCheckOut = true;
			}
			catch (invalid_argument& err)
			{
				// La fecha de check out no es posterior a la de check in
				cout << err.what() << endl;

			}
		}

		try
		{
			// Lista las habitaciones Disponibles para ese checkIn Y checkOut
			map<int, DtHabitacion> habitacionesDisponibles =
					controladorReserva->listarHabitacionesHostalDisponibles(nombreHostal, checkIn, checkOut);

			cout << "Ingrese 1 si es reserva individual o 0 si no lo es: " << endl;
			cin >> esReservaIndivudal;

			cout << endl;
			for (auto& habitacion : habitacionesDisponibles)
			{
				cout << "Numero de habitacion: " << habitacion.second.getNumero() << endl;
				cout << "Precio de habitacion: " << habitacion.second.getPrecio() << endl;
				cout << "Capacidad de habitacion: " << habitacion.second.getCapacidad() << endl;
				cout << endl;
			}

			// Se pide seleccionar habitacion
			bool hayHabitacionSeleccionada = false;
			while (!hayHabitacionSeleccionada)
			{
				try
				{
					cout << "Ingrese el numero de habitacion : " << endl;
					cin >> numeroDeHabitacion;
					cin.clear();
					cin.ignore(10000, '\n');
					controladorReserva->seleccionarHabitacion(numeroDeHabitacion);
					hayHabitacionSeleccionada = true;
				}
				catch (invalid_argument& err)
				{
					// No hay habitacion con ese cantDeEstadiasCreadas
					cout << err.what() << endl;
				}
				cout << endl;
			}

			// Listar usuarios
			cout << "Huespedes registardos en el sistema: " << endl;
			map<string, DtUsuario*> listaUsuarios = controladorReserva->listarUsuarios();

			for (auto& usuario : listaUsuarios)
			{
				DtUsuario* dtu = usuario.second;

				DtHuesped* hues = dynamic_cast<DtHuesped*>(dtu);
				if (hues != NULL)
				{
					cout << "Nombre del huesped es " << hues->getNombre() << ", su email es " << hues->getEmail()
						 << " - "
						 << (hues->getEsFinger() ? "Es finger" : "No es finger") << endl;
				}
				cantHuespedesDisponibles = cantHuespedesDisponibles + 1;
			}

			cout << endl;
			DtFecha actual = fecha->getDtFecha();
			if (esReservaIndivudal)
			{
				bool hayEmailSeleccionado = false;
				while (!hayEmailSeleccionado)
				{
					try
					{
						cout << endl;
						cout << "Ingrese el mail del Huesped que hace la reserva: " << endl;
						getline(cin >> ws, emailHuesped);
						cin.clear();
						controladorReserva->seleccionarUsuario(emailHuesped);
						hayEmailSeleccionado = true;
					}
					catch (invalid_argument& err)
					{
						// No hay usuario con ese mail
						cout << err.what() << endl;
						cout << endl;
					}
				}
				controladorReserva->realizarReservaIndividual(checkIn, checkOut);
			}

			else
			{
				// Es reserva grupal
				map<string, string> listaDeHuespedes;
				string mailDeHuespdes;
				bool agregarMas = true;
				bool ingresoCreadorReserva = false;
				int cantHuespdesGrupal = habitacionesDisponibles[numeroDeHabitacion].getCapacidad();
				cantHuespedesDisponibles = cantHuespedesDisponibles - 1;
				while ((agregarMas) && (cantHuespdesGrupal > 0) && (cantHuespedesDisponibles > 0))
				{
					if (!ingresoCreadorReserva)
					{
						try
						{
							ingresoCreadorReserva = true;
							cout << "Ingrese el mail del Huesped que hace la reserva: " << endl;
							cin >> emailHuesped;
							cin.clear();
							cin.ignore(10000, '\n');
							controladorReserva->seleccionarUsuario(emailHuesped);
							listaDeHuespedes[emailHuesped] = emailHuesped;
						}
						catch (invalid_argument& err)
						{
							cout << err.what() << endl;
						}
					}
					else
					{
						cout << "Ingrese el mail del Huesped para la reserva grupal: " << endl;
						cin >> mailDeHuespdes;
						while (!controladorReserva->existeMailUsuario(mailDeHuespdes))
						{
							cout << "El mail ingresado no existe, ingrese un mail valido: " << endl;
							cin >> mailDeHuespdes;
							cin.clear();
							cin.ignore(10000, '\n');
						}
						if (!listaDeHuespedes.count(mailDeHuespdes))
						{
							listaDeHuespedes[mailDeHuespdes] = mailDeHuespdes;
							cantHuespdesGrupal = cantHuespdesGrupal - 1;
							cantHuespedesDisponibles = cantHuespedesDisponibles - 1;
						}
						else
						{
							cout << "El huesped ya ha sido ingresado." << endl;
						}
						if (cantHuespedesDisponibles != 0)
						{
							cout << "Ingrese 1 si desea seguir agregando a la reserva o 0 si no." << endl;
							cin >> agregarMas;
						}
					}
				}
				controladorReserva->realizarReservaGrupal(checkIn, checkOut, listaDeHuespedes, mailDeHuespdes,
						numeroDeHabitacion);
			}
			// fin de grupal

			cout << "Desea realizar un reserva para el mail : " << emailHuesped << " en la habitacion "
				 << numeroDeHabitacion
				 << endl;

			cout << "La fecha de check-in es:" << checkIn << "La fecha de check-out es:" << checkOut << endl;
			cout << "Ingrese 1 si desea confirmar la reserva o 0 si no: " << endl;
			cin >> confirmarReserva;
			int codigoReserva = controladorReserva->confirmarReserva(confirmarReserva);
			if (confirmarReserva)
			{
				cout << "El codigo de su reserva es : " << codigoReserva << endl;
			}
		}
		catch (invalid_argument& err)
		{
			// No hay habitaciones registradas / disponibles
			cout << endl;
			cout << err.what() << endl;
		}
	}
	catch (invalid_argument& err)
	{
		// No hay hostales registrados
		cout << err.what() << endl;
	}
}

void ConsultarTop3HostalesCasoDeUso(IControladorHostal* controladorHostal)
{
	try
	{
		vector<DtHostal*> top = controladorHostal->listarTop3Hostales();
		if (top.empty())
		{
			cout << "No hay hostales calificados." << endl;
		}
		else
		{
			cout << "Listando top 3 hostales:" << endl;
			cout << endl;

			int i = 1;
			for (auto& it : top)
			{
				cout << "    Hostal " << i << " - " << it->getNombre() << endl;
				cout << "    Direccion: " << it->getDireccion() << endl;
				cout << "    Telefono: " << it->getTelefono() << endl;
				cout << "    Calificacion: " << it->getCalificacion() << endl;
				cout << endl;
				i++;
			}

			try
			{
				string hostal;
				cout << "Ingrese el nombre del hostal: ";
				getline(cin >> ws, hostal);

				controladorHostal->seleccionarHostal(hostal);

				try
				{
					cout << "Calificaciones del hostal: " << endl;
					cout << endl;

					map<int, DtCalificacion> calificaciones = controladorHostal->mostrarCalificaciones();

					for (auto& calificacion : calificaciones)
					{
						DtComentario com = calificacion.second.getComentario();
						cout << "    Autor: " << com.getAutor() << endl;
						cout << "    Fecha: " << calificacion.second.getFecha() << endl;
						cout << "    Calificacion: " << calificacion.second.getCalificacion() << endl;
						cout << "    Comentario: " << com.getComentario() << endl;
						// if(com.getRespuesta() != NULL) {
						//     cout << endl;
						//     cout << "    Respuesta de " << com.getRespuesta()->getAutor() << endl;
						//     cout << "    Respuesta: " << com.getRespuesta()->getComentario() << endl;
						// }
						cout << endl;
					}
				}
				catch (invalid_argument& err)
				{
					cout << err.what() << endl;
				}
			}
			catch (invalid_argument& err)
			{
				cout << err.what() << endl;
			}
		}
	}
	catch (invalid_argument& err)
	{
		cout << err.what() << endl;
	}
}

void RegistrarEstadiaCasoDeUso(IControladorEstadia* controladorEstadia)
{
	try
	{
		// PASO 1: LISTAR HOSTALES REGISTRADOS
		map<string, DtHostal*> hostalesRegistrados = controladorEstadia->listarHostalesRegistrados();
		map<string, DtUsuario*> listaUsuarios = controladorEstadia->listarUsuarios();

		cout << "Listar hostales registrados: " << endl;
		bool existeHuesped = false;
		for (auto& listaUsuario : listaUsuarios)
		{
			DtUsuario* dtu = listaUsuario.second;
			auto* hues = dynamic_cast<DtHuesped*>(dtu);
			if (hues != NULL)
			{
				existeHuesped = true;
				break;
			}
		}

		if (hostalesRegistrados.empty())
		{
			cout << "No hay hostales registrados." << endl;
			cout << endl;
		}
		else if (!existeHuesped)
		{
			cout << "No hay huéspedes registrados." << endl;
			cout << endl;
		}
		else
		{
			for (auto& hostalRegistrado : hostalesRegistrados)
			{
				cout << "  Hostal: " << hostalRegistrado.second->getNombre() << endl;
			}

			try
			{
				// PASO 2: LISTAR RESERVAS NO CANCELADAS
				string hostal;
				string email;
				int codigo;
				bool hostalSeleccionado = false;

				cout << endl;
				while (!hostalSeleccionado)
				{
					try
					{
						cout << "Ingrese el nombre del hostal: " << endl;
						getline(cin >> ws, hostal);
						cin.clear();
						controladorEstadia->seleccionarHostal(hostal);
						hostalSeleccionado = true;
					}
					catch (invalid_argument& err)
					{
						cout << err.what() << endl;
					}

				}

				cout << endl;
				cout << "Todos los huespedes en el sistema: " << endl;
				for (auto& listaUsuario : listaUsuarios)
				{
					DtUsuario* dtu = listaUsuario.second;
					auto* hues = dynamic_cast<DtHuesped*>(dtu);
					if (hues != NULL)
					{
						cout << "  Huesped:   " << hues->getNombre() << " - " << hues->getEmail() << " - "
							 << (hues->getEsFinger() ? "Es finger" : "No es finger") << endl;
					}
				}

				cout << endl;
				bool existeHuesped = false;
				while (!existeHuesped)
				{
					try
					{
						cout << "Ingrese el correo electrónico: " << endl;
						getline(cin >> ws, email);
						cin.clear();
						existeHuesped = controladorEstadia->existeHuesped(email);
					}
					catch (invalid_argument& err)
					{
						cout << err.what() << endl;
					}
				}
				cout << endl;
				cout << "Listar reservas no canceladas: " << endl;
				map<int, DtReserva*> reservasNoCanceladas = controladorEstadia->listarReservasNoCanceladas(hostal,
						email);
				for (auto& reservaNoCancelada : reservasNoCanceladas)
				{
					if (reservaNoCancelada.second->getReservaIndividual())
					{
						cout << "  Reserva individual: Código " << reservaNoCancelada.first << endl;
					}
					else
					{
						cout << "  Reserva grupal: Código " << reservaNoCancelada.first << endl;
					}
				}

				// PASO 3: SELECCIONA EL CÓDIGO DE LA RESERVA
				bool reservaSeleccionada = false;
				cout << endl;
				while (!reservaSeleccionada)
				{
					try
					{
						cout << "Ingrese el código de la reserva: " << endl;
						cin >> codigo;
						cin.clear();
						cin.ignore(10000, '\n');
						controladorEstadia->seleccionarReserva(codigo);
						reservaSeleccionada = true;
					}
					catch (invalid_argument& err)
					{
						cout << err.what() << endl;
					}
				}

				for (map<int, DtReserva*>::iterator it = reservasNoCanceladas.begin();
					 it != reservasNoCanceladas.end();
					 it++)
				{
					delete it->second;
				}
				reservasNoCanceladas.clear();

				try
				{
					// PASO 4: REGISTRAR ESTADIA
					cout << endl;
					controladorEstadia->registrarEstadia(email);
				}
				catch (invalid_argument& err)
				{
					cout << err.what() << endl;
				}
			}
			catch (invalid_argument& err)
			{
				cout << err.what() << endl;
			}
		}

		for (map<string, DtHostal*>::iterator it = hostalesRegistrados.begin(); it != hostalesRegistrados.end(); it++)
		{
			delete it->second;
		}
		hostalesRegistrados.clear();

		for (map<string, DtUsuario*>::iterator it = listaUsuarios.begin(); it != listaUsuarios.end(); it++)
		{
			delete it->second;
		}
		listaUsuarios.clear();
	}
	catch (invalid_argument& err)
	{
		// No hay hostales o usuarios
		cout << err.what() << endl;
	}
}

void FinalizarEstadiaCasoDeUso(IControladorEstadia* controladorEstadia)
{
	try
	{
		// PASO 1: LISTAR HOSTALES REGISTRADOS
		string nombreDeHostal;
		string email;
		IControladorEstadia* contEst = controladorEstadia;
		map<string, DtHostal*> hostalesRegistrados = contEst->listarHostalesRegistrados();
		cout << "Hostales registrados: " << endl;
		cout << endl;
		for (auto& hostalRegistrado : hostalesRegistrados)
		{
			cout << "  Hostal: " << hostalRegistrado.second->getNombre() << endl;
		}
		try
		{
			// PASO 2: existe estadia activa
			bool hayHostalSeleccionado = false;
			while (!hayHostalSeleccionado)
			{
				cout << "Ingrese nombre de hostal: " << endl;
				getline(cin >> ws, nombreDeHostal);
				cin.clear();
				cout << endl;
				hayHostalSeleccionado = hostalesRegistrados.count(nombreDeHostal);
			}
			cout << "Ingrese mail del huesped: ";
			cin >> email;
			bool exist = controladorEstadia->existeEstadiaActiva(email, nombreDeHostal);
			if (exist)
			{
				controladorEstadia->finalizarEstadia(email, nombreDeHostal);
				cout << "Las estadias activas fueron finalizadas ";
			}
			else
			{
				cout << "No existe estadia activa para ese usuario en el hostal ";
			}
		}
		catch (invalid_argument& err)
		{
			// No hay usuarios / usuario con ese email / huesped
			cout << endl;
			cout << err.what() << endl;
		}
	}
	catch (invalid_argument& err)
	{
		// No hay hostales registrados
		cout << err.what() << endl;
	}
}

void CalificarEstadiaCasoDeUso(IControladorEstadia* controladorEstadia)
{
	try
	{
		// PASO 1: LISTAR HOSTALES REGISTRADOS
		string nombreHostal;
		string email;
		int idEstadia;
		int cal;
		string com;

		map<string, DtHostal*> hostalesRegistrados = controladorEstadia->listarHostalesRegistrados();
		cout << "Hostales registrados: " << endl;
		cout << endl;
		for (auto& hostalRegistrado : hostalesRegistrados)
		{
			cout << "  Hostal: " << hostalRegistrado.second->getNombre() << endl;
		}

		// PASO 2: SELECCIONAR HOSTAL
		bool hostalSeleccionado = false;
		while (!hostalSeleccionado)
		{
			try
			{
				cout << "Seleccione un hostal: " << endl;
				getline(cin >> ws, nombreHostal);
				cin.clear();
				controladorEstadia->seleccionarHostal(nombreHostal);
				hostalSeleccionado = true;
			}
			catch (invalid_argument& err)
			{
				// No existe hostal con ese nombre
				cout << err.what() << endl;
			}
		}

		// PASO 3: Listar Estadías del Huésped Finalizadas
		try
		{
			cout << "Ingrese email: ";
			cin >> email;
			map<int, DtEstadia> EstadiasFinalizadas = controladorEstadia->listarEstadiasDelHuespedFinalizadas(
					email);

			for (auto& estadiaFinalizada : EstadiasFinalizadas)
			{
				cout << " Codigo: " << to_string(estadiaFinalizada.second.getId()) << endl;
				cout << " Hostal: " << estadiaFinalizada.second.getHostal() << endl;
				cout << " Check in: " << estadiaFinalizada.second.getCheckIn() << endl;
				cout << " Check out: " << estadiaFinalizada.second.getCheckOut() << endl;
			}

			// PASO 4: Seleccionar Estadia

			bool estadiaSeleccionada = false;
			while (!estadiaSeleccionada)
			{
				try
				{
					cout << "Ingrese el codigo de la estadia a seleccionar: " << endl;
					cin >> idEstadia;
					cin.clear();
					cin.ignore(10000, '\n');
					controladorEstadia->seleccionarEstadia(idEstadia);
					if(EstadiasFinalizadas.count(idEstadia) ){
							estadiaSeleccionada = true;
					}else{
							estadiaSeleccionada = false;
							cout << "El usuario no tiene una estadia con esa id: " << to_string(idEstadia) <<endl;
					}
					//estadiaSeleccionada = true;
				}
				catch (invalid_argument& err)
				{
					// No existe estadias con ese codigo
					cout << err.what() << endl;
				}
			}

			// PASO 5:Enviar Calificacion
			cout << "Ingrese una calificacion del 1 al 5: ";
			cin >> cal;
			cout << "Ingrese un comentario: ";
			getline(cin >> ws, com);

			controladorEstadia->enviarCalificacion(cal, com, email);

			cout << "Calificacion enviada con exito ";
		}
		catch (invalid_argument& err)
		{
			// No existe huesped asociado a ese email o el huesped no tiene asociada ninguna estadia
			cout << err.what() << endl;
		}
	}
	catch (invalid_argument& err)
	{
		// No hay hostales registrados
		cout << err.what() << endl;
	}
}

void ComentarCalificacionCasoDeUso(IControladorEstadia* controladorEstadia)
{
	try
	{
		map<string, DtUsuario*> listaUsuarios = controladorEstadia->listarUsuarios();
		for (auto& listaUsuario : listaUsuarios)
		{
			DtUsuario* dtu = listaUsuario.second;
			auto* emp = dynamic_cast<DtEmpleado*>(dtu);
			if (emp != NULL)
			{
				cout << "Empleado:   " << emp->getNombre() << "   -   " << emp->getEmail() << endl;
			}
		}

		bool hayEmpleadoSeleccionado = false;
		while (!hayEmpleadoSeleccionado)
		{
			try
			{
				string mailDeEmpleado;
				cout << "Ingrese mail del empleado: " << endl;
				cin >> mailDeEmpleado;
				cin.clear();
				cin.ignore(10000, '\n');
				controladorEstadia->seleccionarEmpleado(mailDeEmpleado);
				hayEmpleadoSeleccionado = true;
			}
			catch (invalid_argument& err)
			{
				cout << err.what() << endl;
			}
		}
		try
		{
			// Listar comentarios sin responder
			map<int, DtComentario> comentariosSinResponder = controladorEstadia->listarComentariosSinResponderHostal();

			for (auto& it : comentariosSinResponder)
			{
				cout << "    id: " << it.second.getId() << endl;
				cout << "    Autor: " << it.second.getAutor() << endl;
				cout << "    Fecha: " << it.second.getFecha() << endl;
				cout << "    Comentario: " << it.second.getComentario() << endl;
				cout << endl;
			}

			bool seleccionadoElComentario = false;
			int idDelComentario;
			while (!seleccionadoElComentario)
			{
				cout << "Ingrese id del comentario a responder: ";
				cin >> idDelComentario;
				cin.clear();
				cin.ignore(10000, '\n');
				seleccionadoElComentario = comentariosSinResponder.count(idDelComentario);
			}

			string RespuestaDelEmpleado;
			cout << "Ingrese respuesta del comentario: ";
			getline(cin >> ws, RespuestaDelEmpleado);
			cin.clear();

			controladorEstadia->ingresarRespuestaComentario(RespuestaDelEmpleado, idDelComentario);
			cout << endl;
			cout << "Se agrego la respuesta con exito ";
		}
		catch (invalid_argument& err)
		{
			//No existen comentarios sin responder
			cout << err.what() << endl;
		}
	}
	catch (invalid_argument& err)
	{
		//No existe empleado asociado a ese email
		cout << err.what() << endl;
	}
}

void ConsultaDeUsuarioCasoDeUso(IControladorUsuario* controladorUsuario)
{
	try
	{
		string email;
		map<string, DtUsuario*> listaUsuarios = controladorUsuario->listarUsuarios();
		for (auto& usuario : listaUsuarios)
		{
			DtUsuario* dtu = usuario.second;
			DtEmpleado* emp = dynamic_cast<DtEmpleado*>(dtu);
			DtHuesped* hues = dynamic_cast<DtHuesped*>(dtu);

			if (emp != NULL)
			{
				cout << "Empleado:  " << emp->getNombre() << " - " << emp->getEmail() << " - " << emp->getCargo()
					 << endl;
			}

			if (hues != NULL)
			{
				cout << "Huesped:   " << hues->getNombre() << " - " << hues->getEmail() << " - "
					 << (hues->getEsFinger() ? "Es finger" : "No es finger") << endl;
			}
		}

		cout << endl;
		bool usuarioSeleccionado = false;
		DtUsuario* u = NULL;
		while (!usuarioSeleccionado)
		{
			try
			{
				cout << "Ingrese el email del usuario a consultar:" << endl;
				cin >> email;
				cin.clear();
				cin.ignore(10000, '\n');
				u = controladorUsuario->informacionUsuario(email);
				usuarioSeleccionado = true;

			}
			catch (invalid_argument& err)
			{
				// No existe usuario con ese mail
				cout << err.what() << endl;
			}
		}
		DtEmpleado* emp = dynamic_cast<DtEmpleado*>(u);
		DtHuesped* hues = dynamic_cast<DtHuesped*>(u);
		if (emp != NULL)
		{
			cout << "Empleado:  " << emp->getNombre() << " - " << emp->getEmail() << " - " << emp->getCargo()
				 << " - "
				 << emp->getHostal() << endl;
		}
		if (hues != NULL)
		{
			cout << "Huesped:   " << hues->getNombre() << " - " << hues->getEmail() << " - "
				 << (hues->getEsFinger() ? "Es finger" : "No es finger") << endl;
		}
	}
	catch (invalid_argument& err)
	{
		// No hay usuarios registrados
		cout << err.what() << endl;
	}
}

void ConsultaDeHostalCasoDeUso(IControladorHostal* controladorHostal)
{
	// PASO 1: LISTAR HOSTALES REGISTRADOS
	try
	{
		string hostal;
		map<string, DtHostal*> hostalesRegistrados = controladorHostal->listarHostalesRegistrados();

		cout << "Listar hostales registrados: " << endl;
		for (auto& hostalRegistrado : hostalesRegistrados)
		{
			cout << "  Hostal: " << hostalRegistrado.second->getNombre() << endl;
		}

		try
		{
			// PASO 2: SELECCIONAR HOSTAL
			cout << endl;
			cout << "Seleccione el hostal: ";
			getline(cin >> ws, hostal);
			controladorHostal->seleccionarHostal(hostal);

			// PASO 3: MOSTRAR HOSTAL
			DtHostal* dth = controladorHostal->mostrarHostal();
			cout << endl;
			if (dth == NULL)
				cout << "Error: Este hostal no existe.";
			else
			{
				cout << "Mostrando la informacion del hostal " + dth->getNombre() << endl;
				cout << "    Direccion: " << dth->getDireccion() << endl;
				cout << "    Telefono: " << dth->getTelefono() << endl;
				if (dth->getCalificacion() != 0)
				{
					cout << "    Calificacion: " << dth->getCalificacion() << endl;
				}
				cout << endl;

				// Mostrar en patalla las reservas
				map<int, DtReserva*> reservas = controladorHostal->listarReservas();
				if (reservas.size() > 0)
				{
					cout << "Reservas del hostal: " << endl;
					for (auto& reserva : reservas)
					{
						cout << "    Codigo: " << reserva.second->getCodigo() << endl;
						if (reserva.second->getReservaIndividual())
						{
							cout << "    Tipo de reserva: Individual" << endl;
						}
						else
						{
							cout << "    Tipo de reserva: Grupal" << endl;
						}
						cout << "    Check-in: " << reserva.second->getCheckIn() << endl;
						cout << "    Check-out: " << reserva.second->getCheckOut() << endl;
						cout << "    Estado: " << reserva.second->getEstado() << endl;
						cout << "    Costo: " << reserva.second->getCosto() << endl;
						cout << "    Habitacion: " << reserva.second->getHabitacion() << endl;
						cout << endl;
					}

					for (map<int, DtReserva*>::iterator it = reservas.begin(); it != reservas.end(); it++)
					{
						delete it->second;
					}
					reservas.clear();
				}
				else
				{
					cout << "No hay reservas asociadas a este hostal." << endl;
				}
				// Mostar en pantalla las habitaciones del hostal
				if (!dth->getHabitaciones().empty())
				{
					cout << "Habitaciones del hostal: " << endl;
					for (auto& habitacion : dth->getHabitaciones())
					{
						cout << "Numero de habitacion: " << habitacion.second.getNumero() << endl;
						cout << "Precio de habitacion: " << habitacion.second.getPrecio() << endl;
						cout << "Capacidad de habitacion: " << habitacion.second.getCapacidad() << endl;
						cout << endl;
					}
				}
				else
				{
					cout << "No hay habitaciones en ese hostal " << endl;
				}

				// Mostrar en pantalla las calificaciones
				if (!dth->getCalificaciones().empty())
				{

					cout << "Calificaciones del hostal: " << endl;
					for (auto& calificacion : dth->getCalificaciones())
					{
						DtComentario com = calificacion.second.getComentario();
						cout << "    Autor: " << com.getAutor() << endl;
						cout << "    Fecha: " << calificacion.second.getFecha() << endl;
						cout << "    Calificacion: " << calificacion.second.getCalificacion() << endl;
						cout << "    Comentario: " << com.getComentario() << endl;
						cout << endl;
						if (com.tieneRespuesta())
						{
							DtComentario* respuesta = com.getRespuesta();
							cout << "    Respuesta de " << respuesta->getAutor() << endl;
							cout << "    Respuesta: " << respuesta->getComentario() << endl;
							delete respuesta;
						}
						cout << endl;
					}
				}
				else
				{
					cout << "No hay calificaciones para ese hostal " << endl;
				}
			}
		}
		catch (invalid_argument& err)
		{
			cout << err.what() << endl;
		}

		for (map<string, DtHostal*>::iterator it = hostalesRegistrados.begin(); it != hostalesRegistrados.end(); it++)
		{
			delete it->second;
		}
		hostalesRegistrados.clear();
	}
	catch (invalid_argument& err)
	{
		cout << err.what() << endl;
	}
}

void ConsultaDeReservaCasoDeUso(IControladorReserva* controladorReserva)
{
	// PASO 1: LISTAR HOSTALES
	try
	{
		string hostal;
		map<string, DtHostal*> hostalesRegistrados = controladorReserva->listarHostalesRegistrados();
		for (auto& hostalesRegistrado : hostalesRegistrados)
		{
			cout << "  Hostal: " << hostalesRegistrado.second->getNombre() << endl;
		}

		try
		{
			// PASO 2: SELECCIONAR HOSTAL
			cout << endl;
			cout << "Seleccione el hostal: ";
			getline(cin >> ws, hostal);
			controladorReserva->seleccionarHostal(hostal);

			try
			{
				// PASO 3: LISTAR RESERVAS
				try
				{
					map<int, DtReserva*> listaReservas = controladorReserva->listarReservasAsociadasAHostal();
					cout << endl;
					cout << "Lista de reservas asociadas a este hostal: " << endl;
					cout << endl;
					for (auto& reserva : listaReservas)
					{
						DtReserva* dtr = reserva.second;
						DtReservaIndividual* resvI = dynamic_cast<DtReservaIndividual*>(dtr);
						DtReservaGrupal* resvG = dynamic_cast<DtReservaGrupal*>(dtr);

						if (resvI != NULL)
						{
							cout << "El codigo de reserva individual es: " << resvI->getCodigo() << endl;
							cout << "El numero de habitacion es: " << resvI->getHabitacion() << endl;
							cout << "El costo de la habitacion es: " << resvI->getCosto() << endl;
							cout << "La fecha de check-in es: " << resvI->getCheckIn() << endl;
							cout << "La fecha de check-out es: " << resvI->getCheckOut() << endl;
							cout << "El estado de la reserva es: " << resvI->getEstado() << endl;
						}

						if (resvG != NULL)
						{
							cout << "El codigo de reserva grupal es: " << resvG->getCodigo() << endl;
							cout << "El numero de habitacion es: " << resvG->getHabitacion() << endl;
							cout << "El costo de la habitacion es: " << resvG->getCosto() << endl;
							cout << "La fecha de check-in es: " << resvG->getCheckIn() << endl;
							cout << "La fecha de check-out es: " << resvG->getCheckOut() << endl;
							cout << "El estado de la reserva es: " << resvG->getEstado() << endl;
							// cout << "El mail de las huespedes de la reserva  " << endl;
							map<string, DtHuesped*> mapDt = resvG->getHuespedes();
							for (auto& itr : mapDt)
							{
								cout << "    El mail asociado a la reserva grupal: " << itr.second->getEmail()
									 << " y el nombre es: " << itr.second->getNombre() << endl;
							}
						}
						cout << endl;
					}
				}
				catch (invalid_argument& err)
				{
					// No hay reservas asociadas al hostal
					cout << err.what() << endl;
				}
			}
			catch (invalid_argument& err)
			{
				cout << err.what() << endl;
			}
		}
		catch (invalid_argument& err)
		{
			cout << err.what() << endl;
		}

		for (map<string, DtHostal*>::iterator it = hostalesRegistrados.begin(); it != hostalesRegistrados.end(); it++)
		{
			delete it->second;
		}
		hostalesRegistrados.clear();

	}
	catch (invalid_argument& err)
	{
		// No hay hostales registrados
		cout << err.what() << endl;
	}
}

void ConsultaDeEstadiaCasoDeUso(IControladorEstadia* controladorEstadia)
{
	// Listo los hostales registrado
	bool noHayHostales = false;
	try
	{
		map<string, DtHostal*> listaHostales = controladorEstadia->listarHostalesRegistrados();
	}
	catch (invalid_argument& err)
	{
		// No hay hostales registrados
		noHayHostales = true;
		cout << err.what() << endl;
	}

	map<int, DtEstadia> listaEstadias = controladorEstadia->listarTodasEstadias();
	if ((!noHayHostales) && (!listaEstadias.empty()))
	{
		int codReserva;
		string NombreDeHostal;
		bool consutaCalificacion;
		cout << "Listando Hostales: " << endl;
		map<string, DtHostal*> listaHostales = controladorEstadia->listarHostalesRegistrados();
		for (auto& hostal : listaHostales)
		{
			cout << "Nombre del hostal: " << hostal.second->getNombre() << endl;
			cout << "Direccion del hostal: " << hostal.second->getDireccion() << endl;
			cout << "Telefono del hostal: " << hostal.second->getTelefono() << endl;
			if (hostal.second->getCalificacion() != 0)
			{
				cout << "Calificacion del hostal: " << hostal.second->getCalificacion() << endl;
			}
			cout << endl;
		}
		cout << "Ingrese nombre de hostal : ";
		getline(cin >> ws, NombreDeHostal);

		// Debo chequear que exista el hostal
		while (!listaHostales.count(NombreDeHostal))
		{
			cout << "Ese nombre de hostal no existe, ingrese el nombre de un  hostal registrado: " << endl;
			getline(cin >> ws, NombreDeHostal);
			cin.clear();
			cin.ignore(10000, '\n');
		}

		// Listo todas las estdias pero luego voy a filtrar esto
		cout << "Listando estadías: " << endl;
		cout << endl;
		bool hostalSinEstadias = true;
		for (auto& estadia : listaEstadias)
		{
			if (estadia.second.getHostal() == NombreDeHostal)
			{
				hostalSinEstadias = false;
				cout << "  Codigo: " << estadia.first << endl;
				cout << "  Reserva asociada: " << estadia.second.getCodigoReserva() << endl;
				// cout << "  Hostal: " << it->second.getHostal() << endl;
				cout << "  Huesped: " << estadia.second.getHuesped() << endl;
				cout << "  Habitacion: " << estadia.second.getHabitacion() << endl;
			}
		}

		if (!hostalSinEstadias)
		{
			//seleciona y revisa que  el codigo exista
			cout << "Seleccione una estadia por su codigo: ";
			cin >> codReserva;
			while ((!listaEstadias.count(codReserva))
					|| (listaEstadias.find(codReserva)->second.getHostal() != NombreDeHostal))
			{
				cout << "Codigo invalido selecione un codigo valido: "<< endl;
				cin >> codReserva;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			//si el codigo existe muestra los datos restantes
			DtEstadia estadiaSeleccionada = listaEstadias.find(codReserva)->second;
			//cout << "  Codigo: " << codReserva << endl;
			cout << "  Reserva asociada: " << estadiaSeleccionada.getCodigoReserva() << endl;
			cout << "  Hostal: " << estadiaSeleccionada.getHostal() << endl;
			cout << "  Huesped: " << estadiaSeleccionada.getHuesped() << endl;
			cout << "  Habitacion: " << estadiaSeleccionada.getHabitacion() << endl;
			cout << "  Promo: " << estadiaSeleccionada.getPromo() << endl;
			cout << "  Check-In: " << estadiaSeleccionada.getCheckIn() << endl;
			//cout << "  Check-Out: " << estadiaSeleccionada.getCheckOut() << endl;
			if((estadiaSeleccionada.getCheckOut().getAnio()) != 1899){
					cout << "  Check-Out: " << estadiaSeleccionada.getCheckOut() << endl;
			}else{
					cout << "  La reserva no esta finalizada "<< endl;
			}
			// consulta las calificaciones en caso que tenga califiacion
			if (((estadiaSeleccionada.getCheckOut().getAnio()) != 1899) && (estadiaSeleccionada.getEstaCalificada()))
			{
				cout << "Desea Consultar la calificaion? Presione 1 para confirmar o 0 para lo contrario: " << endl;
				cin >> consutaCalificacion;
				if (consutaCalificacion)
				{
					DtCalificacion cal = estadiaSeleccionada.getCalificaion();
					cout << "La calificacion de la estadia es : " << cal.getCalificacion() << endl;
					DtComentario com = cal.getComentario();
					if (com.tieneRespuesta())
					{
						DtComentario* respuesta = com.getRespuesta();
						cout << "    Respuesta de " << respuesta->getAutor() << endl;
						cout << "    Respuesta: " << respuesta->getComentario() << endl;
						delete respuesta;
					}
					cout << endl;

				}
			}

			//muestra la parte opcional
			cout << "Desea Consultar informacion de la Reserva? Presione 1 para confirmar o 0 para lo contrario: "
				 << endl;
			cin >> consutaCalificacion;
			if (consutaCalificacion)
			{
				controladorEstadia->seleccionarEstadia(codReserva);
				DtReserva* dtres = controladorEstadia->obtenerInformacionReserva(
						estadiaSeleccionada.getCodigoReserva());
				auto* resvI = dynamic_cast<DtReservaIndividual*>(dtres);
				auto* resvG = dynamic_cast<DtReservaGrupal*>(dtres);

				if (resvI != NULL)
				{
					cout << "El codigo de reserva individual es: " << resvI->getCodigo() << endl;
					cout << "El numero de habitacion es: " << resvI->getHabitacion() << endl;
					cout << "El costo de la habitacion es: " << resvI->getCosto() << endl;
					cout << "La fecha de check-in es: " << resvI->getCheckIn() << endl;
					cout << "La fecha de check-out es: " << resvI->getCheckOut() << endl;
					cout << "El estado de la reserva es: " << resvI->getEstado() << endl;
				}

				if (resvG != NULL)
				{
					cout << "El codigo de reserva grupal es: " << resvG->getCodigo() << endl;
					cout << "El numero de habitacion es: " << resvG->getHabitacion() << endl;
					cout << "El costo de la habitacion es: " << resvG->getCosto() << endl;
					cout << "La fecha de check-in es: " << resvG->getCheckIn() << endl;
					cout << "La fecha de check-out es: " << resvG->getCheckOut() << endl;
					cout << "El estado de la reserva es: " << resvG->getEstado() << endl;
					// cout << "El mail de las huespedes de la reserva  " << endl;
					map<string, DtHuesped*> mapDtHuespedes = resvG->getHuespedes();
					for (auto& huseped : mapDtHuespedes)
					{
						cout << "     El mail asociado a la reserva grupal: "
							 << huseped.second->getEmail() << " y el nombre es: "
							 << huseped.second->getNombre() << endl;
					}
				}
				resvI = NULL;
				resvG = NULL;
				delete dtres;
				cout << endl;
			}
		}
		else
		{
			cout << "El hostal no tiene estadias" << endl;
		}
	}
	else
	{
		if (listaEstadias.empty())
		{
			cout << "No hay estadias activas " << endl;
		}
	}
}

void BajaDeReservaCasoDeUso(IControladorReserva* controladorReserva)
{
	string nomHostal;
	int codRes;
	bool confirmaBaja;

	try
	{
		// Lista hostales registrados y selecciona uno
		map<string, DtHostal*> listaHostales = controladorReserva->listarHostalesRegistrados();
		cout << "Hostales registrados: " << endl;
		for (auto& hostal : listaHostales)
		{
			cout << "Nombre del hostal: " << hostal.second->getNombre() << endl;
		}
		cout << endl;

		bool hayHostalSeleccionado = false;
		while (!hayHostalSeleccionado)
		{
			try
			{
				cout << "Ingrese nombre de hostal: ";
				getline(cin >> ws, nomHostal);
				cin.clear();
				controladorReserva->seleccionarHostal(nomHostal);
				hayHostalSeleccionado = true;
				cout << endl;
			}
			catch (invalid_argument& err)
			{
				// Ho hay hostal con ese nombre
				cout << err.what() << endl;
				cout << endl;
			}
		}
		try
		{
			// Lista todas las reservas y selecciona la que desea dar de baja
			map<int, DtReserva*> listaReservas = controladorReserva->listarReservasAsociadasAHostal();
			for (auto& reserva : listaReservas)
			{
				DtReserva* dtr = reserva.second;
				auto* resvI = dynamic_cast<DtReservaIndividual*>(dtr);
				auto* resvG = dynamic_cast<DtReservaGrupal*>(dtr);

				if (resvI != NULL)
				{
					cout << "Codigo de reserva individual: " << resvI->getCodigo() << endl;
					cout << "Numero de habitacion: " << resvI->getHabitacion() << endl;
					cout << "Costo de la habitacion: " << resvI->getCosto() << endl;
					cout << "Fecha de check-in: " << resvI->getCheckIn() << endl;
					cout << "Fecha de check-out: " << resvI->getCheckOut() << endl;
					cout << "Estado de la reserva es: " << resvI->getEstado() << endl;
					cout << endl;
				}
				if (resvG != NULL)
				{
					cout << "Codigo de reserva grupal: " << resvG->getCodigo() << endl;
					cout << "Numero de habitacion: " << resvG->getHabitacion() << endl;
					cout << "Costo de la habitacion: " << resvG->getCosto() << endl;
					cout << "Fecha de check-in: " << resvG->getCheckIn() << endl;
					cout << "Fecha de check-out: " << resvG->getCheckOut() << endl;
					cout << "Estado de la reserva: " << resvG->getEstado() << endl;
					cout << endl;
				}
			}
			bool hayReservaSeleccionada = false;
			while (!hayReservaSeleccionada)
			{
				cout << "Ingrese el codigo de la reserva: ";
				cin >> codRes;
				cin.clear();
				cin.ignore(10000, '\n');
				hayReservaSeleccionada = listaReservas.count(codRes);
				if (hayReservaSeleccionada)
				{
					controladorReserva->seleccionarReserva(codRes);
				}
			}
			cout << endl;

			cout << "Ingrese 1 si desea confirmar la eliminacion o 0 si no: " << endl;
			cin >> confirmaBaja;

			if (confirmaBaja)
				controladorReserva->confirmarEliminacion();
			else
				controladorReserva->cancelarEliminacion();

			for (map<int, DtReserva*>::iterator it = listaReservas.begin(); it != listaReservas.end(); it++)
			{
				delete it->second;
			}
			listaReservas.clear();
		}
		catch (invalid_argument& err)
		{
			// No hay reservas asociadas al hostal
			cout << err.what() << endl;
		}
	}
	catch (invalid_argument& err)
	{
		// No hay hostales registrados
		cout << err.what() << endl;
	}
}

void SuscribirseANotificacionesCasoDeUso(IControladorUsuario* controladorUsuario)
{
	try
	{
		map<string, Empleado*> empleados = controladorUsuario->listarEmpleados();
		cout << "Empleados: " << endl;
		for (const auto& itr : empleados)
		{
			cout << itr.second->getEmail() << endl;
		}

		cout << endl;
		cout << "Ingrese el mail del empleado a suscribir a las notificaciones: " << endl;
		string email;
		bool existeEmpleado = false;
		while (!existeEmpleado)
		{
			cin >> email;
			existeEmpleado = empleados.count(email);
			cout << endl;
			if (!existeEmpleado)
			{
				cout << "Ingrese un mail valido del empleado a suscribir a las notificaciones: " << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		cout << endl;
		controladorUsuario->suscribirse(email);
		cout << "Suscrito con exito a las notificaciones " << endl;
	}
	catch (invalid_argument& err)
	{
		// No hay empleados registrados
		cout << err.what() << endl;
	}

}

void ConsultaDeNotificacionesCasoDeUso(IControladorUsuario* controladorUsuario)
{
	try
	{
		//Paso 1: Listar Empelados
		map<string, Empleado*> empleados = controladorUsuario->listarEmpleados();
		cout << "Empleados: " << endl;
		for (const auto& itr : empleados)
		{
			cout << itr.second->getEmail() << endl;
		}
		//Paso 2: El usuario selecciona uno de ellos
		vector<DtNotificacion> notificaciones;
		string email;
		bool hayEmpleadoSeleccionado = false;
		while (!hayEmpleadoSeleccionado)
		{
			try
			{
				cout << "Ingrese el mail del empleado que quiere consultar sus notificaciones: " << endl;
				cin >> email;
				cin.clear();
				cin.ignore(10000, '\n');
				notificaciones = controladorUsuario->listarNotificaciones(email);
				hayEmpleadoSeleccionado = true;
			}
			catch (invalid_argument& err)
			{
				// No existe usuario
				cout << err.what() << endl;
			}
		}

		if (!notificaciones.empty())
		{
			//Paso 3 : Listar notificaciones del empleado
			for (auto& notificacion : notificaciones)
			{
				cout << "Mail del autor: " << notificacion.getAutor() << endl;
				cout << "Calificacion: " << notificacion.getPuntaje() << endl;
				cout << "Comentario: " << notificacion.getComentario() << endl;
				cout << endl;
			}
			//Paso 3 : Eliminar las notificaciones del empleado
			controladorUsuario->eliminarNotificacionesDelEmpleado(email);
		}
		else
		{
			cout << "No hay notificaciones para el empleado" << endl;
		}
	}
	catch (invalid_argument& err)
	{
		// No hay empleados registrados
		cout << err.what() << endl;
	}
}

void EliminarSuscripcionCasoDeUso(IControladorUsuario* controladorUsuario)
{
	try
	{
		map<string, Empleado*> empleados = controladorUsuario->listarEmpleados();
		cout << "Empleados: " << endl;
		for (const auto& itr : empleados)
		{
			cout << itr.second->getEmail() << endl;
		}
		cout << endl;
		cout << "Ingrese el mail del empleado a eliminar la suscripcion a las notificaciones: " << endl;

		string email;
		bool existeEmpleado = false;
		while (!existeEmpleado)
		{
			cin >> email;
			existeEmpleado = empleados.count(email);
			cout << endl;
			if (!existeEmpleado)
			{
				cout << "Ingrese un mail valido del empleado a eliminar la suscripcion a las notificaciones: " << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		cout << endl;
		try
		{
			controladorUsuario->eliminarSuscripcion(email);
			cout << "Eliminado con exito de las notificaciones " << endl;
		}
		catch (invalid_argument& err)
		{
			cout << err.what() << endl;
		}
	}
	catch (invalid_argument& err)
	{
		// No hay empleados registrados
		cout << err.what() << endl;
	}
}

void ModificarFechaDelSistemaCasoDeUso(FechaSistema* fechaSistema)
{
	cout << "Bienvenido a fecha del sistema: " << endl;
	DtFecha actual = fechaSistema->getDtFecha();
	if (actual.getAnio() != 1900)
	{
		cout << "La fecha actual es: hora " << actual.getHora() << " dia " << actual.getDia() << " mes "
			 << actual.getMes() << " año " << actual.getAnio() << endl;
	}
	int hora;
	int dia;
	int mes;
	int anio;
	cout << "Ingrese la hora: ";
	cin >> hora;
	while ((hora < 0) || (hora > 23))
	{
		cout << "Hora no valida re ingrese la hora: " << endl;
		cin >> hora;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Ingrese el dia: ";
	cin >> dia;
	while ((dia < 0) || (dia > 31))
	{
		cout << "Dia no valido re ingrese el dia: " << endl;
		cin >> dia;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Ingrese el mes: ";
	cin >> mes;
	while ((mes < 0) || (mes > 12))
	{
		cout << "Mes no valido re ingrese el mes: " << endl;
		cin >> mes;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Ingrese el año: ";
	cin >> anio;
	while (anio < 1900)
	{
		cout << "Año no valido re ingrese el año: " << endl;
		cin >> anio;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Desea confirmar el ingreso de la fecha presion 1 para confirma 0 para cancelar: " << endl;
	bool continuar;
	cin >> continuar;
	if (continuar)
	{
		fechaSistema->setFecha(hora, dia, mes, anio);
	}
}

// Para testear
void ListarHostalesRegistrados(IControladorHostal* controladorHostal)
{
	try
	{
		map<string, DtHostal*> hostales = controladorHostal->listarHostalesRegistrados();

		cout << "Lista hostales: " << endl;
		cout << endl;
		for (auto& hostal : hostales)
		{
			cout << "Nombre del hostal: " << hostal.second->getNombre() << endl;
			cout << "Direccion del hostal: " << hostal.second->getDireccion() << endl;
			cout << "Telefono del hostal: " << hostal.second->getTelefono() << endl;
			cout << "Calificacion del hostal: " << hostal.second->getCalificacion() << endl;
			cout << endl;
		}

		for (map<string, DtHostal*>::iterator it = hostales.begin(); it != hostales.end(); it++)
		{
			delete it->second;
		}
		hostales.clear();
	}
	catch (invalid_argument& err)
	{
		// No hay hostales registrados
		cout << err.what() << endl;
	}
}

void ListarHabitaciones(IControladorHabitacion* controladorHabitacion)
{
	vector<DtHabitacion> habitaciones = controladorHabitacion->listarTodasHabitaciones();
	if (habitaciones.empty())
		cout << "No hay habitaciones" << endl;
	else
	{
		cout << "Habitaciones: " << endl;
		cout << endl;

		for (auto& habitacion : habitaciones)
		{
			cout << "Numero de habitacion: " << habitacion.getNumero() << endl;
			cout << "Precio de habitacion: " << habitacion.getPrecio() << endl;
			cout << "Capacidad de habitacion: " << habitacion.getCapacidad() << endl;
			cout << endl;
		}
	}
}

void ListarReservas(IControladorReserva* controladorReserva)
{
	map<int, DtReserva*> reservas = controladorReserva->listarReservas();
	if (reservas.empty())
		cout << "No hay reservas" << endl;
	else
	{
		cout << "Reservas: " << endl;
		cout << endl;

		for (auto& reserva : reservas)
		{
			auto* resvI = dynamic_cast<DtReservaIndividual*>(reserva.second);
			auto* resvG = dynamic_cast<DtReservaGrupal*>(reserva.second);

			if (resvI != NULL)
			{
				cout << "El codigo de reserva individual es: " << resvI->getCodigo() << endl;
				cout << "El numero de habitacion es: " << resvI->getHabitacion() << endl;
				cout << "El costo de la habitacion es: " << resvI->getCosto() << endl;
				cout << "La fecha de check-in es: " << resvI->getCheckIn() << endl;
				cout << "La fecha de check-out es: " << resvI->getCheckOut() << endl;
				cout << "El estado de la reserva es: " << resvI->getEstado() << endl;
				resvI = NULL;
			}

			if (resvG != NULL)
			{
				cout << "El codigo de reserva grupal es: " << resvG->getCodigo() << endl;
				cout << "El numero de habitacion es: " << resvG->getHabitacion() << endl;
				cout << "El costo de la habitacion es: " << resvG->getCosto() << endl;
				cout << "La fecha de check-in es: " << resvG->getCheckIn() << endl;
				cout << "La fecha de check-out es: " << resvG->getCheckOut() << endl;
				cout << "El estado de la reserva es: " << resvG->getEstado() << endl;
				// cout << "El mail de las huespedes de la reserva  " << endl;
				map<string, DtHuesped*> mapDtHuespedes = resvG->getHuespedes();
				for (auto& huseped : mapDtHuespedes)
				{
					cout << "     El mail asociado a la reserva grupal: "
						 << huseped.second->getEmail() << " y el nombre es: "
						 << huseped.second->getNombre() << endl;
				}
				resvG = NULL;
			}

			cout << endl;
		}
		for (map<int, DtReserva*>::iterator it = reservas.begin(); it != reservas.end(); it++)
		{
			delete it->second;
		}
		reservas.clear();
	}
}

void ListarEstadias(IControladorEstadia* controladorEstadia)
{
	map<int, DtEstadia> estadias = controladorEstadia->listarTodasEstadias();
	if (estadias.empty())
		cout << "No hay estadías" << endl;
	else
	{
		cout << "Estadías: " << endl;
		cout << endl;

		for (auto& estadia : estadias)
		{
			cout << "  Codigo: " << estadia.first << endl;
			cout << "  Reserva asociada: " << estadia.second.getCodigoReserva() << endl;
			cout << "  Hostal: " << estadia.second.getHostal() << endl;
			cout << "  Huesped: " << estadia.second.getHuesped() << endl;
			cout << "  Habitacion: " << estadia.second.getHabitacion() << endl;
			cout << "  Promo: " << estadia.second.getPromo() << endl;
			cout << "  Check-In: " << estadia.second.getCheckIn() << endl;

			if (estadia.second.getCheckOut().getAnio() != 1899)
			{
				cout << "  Check-Out: " << estadia.second.getCheckOut() << endl;
			}
			cout << endl;
		}

		// asdf

	}
}

void ListarCalificaciones(IControladorEstadia* controladorEstadia)
{
	map<int, DtCalificacion> calificaciones = controladorEstadia->listarTodasCalificaciones();
	if (calificaciones.empty())
	{
		cout << "No hay calificaciones" << endl;
	}
	else
	{
		cout << "Calificaciones: " << endl;
		cout << endl;
	}

	for (auto& calificacion : calificaciones)
	{
		DtComentario com = calificacion.second.getComentario();
		cout << "    Autor: " << com.getAutor() << endl;
		cout << "    Fecha: " << calificacion.second.getFecha() << endl;
		cout << "    Calificacion: " << calificacion.second.getCalificacion() << endl;
		cout << "    Comentario: " << com.getComentario() << endl;
		cout << endl;
		if (com.tieneRespuesta())
		{
			DtComentario* respuesta = com.getRespuesta();
			cout << "    Respuesta de " << respuesta->getAutor() << endl;
			cout << "    Respuesta: " << respuesta->getComentario() << endl;
			delete respuesta;
		}

		cout << endl;
	}
}
