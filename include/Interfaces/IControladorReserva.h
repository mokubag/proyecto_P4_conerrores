#ifndef ICONTROLADORRESERVA_H
#define ICONTROLADORRESERVA_H

#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtReserva.h"
#include "../Datatypes/DtHabitacion.h"
#include "../Classes/Reserva.h"

#include <string>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;

class IControladorReserva
{
public:
	virtual void cancelarEliminacion() = 0;
	virtual void confirmarEliminacion() = 0;
	virtual int confirmarReserva(bool respuesta) = 0;
	virtual void seleccionarReserva(int codigo) = 0;
	virtual void
	realizarReservaIndividual(DtFecha checkIn, DtFecha checkOut) = 0;
	virtual void
	realizarReservaGrupal(DtFecha checkIn, DtFecha checkOut, map<string, string> emails, string huesped,
			int habitacion) = 0;
	virtual map<string, DtHostal*> listarHostalesRegistrados() = 0;
	virtual map<int, DtReserva*> listarReservasNoCanceladas(string hostal, string email) = 0;
	virtual map<int, DtReserva*> listarReservas() = 0;
	virtual map<int, DtReserva*> listarReservasAsociadasAHostal() = 0;
	virtual map<int, DtHabitacion> listarHabitacionesHostalDisponibles(string hostal, DtFecha checkIn, DtFecha
	checKOut) = 0;
	virtual void seleccionarUsuario(string email) = 0;
	virtual void seleccionarHostal(string nombre) = 0;
	virtual void registrarEstadia(int codigoReserva) = 0;
	virtual Reserva* getReserva(int codigo) = 0;
	virtual void seleccionarHabitacion(int numero) = 0;
	virtual bool existeMailUsuario(string email) = 0;
	virtual bool existeReserva(int codigo) = 0;
	virtual map<string, DtUsuario*> listarUsuarios() = 0;
	virtual ~IControladorReserva()
	{
	};
};

#endif
