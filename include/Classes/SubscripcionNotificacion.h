#ifndef SUBSCRIPCIONNOTIFICACION_H
#define SUBSCRIPCIONNOTIFICACION_H

#include "Empleado.h"

#include "../Controllers/ControladorUsuario.h"

#include <string>
#include <map>

using std::map;
using std::string;

using namespace std;

class ControladorUsuario;
class SubscripcionNotificacion
{
private:
	map<string, Empleado*> suscriptores;

public:
	SubscripcionNotificacion();
	~SubscripcionNotificacion();
	void suscribirse(string nombreEmpleado);
	void eliminarSuscripcion(string nombreEmpleado);
	void notificarSuscriptores(string nombre, int puntaje, string comentario);
};

#endif
