#include "../../include/Classes/ReservaGrupal.h"

ReservaGrupal::ReservaGrupal()
{
	DtFecha f(0, 1, 1, 1900);
	map<string, Huesped*> vectHuesp;

	this->codigo = 0;
	this->checkOut = f;
	this->checkIn = f;
	this->estado = Abierta;
	this->reservaIndividual = false;
	this->huesped = "";
	this->huespedes = vectHuesp;
	this->nombreHostal = "";
	this->hab = NULL;
}

ReservaGrupal::ReservaGrupal(int codigo, DtFecha checkIn, DtFecha checkOut, enumEstado estado, string nombreHostal,
		Habitacion* h, map<string, Huesped*> huespedesReservaGrupal, string huesped, DtFecha fechaActual)
{
	this->codigo = codigo;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->estado = estado;
	this->reservaIndividual = false;
	this->huesped = huesped;
	this->huespedes = huespedesReservaGrupal;
	this->nombreHostal = nombreHostal;
	this->hab = h;
	this->fechaActual = fechaActual;
}

ReservaGrupal::~ReservaGrupal()
{
}

int ReservaGrupal::costo()
{
	return 0;
}

DtReserva* ReservaGrupal::getDtReserva()
{
	map<string, DtHuesped*> listaDtHuesped;
	for (auto& huesped : this->huespedes)
	{
		DtHuesped* dthuesp = dynamic_cast<DtHuesped*>(huesped.second->getDtUsuario());
		if (dthuesp != NULL)
		{
			listaDtHuesped[huesped.second->getEmail()] = dthuesp;
		}
	}
	DtReserva* dtrg = new DtReservaGrupal(
			this->codigo,
			this->checkIn,
			this->checkOut,
			this->estado,
			this->hab->getPrecio(),
			this->hab->getNumero(),
			listaDtHuesped);

	return dtrg;
}

map<string, Huesped*> ReservaGrupal::getHuespedes()
{
	return this->huespedes;
}

void ReservaGrupal::desvincularHuesped(string email)
{
	this->huespedes.erase(email);
}