#include "../../include/Datatypes/DtUsuario.h"

using std::string;

DtUsuario::DtUsuario()
{

}

DtUsuario::DtUsuario(string nombre, string email, string password)
{
	this->nombre = nombre;
	this->email = email;
	this->password = password;
}

string DtUsuario::getNombre()
{
	return this->nombre;
}

string DtUsuario::getEmail()
{
	return this->email;
}

string DtUsuario::getPassword()
{
	return this->password;
}
