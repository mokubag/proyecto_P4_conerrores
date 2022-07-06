#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "../Datatypes/DtFecha.h"
#include "Calificacion.h"
#include "../Datatypes/DtComentario.h"

#include <string>

class Calificacion;
class Comentario
{
private:
	string comentario;
	string autor;
	DtFecha fecha;
	Comentario* respuesta;
	Calificacion* calificacion;
	int id;

public:
	Comentario();
	Comentario(string comentario, string autor, DtFecha fecha, int id);

	void setCalificacion(Calificacion* calificacion);
	string getComentario();
	string getAutor();
	DtFecha getFecha();
	Comentario* getRespuesta();
	DtComentario getDtComentario();
	void eliminarRespuesta();
	int getId();
	void setNull();
	void ingresarRespuesta(string comentario, string autor, DtFecha fecha, int id);
	void desvincularCalificacion();

	~Comentario();
};

#endif
