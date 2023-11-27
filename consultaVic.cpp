#include "ConsultaVic.h"

void ConsultaVic::obtenerPersonasPorCiudad(Lista<Empleado>& lista_empleados, Lista<Ciudad>& lista_ciudades, const std::string& ciudadBuscada) {
    nodo<Empleado>* actual_empleado = lista_empleados.obtener_cabecera();

    while (actual_empleado != nullptr) {
        // Buscar la ciudad de residencia en la lista de ciudades
        nodo<Ciudad>* actual_ciudad = lista_ciudades.obtener_cabecera();
        bool encontrada = false;

        while (actual_ciudad != nullptr) {
            if (actual_ciudad->Dato.obtenerNombre() == actual_empleado->Dato.ciudad_res_empleado) {
                encontrada = true;
                break;
            }
            actual_ciudad = actual_ciudad->sig;
        }

        if (encontrada && actual_ciudad->Dato.obtenerNombre() == ciudadBuscada) {
            // Clasificar por ciudad de nacimiento y actividad laboral
            std::cout << "Ciudad de Nacimiento: " << actual_empleado->Dato.ciudad_nac_empleado << std::endl;
            std::cout << "Actividad Laboral: " << actual_empleado->Dato.act_lab << std::endl;
            std::cout << "Nombre: " << actual_empleado->Dato.nombre_empleado << " " << actual_empleado->Dato.apellido_empleado << std::endl;
            std::cout << "------------------------------" << std::endl;
        }

        actual_empleado = actual_empleado->sig;
    }
}







