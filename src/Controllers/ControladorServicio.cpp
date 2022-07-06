#include "../../include/Controllers/ControladorServicio.h"

ControladorServicio* ControladorServicio::instancia = NULL;

ControladorServicio::ControladorServicio()
{
	vector<Servicio*> vect;
	this->coleccionServicios = vect;
}

ControladorServicio::~ControladorServicio()
{
	while (!coleccionServicios.empty())
	{
		delete coleccionServicios.back();
		coleccionServicios.pop_back();
	}
}

ControladorServicio* ControladorServicio::getInstancia()
{
	if (instancia == NULL) instancia = new ControladorServicio();
	return instancia;
}

Servicio* ControladorServicio::getServicio(int codigo)
{
	return NULL;
}

vector<DtServicio*> ControladorServicio::listarTiposConsumoRegistrados()
{
	vector<DtServicio*> vect;
	return vect;
}