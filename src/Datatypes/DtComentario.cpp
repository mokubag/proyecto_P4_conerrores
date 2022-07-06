#include "../../include/Datatypes/DtComentario.h"
#include <cstddef>

DtComentario::DtComentario()
{
}
DtComentario::~DtComentario()
{
}

DtComentario::DtComentario(
		string comentario,
		string autor,
		DtFecha fecha,
		int id)
{
	this->comentario = comentario;
	this->autor = autor;
	this->fecha = fecha;
	this->respuesta = NULL;
	this->id = id;
}

DtComentario::DtComentario(
		string comentario,
		string autor,
		DtFecha fecha,
		DtComentario* respuesta,
		int id)
{
	this->comentario = comentario;
	this->autor = autor;
	this->fecha = fecha;
	this->respuesta = respuesta;
	this->id = id;
}

string DtComentario::getComentario()
{
	return this->comentario;
}

string DtComentario::getAutor()
{
	return this->autor;
}

DtFecha DtComentario::getFecha()
{
	return this->fecha;
}

int DtComentario::getId()
{
	return this->id;
}

DtComentario* DtComentario::getRespuesta()
{
	return this->respuesta;
}

bool DtComentario::tieneRespuesta()
{
	return (this->respuesta != NULL);
}
