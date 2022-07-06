#ifndef DTRESERVAINDIVIDUAL_H
#define DTRESERVAINDIVIDUAL_H

#include "DtFecha.h"
#include "enumEstado.h"
#include "DtReserva.h"

class DtReservaIndividual : public DtReserva
{
private:
	string nomHues;
public:
	DtReservaIndividual();
	DtReservaIndividual(
			int codigo,
			DtFecha checkIn,
			DtFecha checkOut,
			enumEstado estado,
			float costo,
			int habitacion,
			bool pagado,
			string nombreHuesped);

	string getHuesped();

	~DtReservaIndividual();
};

#endif
