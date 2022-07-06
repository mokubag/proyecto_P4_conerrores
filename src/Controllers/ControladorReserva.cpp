#include "../../include/Controllers/ControladorReserva.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

ControladorReserva* ControladorReserva::instancia = NULL;

ControladorReserva::ControladorReserva()
{
	map<string, string> vectHuesp;
	map<int, Reserva*> vectReservas;

	this->huesped = "";
	this->huespedes = vectHuesp;
	this->coleccionReservas = vectReservas;
	this->habitacion = 0;
	this->nombreHostal = "";
	this->codigo = 0;
	this->cantReservasCreadas = 0;
}

ControladorReserva::~ControladorReserva()
{
	for (map<int, Reserva*>::iterator it = coleccionReservas.begin(); it != coleccionReservas.end(); it++)
	{
		delete it->second;
	};
	this->coleccionReservas.clear();
	this->huespedes.clear();
}

ControladorReserva* ControladorReserva::getInstancia()
{
	if (instancia == NULL) instancia = new ControladorReserva();
	return instancia;
}

void ControladorReserva::cancelarEliminacion()
{
	this->codigo = 0;
	this->nombreHostal = "";

}

void ControladorReserva::confirmarEliminacion()
{
	Reserva* reservaEliminar = this->coleccionReservas[this->codigo];
	auto* reservaIndividual = dynamic_cast<ReservaIndividual*>(reservaEliminar);
	auto* reservaGrupal = dynamic_cast<ReservaGrupal*>(reservaEliminar);
	int numeroHabitacion = reservaEliminar->getHabitacion()->getNumero();

	if (reservaIndividual != NULL)
	{
		string emailHuesped = reservaIndividual->getHuesped();

		reservaIndividual->desvincularHabitacion();

		Huesped* huespedReserva = dynamic_cast<Huesped*>(ControladorUsuario::getInstancia()->getUsuario(emailHuesped));

		if (reservaIndividual->getEstado() == Cerrada)
		{
			// Solo entra si tiene estadia
			map<int, Estadia*> coleccionEstadiasDelHuesped = huespedReserva->getEstadias();
			int codigoEstadia;
			// Buscamos el ID de la estadia recorriendo la coleccion de estadias del huesped
			for (auto& estadia : coleccionEstadiasDelHuesped)
			{
				if (this->codigo == estadia.second->getReserva()->getCodigo())
				{
					codigoEstadia = estadia.second->getCodigo();
					break;
				}
			}
			huespedReserva->desvincularEstadia(codigoEstadia);
			ControladorEstadia::getInstancia()->eliminarEstadia(codigoEstadia, this->nombreHostal);
		}
		huespedReserva->desvincularReserva(this->codigo);
		ControladorHabitacion::getInstancia()->desvincularReserva(numeroHabitacion, this->codigo);

		Reserva* borrar = this->coleccionReservas[this->codigo];
		this->coleccionReservas.erase(this->codigo);
		delete borrar;
	}
	else
	{
		// reserva es grupal
		reservaGrupal->desvincularHabitacion();
		map<string, Huesped*> listaDeHuespedesEnReserva = reservaGrupal->getHuespedes();
		for (auto& huesped : listaDeHuespedesEnReserva)
		{
			// Solo entra si tiene todas las estadias
			map<int, Estadia*> coleccionEstadias = huesped.second->getEstadias();

			int codigoEstadia;
			bool existeEstadiaAsociadaALaReserva = false;
			if (!coleccionEstadias.empty())
			{
				// Buscamos el ID de la estadia recorriendo la coleccion de estadias del huesped
				for (auto& estadia : coleccionEstadias)
				{
					int codigx = estadia.second->getReserva()->getCodigo();
					if (this->codigo == codigx)
					{
						codigoEstadia = estadia.second->getCodigo();
						existeEstadiaAsociadaALaReserva = true;
						break;
					}
				}
			}
			if (existeEstadiaAsociadaALaReserva)
			{
				huesped.second->desvincularEstadia(codigoEstadia);
				ControladorEstadia::getInstancia()->eliminarEstadia(codigoEstadia, this->nombreHostal);
			}
			huesped.second->desvincularReserva(this->codigo);
		}
		ControladorHabitacion::getInstancia()->desvincularReserva(numeroHabitacion, this->codigo);
		Reserva* borrar = this->coleccionReservas[this->codigo];
		this->coleccionReservas.erase(this->codigo);
		delete borrar;
	}
}

