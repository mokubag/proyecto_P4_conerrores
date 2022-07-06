#include "../../include/Classes/Habitacion.h"

Habitacion::Habitacion()
{
	vector<Servicio*> vectServ;
	map<int, Reserva*> vectRes;

	this->numero = 0;
	this->precio = 0;
	this->capacidad = 0;
	this->servicios = vectServ;
	this->reservas = vectRes;
}

Habitacion::Habitacion(int numero, int precio, int capacidad)
{
	vector<Servicio*> vectServ;
	map<int, Reserva*> vectRes;

	this->numero = numero;
	this->precio = precio;
	this->capacidad = capacidad;
	this->servicios = vectServ;
	this->reservas = vectRes;
}

int Habitacion::getNumero()
{
	return this->numero;
}

int Habitacion::getPrecio()
{
	return this->precio;
}

int Habitacion::getCapacidad()
{
	return this->capacidad;
}

void Habitacion::agregarServicio(Servicio* s)
{
	this->servicios.push_back(s);
}

void Habitacion::desvincularReserva(int codigo)
{
	this->reservas.erase(codigo);
}

DtHabitacion Habitacion::getDtHabitacion()
{
	return DtHabitacion(this->numero, this->precio, this->capacidad);
}

vector<Servicio*> Habitacion::getServicios()
{
	return this->servicios;
}

map<int, Reserva*> Habitacion::getReservas()
{
	return this->reservas;
}

bool Habitacion::disponibleEntreFechas(DtFecha checkIn, DtFecha checkOut)
{
	bool respuesta = true;
	int fecha1;
	int fecha2;
	int fecha3;
	int fecha4;
	int max;
	int min;
	int maxHora;
	int minHora;
	fecha1 = (checkIn.getDia()) + ((checkIn.getMes()) * 31) + ((checkIn.getAnio()) * 31 * 12);
	fecha2 = (checkOut.getDia()) + ((checkOut.getMes()) * 31) + ((checkOut.getAnio()) * 31 * 12);
	for (auto& reserva : this->reservas)
	{
		fecha3 = (reserva.second->getcheckIn().getDia()) + ((reserva.second->getcheckIn().getMes()) * 31)
				+ ((reserva.second->getcheckIn().getAnio()) * 31 * 12);
		fecha4 = (reserva.second->getcheckOut().getDia()) + ((reserva.second->getcheckOut().getMes()) * 31)
				+ ((reserva.second->getcheckOut().getAnio()) * 31 * 12);
		if (fecha1 >= fecha3)
		{
			max = fecha1;
			maxHora = checkIn.getHora();
		}
		else
		{
			max = fecha3;
			maxHora = reserva.second->getcheckIn().getHora();
		}
		if (fecha4 >= fecha2)
		{
			min = fecha2;
			minHora = reserva.second->getcheckOut().getHora();
		}
		else
		{
			min = fecha4;
			minHora = checkOut.getHora();
		}
		if (max <= min)
		{
			//respuesta = false;
			if (max == min)
			{
				if (minHora < maxHora)
				{
					respuesta = false;
				}
				else
				{
					respuesta = true;
				}
			}
			else
			{
				respuesta = false;
			}
		}
	}
	return respuesta;
}

void Habitacion::setReserva(Reserva* r)
{
	this->reservas[r->getCodigo()] = r;
}

Habitacion::~Habitacion()
{
	for (map<int, Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++)
	{
		it->second->desvincularHabitacion();
		this->reservas[it->first] = NULL;
	}
	this->reservas.clear();

	while (!servicios.empty())
	{
		delete servicios.back();
		servicios.pop_back();
	}
}