#include "../../include/Datatypes/DtFecha.h"

#include <stdexcept>

DtFecha::DtFecha()
{
}

DtFecha::DtFecha(int hora, int dia, int mes, int anio)
{
	bool errorHora = (hora > 23) || (hora < 0);
	bool errorDia = (dia > 31) || (dia < 1);
	bool errorMes = (mes > 12) || (mes < 1);
//	bool errorAnio = (anio < 1900);

	if(errorHora) throw std::invalid_argument("Se esperaba una hora entre 0 y 23.");
	if(errorDia) throw std::invalid_argument("Se esperaba un dia entre 1 y 31.");
	if(errorMes) throw std::invalid_argument("Se esperaba un mes entre 1 y 12.");
//	if(errorAnio) throw std::invalid_argument("Se esperaba un anio mayor que 1900.");

	this->hora = hora;
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

int DtFecha::getHora()
{
	return this->hora;
}

int DtFecha::getDia()
{
	return this->dia;
}

int DtFecha::getMes()
{
	return this->mes;
}

int DtFecha::getAnio()
{
	return this->anio;
}

int DtFecha::operator-(DtFecha fechaDerecha)
{
	int nDias1 = this->getDia() + 31 * this->getMes() + 31 * 12 * (this->getAnio() - 1900);
	int nDias2 = fechaDerecha.getDia() + 31 * fechaDerecha.getMes() + 31 * 12 * (fechaDerecha.getAnio() - 1900);

	return nDias1 - nDias2;

}

bool DtFecha::entre(DtFecha f1, DtFecha f2)
{
	int nHoras =
			this->getHora() + 24 * this->getDia() + 24 * 31 * this->getMes() + 24 * 31 * 12 * (this->getAnio() - 1900);
	int nHoras1 = f1.getHora() + 24 * f1.getDia() + 24 * 31 * f1.getMes() + 24 * 31 * 12 * (f1.getAnio() - 1900);
	int nHoras2 = f2.getHora() + 24 * f2.getDia() + 24 * 31 * f2.getMes() + 24 * 31 * 12 * (f2.getAnio() - 1900);

	return (nHoras2 >= nHoras) && (nHoras >= nHoras1);

}

bool DtFecha::esPosterior(DtFecha f1)
{
	int fecha1 = f1.getHora()
			+ f1.getDia() * 24
			+ (f1.getMes() * 31 * 24)
			+ (f1.getAnio() * 12 * 31 * 24);

	int fecha2 = this->hora + (this->dia) * 24 + (this->mes * 31 * 24) + (this->anio * 12 * 31 * 24);
	if (fecha2 < fecha1)
		return true;
	else
		return false;

}

DtFecha::~DtFecha()
{
}
