#include "../../include/Datatypes/DtReservaIndividual.h"

DtReservaIndividual::DtReservaIndividual()
{
}

DtReservaIndividual::DtReservaIndividual(
		int codigo,
		DtFecha checkIn,
		DtFecha checkOut,
		enumEstado estado,
		float costo,
		int habitacion,
		bool pagado,
		string nombreHuesped
)
{
	this->codigo = codigo;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->estado = estado;
	this->costo = costo;
	this->habitacion = habitacion;
	this->reservaIndividual = true;
	this->nomHues = nombreHuesped;
}

string DtReservaIndividual::getHuesped()
{
	return this->nomHues;
}
DtReservaIndividual::~DtReservaIndividual()
{
}
