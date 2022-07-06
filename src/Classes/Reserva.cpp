#include "../../include/Classes/Reserva.h"

int Reserva::getCodigo()
{
	return this->codigo;
}

DtFecha Reserva::getcheckIn()
{
	return this->checkIn;
}

DtFecha Reserva::getcheckOut()
{
	return this->checkOut;
}

enumEstado Reserva::getEstado()
{
	return this->estado;
}

bool Reserva::getReservaIndividual()
{
	return this->reservaIndividual;
}

string Reserva::getHostal()
{
	return this->nombreHostal;
}

string Reserva::getHuesped()
{
	return this->huesped;
}

Habitacion* Reserva::getHabitacion()
{
	return this->hab;
}

void Reserva::cerrarReserva()
{
	this->estado = Cerrada;
}

DtFecha Reserva::getFechaReserva()
{
	return this->fechaActual;
}

void Reserva::desvincularHabitacion()
{
	this->hab = NULL;
}

Reserva::~Reserva()
{
}

