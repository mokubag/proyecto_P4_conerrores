#ifndef DTSERVICIO_H
#define DTSERVICIO_H

#include <string>

using std::string;
class DtServicio
{
private:
	string codigo;
	string nombre;
	int precio;

public:
	DtServicio();
	~DtServicio();

	DtServicio(string codigo, string nombre, int precio);

	string getCodigo();
	int getPrecio();
	string getNombre();
};

#endif
