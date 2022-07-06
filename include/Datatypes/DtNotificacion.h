#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>

using std::string;

class DtNotificacion
{
private:
	string autor;
	int puntaje;
	string comentario;

public:
	DtNotificacion();
	DtNotificacion(string autor, int puntaje, string comentario);
	~DtNotificacion();

	string getAutor();
	int getPuntaje();
	string getComentario();
};

#endif
