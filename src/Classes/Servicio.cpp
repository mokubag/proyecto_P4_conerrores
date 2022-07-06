#include "../../include/Classes/Servicio.h"

Servicio::Servicio()
{
	this->codigo = 0;
	this->nombre = "";
	this->precio = 0;
}

Servicio::Servicio(int codigo, string nombre, int precio)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->precio = precio;
}

Servicio::~Servicio()
{

}

int Servicio::getCodigo()
{
	return this->codigo;
}

string Servicio::getNombre()
{
	return this->nombre;
}

int Servicio::getPrecio()
{
	return this->precio;
}