int ControladorReserva::confirmarReserva(bool respuesta)
{
	this->cantReservasCreadas = this->cantReservasCreadas + 1;
	int codigo = this->cantReservasCreadas;

	if (respuesta)
	{
		// En caso de confirma la reserva y ser reserva Individual
		if (this->esReservaIndivudal)
		{
			Usuario* ptrHuesped = ControladorUsuario::getInstancia()->getUsuario(this->huesped);
			Huesped* hues = dynamic_cast<Huesped*>(ptrHuesped);
			Habitacion* hab = ControladorHostal::getInstancia()->habitacionHostal(this->nombreHostal, this->habitacion);
			ReservaIndividual* resv = new ReservaIndividual(codigo, checkIn, checkOut, Abierta, this->nombreHostal, hab,
					hues->getEmail(), FechaSistema::getInstancia()->getDtFecha());

			hues->setReserva(resv);
			this->coleccionReservas[resv->getCodigo()] = resv;
			hab->setReserva(resv);
		}
		else
		{
			// En caso de confirma la reserva y ser reserva Grupal
			Habitacion* hab = ControladorHostal::getInstancia()->habitacionHostal(this->nombreHostal, this->habitacion);
			map<string, Huesped*> mapHuespedes;
			for (auto& huesped : this->huespedes)
			{
				Usuario* ptrHuespedes = ControladorUsuario::getInstancia()->getUsuario(huesped.second);
				Huesped* huesp = dynamic_cast<Huesped*>(ptrHuespedes);
				string a = huesped.second;
				mapHuespedes[a] = huesp;
			}
			ReservaGrupal* resv = new ReservaGrupal(codigo, checkIn, checkOut, Abierta, this->nombreHostal, hab,
					mapHuespedes, this->huesped, FechaSistema::getInstancia()->getDtFecha());

			this->coleccionReservas[resv->getCodigo()] = resv;
			hab->setReserva(resv);
			for (auto& hues : mapHuespedes)
			{
				hues.second->setReserva(resv);
			}
		}
	}
	// Deja de recordar
	this->nombreHostal = "";
	this->habitacion = 0;
	this->huesped = "";
	if (!this->esReservaIndivudal)
	{
		this->huespedes.clear();
	}
	return codigo;
}

void ControladorReserva::seleccionarReserva(int codigo)
{
	this->codigo = codigo;
}

void ControladorReserva::realizarReservaIndividual(DtFecha checkIn, DtFecha checkOut)
{
	this->esReservaIndivudal = true;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
}

void
ControladorReserva::realizarReservaGrupal(DtFecha checkIn, DtFecha checkOut, map<string, string> emails, string huesped,
		int habitacion)
{
	this->esReservaIndivudal = false;
	this->huesped = huesped;
	this->habitacion = habitacion;
	this->huespedes = emails;
	this->checkIn = checkIn;
	this->checkOut = checkOut;

}

map<string, DtHostal*> ControladorReserva::listarHostalesRegistrados()
{
	try
	{
		return ControladorHostal::getInstancia()->listarHostalesRegistrados();
	}
	catch (invalid_argument& err)
	{
		throw invalid_argument(err.what());
	}
}

map<int, DtReserva*> ControladorReserva::listarReservasNoCanceladas(string hostal, string email)
{
	if (this->coleccionReservas.size() == 0)
	{
		throw invalid_argument("No hay reservas registradas");
	}
	map<int, DtReserva*> reservasNoCanceladas;
	for (auto& reserva : this->coleccionReservas)
	{
		if (hostal == reserva.second->getHostal() && reserva.second->getHuesped() == email
				&& reserva.second->getEstado() == Abierta)
		{
			reservasNoCanceladas[reserva.first] = reserva.second->getDtReserva();
		}
	}

	if (reservasNoCanceladas.size() == 0)
	{
		throw invalid_argument("No hay reservas asociadas a este usuario en el hostal seleccionado.");
	}

	return reservasNoCanceladas;
}

