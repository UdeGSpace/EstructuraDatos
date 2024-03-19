#include <iostream>
#include "Cola.h"



int main() {
    Cola colaSolicitudes;

    int opcion;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Dar de alta la solicitud de un alumno" << std::endl;
        std::cout << "2. Elaborar una constancia" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: // Dar de alta la solicitud de un alumno
                {
                    persona nuevoAlumno;
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

            case 3: // Salir
                std::cout << "Saliendo del programa." << std::endl;
                break;

            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }

    } while (opcion != 3);

    return 0;
}