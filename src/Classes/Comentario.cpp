#include "../../include/Classes/Comentario.h"

Comentario::Comentario()
{
	DtFecha f(0, 1, 1, 1900);

	this->comentario = "";
	this->autor = "";
	this->fecha = f;
	this->respuesta = NULL;
	this->calificacion = NULL;
	this->id = 0;
}

Comentario::Comentario(string comentario, string autor, DtFecha fecha, int id)
{
	this->comentario = comentario;
	this->autor = autor;
	this->fecha = fecha;
	this->respuesta = NULL;
	this->calificacion = calificacion;
	this->id = id;
}

void Comentario::setCalificacion(Calificacion* calificacion)
{
	this->calificacion = calificacion;
}

string Comentario::getComentario()
{
	return this->comentario;
}

string Comentario::getAutor()
{
	return this->autor;
}

DtFecha Comentario::getFecha()
{
	return this->fecha;
}

DtComentario Comentario::getDtComentario()
{
	if (this->respuesta == NULL)
	{
		return DtComentario(this->comentario, this->autor, this->fecha, this->id);
	}
	else
	{
		DtComentario* resp = new DtComentario(this->respuesta->getComentario(), this->respuesta->getAutor(),
				this->respuesta->getFecha(), this->id);

		return DtComentario(this->comentario, this->autor, this->fecha, resp, this->id);
	}
}

void Comentario::ingresarRespuesta(string comentario, string autor, DtFecha fecha, int id)
{
	this->respuesta = new Comentario(comentario, autor, fecha, id);
}
Comentario* Comentario::getRespuesta()
{
	return this->respuesta;
}
void Comentario::eliminarRespuesta()
{
	delete this->respuesta;
}
int Comentario::getId()
{
	return this->id;
}

void Comentario::setNull()
{
	this->respuesta = NULL;
}

Comentario::~Comentario()
{
	if (this->respuesta != NULL)
	{
		delete this->respuesta;
	}
	this->calificacion = NULL;
}

void Comentario::desvincularCalificacion()
{
	this->calificacion = NULL;
}