#include "../../include/Controllers/ControladorUsuario.h"
#include "../../include/Classes/Empleado.h"
#include "../../include/Classes/Huesped.h"

// #include "../Datatypes/DtFecha.h"
// #include "../Datatypes/DtEmpleado.h"
// #include "../Datatypes/DtUsuario.h"
// #include "../Datatypes/enumCargo.h"

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario()
{
	map<string, Usuario*> mapUsuarios;
	SubscripcionNotificacion* subscripcion = new SubscripcionNotificacion();

	this->subscripcionNotificacion = subscripcion;
	this->coleccionUsuarios = mapUsuarios;
	this->nombre = "";
	this->email = "";
	this->password = "";
	this->esFinger = false;
	this->cargo = Administracion;
}

ControladorUsuario::~ControladorUsuario()
{
	for (map<string, Usuario*>::iterator itr = this->coleccionUsuarios.begin();
		 itr != this->coleccionUsuarios.end();
		 itr++)
	{
		Empleado* empleado = dynamic_cast<Empleado*>(itr->second);
		if (empleado != NULL)
		{
			// Si el empleado está suscripto se lo saca de la lista de suscriptores antes de eliminarlo
			try
			{
				this->subscripcionNotificacion->eliminarSuscripcion(itr->second->getEmail());
			}
			catch (invalid_argument& err)
			{
			}
		}
		empleado = NULL;
		delete itr->second;
	};
	this->coleccionUsuarios.clear();
	delete this->subscripcionNotificacion;
}

ControladorUsuario* ControladorUsuario::getInstancia()
{
	if (instancia == NULL) instancia = new ControladorUsuario();
	return instancia;
}

void ControladorUsuario::confirmarUsuario(bool esHuesped)
{
	if (esHuesped)
	{
		Huesped* h = new Huesped(this->nombre, this->email, this->password, this->esFinger);
		this->coleccionUsuarios[this->email] = h;
		this->nombre = "";
		this->email = "";
		this->password = "";
		this->esFinger = false;
	}
	else
	{
		Empleado* e = new Empleado(nombre, email, password, cargo);
		this->coleccionUsuarios[email] = e;
		this->nombre = "";
		this->email = "";
		this->password = "";
		this->cargo = Limpieza;
	}
}

void ControladorUsuario::setEsFinger(bool respuesta)
{
	this->esFinger = respuesta;
}

bool ControladorUsuario::existeEstadiaActiva(string email, string hostal)
{
	if (this->coleccionUsuarios.empty())
	{
		throw invalid_argument("No hay usuarios registrados");
	}
	if (!this->coleccionUsuarios.count(email))
	{
		throw invalid_argument("No hay usuario con ese email");
	}
	else
	{
		Huesped* huesped = dynamic_cast<Huesped*>(this->coleccionUsuarios[email]);
		if (huesped == NULL)
		{
			throw invalid_argument("No hay huesped con ese mail");
		}
		bool resp = false;
		if (huesped != NULL)
		{
			map<int, Estadia*> estadiasHostal = huesped->estadiasDeHostal(hostal);
			map<int, Estadia*>::iterator it;
			it = estadiasHostal.begin();
			while (it != estadiasHostal.end() && !resp)
			{
				resp = it->second->esActiva();
				it++;
			}
		}
		return resp;
	};
}

void ControladorUsuario::finalizarEstadia(string email, string hostal, DtFecha checkout)
{
	Huesped* hues = dynamic_cast<Huesped*>(this->coleccionUsuarios[email]);
	if (hues != NULL)
	{
		map<int, Estadia*> estadiasHostal = hues->estadiasDeHostal(hostal);
		map<int, Estadia*>::iterator it;
		for (it = estadiasHostal.begin(); it != estadiasHostal.end(); it++)
		{
			if (it->second->esActiva())
			{
				it->second->finalizarEstadiaActiva(checkout);
			}
		}
	}
}

Usuario* ControladorUsuario::getUsuario(string email)
{
	return this->coleccionUsuarios[email];
}

