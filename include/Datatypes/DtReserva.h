#ifndef DTRESERVA_H
#define DTRESERVA_H

#include "DtFecha.h"
#include "enumEstado.h"

#include <string>
#include <vector>

using std::string;

class DtReserva
{
protected:
	int codigo;
	DtFecha checkIn;
	DtFecha checkOut;
	enumEstado estado;
	float costo;
	int habitacion;
	bool reservaIndividual;

public:
	DtReserva();
	DtReserva(
			int codigo,
			DtFecha checkIn,
			DtFecha checkOut,
			enumEstado estado,
			float costo,
			int habitacion);

	virtual ~DtReserva();
	int getCodigo();
	DtFecha getCheckIn();
	DtFecha getCheckOut();
	enumEstado getEstado();
	float getCosto();
	int getHabitacion();
	bool getReservaIndividual();
};

#endif
