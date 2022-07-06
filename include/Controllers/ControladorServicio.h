#ifndef CONTROLADORSERVICIO_H
#define CONTROLADORSERVICIO_H

#include "../Datatypes/DtServicio.h"
#include "../Interfaces/IControladorServicio.h"
#include "../Classes/Servicio.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class ControladorServicio : public IControladorServicio
{
private:
	ControladorServicio();
	static ControladorServicio* instancia;
	vector<Servicio*> coleccionServicios;

public:
	~ControladorServicio();
	static ControladorServicio* getInstancia();
	Servicio* getServicio(int codigo);
	vector<DtServicio*> listarTiposConsumoRegistrados();
};

#endif
