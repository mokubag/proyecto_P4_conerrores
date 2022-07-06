#include "../../include/Datatypes/DtServicio.h"

DtServicio::DtServicio()
{
}

DtServicio::~DtServicio()
{
}

DtServicio::DtServicio(string codigo, string nombre, int precio)
{
	this->nombre = nombre;
	this->precio = precio;
	this->codigo = codigo;
}

string DtServicio::getCodigo()
{
	return this->codigo;
}
int DtServicio::getPrecio()
{
	return this->precio;
}
string DtServicio::getNombre()
{
	return this->nombre;
}