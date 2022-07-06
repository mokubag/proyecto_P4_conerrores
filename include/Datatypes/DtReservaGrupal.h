#ifndef DTRESERVAGRUPAL_H
#define DTRESERVAGRUPAL_H

#include "DtHuesped.h"
#include "DtReserva.h"
#include "DtFecha.h"
#include "enumEstado.h"

#include <string>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;

class DtReservaGrupal : public DtReserva
{
private:
	map<string, DtHuesped*> maphuespedes;

public:
	DtReservaGrupal();
	DtReservaGrupal(
			int codigo,
			DtFecha checkIn,
			DtFecha checkOut,
			enumEstado estado,
			float costo,
			int habitacion,
			map<string, DtHuesped*> huespedes
	);

	~DtReservaGrupal();

	map<string, DtHuesped*> getHuespedes();
};

#endif
