#ifndef RESERVA_H
#define RESERVA_H

#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtReserva.h"
#include "../Datatypes/enumEstado.h"
#include "Habitacion.h"

#include <string>

using std::string;

class Habitacion;

class Reserva
{
protected:
	int codigo;
	DtFecha checkOut;
	DtFecha checkIn;
	enumEstado estado;
	bool reservaIndividual;
	string nombreHostal;
	string huesped;
	Habitacion* hab;
	DtFecha fechaActual;

public:
	virtual int costo() = 0;
	int getCodigo();
	DtFecha getcheckIn();
	DtFecha getcheckOut();
	enumEstado getEstado();
	bool getReservaIndividual();
	string getHostal();
	string getHuesped();
	Habitacion* getHabitacion();
	void cerrarReserva();
	DtFecha getFechaReserva();
	virtual DtReserva* getDtReserva() = 0;
	void desvincularHabitacion();

	virtual ~Reserva();
};

#endif
