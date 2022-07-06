#include "../../include/Classes/Huesped.h"

Huesped::Huesped()
{
	map<string, Hostal*> hostales;
	map<int, Estadia*> estadias;

	map<int, Reserva*> res;

	this->reservas = res;
	this->esFinger = false;
	this->nombre = "";
	this->email = "";
	this->password = "";
	this->estadias = estadias;
}

Huesped::Huesped(string nombre, string email, string password, bool esFinger)
{
	map<string, Hostal*> hostales;
	map<int, Estadia*> estadias;
	map<int, Reserva*> res;

	this->reservas = res;
	this->esFinger = esFinger;
	this->nombre = nombre;
	this->email = email;
	this->password = password;
	this->estadias = estadias;
}

Huesped::~Huesped()
{
	for (map<int, Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++)
	{
		ReservaGrupal* reservaGrupal = dynamic_cast<ReservaGrupal*>(it->second);
		if (reservaGrupal != NULL)
		{
			reservaGrupal->desvincularHuesped(this->email);

		}
	}
	this->estadias.clear();
}

bool Huesped::getEsFinger()
{
	return this->esFinger;
}

DtHuesped Huesped::getDtHuesped()
{
	DtHuesped dth(this->nombre, this->email, this->password, this->esFinger);
	return dth;
}

void Huesped::setReserva(Reserva* r)
{
	this->reservas[r->getCodigo()] = r;
}

void Huesped::setReservaGrupal(Reserva* r)
{
	this->reservas[r->getCodigo()] = r;
}

DtUsuario* Huesped::getDtUsuario()
{
	DtHuesped* dth = new DtHuesped(this->nombre, this->email, this->password, this->esFinger);
	return dth;
}

void Huesped::asociarEstadia(Estadia* estadia)
{
	this->estadias.insert(std::pair<int, Estadia*>(estadia->getCodigo(), estadia));
}

bool Huesped::existeEstadia()
{
	return (!this->estadias.empty());
}

map<int, Estadia*> Huesped::getEstadias()
{
	return this->estadias;
}

map<int, Estadia*> Huesped::estadiasDeHostal(string hostal)
{
	map<int, Estadia*> resp;
	map<int, Estadia*>::iterator it;
	for (it = this->estadias.begin(); it != this->estadias.end(); it++)
	{
		if (it->second->getReserva()->getHostal() == hostal)
		{
			Estadia* e = it->second;
			resp.insert(std::pair<int, Estadia*>(e->getCodigo(), e));
		}
	}
	return resp;
}

void Huesped::desvincularReserva(int codr)
{
	this->reservas.erase(codr);
}

void Huesped::desvincularEstadia(int codigoEstadia)
{
	this->estadias.erase(codigoEstadia);
}

void Huesped::eliminarReserva(int codigoReserva)
{
	this->reservas[codigoReserva] = NULL;
}

bool Huesped::tieneEstadiaFinalizada()
{
	for (auto& estadia : this->estadias)
	{
		if (!estadia.second->esActiva())
		{
			return true;
		}
	}
	return false;
}

