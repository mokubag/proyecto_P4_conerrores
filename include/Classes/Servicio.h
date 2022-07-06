#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Servicio
{
private:
	int codigo;
	string nombre;
	int precio;

public:
	Servicio();
	Servicio(int codigo, string nombre, int precio);
	~Servicio();

	int getCodigo();
	string getNombre();
	int getPrecio();

};

#endif
