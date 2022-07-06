#ifndef CONTROLADORHABITACION_H
#define CONTROLADORHABITACION_H

#include "../Datatypes/DtServicio.h"
#include "../Datatypes/DtReserva.h"
#include "../Classes/Hostal.h"
#include "../Classes/Habitacion.h"
#include "../Interfaces/IControladorHabitacion.h"

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;


class ControladorHabitacion : public IControladorHabitacion
{
private:
	string nombre;
	int numero;
	int precio;
	int capacidad;

	static ControladorHabitacion* instancia;
	vector<Habitacion*> coleccionHabitaciones;
	ControladorHabitacion();

public:
	~ControladorHabitacion();
	static ControladorHabitacion* getInstancia();

	void cancelarIngresoHabitacion();
	void crearHabitacion();
	void desvincularReserva(int h, int codigo);
	void ingresarHabitacion(int numero, int precio, int capacidad);
	map<int, DtReserva*> listarReservas(string nombre);
	void seleccionarHostal(string nombre);
	map<string, DtHostal*> listarHostalesRegistrados();
	vector<DtHabitacion> listarTodasHabitaciones();
};

#endif
