#include "../../include/Datatypes/DtReservaGrupal.h"

using std::map;

DtReservaGrupal::DtReservaGrupal()
{
}

DtReservaGrupal::DtReservaGrupal(
		int codigo,
		DtFecha checkIn,
		DtFecha checkOut,
		enumEstado estado,
		float costo,
		int habitacion,
		map<string, DtHuesped*> listhuespedes
)
{
	this->codigo = codigo;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->estado = estado;
	this->costo = costo;
	this->habitacion = habitacion;
	this->maphuespedes = listhuespedes;
	this->reservaIndividual = false;
}

DtReservaGrupal::~DtReservaGrupal()
{
	for (map<string, DtHuesped*>::iterator it = maphuespedes.begin(); it != maphuespedes.end(); it++)
	{
		delete it->second;
	}
}

map<string, DtHuesped*> DtReservaGrupal::getHuespedes()
{
	map<string, DtHuesped*> vect = this->maphuespedes;
	return vect;
}
