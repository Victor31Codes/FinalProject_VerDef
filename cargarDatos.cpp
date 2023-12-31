#include <fstream>
#include <sstream>
#include "lista.h"
#include "hijo.h"
#include "empleado.h"
#include "ciudad.h"
#include "sucursal.h"

using namespace std;

int calcularEdad(string fecha_nac);
Lista<Hijo> agregarHijos(int id_empleado,Lista<Hijo>& lista_hijos);
Lista<Empleado> agregarEmpleados(int id_sucursal, Lista<Empleado>& lista_empleados);

void cargarDatos_hijos(const string& nombreArchivo, Lista<Hijo>& lista_hijos){
	ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            Hijo nuevo_hijo;
            if (iss >> nuevo_hijo.id_empleado >> nuevo_hijo.id_hijo >> nuevo_hijo.nombre_hijo >> nuevo_hijo.nac_hijo) {
            	nuevo_hijo.edad=calcularEdad(nuevo_hijo.nac_hijo);
				lista_hijos.insertar_final(nuevo_hijo);
            } else {
                cerr << "No se pudieron leer los atributos correctamente." << std::endl;
            }
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

void cargarDatos_empleados(const string& nombreArchivo, Lista<Empleado>& lista_empleados, Lista<Hijo>& lista_hijos) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            Empleado nuevo_empleado;
            if (iss >> nuevo_empleado.id_sucursal >> nuevo_empleado.id_empleado >> nuevo_empleado.nombre_empleado
                >> nuevo_empleado.apellido_empleado >> nuevo_empleado.tipo_ident >> nuevo_empleado.ident >>
                nuevo_empleado.sexo >> nuevo_empleado.cel >> nuevo_empleado.tel >> nuevo_empleado.correo >>
                nuevo_empleado.fecha_nac_empleado >> nuevo_empleado.ciudad_nac_empleado >> nuevo_empleado.pais_nac_empleado >>
                nuevo_empleado.ciudad_res_empleado >> nuevo_empleado.dir_empleado >> nuevo_empleado.barrio_empleado >>
                nuevo_empleado.act_lab >> nuevo_empleado.tiene_hijos >> nuevo_empleado.num_hijos >> nuevo_empleado.nombre_sucursal) {

                // Calcular la edad y almacenarla
                nuevo_empleado.edad=calcularEdad(nuevo_empleado.fecha_nac_empleado);
                if(nuevo_empleado.tiene_hijos=='S'){
                	//cout<<nuevo_empleado.nombre_empleado<<endl;
					nuevo_empleado.hijos=agregarHijos(nuevo_empleado.id_empleado, lista_hijos);
				}
                lista_empleados.insertar_final(nuevo_empleado);
            } else {
                cerr << "No se pudieron leer los atributos correctamente." <<endl;
            }
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." << endl;
    }
}

void cargarDatos_ciudades(const string& nombreArchivo, Lista<Ciudad>& lista_ciudades){
	ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            Ciudad nueva_ciudad;
            if (iss >> nueva_ciudad.nombre_ciudad) {
                lista_ciudades.insertar_final(nueva_ciudad);
            } else {
                cerr << "No se pudieron leer los atributos correctamente." << endl;
            }
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." << endl;
    }	
}

void cargarDatos_sucursales(const string& nombreArchivo, Lista<Sucursal>& lista_sucursales, Lista<Empleado>& lista_empleados){
	ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            Sucursal nueva_sucursal;
            if (iss >> nueva_sucursal.id_ciudad>>nueva_sucursal.id_sucursal>> nueva_sucursal.nombre_sucursal >> nueva_sucursal.dir_sucursal >> nueva_sucursal.barrio_sucursal>>nueva_sucursal.nombre_gerente) {
                nueva_sucursal.empleados=agregarEmpleados(nueva_sucursal.id_sucursal, lista_empleados);
				lista_sucursales.insertar_final(nueva_sucursal);
            } else {
                cerr << "No se pudieron leer los atributos correctamente." <<endl;
            }
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
}

Lista<Hijo> agregarHijos(int id_empleado, Lista<Hijo>& lista_hijos){
	Lista<Hijo> hijoxempleado;
	nodo<Hijo>* actual_hijo = lista_hijos.obtener_cabecera();
	while (actual_hijo!= nullptr) {
		if(actual_hijo->Dato.id_empleado==id_empleado){
			hijoxempleado.insertar_final(actual_hijo->Dato);
			//cout<<"	"<<actual_hijo->Dato.id_empleado<<" "<<actual_hijo->Dato.nombre_hijo<<endl;
		}
		actual_hijo=actual_hijo->sig;
	}
	return hijoxempleado;
}

Lista<Empleado> agregarEmpleados(int id_sucursal, Lista<Empleado>& lista_empleados){
	Lista<Empleado> empleadoxsucursal;
	nodo<Empleado>* actual_empleado = lista_empleados.obtener_cabecera();
	while (actual_empleado!= nullptr) {
		if(actual_empleado->Dato.id_sucursal==id_sucursal){
			empleadoxsucursal.insertar_final(actual_empleado->Dato);
			//cout<<id_sucursal<<"	"<<actual_empleado->Dato.id_sucursal<<" "<<actual_empleado->Dato.nombre_empleado<<endl;
		}
		actual_empleado=actual_empleado->sig;
	}
	return empleadoxsucursal;
}

