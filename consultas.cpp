#include <fstream>
#include <sstream>
#include "lista.h"
#include "hijo.h"
#include "empleado.h"
#include "ciudad.h"
#include "sucursal.h"

using namespace std;
//Consultar empleado por sucursal

void mostrarMenu() {
    cout << "Seleccione el rango de edad de los hijos a mostrar:" << endl;
    cout << "0. Sin hijos" << endl;
    cout << "1. Con hijos entre 0 y 5 anios" << endl;
    cout << "2. Con hijos entre 6 y 10 anios" << endl;
    cout << "3. Con hijos entre 11 y 18 anios" << endl;
    cout << "4. Con hijos mayores de 18 anios" << endl;
    cout << "Ingrese su opción: ";
}

void mostrarHijosSegunRango(Lista<Hijo>& hijos, int opcion) {
    switch(opcion) {
        case 1:{	//Rango de 0 a 5
        	Lista<Hijo> lista_hijos;
        	nodo<Hijo>* actual_hijo = hijos.obtener_cabecera();
        	while (actual_hijo != nullptr){
				if(actual_hijo->Dato.edad>=0&&actual_hijo->Dato.edad<=5){
					lista_hijos.insertar_final(actual_hijo->Dato);
				}
				actual_hijo=actual_hijo->sig;	
			}
			nodo<Hijo>* aux = lista_hijos.obtener_cabecera();
					
		    while (aux!= nullptr) {
		        cout << "	Nombre: " << aux->Dato.nombre_hijo
		             << ", Edad: " << aux->Dato.edad<<endl;
		        aux = aux->sig;
		    }
            break;
		}
        case 2:{ //Rango de 6 a 11
            Lista<Hijo> lista_hijos;
        	nodo<Hijo>* actual_hijo = hijos.obtener_cabecera();
        	while (actual_hijo != nullptr){
				if(actual_hijo->Dato.edad>=6&&actual_hijo->Dato.edad<=11){
					lista_hijos.insertar_final(actual_hijo->Dato);
				}
				actual_hijo=actual_hijo->sig;	
			}
			nodo<Hijo>* aux = lista_hijos.obtener_cabecera();
					
		    while (aux!= nullptr) {
		        cout << "	Nombre: " << aux->Dato.nombre_hijo
		             << ", Edad: " << aux->Dato.edad<<endl;
		        aux = aux->sig;
		    }
            break;
		}
        case 3:{ //Rango de 11 a 18
            Lista<Hijo> lista_hijos;
        	nodo<Hijo>* actual_hijo = hijos.obtener_cabecera();
        	while (actual_hijo != nullptr){
				if(actual_hijo->Dato.edad>=11&&actual_hijo->Dato.edad<=18){
					lista_hijos.insertar_final(actual_hijo->Dato);
				}
				actual_hijo=actual_hijo->sig;	
			}
			nodo<Hijo>* aux = lista_hijos.obtener_cabecera();
					
		    while (aux!= nullptr) {
		        cout << "	Nombre: " << aux->Dato.nombre_hijo
		             << ", Edad: " << aux->Dato.edad<<endl;
		        aux = aux->sig;
		    }
            break;
		}
        case 4:{ //Mayores de 18
            Lista<Hijo> lista_hijos;
        	nodo<Hijo>* actual_hijo = hijos.obtener_cabecera();
        	while (actual_hijo != nullptr){
				if(actual_hijo->Dato.edad>18){
					lista_hijos.insertar_final(actual_hijo->Dato);
				}
				actual_hijo=actual_hijo->sig;	
			}
			nodo<Hijo>* aux = lista_hijos.obtener_cabecera();
					
		    while (aux!= nullptr) {
		        cout << "	Nombre: " << aux->Dato.nombre_hijo
		             << ", Edad: " << aux->Dato.edad<<endl;
		        aux = aux->sig;
		    }
            break;
		}
        
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
    }
}

void empleadoxsucursal(Lista<Sucursal>& lista_sucursales, Lista<Empleado>& lista_empleados) {
	int cont=0, opc;
	nodo<Sucursal>* actual_sucursal=lista_sucursales.obtener_cabecera();
	mostrarMenu();
    cin >> opc;
	while (actual_sucursal != nullptr){
		nodo<Empleado>* actual_empleado = lista_empleados.obtener_cabecera();
		while (actual_empleado != nullptr){
			if(actual_sucursal->Dato.id_sucursal==actual_empleado->Dato.id_sucursal){
				
                if (opc==0){
                	if (actual_empleado->Dato.tiene_hijos=='N'){
                		cout<<actual_empleado->Dato.nombre_empleado<<endl;
                	}
				}else {
					cout<<actual_empleado->Dato.nombre_empleado<<endl;
					mostrarHijosSegunRango(actual_empleado->Dato.hijos, opc);
				}
				cont=cont+1;
			}
			actual_empleado = actual_empleado->sig;
		}
		cout <<"LA SUCURSAL " <<actual_sucursal->Dato.nombre_sucursal<<" TIENE "<<cont<<" EMPLEADOS"<<endl;
		actual_sucursal = actual_sucursal->sig;
		cont=0;
	}
}


