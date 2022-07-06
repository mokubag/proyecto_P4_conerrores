#include "../../include/Classes/ReservaIndividual.h"

ReservaIndividual::ReservaIndividual()
{
	DtFecha f(0, 0, 0, 1900);
	this->codigo = 0;
	this->checkOut = f;
	this->checkIn = f;
	this->estado = Abierta;
	this->reservaIndividual = true;
	this->nombreHostal = "";
	this->hab = NULL;
	this->huesped = "";
	this->fechaActual = f;
}

ReservaIndividual::ReservaIndividual(int codigo, DtFecha checkIn, DtFecha checkOut, enumEstado estado,
		string nombreHostal, Habitacion* h, string huesped, DtFecha fechaActual)
{
	this->codigo = codigo;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->estado = estado;
	this->reservaIndividual = true;
	this->nombreHostal = nombreHostal;
	this->hab = h;
	this->huesped = huesped;
	this->fechaActual = fechaActual;
}

ReservaIndividual::~ReservaIndividual()
{

}

int ReservaIndividual::costo()
{
	return 0;
}

DtReserva* ReservaIndividual::getDtReserva()
{
	DtReservaIndividual* resv = new DtReservaIndividual(
			this->codigo,
			this->checkIn,
			this->checkOut,
			this->estado,
			this->hab->getPrecio(),
			this->hab->getNumero(),
			false,
			this->huesped);

	return resv;
}
