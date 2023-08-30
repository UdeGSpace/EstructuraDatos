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

    void imprime() {
        cout << "Clave: " << Clave << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Profesor: " << Profesor << endl;
        cout << "Libro: " << Libro << endl;
    }

    void cambiarClave(int clave) {
        Clave = clave;
    }

    void cambiarProfesor(const string& profesor) {
        Profesor = profesor;
    }
};
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
string Menu = "1. Cambiar clade de materia \n2. Cambiar nombre de Profesor de Bases de Datos\n3. Impirmir datos de la Materia Base de datos\n4. Salir\n";


int main() {
    Materia Programacion(123, "Programacion", "Jaime", "Algoritmos en C++");
    Materia BaseDatos(1234, "Base de datos", "Jaime", "Estructuras");
    int option = 0, nuevaClave;
    string temp;
    while (option!=5){
        cout<< Menu<< endl;
        cin>>option;
        switch (option)
        {
        case 1:
            cout<< "Ingresa la nueva clave: ";
            cin>> nuevaClave;
            Programacion.cambiarClave(nuevaClave);
            break;
        case 2:
            cout<< "Ingresa el nombre del nuevo profesor: ";
            cin>> temp;    
            BaseDatos.cambiarProfesor(temp);        
            break;
        case 3:
            BaseDatos.imprime();
        default:
            break;
        }
    }
    
}