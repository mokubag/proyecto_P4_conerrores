#include "../../include/Classes/Hostal.h"
#include "../../include/Datatypes/DtHostal.h"
#include "../../include/Datatypes/DtCalificacion.h"

#include <map>

#include <string>
#include <iostream>

using std::map;
using std::cout;
using std::endl;

Hostal::Hostal()
{
}

Hostal::~Hostal()
{
	for (map<int, Habitacion*>::iterator it = Habitaciones.begin(); it != Habitaciones.end(); it++)
	{
		Habitaciones[it->first] = NULL;
	}
	this->Habitaciones.clear();

	for (map<int, Calificacion*>::iterator it = coleccionCalificaciones.begin(); it != coleccionCalificaciones.end(); it++)
	{
		coleccionCalificaciones[it->first] = NULL;
	}
	this->coleccionCalificaciones.clear();
}

Hostal::Hostal(string nombre, string direccion, string telefono)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
}

string Hostal::getNombre()
{
	return this->nombre;
}

string Hostal::getDireccion()
{
	return this->direccion;
}

string Hostal::getTelefono()
{
	return this->telefono;
}

void Hostal::agregarHabitacion(Habitacion* habitacion)
{
	this->Habitaciones[habitacion->getNumero()] = habitacion;
}

void Hostal::agregarCalificacion(Calificacion* calificacion)
{
	this->coleccionCalificaciones[calificacion->getId()] = calificacion;
}

float Hostal::getCalificacion()
{
	if (this->coleccionCalificaciones.empty())
	{
		return 0;
	}
	float total = 0;
	for (auto& calificacion : this->coleccionCalificaciones)
	{
		total += calificacion.second->getCalificacion();
	}
	return total / this->coleccionCalificaciones.size(); // Duda, el compilador no sabe qué es i.
}

map<int, Calificacion*> Hostal::getCalificaciones()
{
	return this->coleccionCalificaciones;
}

DtCalificacion Hostal::getDtCalificacion()
{
	DtCalificacion dtc;

	return dtc;
}

DtHostal* Hostal::getDtHostal()
{
	// Llenamos la dataCalificaciones
	map<int, DtCalificacion> datacalificaciones;
	for (auto& calificacion : this->coleccionCalificaciones)
	{
		datacalificaciones[calificacion.first] = calificacion.second->getDtCalificacion();
		map<int, Calificacion*> listaCalificaiones = this->coleccionCalificaciones;
	}

	// Llenamos la dataHabitaciones
	map<int, DtHabitacion> dataHabitaciones;
	for (auto& habitacion : this->Habitaciones)
	{
		dataHabitaciones[habitacion.first] = habitacion.second->getDtHabitacion();
	}

	DtHostal* dth = new DtHostal(
			this->nombre,
			this->direccion,
			this->telefono,
			(int)this->getCalificacion(),
			datacalificaciones,
			dataHabitaciones);
	return dth;
}

map<int, Habitacion*> Hostal::listarHabitacionesHostal()
{
	return this->Habitaciones;
}

void Hostal::desvincularCalificacion(int idCalificacion)
{
	this->coleccionCalificaciones.erase(idCalificacion);
}
