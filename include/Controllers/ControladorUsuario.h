#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "../Classes/Usuario.h"
#include "../Classes/Empleado.h"
#include "../Interfaces/IControladorUsuario.h"
#include "../Datatypes/enumCargo.h"
#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtUsuario.h"
#include "ControladorHostal.h"
#include "../Classes/SubscripcionNotificacion.h"

#include <string>
#include <map>


using std::map;
using std::string;
using std::vector;

class SubscripcionNotificacion;

class ControladorUsuario : public IControladorUsuario
{
private:
	ControladorUsuario();
	static ControladorUsuario* instancia;

	map<string, Usuario*> coleccionUsuarios;

	SubscripcionNotificacion* subscripcionNotificacion;
	string nombre;
	string email;
	string password;
	bool esFinger;
	enumCargo cargo;

public:
	static ControladorUsuario* getInstancia();
	~ControladorUsuario();

	void confirmarUsuario(bool esHuesped);
	void setEsFinger(bool respuesta);
	bool existeEstadiaActiva(string email, string hostal);
	void finalizarEstadia(string email, string hostal, DtFecha checkout);
	Usuario* getUsuario(string email);
	DtUsuario* informacionUsuario(string email);
	void ingresarCargo(enumCargo cargo);
	void registrarUsuario(string nombre, string email, string contrasena);
	void registrarEstadia(string email);
	bool existeMailUsuario(string mail);
	bool existeHuesped(string email);
	map<string, DtUsuario*> listarUsuarios();
	map<string, DtEmpleado*> listarEmpleadosSinAsignar();
	map<string, Empleado*> listarEmpleados();
	void suscribirse(string email);
	void eliminarSuscripcion(string email);
	void notificarSuscriptores(string nombre, int puntaje, string comentario);
	vector<DtNotificacion> listarNotificaciones(string email);
	void eliminarNotificacionesDelEmpleado(string email);

};

#endif
