#include "../../include/Datatypes/DtHostal.h"

// #include <string>
// #include <vector>
// #include <iostream>

// using std::string;
// using std::vector;

DtHostal::DtHostal()
{
}
DtHostal::~DtHostal()
{
}

DtHostal::DtHostal(
		string nombre,
		string direccion,
		string telefono,
		int calificacion,
		map<int, DtCalificacion> calificaciones,
		map<int, DtHabitacion> habitaciones)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
	this->calificacionPromedio = calificacion;

	this->calificaciones = calificaciones;
	this->habitaciones = habitaciones;
	//
}

string DtHostal::getNombre()
{
	return this->nombre;
}
string DtHostal::getDireccion()
{
	return this->direccion;
}
string DtHostal::getTelefono()
{
	return this->telefono;
}
int DtHostal::getCalificacion()
{
	return this->calificacionPromedio;
}

map<int, DtCalificacion> DtHostal::getCalificaciones()
{
	return this->calificaciones;
}
map<int, DtHabitacion> DtHostal::getHabitaciones()
{
	return this->habitaciones;
}
