#ifndef DTESTADIA_H
#define DTESTADIA_H

#include "DtFecha.h"
#include "DtCalificacion.h"

#include <string>
#include <map>

using std::string;
using std::map;

class DtEstadia
{
private:
	int id;
	string hostal;
	string huesped;
	int habitacion;
	DtFecha checkIn;
	DtFecha checkOut;
	string promo;
	int codigoReserva;
	DtCalificacion calificacion;
	bool estaCalificada;

public:
	DtEstadia();
	DtEstadia(
			int id,
			string hostal,
			string huesped,
			int habitacion,
			DtFecha checkIn,
			DtFecha checkOut,
			string promo,
			int codigoReserva,
			DtCalificacion calificacion,
			bool estaCalificada
	);

	~DtEstadia();

	int getId();
	string getHostal();
	string getHuesped();
	int getHabitacion();
	DtFecha getCheckIn();
	DtFecha getCheckOut();
	string getPromo();
	int getCodigoReserva();
	DtCalificacion getCalificaion();
	bool getEstaCalificada();

};

#endif
