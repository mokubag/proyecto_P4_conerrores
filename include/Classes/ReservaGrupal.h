#ifndef RESERVAGRUPAL_H
#define RESERVAGRUPAL_H

#include "../Datatypes/DtReserva.h"
#include "../Datatypes/DtReservaGrupal.h"
#include "../Datatypes/DtReservaIndividual.h"
#include "../Datatypes/DtFecha.h"
#include "Reserva.h"
#include "Huesped.h"

#include <iostream>
#include <vector>

using namespace std;
using std::vector;

class Huesped;

class ReservaGrupal : public Reserva
{
private:
	map<string, Huesped*> huespedes;
public:
	ReservaGrupal();
	ReservaGrupal(int codigo, DtFecha checkIn, DtFecha checkOut, enumEstado estado, string nombreHostal, Habitacion* h,
			map<string, Huesped*> huespedesReservaGrupal, string huesped, DtFecha fechaActual);
	~ReservaGrupal();
	int costo();
	//int getCodigo();
	DtFecha getcheckIn();
	DtFecha getcheckOut();
	//enumEstado getEstado();
	bool getReservaIndividual();
	DtReserva* getDtReserva();
	map<string, Huesped*> getHuespedes();
	void desvincularHuesped(string email);
};

#endif
