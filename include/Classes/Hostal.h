#ifndef HOSTAL_H
#define HOSTAL_H

#include "../Datatypes/DtHostal.h"
#include "../Datatypes/DtCalificacion.h"
#include "Habitacion.h"
#include "Calificacion.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Hostal
{
private:
	string nombre;
	string direccion;
	string telefono;
	map<int, Habitacion*> Habitaciones;
	map<int, Calificacion*> coleccionCalificaciones;

public:
	Hostal();
	~Hostal();

	Hostal(string nombre, string direccion, string telefono);

	string getNombre();
	string getDireccion();
	string getTelefono();
	void agregarHabitacion(Habitacion* habitacion);
	void agregarCalificacion(Calificacion* calificacion);
	float getCalificacion();
	map<int, Calificacion*> getCalificaciones();
	DtCalificacion getDtCalificacion();
	DtHostal* getDtHostal();
	map<int, Habitacion*> listarHabitacionesHostal();

	void desvincularCalificacion(int idCalificacion);
};

#endif
