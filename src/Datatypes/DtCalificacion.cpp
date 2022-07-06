#include "../../include/Datatypes//DtCalificacion.h"

DtCalificacion::DtCalificacion()
{
}

DtCalificacion::DtCalificacion(int calificacion, DtFecha fecha, DtComentario comentario)
{
	this->calificacion = calificacion;
	this->fecha = fecha;
	this->comentario = comentario;
}

DtCalificacion::~DtCalificacion()
{
}

int DtCalificacion::getCalificacion()
{
	return this->calificacion;
}

DtFecha DtCalificacion::getFecha()
{
	return this->fecha;
}

DtComentario DtCalificacion::getComentario()
{
	return this->comentario;
}