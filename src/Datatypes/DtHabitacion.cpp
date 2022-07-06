#include "../../include/Datatypes/DtHabitacion.h"

DtHabitacion::DtHabitacion()
{
}

DtHabitacion::DtHabitacion(int numero, int precio, int capacidad)
{
	this->numero = numero;
	this->precio = precio;
	this->capacidad = capacidad;
}

DtHabitacion::~DtHabitacion()
{
}

int DtHabitacion::getNumero()
{
	return this->numero;
}

int DtHabitacion::getPrecio()
{
	return this->precio;
}

int DtHabitacion::getCapacidad()
{
	return this->capacidad;
}
