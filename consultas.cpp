#include <fstream>
#include <sstream>
#include "lista.h"
#include "hijo.h"
#include "empleado.h"
#include "ciudad.h"
#include "sucursal.h"

using namespace std;

void empleadoxsucursal(Lista<Sucursal>& lista_sucursales, Lista<Empleado>& lista_empleados) {
	int cont=0, aux1, aux2;
	nodo<Sucursal>* actual_sucursal=lista_sucursales.obtener_cabecera();
	while (actual_sucursal != nullptr){
		nodo<Empleado>* actual_empleado = lista_empleados.obtener_cabecera();
		
		while (actual_empleado != nullptr){
		
			if(actual_sucursal->Dato.id_sucursal==actual_empleado->Dato.id_sucursal){
				
				
				cont=cont+1;
			}
			actual_empleado = actual_empleado->sig;
		}
		cout <<"La sucursal " <<actual_sucursal->Dato.nombre_sucursal<<" tiene "<<cont<<" empleados"<<endl;
		actual_sucursal = actual_sucursal->sig;
		cont=0;
	}
}


