#ifndef RESERVAINDIVIDUAL_H
#define RESERVAINDIVIDUAL_H

#include "Reserva.h"
#include "Huesped.h"
#include "Habitacion.h"
#include "../Datatypes/DtReservaIndividual.h"

class Huesped;

class ReservaIndividual : public Reserva
{
private:
	Huesped* huesp;
public:
	ReservaIndividual();
	ReservaIndividual(int codigo, DtFecha checkIn, DtFecha checkOut, enumEstado estado, string nombreHostal,
			Habitacion* h, string huesped, DtFecha fechaActual);

	~ReservaIndividual();

	int costo();
	DtReserva* getDtReserva();

};

#endif
