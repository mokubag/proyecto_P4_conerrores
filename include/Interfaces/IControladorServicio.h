#ifndef ICONTROLADORSERVICIO_H
#define ICONTROLADORSERVICIO_H

#include "../Classes/Servicio.h"
#include "../Datatypes/DtServicio.h"

#include <string>
#include <vector>

class IControladorServicio
{
public:
	virtual Servicio* getServicio(int codigo) = 0;
	virtual vector<DtServicio*> listarTiposConsumoRegistrados() = 0;

	virtual ~IControladorServicio()
	{
	};
};

#endif
