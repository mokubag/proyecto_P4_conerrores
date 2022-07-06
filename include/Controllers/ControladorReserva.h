#ifndef CONTROLADORRESERVA_H
#define CONTROLADORRESERVA_H

#include "../Datatypes/DtHabitacion.h"
#include "../Datatypes/DtReserva.h"
#include "../Datatypes/DtFecha.h"
#include "../Interfaces/IControladorReserva.h"
#include "../Classes/Reserva.h"
#include "../Classes/ReservaIndividual.h"
#include "../Classes/ReservaGrupal.h"
#include "../Classes/Huesped.h"

#include "ControladorHostal.h"
#include "ControladorUsuario.h"
#include "ControladorHabitacion.h"
#include "ControladorEstadia.h"
#include "../Classes/FechaSistema.h"

#include <string>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;

class ControladorReserva : public IControladorReserva
{
private:
	ControladorReserva();
	string huesped;
	map<string, string> huespedes;
	int habitacion;
	string nombreHostal;
	int codigo;
	int cantReservasCreadas;
	static ControladorReserva* instancia;
	map<int, Reserva*> coleccionReservas;
	bool esReservaIndivudal;
	DtFecha checkIn;
	DtFecha checkOut;
	DtFecha fechaActual;

public:
	static ControladorReserva* getInstancia();
	void cancelarEliminacion();
	void confirmarEliminacion();
	int confirmarReserva(bool respuesta);
	void seleccionarReserva(int codigo);
	void realizarReservaIndividual(DtFecha checkIn, DtFecha checkOut);
	void
	realizarReservaGrupal(DtFecha checkIn, DtFecha checkOut, map<string, string> emails, string huesped,
			int habitacion);
	map<string, DtHostal*> listarHostalesRegistrados();
	map<int, DtReserva*> listarReservasNoCanceladas(string hostal, string email);
	map<int, DtReserva*> listarReservas();
	map<int, DtReserva*> listarReservasAsociadasAHostal();
	map<int, DtHabitacion> listarHabitacionesHostalDisponibles(string hostal, DtFecha checkIn, DtFecha checKOut);
	void seleccionarUsuario(string email);
	void seleccionarHostal(string nombre);
	void registrarEstadia(int codigoReserva);
	Reserva* getReserva(int codigo);
	void seleccionarHabitacion(int numero);
	bool existeMailUsuario(string email);
	bool existeReserva(int codigo);
	map<string, DtUsuario*> listarUsuarios();
	~ControladorReserva();
};

#endif
