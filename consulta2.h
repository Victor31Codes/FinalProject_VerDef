#ifndef CONSULTA2_H
#define CONSULTA2_H


#include "sucursal.h"
#include "lista.h"
#include "hijo.h"
#include "empleado.h"

using namespace std;

void clasificar_numHijos(Lista<Empleado>& lista_empleados, Lista<Hijo>& lista_hijos, int rangoInicio, int rangoFin) {
	
	 // Lista para almacenar empleados filtrados
    Lista<Empleado> empleadosFiltrados;

    // Iterar sobre la lista de empleados
    nodo<Empleado>* actual_empleado = lista_empleados.obtener_cabecera();
    while (actual_empleado != nullptr) {
        // Filtrar por el rango de número de hijos
        if (actual_empleado->Dato.num_hijos >= rangoInicio && actual_empleado->Dato.num_hijos <= rangoFin) {
            // Agregar el empleado filtrado a la lista
            empleadosFiltrados.insertar_final(actual_empleado->Dato);
        }
        actual_empleado = actual_empleado->sig;
    }

    // Ahora, puedes iterar sobre la lista de empleados filtrados para clasificar por ciudad y país
    nodo<Empleado>* empleado_filtrado_actual = empleadosFiltrados.obtener_cabecera();
    cout << "\n\nConsulta #2: " << endl;
	while (empleado_filtrado_actual != nullptr) {
        // Accede a la información necesaria del empleado y clasifica según ciudad y país
        cout << "Nombre: " << empleado_filtrado_actual->Dato.nombre_empleado << " " << empleado_filtrado_actual->Dato.apellido_empleado << endl;
        cout << "Ciudad: " << empleado_filtrado_actual->Dato.ciudad_res_empleado << ", País: " << empleado_filtrado_actual->Dato.pais_nac_empleado << endl;

        // Aquí también puedes acceder a la lista de hijos de cada empleado (empleado_filtrado_actual->Dato.hijos)
        // y realizar operaciones adicionales si es necesario

        empleado_filtrado_actual = empleado_filtrado_actual->sig;
    }
	
}

#endif
