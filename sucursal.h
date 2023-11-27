#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "string"
#include "lista.h"
#include "empleado.h"
using namespace std;

class Sucursal {
	public:
	int id_ciudad, id_sucursal, cant_empleados;
    string nombre_sucursal, dir_sucursal, barrio_sucursal, nombre_gerente;
    Lista<Empleado> empleados;
};

#endif
