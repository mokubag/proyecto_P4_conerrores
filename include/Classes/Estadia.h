#ifndef ESTADIA_H
#define ESTADIA_H

#include "../Datatypes/DtEmpleado.h"
#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtEstadia.h"
#include "../Datatypes/DtCalificacion.h"
#include "Reserva.h"
#include "Calificacion.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Reserva;

class Estadia
{
private:
	DtFecha checkIn;
	DtFecha checkOut;
	string promo;
	int codigo;
	Reserva* reserva;
	Calificacion* calificacion;
	string emailHuesped;

public:
	Estadia();
	Estadia(DtFecha checkIn, DtFecha checkOut, string promo, Reserva* reserva, int codigo, string emailHuesped);
	void eliminarCalificacion();
	bool esActiva();
	void finalizarEstadiaActiva(DtFecha checkOut);
	int getCodigo();
	int getCodigoReserva();
	DtCalificacion getDtCalificacion();
	DtEstadia getDtEstadia();
	Calificacion* getCalificacion();
	DtFecha getCheckIn();
	DtFecha getCheckOut();
	string getPromo();
	Reserva* getReserva();
	void setCalificacion(Calificacion* cal);
	void desvincularReserva();

	~Estadia();
};

#endif
