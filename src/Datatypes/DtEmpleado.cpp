#include "../../include/Datatypes/DtEmpleado.h"

#include <string>
using std::string;

DtEmpleado::DtEmpleado()
{

}
DtEmpleado::DtEmpleado(string nombre, string email, string password, enumCargo cargo, string hostal)
{
	this->nombre = nombre;
	this->email = email;
	this->password = password;
	this->cargo = cargo;
	this->hostal = hostal;
}

DtEmpleado::~DtEmpleado()
{
}

enumCargo DtEmpleado::getCargo()
{
	return this->cargo;
}

string DtEmpleado::getHostal()
{
	return this->hostal;
}

