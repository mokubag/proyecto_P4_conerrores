#ifndef ICONTROLADORHABITACION_H
#define ICONTROLADORHABITACION_H

#include "../Datatypes/DtHabitacion.h"
#include "../Datatypes/DtHostal.h"
#include "../Datatypes/DtReserva.h"
#include "../Datatypes/DtServicio.h"

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

class IControladorHabitacion
{
public:
	virtual void cancelarIngresoHabitacion() = 0;
	virtual void crearHabitacion() = 0;
	virtual void desvincularReserva(int h, int codigo) = 0;
	virtual void seleccionarHostal(string nombre) = 0;
	virtual map<int, DtReserva*> listarReservas(string nombre) = 0;
	virtual void ingresarHabitacion(int numero, int precio, int capacidad) = 0;
	virtual map<string, DtHostal*> listarHostalesRegistrados() = 0;
	virtual vector<DtHabitacion> listarTodasHabitaciones() = 0;

	virtual ~IControladorHabitacion()
	{
	};
};

#endif
