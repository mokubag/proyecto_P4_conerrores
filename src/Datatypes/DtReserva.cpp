#include "../../include/Datatypes/DtReserva.h"

using namespace std;
#include <iostream>

DtReserva::DtReserva()
{

}

DtReserva::DtReserva(
		int codigo,
		DtFecha checkIn,
		DtFecha checkOut,
		enumEstado estado,
		float costo,
		int habitacion
)
{
	this->codigo = codigo;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->estado = estado;
	this->costo = costo;
	this->habitacion = habitacion;
}

DtReserva::~DtReserva()
{
}

int DtReserva::getCodigo()
{
	return this->codigo;
}

DtFecha DtReserva::getCheckIn()
{
	return this->checkIn;
}

DtFecha DtReserva::getCheckOut()
{
	return this->checkOut;
}

enumEstado DtReserva::getEstado()
{
	return this->estado;
}

float DtReserva::getCosto()
{
	return this->costo;
}

int DtReserva::getHabitacion()
{
	return this->habitacion;
}

bool DtReserva::getReservaIndividual()
{
	return this->reservaIndividual;
}