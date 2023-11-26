#include <stdlib.h>  //Libreria para limpiar pantalla
#include <iostream>
#include "LeerEntradas.h"
#include "empleado.h"

using namespace std;

class Menu {
	public:
	
	int Opcion;
//	Sucursal
	Empleado empleado;
	
	// Menus disponbles:
	
//	void SelectorMenu();
//	void MenuPrincipal();
//	void SubMenu_SobreNosotros();
//	void SubMenu_BusquedaPorCategoria();
//	void SubMenu_RealizarConsultas();
//	void SubMenu_CRUD();
	
	// Leer archivos:
	
	void leerArchivos() {
		cout << "algo";
	}

	void MenuPrincipal() {
		bool programaAbierto = true;
		
		while(programaAbierto) { // Bucle hasta que se escoja salir.
//			system("cls");
			SelectorMenu();
			Opcion = LeerEntradas::leerEntrada(1,4);
			
			switch (Opcion) {
				case 1: {
					SubMenu_SobreNosotros();
					cin.ignore(); // Detiene el programa hasta que se presione una tecla.
					break;
				}
				case 2: {
//					system("cls");
					SubMenu_RealizarConsultas();
					Opcion = LeerEntradas::leerEntrada(1,7);
					
					switch (Opcion) {
						case 1: {
							cout << "Numero total de personas que trabajan en una sucursal dada, clasificandolos por rangos de edades de los hijos de la siguiente forma: sin hijos, de 0-5, 6-10, 11-18, mayor de 18.";
//							system("Pause");
							break;
						}
						case 2: {
							cout << "Listado de los nombres y apellidos de aquellos que tienen un número de hijos dado (en rangos), clasificándolos por ciudad y país en que viven.";
//							system("Pause");
							break;
						}
						case 3: {
							cout << "Nombre y apellidos de las personas que viven en una ciudad dada,  clasificándolos por ciudad de nacimiento y actividad laboral.";
//							system("Pause");
							break;
						}
						case 4: {
							cout << "Numero de sucursales en las que trabaja un numero de personas superior a un número dado, mostrando la cantidad de personas de cada sucursal junto con el nombre del gerente, el nombre de la sucursal y el barrio en que se encuentra ubicada dicha sucursal.";
//							system("Pause");
							break;
						}
						case 5: {
							cout << "Obtener el numero de hombres y el número de mujeres que trabajan en las diferentes sucursales, clasificando la información por país y ciudad, mostrando el nombre de la sucursal y del gerente.";
//							system("Pause");
							break;
						}
						case 6: {
							cout << "Dado un rango de edad y una actividad laborar mostrar la lista de trabajadores de esa edad, clasificados por barrio y sucursal a la que pertenecen.";
//							system("Pause");
							break;
						}
						case 7: {
							programaAbierto = false;
							break;
						}
					}
					
					break;
				}
				
				case 3: {
					
//					system("cls");
					SubMenu_CRUD();
					Opcion = LeerEntradas::leerEntrada(1,3);
					
					switch (Opcion) {
						case 1: {
							// insertar empleado
							Empleado empleado;
							empleado.llenarFormulario();
							break;
						}
						case 2: {
							cout << "Elim empleado";
							break;
						}
						case 3: {
							cout << "Insertar Sucursal";
							break;
						}
						case 4: {
							cout << "Elim sucursal";
							break;
						}
						case 5: {
							cout << "Insert City";
							break;
						}
						case 6: {
							cout << "Elim City";
							break;
						}
						case 7: {
							programaAbierto = false;
							break;
						}
					}
					
					break;
				}
				case 4: {
					system("cls");
					cout << "Gracias por usar nuestro programa !";
					programaAbierto = false;
					break;
				}
			}
		}
	}
		
		
				
	void SelectorMenu() {
		cout << "\n\nEmpresa CC1" << endl;
	    cout << "Menu Principal" << endl;
	    cout << "--------------------------------------------------" << endl;
	    cout << "1. Sobre nosotros como empresa" << endl;	
	    cout << "2. Realizar Consultas" << endl;
	    cout << "3. Insertar, Modificar y Eliminar" << endl;
	    cout << "4. Salir" << endl;
	}
	
	void SubMenu_SobreNosotros() {
		cout << "Empresa CC1 busca recoger información acerca de sus empleados con el fin de hallar perfiles \nque les permitan enfocar el desarrollo de las labores de manera más eficiente.  \nPara ello, los gerentes ordenan la elaboración de formularios que son entregados en cada \nuna de las sucursales ubicadas a lo largo y ancho del país \n(puede haber más de una sucursal en la misma ciudad).";
	}
	
	void SubMenu_RealizarConsultas(){
		cout << "Realizar una consulta" << endl;
	    cout << "--------------------------------------------------" << endl;
	    cout << "1. Numero total de personas que trabajan en una sucursal dada." << endl;
	    cout << "2. Listado de los nombres y apellidos de aquellos que tienen cierto número de hijos." << endl;
	    cout << "3. Nombre y apellidos de las personas que viven en una ciudad dada,  clasificándolos por ciudad de nacimiento y actividad laboral." << endl;
	    cout << "4. Numero de sucursales en las que trabaja un numero de personas superior a un número dado, mostrando la cantidad de personas de cada sucursal junto con el nombre del gerente, el nombre de la sucursal y el barrio en que se encuentra ubicada dicha sucursal." << endl;
	    cout << "5. Obtener el numero de hombres y el número de mujeres que trabajan en las diferentes sucursales, clasificando la información por país y ciudad, mostrando el nombre de la sucursal y del gerente." << endl;
	    cout << "6. Dado un rango de edad y una actividad laborar mostrar la lista de trabajadores de esa edad, clasificados por barrio y sucursal a la que pertenecen." << endl;
	    cout << "7. Salir" << endl;
	}
	
	void SubMenu_CRUD() {
		cout << "Acciones CRUD" << endl;
	    cout << "--------------------------------------------------" << endl;
	    cout << "1. Insertar Empleado" << endl;
	    cout << "2. Eliminar Empleado" << endl;

	    cout << "3. Insertar Sucursal" << endl;
	    cout << "4. Eliminar Sucursal" << endl;

		cout << "5. Insertar Ciudad" << endl;
		cout << "6. Eliminar Ciudad" << endl;

	    cout << "7. Salir" << endl;
	}
		
};
