#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include "DtFecha.h"
#include "DtComentario.h"

#include <string>
using std::string;

class DtComentario
{
private:
	string comentario;
	string autor;
	DtFecha fecha;
	DtComentario* respuesta;
	int id;

public:
	DtComentario();
	~DtComentario();

	/*Este constructor sirve para las respuesta del empleado*/
	DtComentario(
			string comentario,
			string autor,
			DtFecha fecha,
		        int id);

	DtComentario(
			string comentario,
			string autor,
			DtFecha fecha,
			DtComentario* respuesta,
			int id);

	string getComentario();
	string getAutor();
	DtFecha getFecha();
	DtComentario* getRespuesta();
	int getId();
	bool tieneRespuesta();
};

#endif
