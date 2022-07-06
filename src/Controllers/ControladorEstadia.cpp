#include "../../include/Controllers/ControladorEstadia.h"
#include "../../include/Controllers/ControladorReserva.h"
#include "../../include/Classes/FechaSistema.h"
#include "../../include/Classes/Hostal.h"
#include "../../include/Classes/Empleado.h"
#include "../../include/Classes/Reserva.h"

ControladorEstadia* ControladorEstadia::instancia = NULL;

ControladorEstadia::ControladorEstadia()
{
	map<int, Estadia*> mapEstadias;
	map<int, Calificacion*> mapCalificaciones;

	this->nombreHostal = "";
	this->id = 0;
	this->email = "";
	this->codigoReserva = 0;
	this->cantEstadiasCreadas = 1;
	this->cantComentariosCreados = 1;
	this->coleccionEstadias = mapEstadias;
	this->cantDeEstadiasCreadas = 1;
	this->coleccionCalificaciones = mapCalificaciones;
}

ControladorEstadia::~ControladorEstadia()
{
	for (map<int, Estadia*>::iterator it = coleccionEstadias.begin(); it != coleccionEstadias.end(); it++)
	{
		delete it->second;
	}
	this->coleccionEstadias.clear();

	for (map<int, Calificacion*>::iterator it = coleccionCalificaciones.begin();
		 it != coleccionCalificaciones.end();
		 it++)
	{
		delete it->second;
	}
	this->coleccionCalificaciones.clear();
}

ControladorEstadia* ControladorEstadia::getInstancia()
{
	if (instancia == NULL) instancia = new ControladorEstadia();
	return instancia;
}

void ControladorEstadia::eliminarEstadia(int codigoEstadia, string nombreHostal)
{
	if (this->coleccionEstadias[codigoEstadia]->getCalificacion() != NULL)
	{
		Comentario* respuesta = this->coleccionEstadias[codigoEstadia]->getCalificacion()->getComentario()->getRespuesta();
		if (respuesta != NULL)
		{
			string emailEmpleado = respuesta->getAutor();
			Empleado* emp = dynamic_cast<Empleado*>(ControladorUsuario::getInstancia()->getUsuario(emailEmpleado));
			emp->desvincularComentario(codigoEstadia);
		}
		if (this->coleccionCalificaciones.count(codigoEstadia))  // codigo estadia es el mismo que el de calificacion
		{
			this->coleccionCalificaciones.erase(codigoEstadia);
			this->coleccionEstadias[codigoEstadia]->eliminarCalificacion();
		}
		// El codigo de la estadia es el mismo que el de la calificacion
		ControladorHostal::getInstancia()->getHostal(nombreHostal)->desvincularCalificacion(codigoEstadia);
	}
	this->coleccionEstadias[codigoEstadia]->desvincularReserva();
	this->coleccionEstadias.erase(codigoEstadia);
}

void ControladorEstadia::enviarCalificacion(int cal, string com, string autor)
{
	DtFecha actual = FechaSistema::getInstancia()->getDtFecha();
	Hostal* h = ControladorHostal::getInstancia()->getHostal(this->nombreHostal);
	Estadia* e = this->coleccionEstadias[this->id];
//	int idNuevaCalificacion = this->cantDeEstadiasCreadas;

	Comentario* coment = new Comentario(com, autor, actual, this->cantComentariosCreados);
	incrementarComentariosCreados();
	Calificacion* c = new Calificacion(cal, actual, this->id, coment);
	c->getComentario()->setNull();
	e->setCalificacion(c);
	h->agregarCalificacion(c);
//	this->cantDeEstadiasCreadas = this->cantDeEstadiasCreadas + 1;
	this->coleccionCalificaciones[this->id] = c;
	ControladorUsuario::getInstancia()->notificarSuscriptores(autor, cal, com);
	this->nombreHostal = "";
	this->id = 0;
}

