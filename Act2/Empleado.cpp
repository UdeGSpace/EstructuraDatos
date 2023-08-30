#include <iostream>
#include <string>
using namespace std;

class Empleado {
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string Reporta;

public:
    Empleado(int clave, const string& nombre, const string& domicilio, float sueldo, const string& reporta)
        : ClaveEmpleado(clave), Nombre(nombre), Domicilio(domicilio), Sueldo(sueldo), Reporta(reporta) {}

    void imprime() {
        cout << "Clave del Empleado: " << ClaveEmpleado << endl;
        cout << "Nombre del Empleado: " << Nombre << endl;
        cout << "Domicilio del Empleado: " << Domicilio << endl;
        cout << "Sueldo del Empleado: " << Sueldo << endl;
        cout << "Reporta a: " << Reporta << endl;
    }

    void cambiarDomicilio(const string& domicilio) {
        Domicilio = domicilio;
    }

    void cambiarReporteA(const string& reporta) {
        Reporta = reporta;
    }

    void actualSueldo(float sueldo) {
        Sueldo = sueldo;
    }

    int getClaveEmpleado() {
        return ClaveEmpleado;
    }
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

string Menu = "1. Mostrar Datos de empleados\n2. Cambiar domicilio\n3. Cambiar encargado\n4. Actualizar sueldo\n5. Salir\n";

int main() {
    Empleado JefePlanta(123, "Jose", "123 Calle Principal", 3000, "Af");
    Empleado JefePersonal(234, "Pepe", "456 Calle Secundaria", 3500,"Bdd");

    int option = 0;
    string temp;
    char tempString[50];
    float nuevoSueldo = 0;
    while (option != 5) {
        cout << Menu;
        cin >> option;
        switch (option) {
        case 1:
            int code;
            cout << "Ingresa la clave de empleado: ";
            cin >> code;
            if (code == JefePlanta.getClaveEmpleado()) {
                JefePlanta.imprime();
            } else if (code == JefePersonal.getClaveEmpleado()) {
                JefePersonal.imprime();
            } else {
                cout << "Clave de empleado no válida." << endl;
            }
            break;
        case 2:
            cout << "Ingresa la clave de empleado: ";
            cin >> code;
            cout << "Ingresa el nuevo domicilio: ";
            cin.ignore();
            getline(cin, temp);
            if (code == JefePlanta.getClaveEmpleado()) {
                JefePlanta.cambiarDomicilio(temp);
            } else if (code == JefePersonal.getClaveEmpleado()) {
                JefePersonal.cambiarDomicilio(temp);
            } else {
                cout << "Clave de empleado no válida." << endl;
            }
            clearScreen();
            break;
        case 3:
            cout << "Ingresa la clave de empleado: ";
            cin >> code;
            cin.ignore(); // Limpiar el buffer
            cout << "Ingresa el nombre del nuevo encargado: ";
            getline(cin, temp); // Leer una línea completa
            if (code == JefePlanta.getClaveEmpleado()) {
                JefePlanta.cambiarReporteA(temp); // Pasar la cadena completa
            } else if (code == JefePersonal.getClaveEmpleado()) {
                JefePersonal.cambiarReporteA(temp); // Pasar la cadena completa
            } else {
                cout << "Clave de empleado no válida." << endl;
            }
            clearScreen();
            break;

        case 4:
            cout << "Ingresa la clave de empleado: ";
            cin >> code;
            cout << "Ingresa el nuevo salario: ";
            cin >> nuevoSueldo;
            if (code == JefePlanta.getClaveEmpleado()) {
                JefePlanta.actualSueldo(nuevoSueldo);
            } else if (code == JefePersonal.getClaveEmpleado()) {
                JefePersonal.actualSueldo(nuevoSueldo);
            } else {
                cout << "Clave de empleado no válida." << endl;
            }
            clearScreen();
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida. Ingresa un número del 1 al 5." << endl;
            break;
        }
    }

    return 0;
}
