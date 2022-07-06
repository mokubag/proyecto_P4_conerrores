#ifndef USUARIO_H
#define USUARIO_H

#include "Estadia.h"
#include "../Datatypes/DtUsuario.h"
#include "Reserva.h"

#include <string>
#include <vector>

class Usuario
{
protected:
	string nombre;
	string email;
	string password;

public:
	Usuario();
	string getNombre();
	string getEmail();
	string getPassword();
	virtual DtUsuario* getDtUsuario() = 0;
	virtual ~Usuario();
};

#endif

