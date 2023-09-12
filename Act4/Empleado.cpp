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
    ListaEstatica():Tam(){}

    int Inserta(Empleado elemento, int posicion) {
        if (posicion < 0 || posicion > Tam || Tam == MAX) {
            return -1; // Error: Posición no válida o lista llena
        }

        for (int i = Tam; i > posicion; i--) {
            Datos[i] = Datos[i - 1]; // Desplaza los elementos a la derecha
        }

        Datos[posicion] = elemento;
        Tam++;
        return 0; // Éxito
    }

    int Agrega(Empleado elemento) {
        if (Tam == MAX) {
            return -1; // Error: Lista llena
        }

        Datos[Tam] = elemento;
        Tam++;
        return 0; // Éxito
    }

    int Busca(int elemento) {
        for (int i = 0; i < Tam; i++) {
            if (Datos[i].getClaveEmpleado() == elemento) {
                return i; // Elemento encontrado en la posición i
            }
        }
        return -1; // Elemento no encontrado
    }

    int Elimina(int posicion) {
        if (posicion < 0 || posicion >= Tam) {
            return -1; // Error: Posición no válida
        }

        for (int i = posicion; i < Tam - 1; i++) {
            Datos[i] = Datos[i + 1]; // Desplaza los elementos a la izquierda
        }

        Tam--;
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
        for (int i = 0; i < Tam; i++) {
            std::cout << Datos[i] << " ";}
            std::cout << std::endl;
    }
};

int main() {
    ListaEstatica lista;
    Empleado datosEmpleado;
    int opcion;
    int elemento, posicion, codigo;

    do {
        // Mostrar el menú
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Agrega" << std::endl;
        std::cout << "2. Buscar" << std::endl;
        std::cout << "3. Elimina" << std::endl;
        std::cout << "4. Inserta" << std::endl;
        std::cout << "5. Muestra" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: // Agrega
                std::cout << "Ingrese el elemento a agregar: ";
                std::cin >> datosEmpleado;
                lista.Agrega(datosEmpleado);
                break;

            case 2: // Buscar
                std::cout << "Ingrese el elemento a buscar: ";
                std::cin >> elemento;
                posicion = lista.Busca(elemento);
                if (posicion != -1) {
                    std::cout << "El elemento " << elemento << " se encuentra en la posición " << posicion << std::endl;
                } else {
                    std::cout << "El elemento " << elemento << " no se encuentra en la lista." << std::endl;
                }
                break;

            case 3: // Elimina
                std::cout << "Ingrese elcodigo del empleado a eliminar:  ";
                std::cin >> elemento;
                posicion = lista.Busca(elemento);
                if (lista.Elimina(posicion) == 0) {
                    std::cout << "Elemento eliminado correctamente." << std::endl;
                } else {
                    std::cout << "Error al eliminar el elemento." << std::endl;
                }
                break;

            case 4: // Inserta
                std::cout << "Ingresa los datos del empleado a insertar: ";
                std::cin >> datosEmpleado;
                std::cout << "Ingrese la posición en la que desea insertar: ";
                std::cin >> posicion;
                if (lista.Inserta(datosEmpleado, posicion) == 0) {
                    std::cout << "Elemento insertado correctamente." << std::endl;
                } else {
                    std::cout << "Error al insertar el elemento." << std::endl;
                }
                break;

            case 5: // Muestra
                lista.Muestra();
                break;

            case 6: // Salir
                std::cout << "Saliendo del programa." << std::endl;
                break;

            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }

    } while (opcion != 6);

    return 0;
}
