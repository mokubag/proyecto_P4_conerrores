#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "../Datatypes/DtEmpleado.h"
#include "../Datatypes/enumCargo.h"
#include "../Datatypes/DtNotificacion.h"
#include "Usuario.h"
#include "Hostal.h"
#include "Notificacion.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Empleado : public Usuario
{
private:
	enumCargo cargo;
	Hostal* hostal;
	map<int, Comentario*> coleccionComentarios;
	vector<Notificacion*> notificaciones;

public:
	Empleado();
	Empleado(string nombre, string email, string password, enumCargo cargo);
	~Empleado();

	enumCargo getCargo();
	DtEmpleado* getDtEmpleado();
	Hostal* getHostal();
	void setHostal(Hostal* h);
	void setCargo(enumCargo cargo);
	void actualizar(string nombre, int puntaje, string comentario);
	vector<DtNotificacion> getNotificaciones();
	void eliminarNotificaciones();
	void desvincularComentario(int id);

	DtUsuario* getDtUsuario();
};

#endif
