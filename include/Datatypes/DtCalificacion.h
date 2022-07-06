#ifndef DTCALIFICACION_H
#define DTCALIFICACION_H

#include "DtFecha.h"
#include "DtComentario.h"

class DtCalificacion
{
private:
	int calificacion;
	DtFecha fecha;
	DtComentario comentario;

public:
	DtCalificacion();
	DtCalificacion(int calificacion, DtFecha fecha, DtComentario comentario);
	~DtCalificacion();

	int getCalificacion();
	DtFecha getFecha();
	DtComentario getComentario();
};

#endif

