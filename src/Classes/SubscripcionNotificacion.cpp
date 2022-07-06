#include "../../include/Classes/SubscripcionNotificacion.h"

SubscripcionNotificacion::SubscripcionNotificacion()
{
	map<string, Empleado*> mapSuscriptores;
	this->suscriptores = mapSuscriptores;
}

SubscripcionNotificacion::~SubscripcionNotificacion()
{
	for (map<string, Empleado*>::iterator itr = this->suscriptores.begin();
		 itr != this->suscriptores.end(); itr++)
	{
		itr->second = NULL;
	};
	this->suscriptores.clear();
}

void SubscripcionNotificacion::suscribirse(string email)
{
	Empleado* nuevoSusctiptor = dynamic_cast<Empleado*>(ControladorUsuario::getInstancia()->getUsuario(email));
	this->suscriptores[email] = nuevoSusctiptor;
}

void SubscripcionNotificacion::eliminarSuscripcion(string email)
{
	if (this->suscriptores.count(email))
	{
		this->suscriptores.erase(email);
	}
	else
	{
		throw invalid_argument("El empleado no estaba suscripto");
	}
}

void SubscripcionNotificacion::notificarSuscriptores(string nombre, int puntaje, string comentario)
{
	for (const auto& itr : this->suscriptores)
	{
		itr.second->actualizar(nombre, puntaje, comentario);
	}
}
