#ifndef FECHASISTEMA_H
#define FECHASISTEMA_H

#include "../Datatypes/DtFecha.h"

class FechaSistema
{
private:
	int hora;
	int dia;
	int mes;
	int anio;
	static FechaSistema* instancia;

	FechaSistema(int hora, int dia, int mes, int anio);
public:
	static FechaSistema* getInstancia();
	~FechaSistema();
	DtFecha getDtFecha();
	int getHora();
	int getDia();
	int getMes();
	int getAnio();
	void setHora(int hora);
	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);
	void setFecha(int hora, int dia, int mes, int anio);
	void setFecha(DtFecha fecha);
	bool esFechaPosterior(DtFecha fecha);
	bool fechaEntre(DtFecha fecha1, DtFecha fecha2);
};

#endif
