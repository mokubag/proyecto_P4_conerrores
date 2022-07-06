#include "../../include/Controllers/ControladorHostal.h"
#include "../../include/Controllers/ControladorUsuario.h"
#include "../../include/Controllers/ControladorHabitacion.h"

#include <algorithm>
using std::sort;

ControladorHostal* ControladorHostal::instancia = NULL;

ControladorHostal::ControladorHostal()
{
	map<string, Hostal*> mapHostales;

	this->nombre = "";
	this->direccion = "";
	this->telefono = "";
	this->coleccionHostales = mapHostales;
}

ControladorHostal::~ControladorHostal()
{
	for (map<string, Hostal*>::iterator itr = this->coleccionHostales.begin();
		 itr != this->coleccionHostales.end();
		 itr++)
	{
		delete itr->second;
	};
	this->coleccionHostales.clear();
}

ControladorHostal* ControladorHostal::getInstancia()
{
	if (instancia == NULL)
		instancia = new ControladorHostal();
	return instancia;
}

void ControladorHostal::agregarHabitacionAHostal(string nombre, Habitacion* h)
{
	this->coleccionHostales[nombre]->agregarHabitacion(h);
}

void ControladorHostal::asignarEmpleado(string email, enumCargo cargo)
{
	Empleado* empleado = dynamic_cast<Empleado*>(ControladorUsuario::getInstancia()->getUsuario(email));
	if (empleado == NULL)
	{
		throw invalid_argument("No existe empleado con ese mail");
	}
	else
	{
		empleado->setCargo(cargo);
		empleado->setHostal(this->getHostal(this->nombre));
	}
}

void ControladorHostal::confirmarHostal()
{
	Hostal* h = new Hostal(nombre, direccion, telefono);
	this->coleccionHostales[nombre] = h;
	this->nombre = "";
	this->direccion = "";
	this->telefono = "";
}

bool ControladorHostal::verificarHostal(string nombre)
{
	if (this->coleccionHostales.count(nombre))
	{
		// como ya existe hostal con el nombre se deja de recordar nombre, direccion, telefono
		this->nombre = "";
		this->direccion = "";
		this->telefono = "";
		return true;
	}
	return false;
}

void ControladorHostal::seleccionarHostal(string nombre)
{
	if (this->coleccionHostales.count(nombre) != 0)
		this->nombre = nombre;
	else
	{
		string error = "No hay hostal de nombre " + nombre + " registrado";
		throw invalid_argument(error);
	}
}

DtHostal* ControladorHostal::mostrarHostal()
{
	DtHostal* hostal = this->coleccionHostales[this->nombre]->getDtHostal();
	this->nombre = "";
	return hostal;
}

map<int, DtCalificacion> ControladorHostal::mostrarCalificaciones()
{
	map<string, Hostal*> hostales = this->coleccionHostales;
	Hostal* h = hostales[nombre];
	map<int, DtCalificacion> dtCalificaciones;

	if (h != NULL)
	{
		map<int, Calificacion*> calificaciones = h->getCalificaciones();
		for (auto& calificacion : calificaciones)
		{
			dtCalificaciones[calificacion.first] = calificacion.second->getDtCalificacion();
		}
	}
	this->nombre = "";
	return dtCalificaciones;
}

map<int, DtReserva*> ControladorHostal::listarReservas()
{
	return ControladorHabitacion::getInstancia()->listarReservas(this->nombre);
}

map<string, DtHostal*> ControladorHostal::listarHostalesRegistrados()
{
	if (!this->coleccionHostales.empty())
	{
		map<string, DtHostal*> ListaHostales;
		for (auto& hostal : this->coleccionHostales)
		{
			ListaHostales[hostal.second->getNombre()] = (hostal.second->getDtHostal());
		}
		return ListaHostales;
	}

	else
		throw invalid_argument("No hay hostales registrados");
}

