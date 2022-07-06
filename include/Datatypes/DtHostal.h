

#ifndef DTHOSTAL_H
#define DTHOSTAL_H

#include "DtCalificacion.h"
#include "DtHabitacion.h"

#include <string>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;

class DtHostal
{
private:
	string nombre;
	string direccion;
	string telefono;
	int calificacionPromedio;
	map<int, DtCalificacion> calificaciones;
	map<int, DtHabitacion> habitaciones;

public:
	DtHostal();
	~DtHostal();

	DtHostal(
			string nombre,
			string direccion,
			string telefono,
			int calificacion,
			map<int, DtCalificacion> calificaciones,
			map<int, DtHabitacion> habitaciones);

	string getNombre();
	string getDireccion();
	string getTelefono();
	int getCalificacion();
	map<int, DtCalificacion> getCalificaciones();
	map<int, DtHabitacion> getHabitaciones();
};

#endif
