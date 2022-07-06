#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H

#include "enumCargo.h"
#include "DtHostal.h"
#include "DtUsuario.h"

#include <string>
using std::string;

class DtEmpleado : public DtUsuario
{
private:
	enumCargo cargo;
	string hostal;

public:
	DtEmpleado();
	DtEmpleado(string nombre, string email, string password, enumCargo cargo, string hostal);

	~DtEmpleado();

	enumCargo getCargo();
	string getHostal();
};

#endif
