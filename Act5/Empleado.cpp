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


    void imprime() const {
        cout << "Clave del Empleado: " << ClaveEmpleado << endl;
        cout << "Nombre del Empleado: " << Nombre << endl;
        cout << "Domicilio del Empleado: " << Domicilio << endl;
        cout << "Sueldo del Empleado: " << Sueldo << endl;
        cout << "Reporta a: " << Reporta << endl;
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


    Empleado operator+(const Empleado& other) const {
        int nuevaClave = ClaveEmpleado + other.ClaveEmpleado;
        float nuevoSueldo = Sueldo + other.Sueldo;
        string nuevoNombre = Nombre + " " + other.Nombre;
        string nuevoDomicilio = Domicilio + " " + other.Domicilio;
        string nuevoReporta = Reporta + " " + other.Reporta;
        return Empleado();
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

const int MAX = 100; // Tamaño máximo de la lista

class ListaEstatica {
private:
    Empleado Datos[MAX];
    int Tam;

public:
    ListaEstatica() : Tam(-1) {}

    int Inserta(Empleado elemento, int posicion) {
        if (posicion < 0 || posicion > Tam || Tam == MAX) {
            return -1; // Error: Posición no válida o lista llena
        }

        for (int i = Tam; i > posicion; i--) {
            Datos[i] = Datos[i - 1]; // Desplaza los elementos a la derecha
        }

        Datos[posicion] = elemento;
        return 0; // Éxito
    }
    bool vacia()const{
        if(Tam==-1)
            return true;
        return false;
    }

    int Llena() {
        return (Tam == MAX) ? 1 : 0; // 1 si la lista está llena, 0 en otro caso
    }

    void Muestra() {
        if (vacia()) {
            std::cout << "Lista vacía" << std::endl;
        } else {
            std::cout << Datos[Tam] << std::endl;
        }
    }
    void Apilar(Empleado& elem) {
        if (Tam + 1 < MAX) {
            Tam++;
            Datos[Tam] = elem;
        } else {
            std::cout << "No se puede apilar, lista llena" << std::endl;
        }
    }
Empleado& Desapilar() {
    if (vacia()) {
        std::cout << "No se puede desapilar, lista vacía" << std::endl;
        return Datos[Tam];
    }
    Tam--;
    return Datos[Tam];
}

    int Ultimo()const{
        return Tam;
    }
};

int main() {
    ListaEstatica lista;
    Empleado datosEmpleado;
    int opcion;
    int elemento, posicion, codigo;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Top" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: // Push
                std::cout << "Ingrese el elemento a agregar: ";
                std::cin >> datosEmpleado;
                lista.Apilar(datosEmpleado);
                break;

            case 2: // Pop
                if (lista.vacia()) {
                    std::cout << "Lista vacía" << std::endl;
                } else {
                    std::cout << "Elemento desapilado: " << lista.Desapilar() << std::endl;
                }
                break;

            case 3: // Top
                lista.Muestra();
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