void ControladorEstadia::ingresarRespuestaComentario(string respuesta, int id)
{
	DtFecha actual = FechaSistema::getInstancia()->getDtFecha();

	for (auto& calificacion : coleccionCalificaciones)
	{
		if (calificacion.second->getComentario()->getId() == id)
		{
			Comentario* com = calificacion.second->getComentario();
			int nuevoid = this->cantComentariosCreados;
			com->ingresarRespuesta(respuesta, this->email, actual, nuevoid);
			incrementarComentariosCreados();
		}
	}

	this->email = "";
	this->nombreHostal = "";
	this->id = 0;
}

map<int, DtComentario> ControladorEstadia::listarComentariosSinResponderHostal()
{
	try
	{
		return ControladorHostal::getInstancia()->listarComentariosSinResponderHostal(this->email);
	}
	catch (invalid_argument& err)
	{
		throw invalid_argument(err.what());
	}
}

map<int, DtEstadia> ControladorEstadia::listarEstadiasDelHuespedFinalizadas(string email)
{
	Usuario* u = ControladorUsuario::getInstancia()->getUsuario(email);
	Huesped* hues = dynamic_cast<Huesped*>(u);
	map<int, DtEstadia> resp;
	if (hues != NULL)
	{
		if (hues->existeEstadia() && hues->tieneEstadiaFinalizada())
		{
			map<int, Estadia*> estadiasHuesped = hues->getEstadias();
			DtEstadia e;
			for (auto& it : estadiasHuesped)
			{
				e = it.second->getDtEstadia();
				resp[e.getId()] = e;
			}
		}
		else
		{
			throw invalid_argument("El huesped no tiene asociada ninguna estadia");
		}
	}
	else
	{
		throw invalid_argument("No existe huesped asociado a este mail");
	}
	return resp;
}

map<int, DtReserva*> ControladorEstadia::listarReservasNoCanceladas(string hostal, string email)
{
	return ControladorReserva::getInstancia()->listarReservasNoCanceladas(hostal, email);
}

void ControladorEstadia::seleccionarEmpleado(string mail)
{
	Usuario* usu = ControladorUsuario::getInstancia()->getUsuario(mail);
	Empleado* emp = dynamic_cast<Empleado*>(usu);
	if (emp != NULL)
	{
		this->email = mail;
	}
	else
	{
		throw invalid_argument("No existe empleado asociado a ese email");
	}
}

DtReserva* ControladorEstadia::obtenerInformacionReserva(int codigoReserva)
{
	Reserva* res;
	if (this->coleccionEstadias[this->id]->getReserva()->getReservaIndividual())
	{
		res = this->coleccionEstadias[this->id]->getReserva();
	}
	else
	{
		res = this->coleccionEstadias[this->id]->getReserva();
	}
	DtReserva* dtres = res->getDtReserva();
	this->id = 0;
	return dtres;
}

void ControladorEstadia::registrarEstadia(string email)
{
	bool existeEstadiaRegistrada = false;
	Usuario* usu = ControladorUsuario::getInstancia()->getUsuario(email);
	Huesped* huesp = dynamic_cast<Huesped*>(usu);
	for (auto& estadia : huesp->getEstadias())
	{
		if (estadia.second->getReserva()->getCodigo() == this->codigoReserva)
		{
			existeEstadiaRegistrada = true;
			break;
		}
	}
	if (!existeEstadiaRegistrada)
	{
		// Cierra la reserva
		ControladorReserva::getInstancia()->registrarEstadia(this->codigoReserva);

		// Obtiene el usuario
		Usuario* usuario = ControladorUsuario::getInstancia()->getUsuario(email);
		Huesped* huesp = dynamic_cast<Huesped*>(usuario);

		if (huesp != NULL)
		{
			int nuevoIdEstadia = getCantEstadiasCreadas();
			// Crea la estadía
			DtFecha f = FechaSistema::getInstancia()->getDtFecha();
			Reserva* r = ControladorReserva::getInstancia()->getReserva(this->codigoReserva);
			Estadia* nuevaEstadia = new Estadia(f, DtFecha(0, 1, 1, 1899), "", r, nuevoIdEstadia, email);

			// Almacena la estadía en la colección de estadías
			this->coleccionEstadias[nuevoIdEstadia] = nuevaEstadia;
			this->cantEstadiasCreadas++;

			// Vincula al usuario con la estadía
			huesp->asociarEstadia(nuevaEstadia);
			this->codigoReserva = 0;

		}
		else
		{
			// No se puede crear una estadía
			throw invalid_argument("El usuario seleccionado no es un huesped.");
		}
	}
	else
	{
		string error = "Ya existe una estadia asociada a este huesped en esta reserva.";
		throw invalid_argument(error);
	}
}

