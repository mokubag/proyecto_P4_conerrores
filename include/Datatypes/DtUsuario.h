#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <string>

using std::string;

class DtUsuario
{
protected:
	string nombre;
	string email;
	string password;
public:
	DtUsuario();
	DtUsuario(string nombre,
			string email,
			string password
	);
	string getNombre();
	string getEmail();
	string getPassword();
	virtual ~DtUsuario()
	{
	};
};

#endif
