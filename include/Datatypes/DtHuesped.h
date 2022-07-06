#ifndef DTHUESPED_H
#define DTHUESPED_H

#include "DtUsuario.h"
#include <string>

using std::string;

class DtHuesped : public DtUsuario
{
private:
	bool esFinger;

public:
	DtHuesped();
	DtHuesped(string nombre, string email, string password, bool esFinger);
	~DtHuesped();
	bool getEsFinger();

};

#endif

