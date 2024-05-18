#include <iostream>
#include <string>
using namespace std;

const int MAX = 100; // Tamaño máximo de la lista

class Aspirantes {
private:
    string Nombre;
    string Carrera;
    string Preparatoria;
    float Promedio;
    int id;

public:
    void imprime() const {
        cout << "Nombre del Alumnos: " << Nombre << endl;
        cout << "Carrera a la que aplica: " << Carrera << endl;
        cout << "Preparatoria donde estudio: " << Preparatoria << endl;
        cout << "Promedio obtenido: " << Promedio << endl;
    }

    // Sobrecarga de operadores
    bool operator ==(const Aspirantes& other) const {
        return id == other.id;
    }

    bool operator!=(const Aspirantes& other) const {
        return id != other.id;
    }

    friend ostream& operator<<(ostream& os, const Aspirantes& aspirante) {
        os << "Id del Aspirante: " << aspirante.id << endl;
        os << "Nombre: " << aspirante.Nombre << endl;
        os << "Carrera: " << aspirante.Carrera << endl;
        os << "Preparatoria: " << aspirante.Preparatoria << endl;
        os << "Promedio: " << aspirante.Promedio << endl;

        return os;
    }

    friend istream& operator>>(istream& is, Aspirantes& aspirante) {
        cout << "Ingresa el nombre del aspirante: ";
        is >> aspirante.Nombre;
        cout << "Ingresa la carrera: ";
        is >> aspirante.Carrera;
        cout << "Ingresa el nombre de la preparatoria: ";
        is >> aspirante.Preparatoria;
        cout << "Ingresa el promedio obtenido: ";
        is >> aspirante.Promedio;
        cout << "Ingresa el Id: ";
        is >> aspirante.id;
        return is;
    }

    float getPromedio() const {
        return Promedio;
    }
    
    int getId() const{
        return id;
    }
};

class ListaEstatica {
private:
    Aspirantes Datos[MAX];
    int Tam;

public:
    ListaEstatica(): Tam(0) {}

    // Función para realizar el particionamiento del Quicksort
    int Quick(int extizq, int extder) {
        float pivote = Datos[(extizq + extder) / 2].getPromedio();
        int i = extizq;
        int j = extder;

        while (i <= j) {
            while (Datos[i].getPromedio() > pivote) {
                i++;
            }
            while (Datos[j].getPromedio() < pivote) {
                j--;
            }
            if (i <= j) {
                swap(Datos[i], Datos[j]);
                i++;
                j--;
            }
        }
        return i;
    }


    // Función recursiva para realizar Quicksort
    void QuickSort(int extizq, int extder) {
        if (extizq < extder) {
            int pi = Quick(extizq, extder);
            QuickSort(extizq, pi - 1);
            QuickSort(pi, extder);
        }
    }

    int Inserta(Aspirantes elemento) {
        if (Tam == MAX) {
            return -1; // Error: Lista llena
        }

        // Inserta el elemento en la posición correcta según el promedio descendente
        int i = Tam - 1;
        while (i >= 0 && Datos[i].getPromedio() < elemento.getPromedio()) {
            Datos[i + 1] = Datos[i];
            i--;
        }
        Datos[i + 1] = elemento;
        Tam++;

        return 0; // Éxito
    }

int busquedaBinaria(int elem) {
    int i = 0;
    int j = Tam - 1;

    while (i <= j) {
        int medio = (i + j) / 2;

        if (Datos[medio].getId() == elem) {
            // Si encontramos el elemento, devolvemos la posición y salimos del bucle
            return medio;
        } else if (Datos[medio].getId() < elem) {
            // Si el elemento es mayor que el elemento medio, ajustamos el límite superior (j)
            j = medio - 1;
        } else {
            // Si el elemento es menor que el elemento medio, ajustamos el límite inferior (i)
            i = medio + 1;
        }
    }
    // Si llegamos aquí, significa que no encontramos el elemento en la lista
    return -1;
}



    bool vacia() const {
        if (Tam == 0)
            return true;
        return false;
    }

    int Llena() {
        return (Tam == MAX) ? 1 : 0; // 1 si la lista está llena, 0 en otro caso
    }

    void Muestra() const {
        for (int i = 0; i < Tam; i++) {
            std::cout << Datos[i] << " ";
        }
        std::cout << std::endl;
    }

    void MuestraElemento(int pos) const {
        std::cout << "ID de Aspirante: " << Datos[pos].getId() << std::endl;
        Datos[pos].imprime();
    }

    int getId() {
        return Tam;
    }
};

int main() {
    ListaEstatica lista;
    Aspirantes datosAspirante;
    int opcion;
    int elemento, posicion, codigo;

    do {
        // Mostrar el menú
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Buscar" << std::endl;
        std::cout << "2. Insertar" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: // Buscar
                if (lista.vacia()) {
                    std::cout << "Lista Vacia" << std::endl;
                } else {
                    std::cout << "Ingrese el Id a buscar: ";
                    std::cin >> elemento;
                    posicion = lista.busquedaBinaria(elemento);
                    if (posicion != -1) {
                        std::cout << "Su solicitud está en la posición: " << posicion << std::endl;
                        lista.MuestraElemento(posicion); // Utiliza un método para mostrar el elemento en la posición indicada
                        std::cout << std::endl;
                    } else {
                        std::cout << "El elemento " << elemento << " no se encuentra en la lista." << std::endl;
                    }
                }
                break;

            case 2: // Inserta
                std::cout << "Ingresa los datos del Aspirante. " << std::endl;
                std::cin >> datosAspirante;
                if (lista.Inserta(datosAspirante) == 0) {
                    std::cout << "Elemento insertado correctamente." << std::endl;
                } else {
                    std::cout << "Error al insertar el elemento." << std::endl;
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