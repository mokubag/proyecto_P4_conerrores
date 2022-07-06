#ifndef ICONTROLADORUSUARIO_H
#define ICONTROLADORUSUARIO_H

#include "../Datatypes/DtUsuario.h"
#include "../Datatypes/DtEmpleado.h"
#include "../Classes/Usuario.h"
#include "../Classes/Empleado.h"
#include <map>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::map;

class IControladorUsuario
{
public:
	virtual void confirmarUsuario(bool) = 0;
	virtual void setEsFinger(bool respuesta) = 0;
	virtual bool existeEstadiaActiva(string email, string hostal) = 0;
	virtual void finalizarEstadia(string email, string hostal, DtFecha checkout) = 0;
	virtual Usuario* getUsuario(string email) = 0;
	virtual DtUsuario* informacionUsuario(string email) = 0;
	virtual void ingresarCargo(enumCargo cargo) = 0;
	virtual void registrarUsuario(string nombre, string email, string contrasena) = 0;
	virtual void registrarEstadia(string email) = 0;
	virtual bool existeMailUsuario(string mail) = 0;
	virtual bool existeHuesped(string email) = 0;
	virtual map<string, DtUsuario*> listarUsuarios() = 0;
	virtual map<string, DtEmpleado*> listarEmpleadosSinAsignar() = 0;
	virtual map<string, Empleado*> listarEmpleados() = 0;
	virtual ~IControladorUsuario()
	{
	};
	virtual void suscribirse(string email) = 0;
	virtual void eliminarSuscripcion(string email) = 0;
	virtual void notificarSuscriptores(string nombre, int puntaje, string comentario) = 0;
	virtual vector<DtNotificacion> listarNotificaciones(string email) = 0;
	virtual void eliminarNotificacionesDelEmpleado(string email) = 0;
};

#endif
