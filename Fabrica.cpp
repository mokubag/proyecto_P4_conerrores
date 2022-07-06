#include "Fabrica.h"
#include "include/Controllers/ControladorUsuario.h"
#include "include/Controllers/ControladorHostal.h"
#include "include/Controllers/ControladorEstadia.h"
#include "include/Controllers/ControladorHabitacion.h"
#include "include/Controllers/ControladorServicio.h"
#include "include/Controllers/ControladorReserva.h"

IControladorHostal* Fabrica::getIControladorHostal()
{
	return ControladorHostal::getInstancia();
}

IControladorEstadia* Fabrica::getIControladorEstadia()
{
	return ControladorEstadia::getInstancia();
}

IControladorUsuario* Fabrica::getIControladorUsuario()
{
	return ControladorUsuario::getInstancia();
}

IControladorHabitacion* Fabrica::getIControladorHabitacion()
{
	return ControladorHabitacion::getInstancia();
}

IControladorReserva* Fabrica::getIControladorReserva()
{
	return ControladorReserva::getInstancia();
}

IControladorServicio* Fabrica::getIControladorServicio()
{
	return ControladorServicio::getInstancia();
}

Fabrica::~Fabrica()
{
	delete ControladorUsuario::getInstancia();
	delete ControladorHostal::getInstancia();
	delete ControladorReserva::getInstancia();
	delete ControladorEstadia::getInstancia();
	delete ControladorHabitacion::getInstancia();
	delete ControladorServicio::getInstancia();
}