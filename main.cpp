#include <iostream>
#include <fstream>
#include <sstream>
#include "lista.h"
#include "hijo.h"
#include "empleado.h"
#include "ciudad.h"
#include "sucursal.h"
#include "consulta2.h"

using namespace std;

void cargarDatos_hijos(const string& nombreArchivo, Lista<Hijo>& lista_hijos);
void cargarDatos_empleados(const string& nombreArchivo, Lista<Empleado>& lista_empleados, Lista<Hijo>& lista_hijos);
void cargarDatos_ciudades(const string& nombreArchivo, Lista<Ciudad>& lista_ciudades);
void cargarDatos_sucursales(const string& nombreArchivo, Lista<Sucursal>& lista_sucursales);
void empleadoxsucursal(Lista<Sucursal>& lista_sucursales, Lista<Empleado>& lista_empleados);
void clasificarhijos(Lista<Hijo>& lista_hijos);

int main(int argc, char** argv) {
	
	Lista<Ciudad> lista_ciudades;
    cargarDatos_ciudades("DB//Ciudades.txt", lista_ciudades);
    /*nodo<Ciudad>* actual_ciudad=lista_ciudades.obtener_cabecera();
	while (actual_ciudad != nullptr) {
	        cout << actual_ciudad->Dato.nombre_ciudad<< endl;
	    actual_ciudad = actual_ciudad->sig;
    }*/
    
    Lista<Sucursal> lista_sucursales;
    cargarDatos_sucursales("DB//Sucursales.txt", lista_sucursales);
    /*nodo<Sucursal>* actual_sucursal=lista_sucursales.obtener_cabecera();
	while (actual_sucursal != nullptr) {
	        cout << actual_sucursal->Dato.id_ciudad<<" "
	        	<<actual_sucursal->Dato.id_sucursal<<" "
	        	<<actual_sucursal->Dato.nombre_sucursal<<" "
	        	<<actual_sucursal->Dato.dir_sucursal<<" "
	        	<<actual_sucursal->Dato.barrio_sucursal<<" "
	        	<<actual_sucursal->Dato.nombre_gerente<<endl;
	    actual_sucursal = actual_sucursal->sig;
    }*/
    
    Lista<Hijo> lista_hijos;
    cargarDatos_hijos("DB//Hijos.txt", lista_hijos);
    /*nodo<Hijo>* actual_hijo = lista_hijos.obtener_cabecera();
    while (actual_hijo != nullptr) {
        cout << actual_hijo->Dato.id_empleado << " "
                << actual_hijo->Dato.id_hijo << " "
                << actual_hijo->Dato.nombre_hijo << " "
                << actual_hijo->Dato.nac_hijo <<" "
                << "Edad: " << actual_hijo->Dato.edad << " anios" << endl;
        actual_hijo = actual_hijo->sig;
    }*/
    
    Lista<Empleado> lista_empleados;
    cargarDatos_empleados("DB//Empleados.txt", lista_empleados, lista_hijos);
    /*nodo<Empleado>* actual_empleado =lista_empleados.obtener_cabecera();
    while (actual_empleado != nullptr) {
        cout << actual_empleado->Dato.id_sucursal <<" "
        		<<actual_empleado->Dato.id_empleado <<" "
        		<<actual_empleado->Dato.nombre_empleado <<" "
        		<<actual_empleado->Dato.apellido_empleado<<" "
        		<<actual_empleado->Dato.tipo_ident<<" "
        		<<actual_empleado->Dato.ident<<" "
				<<actual_empleado->Dato.sexo<<" "
				<<actual_empleado->Dato.cel<<" "
				<<actual_empleado->Dato.tel<<" "
				<<actual_empleado->Dato.correo<<" "
				<<actual_empleado->Dato.fecha_nac_empleado<<" "
				<<actual_empleado->Dato.ciudad_nac_empleado<<" "
				<<actual_empleado->Dato.pais_nac_empleado<<" "
				<<actual_empleado->Dato.ciudad_res_empleado<<" "
				<<actual_empleado->Dato.dir_empleado<<" "
				<<actual_empleado->Dato.barrio_empleado<<" "
				<<actual_empleado->Dato.act_lab<<" "
				<<actual_empleado->Dato.tiene_hijos<<" "
				<<actual_empleado->Dato.num_hijos<<" "
				<<actual_empleado->Dato.nombre_sucursal<<" "
				<< "Edad: " << actual_empleado->Dato.edad << " anios" << endl;
        actual_empleado = actual_empleado->sig;
    }*/
    
	
	clasificar_numHijos(lista_empleados,lista_hijos,1,3);
    empleadoxsucursal(lista_sucursales, lista_empleados);
    clasificarhijos(lista_hijos);
    
    return 0;
}
