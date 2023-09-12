#include <iostream>

const int MAX = 100; // Tamaño máximo de la lista

template <typename T>
class ListaEstatica {
private:
    T Datos[MAX];
    int Tam;

public:
    ListaEstatica() {
        Tam = 0;
    }

    int Inserta(T elemento, int posicion) {
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

    int Agrega(T elemento) {
        if (Tam == MAX) {
            return -1; // Error: Lista llena
        }

        Datos[Tam] = elemento;
        Tam++;
        return 0; // Éxito
    }

    int Busca(T elemento) {
        for (int i = 0; i < Tam; i++) {
            if (Datos[i] == elemento) {
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

    int Vacia() {
        return (Tam == 0) ? 1 : 0; // 1 si la lista está vacía, 0 en otro caso
    }

    int Llena() {
        return (Tam == MAX) ? 1 : 0; // 1 si la lista está llena, 0 en otro caso
    }

    void Muestra() {
        for (int i = 0; i < Tam; i++) {
            std::cout << Datos[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    ListaEstatica<int> lista;

    int opcion;
    int elemento, posicion;

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
                std::cin >> elemento;
                lista.Agrega(elemento);
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
                std::cout << "Ingrese la posición del elemento a eliminar: ";
                std::cin >> posicion;
                if (lista.Elimina(posicion) == 0) {
                    std::cout << "Elemento eliminado correctamente." << std::endl;
                } else {
                    std::cout << "Error al eliminar el elemento." << std::endl;
                }
                break;

            case 4: // Inserta
                std::cout << "Ingrese el elemento a insertar: ";
                std::cin >> elemento;
                std::cout << "Ingrese la posición en la que desea insertar: ";
                std::cin >> posicion;
                if (lista.Inserta(elemento, posicion) == 0) {
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
