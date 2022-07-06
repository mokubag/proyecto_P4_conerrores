#ifndef HUESPED_H
#define HUESPED_H

#include "Usuario.h"

#include "../Datatypes/DtHuesped.h"
#include "Hostal.h"
#include "Reserva.h"
#include "Estadia.h"
#include "ReservaIndividual.h"
#include "ReservaGrupal.h"

#include <map>
#include <string>

using std::map;
using std::string;

class Huesped : public Usuario
{
private:
	bool esFinger;
	map<int, Estadia*> estadias;
	map<int, Reserva*> reservas;

public:
	Huesped();
	Huesped(
			string nombre,
			string email,
			string password,
			bool esFinger
	);
	~Huesped();

	bool getEsFinger();
	DtHuesped getDtHuesped();

	void desvincularReserva(int codr);
	void setReserva(Reserva* r);
	void setReservaGrupal(Reserva* r);
	void asociarEstadia(Estadia* estadia);
	bool existeEstadia();
	void desvincularEstadia(int codigoEstadia);
	void eliminarReserva(int codigoReserva);
	map<int, Estadia*> getEstadias();
	map<int, Estadia*> estadiasDeHostal(string hostal);
	bool tieneEstadiaFinalizada();

	DtUsuario* getDtUsuario();
};
#endif
