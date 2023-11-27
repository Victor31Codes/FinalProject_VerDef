#ifndef CONSULTAVIC_H
#define CONSULTAVIC_H

#include "lista.h"
#include "empleado.h"
#include "ciudad.h"
#include <string>

class ConsultaVic {
public:
    static void obtenerPersonasPorCiudad(Lista<Empleado>& lista_empleados, Lista<Ciudad>& lista_ciudades, const std::string& ciudadBuscada);
};

#endif