map<int, DtReserva*> ControladorReserva::listarReservas()
{
	map<int, DtReserva*> vect;
	for (auto& reserva : this->coleccionReservas)
	{
		vect[reserva.second->getCodigo()] = reserva.second->getDtReserva();
	}
	return vect;
}

map<int, DtReserva*> ControladorReserva::listarReservasAsociadasAHostal()
{
	map<int, DtReserva*> reservasHostal;
	for (auto& reserva : this->coleccionReservas)
	{
		if (reserva.second->getHostal() == this->nombreHostal)
		{
			reservasHostal[reserva.second->getCodigo()] = reserva.second->getDtReserva();
		}
	}
	if (!reservasHostal.empty())
	{
		return reservasHostal;
	}
	else
	{
		throw invalid_argument("No hay reservas asociadas al hostal");
	}
}

map<int, DtHabitacion>
ControladorReserva::listarHabitacionesHostalDisponibles(string hostal, DtFecha checkIn, DtFecha checKOut)
{
	try
	{
		map<int, DtHabitacion> habitaciones = ControladorHostal::getInstancia()
				->listarHabitacionesHostalDisponibles(hostal, checkIn, checKOut);
		if (habitaciones.empty())
		{
			throw invalid_argument("No hay habitaciones disponibles");
		}
		this->nombreHostal = hostal;
		return habitaciones;
	}
	catch (invalid_argument& err)
	{
		throw invalid_argument(err.what());
	}
}

void ControladorReserva::seleccionarUsuario(string email)
{
	if (ControladorUsuario::getInstancia()->existeMailUsuario(email))
	{
		this->huesped = email;
	}
	else
	{
		string error = "No hay usuario registrado con email " + email + " en el sistema";
		throw invalid_argument(error);
	}
}

void ControladorReserva::seleccionarHostal(string nombre)
{
	if (ControladorHostal::getInstancia()->existeHostal(nombre))
	{
		this->nombreHostal = nombre;
	}
	else
	{
		string error = "No hay hostal de nombre " + nombre + " registrado";
		throw invalid_argument(error);
	}
}

void ControladorReserva::registrarEstadia(int codigoReserva)
{
	Reserva* reserva = getReserva(codigoReserva);
	if (reserva->getReservaIndividual())
		reserva->cerrarReserva();
	else
	{
		int cantEstadiasCerradas = ControladorEstadia::getInstancia()->getCantEstadiasCerradas(codigoReserva);
		auto* reservaGrupal = dynamic_cast<ReservaGrupal*>(this->coleccionReservas[codigoReserva]);

		int cantHuespedes = reservaGrupal->getHuespedes().size();

		// Se cierra la reserva cuando el ultimo huesped cierra su estadia
		if ((cantHuespedes - 1) == cantEstadiasCerradas)
			reserva->cerrarReserva();

	}
}

Reserva* ControladorReserva::getReserva(int codigo)
{
	return this->coleccionReservas[codigo];
}

void ControladorReserva::seleccionarHabitacion(int numero)
{
	if (ControladorHostal::getInstancia()->existeHabitacion(this->nombreHostal, numero))
	{
		this->habitacion = numero;
	}
	else
	{
		string error = "No hay habitacion numero " + to_string(numero) + " registrada";
		throw invalid_argument(error);
	}
}

bool ControladorReserva::existeMailUsuario(string email)
{
	bool existe = ControladorUsuario::getInstancia()->existeMailUsuario(email);
	return existe;
}

bool ControladorReserva::existeReserva(int codigo)
{
	bool existe = this->coleccionReservas.count(codigo);
	return existe;
}

map<string, DtUsuario*> ControladorReserva::listarUsuarios()
{
	return ControladorUsuario::getInstancia()->listarUsuarios();
}