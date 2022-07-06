
#include "../../include/Controllers/ControladorHabitacion.h"
#include "../../include/Controllers/ControladorHostal.h"
#include "../../include/Classes/Habitacion.h"

ControladorHabitacion* ControladorHabitacion::instancia = NULL;

ControladorHabitacion::ControladorHabitacion()
{
	vector<Habitacion*> vectHabitaciones;
	this->nombre = "";
	this->numero = 0;
	this->precio = 0;
	this->capacidad = 0;
	this->coleccionHabitaciones = vectHabitaciones;
}

ControladorHabitacion::~ControladorHabitacion()
{
	while (!coleccionHabitaciones.empty())
	{
		delete coleccionHabitaciones.back();
		coleccionHabitaciones.pop_back();
	}
}

ControladorHabitacion* ControladorHabitacion::getInstancia()
{
	if (instancia == NULL)
		instancia = new ControladorHabitacion();
	return instancia;
}

void ControladorHabitacion::cancelarIngresoHabitacion()
{
	this->nombre = "";
	this->numero = 0;
	this->precio = 0;
	this->capacidad = 0;
}

void ControladorHabitacion::crearHabitacion()
{
	bool existeHabitacion = ControladorHostal::getInstancia()->getHostal(
			this->nombre)->listarHabitacionesHostal().count(this->numero);
	if (!existeHabitacion)
	{
		Habitacion* h = new Habitacion(this->numero, this->precio, this->capacidad);
		ControladorHostal::getInstancia()->agregarHabitacionAHostal(this->nombre, h);

		this->coleccionHabitaciones.push_back(h);

		this->nombre = "";
		this->numero = 0;
		this->precio = 0;
		this->capacidad = 0;
	}
	else
	{
		this->nombre = "";
		this->numero = 0;
		this->precio = 0;
		this->capacidad = 0;

		throw invalid_argument("Ya existe otra habitacion con ese numero en el hostal");
	}
}

void ControladorHabitacion::desvincularReserva(int h, int codigo)
{
	for (auto& habitacion : this->coleccionHabitaciones)
	{
		if (habitacion->getNumero() == h)
		{
			habitacion->desvincularReserva(codigo);
		}
	}
}

void ControladorHabitacion::ingresarHabitacion(int numero, int precio, int capacidad)
{
	if (this->nombre != "")
	{
		this->numero = numero;
		this->precio = precio;
		this->capacidad = capacidad;
	}
	else
		throw invalid_argument("No hay hostal seleccionado");
}

map<int, DtReserva*> ControladorHabitacion::listarReservas(string nombre)
{
	map<int, DtReserva*> dtr;
	for (auto& habitacion : this->coleccionHabitaciones)
	{
		for (auto& reserva : habitacion->getReservas())
		{
			if (reserva.second->getHostal() == nombre)
			{
				dtr[reserva.first] = reserva.second->getDtReserva();
			}
		}
	}
	return dtr;
}

void ControladorHabitacion::seleccionarHostal(string nombre)
{
	bool existeHostal = ControladorHostal::getInstancia()->existeHostal(nombre);
	if (existeHostal)
		this->nombre = nombre;
	else
		throw invalid_argument("No hay hostal registrado con ese nombre");
}

map<string, DtHostal*> ControladorHabitacion::listarHostalesRegistrados()
{
	try
	{
		return ControladorHostal::getInstancia()->listarHostalesRegistrados();
	}
	catch (invalid_argument& err)
	{
		throw invalid_argument(err.what());
	}
}

vector<DtHabitacion> ControladorHabitacion::listarTodasHabitaciones()
{
	vector<DtHabitacion> habitaciones;
	for (auto& habitacion : this->coleccionHabitaciones)
	{
		habitaciones.push_back(habitacion->getDtHabitacion());
	}
	return habitaciones;
}
