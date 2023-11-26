#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include "lista.h"
#include "hijo.h"
#include "empleado.h"
#include "ciudad.h"
#include "sucursal.h"

using namespace std;

int calcularEdad(string fecha_nac) {
    int edad=0;
	auto ahora = chrono::system_clock::now();
    auto tiempo_actual = chrono::system_clock::to_time_t(ahora);
    tm tm_actual = *localtime(&tiempo_actual);

    // Obtener la fecha de nacimiento
    istringstream ss(fecha_nac);
    char dash;  // Car?cter para almacenar el guion '-'
    int dia, mes, anio;
    ss >> dia >> dash >> mes >> dash >> anio;

    if (ss.fail()) {
        cerr << "Error al leer la fecha de nacimiento." << endl;
        return 0;
    }

    // Configurar la estructura tm con la fecha de nacimiento
    tm tm_nac = {};
    tm_nac.tm_mday = dia;
    tm_nac.tm_mon = mes - 1;  // Restar 1, ya que en struct tm, los meses van de 0 a 11
    tm_nac.tm_year = anio - 1900;  // Restar 1900, ya que struct tm cuenta los a?os desde 1900

    // Calcular la diferencia de a?os
    auto edad_chrono = chrono::duration_cast<std::chrono::hours>(ahora - chrono::system_clock::from_time_t(mktime(&tm_nac)));
    int edad_en_anios = static_cast<int>(edad_chrono.count()) / (24 * 365);

    edad = edad_en_anios;
    return edad;
}


