#ifndef CALIFICACION_H
#define CALIFICACION_H
#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtComentario.h"
#include "../Datatypes/DtCalificacion.h"
#include "Comentario.h"

class Comentario;
class Calificacion
{
private:
	int calificacion;
	DtFecha fecha;
	Comentario* comentario;
	int id;

public:
	Calificacion();
	Calificacion(int calificacion, DtFecha fecha, int id, Comentario* c);
	~Calificacion();

	int getCalificacion();
	int getId();
	DtFecha getFechaCalificacion();
	DtComentario getDtComentario();
	void setComentario(Comentario* c);
	DtCalificacion getDtCalificacion();
	Comentario* getComentario();
	void eliminarComentario();
};

#endif
