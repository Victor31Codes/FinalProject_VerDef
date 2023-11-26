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
                	cout<<nuevo_empleado.nombre_empleado<<endl;
					nuevo_empleado.hijos=agregarHijos(nuevo_empleado.id_empleado, lista_hijos);
				}else{
					nuevo_empleado.tiene_hijos==NULL;
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

void cargarDatos_sucursales(const string& nombreArchivo, Lista<Sucursal>& lista_sucursales){
	ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            Sucursal nueva_sucursal;
            if (iss >> nueva_sucursal.id_ciudad>>nueva_sucursal.id_sucursal>> nueva_sucursal.nombre_sucursal >> nueva_sucursal.dir_sucursal >> nueva_sucursal.barrio_sucursal>>nueva_sucursal.nombre_gerente) {
                
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
			cout<<"	"<<actual_hijo->Dato.id_empleado<<" "<<actual_hijo->Dato.nombre_hijo<<endl;
		}
		actual_hijo=actual_hijo->sig;
	}
	return hijoxempleado;
}

void clasificarhijos(Lista<Hijo>& lista_hijos){
	Lista<Hijo> lista_hijos05;
	Lista<Hijo> lista_hijos610;
	Lista<Hijo> lista_hijos1115;
	Lista<Hijo> lista_hijos15;
	Lista<Hijo> lista_hijo_rangos;
	nodo<Hijo>* actual_hijo = lista_hijos.obtener_cabecera();
	while (actual_hijo!= nullptr) {
		if (actual_hijo->Dato.edad>=0&&actual_hijo->Dato.edad<=5){
			lista_hijos05.insertar_final(actual_hijo->Dato);
		}else if(actual_hijo->Dato.edad>=6&&actual_hijo->Dato.edad<=10){
			lista_hijos610.insertar_final(actual_hijo->Dato);
		}else if(actual_hijo->Dato.edad>=11&&actual_hijo->Dato.edad<=15){
			lista_hijos1115.insertar_final(actual_hijo->Dato);
		}else if(actual_hijo->Dato.edad>15){
			lista_hijos15.insertar_final(actual_hijo->Dato);
		}
		actual_hijo = actual_hijo->sig;
	}
	Lista<Lista<Hijo>> lista_rango_hijos;
	lista_rango_hijos.insertar_final(lista_hijos05);
    lista_rango_hijos.insertar_final(lista_hijos610);
    lista_rango_hijos.insertar_final(lista_hijos1115);
    lista_rango_hijos.insertar_final(lista_hijos15);
	nodo<Hijo>* aux = lista_hijos05.obtener_cabecera();
    while (aux!= nullptr) {
        cout << "ID: " << aux->Dato.id_hijo << ", Nombre: " << aux->Dato.nombre_hijo
             << ", Edad: " << aux->Dato.edad<<endl;
        aux = aux->sig;
    }
    aux = lista_hijos610.obtener_cabecera();
    while (aux!= nullptr) {
        cout << "ID: " << aux->Dato.id_hijo << ", Nombre: " << aux->Dato.nombre_hijo
             << ", Edad: " << aux->Dato.edad <<endl;
        aux = aux->sig;
    }
    aux = lista_hijos1115.obtener_cabecera();
    while (aux!= nullptr) {
        cout << "ID: " << aux->Dato.id_hijo << ", Nombre: " << aux->Dato.nombre_hijo
             << ", Edad: " << aux->Dato.edad <<endl;
        aux = aux->sig;
    }
    aux = lista_hijos15.obtener_cabecera();
    while (aux!= nullptr) {
        cout << "ID: " << aux->Dato.id_hijo << ", Nombre: " << aux->Dato.nombre_hijo
             << ", Edad: " << aux->Dato.edad <<endl;
        aux = aux->sig;
    }
}
