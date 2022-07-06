#include "../../include/Classes/Notificacion.h"

Notificacion::Notificacion()
{
	this->autor = "";
	this->puntaje = 0;
	this->comentario = "";
}

Notificacion::Notificacion(string autor, int puntaje, string comentario)
{
	this->autor = autor;
	this->puntaje = puntaje;
	this->comentario = comentario;
}

DtNotificacion Notificacion::getDtNotificacion()
{
	return DtNotificacion(this->autor, this->puntaje, this->comentario);
}

Notificacion::~Notificacion()
{
}