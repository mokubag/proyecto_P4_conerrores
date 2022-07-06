#include "../../include/Classes/Empleado.h"
#include "../../include/Classes/Hostal.h"

Empleado::Empleado()
{
	map<int, Comentario*> c;
	vector<Notificacion*> n;

	this->cargo = Administracion;
	this->hostal = NULL;
	this->coleccionComentarios = c;
	this->nombre = "";
	this->email = "";
	this->password = "";
	this->notificaciones = n;
}

Empleado::Empleado(string nombre, string email, string password, enumCargo cargo)
{
	map<int, Comentario*> c;
	vector<Notificacion*> n;

	this->cargo = cargo;
	this->hostal = NULL;
	this->coleccionComentarios = c;
	this->nombre = nombre;
	this->email = email;
	this->password = password;
	this->notificaciones = n;
}

Empleado::~Empleado()
{
	while (!notificaciones.empty())
	{
		delete notificaciones.back();
		notificaciones.pop_back();
	}

	for (map<int, Comentario*>::iterator it = coleccionComentarios.begin(); it != coleccionComentarios.end(); it++)
	{
		coleccionComentarios[it->first] = NULL;
	}
	this->coleccionComentarios.clear();
	this->hostal = NULL;
}

enumCargo Empleado::getCargo()
{
	return this->cargo;
}

void Empleado::setCargo(enumCargo cargo)
{
	this->cargo = cargo;
}

DtEmpleado* Empleado::getDtEmpleado()
{
	DtEmpleado* dte;
	if (hostal != NULL)
	{
		dte = new DtEmpleado(nombre, email, password, this->cargo, hostal->getNombre());
	}
	else
	{
		dte = new DtEmpleado(nombre, email, password, this->cargo, "");
	}

	return dte;
}

void Empleado::setHostal(Hostal* h)
{
	this->hostal = h;
}

Hostal* Empleado::getHostal()
{
	return this->hostal;
}

void Empleado::actualizar(string nombre, int puntaje, string comentario)
{
	Notificacion* n = new Notificacion(nombre, puntaje, comentario);
	this->notificaciones.push_back(n);
}

DtUsuario* Empleado::getDtUsuario()
{
	string h = "Sin asignar a hostal";
	if (this->hostal != NULL)
	{
		h = this->hostal->getNombre();
	}
	DtEmpleado* dte = new DtEmpleado(this->nombre, this->email, this->password, this->cargo, h);
	return dte;
}

vector<DtNotificacion> Empleado::getNotificaciones()
{
	vector<DtNotificacion> notificaciones;
	for (auto& notificacion : this->notificaciones)
	{
		notificaciones.push_back(notificacion->getDtNotificacion());
	}
	return notificaciones;
}

void Empleado::eliminarNotificaciones()
{
	for (auto notificacion : this->notificaciones)
	{
		delete notificacion;
	}
	this->notificaciones.clear();
}

void Empleado::desvincularComentario(int id)
{
	this->coleccionComentarios.erase(id);
}