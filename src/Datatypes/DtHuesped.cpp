#include "../../include/Datatypes/DtHuesped.h"

#include <string>

using std::string;

DtHuesped::DtHuesped()
{

}

DtHuesped::DtHuesped(string nombre, string email, string password, bool esFinger)
{
	this->nombre = nombre;
	this->email = email;
	this->password = password;
	this->esFinger = esFinger;
}

DtHuesped::~DtHuesped()
{
}

bool DtHuesped::getEsFinger()
{
	return this->esFinger;
}