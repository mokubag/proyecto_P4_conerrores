#ifndef CONTROLADORESTADIA_H
#define CONTROLADORESTADIA_H

#include "../Interfaces/IControladorEstadia.h"
#include "../Classes/Estadia.h"
#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtComentario.h"
#include "../Datatypes/DtEstadia.h"
#include "../Datatypes/DtCalificacion.h"
#include "../Datatypes/DtReserva.h"
#include "../Classes/FechaSistema.h"

#include "ControladorHostal.h"
#include "ControladorUsuario.h"

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class ControladorEstadia : public IControladorEstadia
{
private:
	ControladorEstadia();
	static ControladorEstadia* instancia;

	string nombreHostal;
	int id;
	string email;
	int codigoReserva;
	int cantEstadiasCreadas;
	int cantComentariosCreados;
	int cantDeEstadiasCreadas;

	map<int, Estadia*> coleccionEstadias;
	map<int, Calificacion*> coleccionCalificaciones;

public:
	void eliminarEstadia(int codigoEstadia, string nombreHostal);
	void enviarCalificacion(int cal, string com, string autor);
	void ingresarRespuestaComentario(string respuesta, int id);
	map<int, DtComentario> listarComentariosSinResponderHostal();
	map<int, DtEstadia> listarEstadiasDelHuespedFinalizadas(string email);
	map<int, DtReserva*> listarReservasNoCanceladas(string hostal, string email);
	void seleccionarEmpleado(string mail);
	DtReserva* obtenerInformacionReserva(int codigoReserva);
	void registrarEstadia(string email);
	void seleccionarEstadia(int id);
	void seleccionarHostal(string nombre);
	void seleccionarReserva(int codigo);
	map<string, DtHostal*> listarHostalesRegistrados();
	int getCantEstadiasCreadas();
	void incrementarComentariosCreados();
	map<int, DtEstadia> listarTodasEstadias();
	bool existeEstadiaActiva(string email, string hostal);
	bool existeHuesped(string email);
	void finalizarEstadia(string email, string hostal);
	map<int, DtCalificacion> listarTodasCalificaciones();
	map<string, DtUsuario*> listarUsuarios();
	int getCantEstadiasCerradas(int codigo);
	static ControladorEstadia* getInstancia();

	~ControladorEstadia();
};

#endif
