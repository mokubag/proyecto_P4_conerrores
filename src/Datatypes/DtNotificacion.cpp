#include "../../include/Datatypes/DtNotificacion.h"

#include <string>

using std::string;

DtNotificacion::DtNotificacion()
{

}

DtNotificacion::DtNotificacion(string autor, int puntaje, string comentario)
{
	this->autor = autor;
	this->puntaje = puntaje;
	this->comentario = comentario;
}

DtNotificacion::~DtNotificacion()
{
}

string DtNotificacion::getAutor()
{
	return this->autor;
}

int DtNotificacion::getPuntaje()
{
	return this->puntaje;
}

string DtNotificacion::getComentario()
{
	return this->comentario;
}

