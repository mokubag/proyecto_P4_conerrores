#include <iostream>
#include <map>
#include <vector>
using std::map;
using namespace std;

#include "Fabrica.h"
#include "include/Classes/FechaSistema.h"

#include "include/Interfaces/IControladorUsuario.h"
#include "include/Interfaces/IControladorHostal.h"
#include "include/Interfaces/IControladorEstadia.h"
#include "include/Interfaces/IControladorHabitacion.h"
#include "include/Interfaces/IControladorServicio.h"
#include "include/Interfaces/IControladorReserva.h"

#include "include/Datatypes/DtCalificacion.h"	
#include "include/Datatypes/DtComentario.h"
#include "include/Datatypes/DtEmpleado.h"
#include "include/Datatypes/DtEstadia.h"
#include "include/Datatypes/DtHabitacion.h"
#include "include/Datatypes/DtHostal.h"
#include "include/Datatypes/DtNotificacion.h"
#include "include/Datatypes/DtReserva.h"
#include "include/Datatypes/DtServicio.h"
#include "include/Datatypes/enumCargo.h"
#include "include/Datatypes/enumEstado.h"
#include "include/Datatypes/DtHuesped.h"
#include "include/Datatypes/DtReservaIndividual.h"
#include "include/Datatypes/DtReservaGrupal.h"
#include "include/Datatypes/DtUsuario.h"
#include "include/Datatypes/DtFecha.h"

void CargarDatos(Fabrica* f, FechaSistema* fecha);