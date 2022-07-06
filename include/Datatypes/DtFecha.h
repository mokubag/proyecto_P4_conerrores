#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha
{
private:
	int hora;
	int dia;
	int mes;
	int anio;

public:
	DtFecha();
	~DtFecha();

	DtFecha(int hora, int dia, int mes, int anio);

	int getHora();
	int getDia();
	int getMes();
	int getAnio();

	int operator-(DtFecha fecha);
	bool entre(DtFecha f1, DtFecha f2);
	bool esPosterior(DtFecha f1);
};

#endif
