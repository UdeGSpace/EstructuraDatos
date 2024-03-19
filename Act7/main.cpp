#include <iostream>
#include "include/Cola.h"


int main() {
    Cola colaSolicitudes;
    int opcion;
    persona nuevoAlumno;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Dar de alta la solicitud de un alumno" << std::endl;
        std::cout << "2. Elaborar una constancia" << std::endl;
        std::cout << "3. Buscar" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: // Dar de alta la solicitud de un alumno
                {
                    
                    std::cin >> nuevoAlumno;
                    colaSolicitudes.enqueue(nuevoAlumno);
                    std::cout << "Solicitud de constancia encolada correctamente." << std::endl;
                }
                break;

            case 2: // Elaborar una constancia
                if (!colaSolicitudes.vacia()) {
                    persona alumnoAtendido = colaSolicitudes.dequeue();
                    std::cout << "Elaborando constancia para el siguiente alumno:" << std::endl;
                    std::cout << alumnoAtendido << std::endl;
                } else {
                    std::cout << "No hay solicitudes pendientes." << std::endl;
                }
                break;
            case 3: // Buscar constancia
                std::cout << "Ingresa el nombre del alumno a buscar" << std::endl;
                std::cin >> nuevoAlumno;
                colaSolicitudes.busquedaLineal(nuevoAlumno);
                break;
            case 4: // Salir
                std::cout << "Saliendo del programa." << std::endl;
                break;

            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }

    } while (opcion != 4);

    return 0;
}
