#ifndef FABRICA_H
#define FABRICA_H

#include "include/Interfaces/IControladorHostal.h"
#include "include/Interfaces/IControladorEstadia.h"
#include "include/Interfaces/IControladorUsuario.h"
#include "include/Interfaces/IControladorHabitacion.h"
#include "include/Interfaces/IControladorReserva.h"
#include "include/Interfaces/IControladorServicio.h"
#include "include/Interfaces/IControladorReserva.h"

#include <string>
#include <vector>

class Fabrica
{

private:
    
public:
    IControladorHostal *getIControladorHostal();
    IControladorEstadia *getIControladorEstadia();
    IControladorUsuario *getIControladorUsuario();
    IControladorHabitacion *getIControladorHabitacion();
    IControladorReserva *getIControladorReserva();
    IControladorServicio *getIControladorServicio();
	~Fabrica();
};



#endif
