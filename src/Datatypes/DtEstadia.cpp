#include "../../include/Datatypes/DtEstadia.h"

DtEstadia::DtEstadia()
{
	DtFecha f(0, 1, 1, 1900);
	this->id = 0;
	this->hostal = "";
	this->huesped = "";
	this->habitacion = 0;
	this->checkIn = f;
	this->checkOut = f;
	this->promo = "";
	this->codigoReserva = 0;
	this->estaCalificada = false;
}

DtEstadia::DtEstadia(int id, string hostal, string huesped, int habitacion, DtFecha checkIn, DtFecha checkOut,
		string promo, int codigoReserva, DtCalificacion calificacion, bool estaCalificada)
{
	this->id = id;
	this->hostal = hostal;
	this->huesped = huesped;
	this->habitacion = habitacion;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->promo = promo;
	this->codigoReserva = codigoReserva;
	this->calificacion = calificacion;
	this->estaCalificada = estaCalificada;
}

int DtEstadia::getId()
{
	return this->id;
}

string DtEstadia::getHostal()
{
	return this->hostal;
}

string DtEstadia::getHuesped()
{
	return this->huesped;
}

int DtEstadia::getHabitacion()
{
	return this->habitacion;
}

DtFecha DtEstadia::getCheckIn()
{
	return this->checkIn;
}

DtFecha DtEstadia::getCheckOut()
{
	return this->checkOut;
}

string DtEstadia::getPromo()
{
	return this->promo;
}

int DtEstadia::getCodigoReserva()
{
	return this->codigoReserva;
}

DtCalificacion DtEstadia::getCalificaion()
{
	return this->calificacion;
}

bool DtEstadia::getEstaCalificada()
{
	return this->estaCalificada;
}


DtEstadia::~DtEstadia()
{

}
