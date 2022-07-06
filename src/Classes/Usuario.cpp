#include "../../include/Classes/Usuario.h"

Usuario::Usuario()
{
}

Usuario::~Usuario()
{
}

string Usuario::getNombre()
{
	return this->nombre;
}

string Usuario::getEmail()
{
	return this->email;
}

string Usuario::getPassword()
{
	return this->password;
}

