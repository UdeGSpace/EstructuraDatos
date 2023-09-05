#include <iostream>
#include <string>
using namespace std;

class Materia {
private:
    int Clave;
    string Nombre;
    string Profesor;
    string Libro;

public:
    Materia(int clave, const string& nombre, const string& profesor, const string& libro)
        : Clave(clave), Nombre(nombre), Profesor(profesor), Libro(libro) {}

    void imprime() const {
        cout << "Clave de la Materia: " << Clave << endl;
        cout << "Nombre de la Materia: " << Nombre << endl;
        cout << "Profesor: " << Profesor << endl;
        cout << "Libro: " << Libro << endl;
    }

    void cambiarClave(int clave) {
        Clave = clave;
    }

    void cambiarProfesor(const string& profesor) {
        Profesor = profesor;
    }

    // Sobrecarga de operadores
    bool operator==(const Materia& other) const {
        return Clave == other.Clave;
    }

    bool operator!=(const Materia& other) const {
        return Clave != other.Clave;
    }

    bool operator<(const Materia& other) const {
        return Clave < other.Clave;
    }

    bool operator>(const Materia& other) const {
        return Clave > other.Clave;
    }

    Materia operator+(const Materia& other) const {
        int nuevaClave = Clave + other.Clave;
        string nuevoNombre = Nombre + " " + other.Nombre;
        string nuevoProfesor = Profesor + " " + other.Profesor;
        string nuevoLibro = Libro + " " + other.Libro;
        return Materia(nuevaClave, nuevoNombre, nuevoProfesor, nuevoLibro);
    }

    friend ostream& operator<<(ostream& os, const Materia& materia) {
        os << "Clave de la Materia: " << materia.Clave << endl;
        os << "Nombre de la Materia: " << materia.Nombre << endl;
        os << "Profesor: " << materia.Profesor << endl;
        os << "Libro: " << materia.Libro << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Materia& materia) {
        cout << "Ingresa la clave de la materia: ";
        is >> materia.Clave;
        cout << "Ingresa el nombre de la materia: ";
        is >> materia.Nombre;
        cout << "Ingresa el profesor de la materia: ";
        is >> materia.Profesor;
        cout << "Ingresa el libro de la materia: ";
        is >> materia.Libro;
        return is;
    }
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

string Menu = "1. Cambiar clave de la materia Programación\n2. Cambiar nombre del profesor de la materia BasesDatos\n3. Imprimir datos de la materia BasesDatos\n4. Salir\n";

int main() {
    Materia Programacion(123, "Programación", "Jaime", "Algoritmos en C++");
    Materia BasesDatos(234, "BasesDatos", "Maria", "Fundamentos de Bases de Datos");

    int option = 0;
    while (option != 4) {
        string temp;
        cout << Menu;
        cin >> option;
        switch (option) {
        case 1:
            int nuevaClave;
            cout << "Ingresa la nueva clave de la materia Programación: ";
            cin >> nuevaClave;
            Programacion.cambiarClave(nuevaClave);
            break;
        case 2:
            cout << "Ingresa el nuevo nombre del profesor de la materia BasesDatos: ";
            cin.ignore(); // Limpiar el buffer antes de leer la cadena
            getline(cin, temp);
            BasesDatos.cambiarProfesor(temp);
            break;
        case 3:
            cout << BasesDatos;
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida. Ingresa un número del 1 al 4." << endl;
            break;
        }
    }

    return 0;
}
