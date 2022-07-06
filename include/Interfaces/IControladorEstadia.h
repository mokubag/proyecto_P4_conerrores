#ifndef ICONTROLADORESTADIA_H
#define ICONTROLADORESTADIA_H

#include "../Classes/Estadia.h"

#include "../Datatypes/DtComentario.h"
#include "../Datatypes/DtEstadia.h"
#include "../Datatypes/DtCalificacion.h"
#include "../Datatypes/DtReserva.h"
#include "../Datatypes/DtFecha.h"

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class IControladorEstadia
{
public:
	virtual void eliminarEstadia(int codigo, string nombreHostal) = 0;
	virtual void enviarCalificacion(int cal, string com, string autor) = 0;
	virtual void ingresarRespuestaComentario(string respuesta, int id) = 0;
	virtual map<int, DtComentario> listarComentariosSinResponderHostal() = 0;
	virtual map<int, DtEstadia> listarEstadiasDelHuespedFinalizadas(string email) = 0;
	virtual map<int, DtReserva*> listarReservasNoCanceladas(string hostal, string email) = 0;
	virtual void seleccionarEmpleado(string mail) = 0;
	virtual DtReserva* obtenerInformacionReserva(int codigoReserva) = 0;
	virtual void registrarEstadia(string email) = 0;
	virtual void seleccionarEstadia(int id) = 0;
	virtual void seleccionarHostal(string nombre) = 0;
	virtual void seleccionarReserva(int codigo) = 0;
	virtual map<string, DtHostal*> listarHostalesRegistrados() = 0;
	virtual int getCantEstadiasCreadas() = 0;
	virtual map<int, DtEstadia> listarTodasEstadias() = 0;
	virtual bool existeEstadiaActiva(string email, string hostal) = 0;
	virtual bool existeHuesped(string email) = 0;
	virtual void finalizarEstadia(string email, string hostal) = 0;
	virtual map<int, DtCalificacion> listarTodasCalificaciones() = 0;
	virtual map<string, DtUsuario*> listarUsuarios() = 0;
	virtual int getCantEstadiasCerradas(int codigo) = 0;
	virtual ~IControladorEstadia()
	{
	};
};

#endif
