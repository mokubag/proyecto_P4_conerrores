#ifndef CONTROLADORHOSTAL_H
#define CONTROLADORHOSTAL_H

#include "../Classes/Empleado.h"
#include "../Datatypes/DtEmpleado.h"
#include "../Datatypes/DtHostal.h"
#include "../Datatypes/DtReserva.h"
#include "../Datatypes/DtCalificacion.h"
#include "../Interfaces/IControladorHostal.h"
#include "../Datatypes/enumCargo.h"
#include "ControladorUsuario.h"

#include <map>
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::map;
using std::string;
using std::vector;

class ControladorHostal : public IControladorHostal
{
private:
	string nombre;
	string direccion;
	string telefono;
	ControladorHostal();
	static ControladorHostal* instancia;
	map<string, Hostal*> coleccionHostales;

public:
	static ControladorHostal* getInstancia();

	void agregarHabitacionAHostal(string nombre, Habitacion* h);
	void asignarEmpleado(string email, enumCargo cargo);
	void confirmarHostal();
	bool verificarHostal(string nombre);
	void seleccionarHostal(string nombre);
	DtHostal* mostrarHostal();
	map<int, DtCalificacion> mostrarCalificaciones();
	map<int, DtReserva*> listarReservas();
	map<string, DtHostal*> listarHostalesRegistrados();
	map<string, DtEmpleado*> listarEmpleadosSinAsignar();
	void ingresarHostal(string nombre, string direccion, string telefono);
	Hostal* getHostal(string nombre);
	map<int, DtHabitacion> listarHabitacionesHostalDisponibles(string hostal, DtFecha checkIn, DtFecha checKOut);
	Habitacion* habitacionHostal(string hostal, int numeroHabitacion);
	vector<DtHostal*> listarTop3Hostales();
	bool existeHostal(string nombre);
	map<int, DtComentario> listarComentariosSinResponderHostal(string email);


	bool existeHabitacion(string nombreHostal, int numero);

	~ControladorHostal();
};

#endif