map<string, DtEmpleado*> ControladorHostal::listarEmpleadosSinAsignar()
{
	try
	{
		return ControladorUsuario::getInstancia()->listarEmpleadosSinAsignar();
	}
	catch (invalid_argument& err)
	{
		// No hay empleados sin asignar
		throw invalid_argument(err.what());
	}
}

void ControladorHostal::ingresarHostal(string nombre, string direccion, string telefono)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
}

Hostal* ControladorHostal::getHostal(string nombre)
{
	return this->coleccionHostales[nombre];
}

map<int, DtHabitacion>
ControladorHostal::listarHabitacionesHostalDisponibles(string hostal, DtFecha checkIn, DtFecha checKOut)
{
	map<int, DtHabitacion> listaDeHabitacionesDisponibles;
	map<int, Habitacion*> habitacionesDeHostal = coleccionHostales[hostal]->listarHabitacionesHostal();
	if (habitacionesDeHostal.empty())
	{
		throw invalid_argument("No hay habitaciones registradas");
	}
	for (auto& habitacion : habitacionesDeHostal)
	{
		bool libre;
		libre = habitacion.second->disponibleEntreFechas(checkIn, checKOut);
		if (libre)
		{
			listaDeHabitacionesDisponibles[habitacion.second->getNumero()] = habitacion.second->getDtHabitacion();
		}
	}
	return listaDeHabitacionesDisponibles;
}

Habitacion* ControladorHostal::habitacionHostal(string hostal, int numeroHabitacion)
{
	return coleccionHostales[hostal]->listarHabitacionesHostal()[numeroHabitacion];
}

bool esMayor(Hostal* i, Hostal* j)
{
	return (i->getCalificaciones() < j->getCalificaciones());
}

vector<DtHostal*> ControladorHostal::listarTop3Hostales()
{
	vector<Hostal*> hostalesOrdenados;
	map<string, Hostal*> hostales = this->coleccionHostales;

	// Inserta de forma ordenada
	vector<Hostal*> hostalesNoOrdenados;
	for (auto& hostal : hostales)
	{
		if (hostal.second->getCalificacion() != 0)
		{
			hostalesNoOrdenados.push_back(hostal.second);
		}
	}
	sort(hostalesNoOrdenados.begin(), hostalesNoOrdenados.end(), esMayor);
	hostalesOrdenados = hostalesNoOrdenados;

	// Se obtienen los Dt de los tres hostales mejor calificados
	vector<DtHostal*> dthlist;
	int i = 0;
	int nTop = 3;
	while (i < nTop && i < int(hostalesOrdenados.size()))
	{
		DtHostal* dth = hostalesOrdenados[i]->getDtHostal();
		dthlist.push_back(dth);
		i++;
	}
	return dthlist;
}

bool ControladorHostal::existeHostal(string nombre)
{
	return this->coleccionHostales.count(nombre);
}

map<int, DtComentario> ControladorHostal::listarComentariosSinResponderHostal(string email)
{
	map<int, DtComentario> listaComentarios;
	Empleado* empleado = dynamic_cast<Empleado*>(ControladorUsuario::getInstancia()->getUsuario(email));

	map<int, Calificacion*> calificacionesHostal = empleado->getHostal()->getCalificaciones();
	for (auto& calificacion : calificacionesHostal)
	{
		Comentario* respuesta = calificacion.second->getComentario()->getRespuesta();
		if (respuesta == NULL)
		{
			listaComentarios[calificacion.second->getComentario()->getId()] = calificacion.second->getDtComentario();
		}
	}
	if (!listaComentarios.empty())
	{
		return listaComentarios;
	}
	else
	{
		throw invalid_argument("No hay comentarios sin responder para este hostal");
	}
}

bool ControladorHostal::existeHabitacion(string nombreHostal, int numero)
{
	return this->coleccionHostales[nombreHostal]->listarHabitacionesHostal().count(numero);
}