DtUsuario* ControladorUsuario::informacionUsuario(string email)
{
	if (this->coleccionUsuarios.count(email))
	{
		return this->coleccionUsuarios[email]->getDtUsuario();
	}
	else
	{
		throw invalid_argument("No existe usuario con ese mail");
	}

}

void ControladorUsuario::ingresarCargo(enumCargo cargo)
{
	this->cargo = cargo;

}

void ControladorUsuario::registrarUsuario(string nombre, string email, string password)
{
	this->nombre = nombre;
	this->email = email;
	this->password = password;
}

void ControladorUsuario::registrarEstadia(string email)
{

}

bool ControladorUsuario::existeMailUsuario(string mail)
{
	return this->coleccionUsuarios.count(mail) != 0;
}

bool ControladorUsuario::existeHuesped(string email)
{
	if (this->coleccionUsuarios.count(email) != 0)
	{
		Usuario* usu = this->coleccionUsuarios[email];
		auto* huesp = dynamic_cast<Huesped*>(usu);
		if (huesp == NULL)
		{
			throw invalid_argument("El usuario seleccionado no es un huésped");
		}
		return true;
	}
	else
	{
		throw invalid_argument("No existe ningun usuario con ese email.");
	}
}

map<string, DtUsuario*> ControladorUsuario::listarUsuarios()
{
	if (!this->coleccionUsuarios.empty())
	{
		map<string, DtUsuario*> listaUsuarios;
		for (const auto& usuario : this->coleccionUsuarios)
		{
			listaUsuarios[usuario.second->getEmail()] = (usuario.second->getDtUsuario());
		}
		return listaUsuarios;
	}
	else
	{
		throw invalid_argument("No hay usuarios registrados");
	}
}

map<string, DtEmpleado*> ControladorUsuario::listarEmpleadosSinAsignar()
{
	map<string, DtEmpleado*> empleadosSinAsignar;
	for (auto& usuario : this->coleccionUsuarios)
	{
		auto* empleado = dynamic_cast<Empleado*>(usuario.second);
		if (empleado != NULL && empleado->getHostal() == NULL)
		{
			string a = empleado->getEmail();
			empleadosSinAsignar[a] = empleado->getDtEmpleado();
		}
	}
	if (empleadosSinAsignar.empty())
	{
		throw invalid_argument("No hay empleados sin asignar");
	}
	else
	{
		return empleadosSinAsignar;
	}
}

map<string, Empleado*> ControladorUsuario::listarEmpleados()
{
	map<string, Empleado*> listaEmpleados;
	for (auto& usuario : this->coleccionUsuarios)
	{
		auto* empleado = dynamic_cast<Empleado*>(usuario.second);
		if (empleado != NULL)
		{
			string a = empleado->getEmail();
			listaEmpleados[a] = empleado;
		}

	}
	if (!listaEmpleados.empty())
	{
		return listaEmpleados;
	}
	else
	{
		throw invalid_argument("No hay empleados registrados");
	}
}

void ControladorUsuario::suscribirse(string email)
{
	this->subscripcionNotificacion->suscribirse(email);
}

void ControladorUsuario::eliminarSuscripcion(string email)
{
	try
	{
		this->subscripcionNotificacion->eliminarSuscripcion(email);
	}
	catch (invalid_argument& err)
	{
		throw invalid_argument(err.what());
	}
}

void ControladorUsuario::notificarSuscriptores(string nombre, int puntaje, string comentario)
{
	this->subscripcionNotificacion->notificarSuscriptores(nombre, puntaje, comentario);
}

vector<DtNotificacion> ControladorUsuario::listarNotificaciones(string email)
{
	if (this->coleccionUsuarios.count(email))
	{
		Empleado* emp = dynamic_cast<Empleado*>(getUsuario(email));
		return emp->getNotificaciones();
	}
	else
	{
		throw invalid_argument("No hay empleado con ese mail");
	}
}

void ControladorUsuario::eliminarNotificacionesDelEmpleado(string email)
{
	Usuario* U = getUsuario(email);
	Empleado* emp = dynamic_cast<Empleado*>(U);
	emp->eliminarNotificaciones();
}