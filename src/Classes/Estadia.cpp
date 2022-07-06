#include "../../include/Classes/Estadia.h"

Estadia::Estadia()
{
	DtFecha f(0, 1, 1, 1900);
	this->checkIn = f;
	this->checkOut = f;
	this->promo = "";
	this->reserva = NULL;
	this->codigo = 0;
	this->calificacion = NULL;

}

Estadia::Estadia(DtFecha checkIn, DtFecha checkOut, string promo, Reserva* reserva, int codigo, string emailHuesped)
{
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->promo = promo;
	this->reserva = reserva;
	this->codigo = codigo;
	this->calificacion = NULL;
	this->emailHuesped = emailHuesped;
}

void Estadia::eliminarCalificacion()
{
	delete this->calificacion;
}

bool Estadia::esActiva()
{
	return (this->checkOut.getAnio() == 1899);
}

void Estadia::finalizarEstadiaActiva(DtFecha checkOut)
{
	this->checkOut = checkOut;
}

int Estadia::getCodigo()
{
	return this->codigo;
}

int Estadia::getCodigoReserva()
{
	return this->reserva->getCodigo();
}

DtCalificacion Estadia::getDtCalificacion()
{
	DtCalificacion dtc = DtCalificacion(
			this->calificacion->getCalificacion(),
			this->calificacion->getFechaCalificacion(),
			this->calificacion->getDtComentario());
	return dtc;
}

DtEstadia Estadia::getDtEstadia()
{
	DtCalificacion cal;
	bool estaCalificada = false;
	if (this->calificacion != NULL)
	{
		estaCalificada = true;
		cal = this->calificacion->getDtCalificacion();
	}
	DtEstadia dte(
			this->codigo,
			this->reserva->getHostal(),
			this->emailHuesped,
			this->reserva->getHabitacion()->getNumero(),
			this->checkIn,
			this->checkOut,
			this->promo,
			this->reserva->getCodigo(),
			cal,
			estaCalificada
	);
	return dte;
}

DtFecha Estadia::getCheckIn()
{
	return this->checkIn;
}

DtFecha Estadia::getCheckOut()
{
	return this->checkOut;
}

string Estadia::getPromo()
{
	return this->promo;
}

Reserva* Estadia::getReserva()
{
	return this->reserva;
}

Calificacion* Estadia::getCalificacion()
{
	return this->calificacion;
}

void Estadia::setCalificacion(Calificacion* cal)
{
	this->calificacion = cal;
}

void Estadia::desvincularReserva()
{
	this->reserva = NULL;
}

Estadia::~Estadia()
{
	this->reserva = NULL;
	this->calificacion = NULL;
}