void ControladorEstadia::seleccionarEstadia(int id)
{
	if (this->coleccionEstadias.count(id))
	{
		this->id = id;
	}
	else
	{
		string error = "No hay estadia con codigo " + to_string(id) + " en el sistema";
		throw invalid_argument(error);
	}
}

void ControladorEstadia::seleccionarHostal(string nombre)
{
	bool existeHostal = ControladorHostal::getInstancia()->existeHostal(nombre);
	if (existeHostal)
		this->nombreHostal = nombre;
	else
		throw invalid_argument("No hay hostal registrado con ese nombre");
}

void ControladorEstadia::seleccionarReserva(int codigo)
{
	if (!ControladorReserva::getInstancia()->existeReserva(codigo))
	{
		throw invalid_argument("No hay reserva registrada con ese codigo.");
	}
	this->codigoReserva = codigo;
}

map<string, DtHostal*> ControladorEstadia::listarHostalesRegistrados()
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

bool ControladorEstadia::existeEstadiaActiva(string email, string hostal)
{
	try
	{
		return ControladorUsuario::getInstancia()->existeEstadiaActiva(email, hostal);
	}
	catch (invalid_argument& err)
	{
		throw invalid_argument(err.what());
	}
}

bool ControladorEstadia::existeHuesped(string email)
{
	try
	{
		bool existe = ControladorUsuario::getInstancia()->existeHuesped(email);
		return existe;
	}
	catch (invalid_argument& err)
	{
		throw invalid_argument(err);
	}
}

void ControladorEstadia::finalizarEstadia(string email, string hostal)
{
	return ControladorUsuario::getInstancia()->finalizarEstadia(email, hostal,
			FechaSistema::getInstancia()->getDtFecha());
}

int ControladorEstadia::getCantEstadiasCreadas()
{
	return this->cantEstadiasCreadas;
}

void ControladorEstadia::incrementarComentariosCreados()
{
	this->cantComentariosCreados += 1;
}

map<int, DtEstadia> ControladorEstadia::listarTodasEstadias()
{
	map<int, Estadia*> estadias = this->coleccionEstadias;
	map<int, DtEstadia> res;

	for (auto& estadia : estadias)
	{
		res[estadia.first] = estadia.second->getDtEstadia();
	}
	return res;
}

map<int, DtCalificacion> ControladorEstadia::listarTodasCalificaciones()
{
	map<int, Calificacion*> calificaciones = this->coleccionCalificaciones;
	map<int, DtCalificacion> res;

	for (auto& calificacion : calificaciones)
	{
		res[calificacion.first] = calificacion.second->getDtCalificacion();
	}
	return res;
}

map<string, DtUsuario*> ControladorEstadia::listarUsuarios()
{
	try
	{
		return ControladorUsuario::getInstancia()->listarUsuarios();
	}
	catch (invalid_argument& err)
	{
		throw invalid_argument(err.what());
	}
}

int ControladorEstadia::getCantEstadiasCerradas(int codigo)
{
	int contador = 0;
	for (auto& estadia : this->coleccionEstadias)
		if (estadia.second->getReserva()->getCodigo() == codigo)
			contador++;

	return contador;
}
