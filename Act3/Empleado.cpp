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

    void imprime() const {
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

    void actualSueldo(float incrementoPorcentaje) {
        float incremento = Sueldo * (incrementoPorcentaje / 100.0);
        Sueldo += incremento;
    }

    int getClaveEmpleado() const {
        return ClaveEmpleado;
    }

    // Sobrecarga de operadores
    bool operator==(const Empleado& other) const {
        return ClaveEmpleado == other.ClaveEmpleado;
    }

    bool operator!=(const Empleado& other) const {
        return ClaveEmpleado != other.ClaveEmpleado;
    }

    bool operator<(const Empleado& other) const {
        return ClaveEmpleado < other.ClaveEmpleado;
    }

    bool operator>(const Empleado& other) const {
        return ClaveEmpleado > other.ClaveEmpleado;
    }

    Empleado operator+(const Empleado& other) const {
        int nuevaClave = ClaveEmpleado + other.ClaveEmpleado;
        float nuevoSueldo = Sueldo + other.Sueldo;
        string nuevoNombre = Nombre + " " + other.Nombre;
        string nuevoDomicilio = Domicilio + " " + other.Domicilio;
        string nuevoReporta = Reporta + " " + other.Reporta;
        return Empleado(nuevaClave, nuevoNombre, nuevoDomicilio, nuevoSueldo, nuevoReporta);
    }

    friend ostream& operator<<(ostream& os, const Empleado& empleado) {
        os << "Clave del Empleado: " << empleado.ClaveEmpleado << endl;
        os << "Nombre del Empleado: " << empleado.Nombre << endl;
        os << "Domicilio del Empleado: " << empleado.Domicilio << endl;
        os << "Sueldo del Empleado: " << empleado.Sueldo << endl;
        os << "Reporta a: " << empleado.Reporta << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Empleado& empleado) {
        cout << "Ingresa la clave del empleado: ";
        is >> empleado.ClaveEmpleado;
        cout << "Ingresa el nombre del empleado: ";
        is >> empleado.Nombre;
        cout << "Ingresa el domicilio del empleado: ";
        is >> empleado.Domicilio;
        cout << "Ingresa el sueldo del empleado: ";
        is >> empleado.Sueldo;
        cout << "Ingresa a quién reporta el empleado: ";
        is >> empleado.Reporta;
        return is;
    }
};

void cleanScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

string Menu = "1. Cambiar domicilio de un empleado\n2. Actualizar sueldo de un empleado\n3. Imprimir datos de un empleado\n4. Cambiar persona a quien reporta\n5. Salir\n";

int main() {
    Empleado JefePlanta(123, "Jose", "123 Calle Principal", 3000.0, "Jaime");
    Empleado JefePersonal(234, "Pepe", "456 Calle Secundaria", 3500.0, "Rodrigo");

    int option = 0;
    while (option != 5) {
        string temp;
        cout << Menu;
        cin >> option;
        switch (option) {
        case 1:
            int claveDomicilio;           
            cout << "Ingresa la clave del empleado: ";
            cin >> claveDomicilio;
            if (claveDomicilio == JefePlanta.getClaveEmpleado()) {
                cout << "Ingresa el nuevo domicilio: ";
                cin >> temp;
                JefePlanta.cambiarDomicilio(temp);
            } else if (claveDomicilio == JefePersonal.getClaveEmpleado()) {
                cout << "Ingresa el nuevo domicilio: ";
                cin >> temp;
                JefePersonal.cambiarDomicilio(temp);
            } else {
                cout << "Clave de empleado no válida." << endl;
            }
            cleanScreen();
            break;
        case 2:
            int claveSueldo;
            float incrementoPorcentaje;
            cout << "Ingresa la clave del empleado: ";
            cin >> claveSueldo;
            if (claveSueldo == JefePlanta.getClaveEmpleado()) {
                cout << "Ingresa el porcentaje de incremento al sueldo: ";
                cin >> incrementoPorcentaje;
                JefePlanta.actualSueldo(incrementoPorcentaje);
            } else if (claveSueldo == JefePersonal.getClaveEmpleado()) {
                cout << "Ingresa el porcentaje de incremento al sueldo: ";
                cin >> incrementoPorcentaje;
                JefePersonal.actualSueldo(incrementoPorcentaje);
            } else {
                cout << "Clave de empleado no válida." << endl;
            }
            cleanScreen();
            break;
        case 3:
            int claveImprimir;
            cout << "Ingresa la clave del empleado: ";
            cin >> claveImprimir;
            if (claveImprimir == JefePlanta.getClaveEmpleado()) {
                cout << JefePlanta;
            } else if (claveImprimir == JefePersonal.getClaveEmpleado()) {
                cout << JefePersonal;
            } else {
                cout << "Clave de empleado no válida." << endl;
            }
            break;
        case 4:
            int claveReporta;
            cout << "Ingresa la clave del empleado: ";
            cin >> claveReporta;
            cin.ignore();
            cout << "Ingresa la nueva persona a quien reporta: ";
            getline(cin, temp);
            if (claveReporta == JefePlanta.getClaveEmpleado()) {
                JefePlanta.cambiarReporteA(temp);
            } else if (claveReporta == JefePersonal.getClaveEmpleado()) {
                JefePersonal.cambiarReporteA(temp);
            } else {
                cout << "Clave de empleado no válida." << endl;
            }
            cleanScreen();
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
