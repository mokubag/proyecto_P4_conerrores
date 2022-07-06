#ifndef NOTIFICACION_H
#define NOTIFICACION_H
#include "../Datatypes/DtNotificacion.h"

#include <string>
using std::string;

class Notificacion
{
private:
	string autor;
	int puntaje;
	string comentario;

public:
	Notificacion();
	Notificacion(string autor, int puntaje, string comentario);
	DtNotificacion getDtNotificacion();
	~Notificacion();
};

#endif