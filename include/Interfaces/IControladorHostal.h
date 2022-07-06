#ifndef ICONTROLADORHOSTAL_H
#define ICONTROLADORHOSTAL_H

#include "../Datatypes/DtCalificacion.h"
#include "../Datatypes/DtReserva.h"
#include "../Datatypes/DtHostal.h"
#include "../Datatypes/DtEmpleado.h"
#include "../Classes/Hostal.h"
#include "IControladorUsuario.h"

#include <string>
#include <vector>
#include <map>
using std::map;
using std::string;

class IControladorHostal
{

public:
	virtual void agregarHabitacionAHostal(string nombre, Habitacion* h) = 0;
	virtual void asignarEmpleado(string email, enumCargo cargo) = 0;
	virtual void confirmarHostal() = 0;
	virtual bool verificarHostal(string nombre) = 0;
	virtual void seleccionarHostal(string nombre) = 0;
	virtual DtHostal* mostrarHostal() = 0;
	virtual map<int, DtCalificacion> mostrarCalificaciones() = 0;
	virtual map<int, DtReserva*> listarReservas() = 0;
	virtual map<string, DtHostal*> listarHostalesRegistrados() = 0;
	virtual map<string, DtEmpleado*> listarEmpleadosSinAsignar() = 0;
	virtual void ingresarHostal(string nombre, string direccion, string telefono) = 0;
	virtual Hostal* getHostal(string nombre) = 0;
	virtual map<int, DtHabitacion>
	listarHabitacionesHostalDisponibles(string hostal, DtFecha checkIn, DtFecha checKOut) = 0;
	virtual Habitacion* habitacionHostal(string hostal, int numeroHabitacion) = 0;
	virtual vector<DtHostal*> listarTop3Hostales() = 0;
	virtual bool existeHostal(string nombre) = 0;
	virtual map<int, DtComentario> listarComentariosSinResponderHostal(string email) = 0;

	virtual bool existeHabitacion(string nombreHostal, int numero) = 0;
	virtual ~IControladorHostal()
	{
	};
};

#endif
