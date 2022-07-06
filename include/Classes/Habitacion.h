#ifndef HABITACION_H
#define HABITACION_H

#include "Servicio.h"
#include "Estadia.h"

#include "../Datatypes/DtHabitacion.h"
#include "../Datatypes/DtReserva.h"

#include <string>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;

class Reserva;
class Estadia;

class Habitacion
{
private:
	int numero;
	int precio;
	int capacidad;
	vector<Servicio*> servicios;
	map<int, Reserva*> reservas;

public:
	Habitacion();
	Habitacion(int numero, int precio, int capacidad);
	int getNumero();
	int getPrecio();
	int getCapacidad();
	void agregarServicio(Servicio* s);
	void desvincularReserva(int codigo);
	DtHabitacion getDtHabitacion();
	vector<Servicio*> getServicios();
	map<int, Reserva*> getReservas();
	bool disponibleEntreFechas(DtFecha checkIn, DtFecha checkOut);
	void setReserva(Reserva* r);

	~Habitacion();
};
#endif
