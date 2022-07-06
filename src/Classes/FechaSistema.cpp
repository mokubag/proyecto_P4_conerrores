#include "../../include/Classes/FechaSistema.h"
#include <cstddef>
#include <stdexcept>
using std::to_string;

FechaSistema* FechaSistema::instancia = NULL;

FechaSistema::FechaSistema(int hora, int dia, int mes, int anio)
{
	bool errorHora = (hora > 23) || (hora < 0);
	bool errorDia = (dia > 31) || (dia < 1);
	bool errorMes = (mes > 12) || (mes < 1);
	bool errorAnio = (anio < 1900);

	if (errorHora) throw std::invalid_argument("Se esperaba una hora entre 0 y 23. Se recibió" + to_string(hora));
	if (errorDia) throw std::invalid_argument("Se esperaba un dia entre 1 y 31. Se recibió" + to_string(dia));
	if (errorMes) throw std::invalid_argument("Se esperaba un mes entre 1 y 12. Se recibió" + to_string(mes));
	if (errorAnio) throw std::invalid_argument("Se esperaba un anio mayor que 1900. Se recibió" + to_string(anio));

	this->hora = hora;
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

FechaSistema::~FechaSistema()
{
}

FechaSistema* FechaSistema::getInstancia()
{
	if (instancia == NULL) instancia = new FechaSistema(0, 1, 1, 1900);
	return instancia;
}

DtFecha FechaSistema::getDtFecha()
{
	DtFecha dtf(this->hora, this->dia, this->mes, this->anio);
	return dtf;
}

int FechaSistema::getHora()
{
	return this->hora;
}

int FechaSistema::getDia()
{
	return this->dia;
}

int FechaSistema::getMes()
{
	return this->mes;
}

int FechaSistema::getAnio()
{
	return this->anio;
}

void FechaSistema::setHora(int hora)
{
	bool errorHora = (hora > 23) || (hora < 0);

	if (errorHora) throw std::invalid_argument("Se esperaba una hora entre 0 y 23. Se recibió" + to_string(hora));
	this->hora = hora;
}

void FechaSistema::setDia(int dia)
{
	bool errorDia = (dia > 31) || (dia < 1);

	if (errorDia) throw std::invalid_argument("Se esperaba un dia entre 1 y 31. Se recibió" + to_string(dia));

	this->dia = dia;
}

void FechaSistema::setMes(int mes)
{
	bool errorMes = (mes > 12) || (mes < 1);

	if (errorMes) throw std::invalid_argument("Se esperaba un mes entre 1 y 12. Se recibió" + to_string(mes));

	this->mes = mes;
}

void FechaSistema::setAnio(int anio)
{
	bool errorAnio = (anio < 1900);

	if (errorAnio) throw std::invalid_argument("Se esperaba un anio mayor que 1900. Se recibió" + to_string(anio));

	this->anio = anio;
}

void FechaSistema::setFecha(int hora, int dia, int mes, int anio)
{
	bool errorHora = (hora > 23) || (hora < 0);
	bool errorDia = (dia > 31) || (dia < 1);
	bool errorMes = (mes > 12) || (mes < 1);
	bool errorAnio = (anio < 1900);

	if (errorHora) throw std::invalid_argument("Se esperaba una hora entre 0 y 23.");
	if (errorDia) throw std::invalid_argument("Se esperaba un dia entre 1 y 31.");
	if (errorMes) throw std::invalid_argument("Se esperaba un mes entre 1 y 12.");
	if (errorAnio) throw std::invalid_argument("Se esperaba un anio mayor o igual que 1900.");

	this->hora = hora;
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

void FechaSistema::setFecha(DtFecha fecha)
{
	this->hora = fecha.getHora();
	this->dia = fecha.getDia();
	this->mes = fecha.getMes();
	this->anio = fecha.getAnio();
}

bool FechaSistema::esFechaPosterior(DtFecha fecha)
{
	int fecha1 = fecha.getHora()
			+ fecha.getDia() * 24
			+ (fecha.getMes() * 31 * 24)
			+ (fecha.getAnio() * 12 * 31 * 24);

	int fecha2 = this->hora + (this->dia) * 24 + (this->mes * 31 * 24) + (this->anio * 12 * 31 * 24);
	if (fecha2 < fecha1)
		return true;
	else
		return false;
}

bool FechaSistema::fechaEntre(DtFecha fechaIni, DtFecha fechaFin)
{
	int fecha1 = fechaIni.getHora()
			+ fechaIni.getDia() * 24
			+ (fechaIni.getMes() * 31 * 24)
			+ (fechaIni.getAnio() * 12 * 31 * 24);

	int fecha2 = fechaFin.getHora()
		+ fechaFin.getDia() * 24
		+ (fechaFin.getMes() * 31 * 24)
		+ (fechaFin.getAnio() * 12 * 31 * 24);

	int fechaAct = this->hora + (this->dia) * 24 + (this->mes * 31 * 24) + (this->anio * 12 * 31 * 24);
	if (fecha1 <= fechaAct && fechaAct <= fecha2)
		return true;
	else
		return false;
}