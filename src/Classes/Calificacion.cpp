#include "../../include/Classes/Calificacion.h"

Calificacion::Calificacion()
{
	this->comentario = NULL;
	DtFecha f(0, 1, 1, 1900);
	this->calificacion = 0;
	this->fecha = f;
	this->comentario = NULL;
}

Calificacion::Calificacion(int calificacion, DtFecha fecha, int id, Comentario* c)
{
	this->calificacion = calificacion;
	this->fecha = fecha;
	this->id = id;
	this->comentario = c;
}

Calificacion::~Calificacion()
{
	if (this->comentario != NULL)
	{
		this->comentario->desvincularCalificacion();
		delete this->comentario;
	}
}

int Calificacion::getCalificacion()
{
	return this->calificacion;
}

int Calificacion::getId()
{
	return this->id;
}

DtFecha Calificacion::getFechaCalificacion()
{
	return this->fecha;
}

DtComentario Calificacion::getDtComentario()
{
	if (this->comentario->getRespuesta() == NULL)
	{
		DtComentario resp(this->comentario->getComentario(), this->comentario->getAutor(),
				this->comentario->getFecha(), this->comentario->getId());
		return resp;
	}
	else
	{
		DtComentario* resp = new DtComentario(
				this->comentario->getRespuesta()->getComentario(),
				this->comentario->getRespuesta()->getAutor(),
				this->comentario->getRespuesta()->getFecha(),
				this->comentario->getId() + 100);
		DtComentario c =
				DtComentario(
						this->comentario->getComentario(),
						this->comentario->getAutor(),
						this->comentario->getFecha(),
						resp,
						this->comentario->getId());
		return c;
	}
}

Comentario* Calificacion::getComentario()
{
	return this->comentario;
}

void Calificacion::setComentario(Comentario* c)
{
	this->comentario = c;
}

DtCalificacion Calificacion::getDtCalificacion()
{
	return DtCalificacion(this->calificacion, this->fecha, this->comentario->getDtComentario());;
}

void Calificacion::eliminarComentario()
{
	delete this->comentario;
}
