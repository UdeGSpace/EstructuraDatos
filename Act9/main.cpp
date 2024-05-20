#include <iostream>
#include <string>

// Definición de la clase SocioClub
class SocioClub {
private:
    int NumeroSocio;
    std::string NombreSocio;
    std::string Domicilio;

public:
    // Constructores
    SocioClub() : NumeroSocio(0), NombreSocio(""), Domicilio("") {}
    SocioClub(int numSocio, const std::string& nombre, const std::string& domicilio)
        : NumeroSocio(numSocio), NombreSocio(nombre), Domicilio(domicilio) {}

    // Métodos de acceso
    int getNumeroSocio() const { return NumeroSocio; }
    void setNumeroSocio(int numSocio) { NumeroSocio = numSocio; }
    std::string getNombreSocio() const { return NombreSocio; }
    void setNombreSocio(const std::string& nombre) { NombreSocio = nombre; }
    std::string getDomicilio() const { return Domicilio; }
    void setDomicilio(const std::string& domicilio) { Domicilio = domicilio; }

    // Sobrecarga del operador de comparación para ordenar los socios por número
    bool operator<(const SocioClub& otro) const {
        return NumeroSocio < otro.NumeroSocio;
    }

    // Método para imprimir los datos del socio
    void imprimir() const {
        std::cout << "Número de Socio: " << NumeroSocio << ", Nombre: " << NombreSocio << ", Domicilio: " << Domicilio << std::endl;
    }
};

// Declaración de la lista simplemente ligada
template<class T>
class LSLSE;

// Declaración de la clase node
template<class T>
class node {
private:
    T data;
    node<T>* sig;
public:
    node() : sig(nullptr) {};
    friend class LSLSE<T>;
};

// Definición de la lista simplemente ligada
template<class T>
class LSLSE {
private:
    node<T>* lista;
public:
    LSLSE() : lista(nullptr) {};
    bool vacia() const;
    node<T>* ultimo() const;
    node<T>* primero() const;
    node<T>* anterior(node<T>* pos) const;
    node<SocioClub>* buscarId(const int& NumeroSocio) const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir() const;

    // Declaraciones de los nuevos métodos
    int contarSocios() const;
    SocioClub* buscarPorNombre(const std::string& nombre) const;
    SocioClub* buscarPorDomicilio(const std::string& domicilio) const;
};

// Implementación de los nuevos métodos

template<class T>
int LSLSE<T>::contarSocios() const {
    int count = 0;
    node<T>* aux = lista;
    while (aux != nullptr) {
        count++;
        aux = aux->sig;
    }
    return count;
}

template<class T>
node<SocioClub>* LSLSE<T>::buscarId(const int& NumeroSocio) const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        if (aux->data.getNumeroSocio() == NumeroSocio) {
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}

template<class T>
SocioClub* LSLSE<T>::buscarPorNombre(const std::string& nombre) const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        if (aux->data.getNombreSocio() == nombre) {
            return &(aux->data);
        }
        aux = aux->sig;
    }
    return nullptr;
}

template<class T>
SocioClub* LSLSE<T>::buscarPorDomicilio(const std::string& domicilio) const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        if (aux->data.getDomicilio() == domicilio) {
            return &(aux->data);
        }
        aux = aux->sig;
    }
    return nullptr;
}

template<class T>
void LSLSE<T>::imprimir() const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        aux->data.imprimir();  // Llamamos al método imprimir de SocioClub
        aux = aux->sig;
    }
}


template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

void mostrarMenu() {
    std::cout << "\nMenú de Opciones:" << std::endl;
    std::cout << "1. Registrar un nuevo socio" << std::endl;
    std::cout << "2. Dar de baja un socio del club" << std::endl;
    std::cout << "3. Generar un reporte con los datos de todos los socios" << std::endl;
    std::cout << "4. Buscar socio por nombre" << std::endl;
    std::cout << "5. Buscar socio por domicilio" << std::endl;
    std::cout << "6. Calcular e imprimir el total de socios registrados" << std::endl;
    std::cout << "7. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int main() {
    LSLSE<SocioClub> listaSocios;
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        switch (opcion) {
            case 1: {
                int numSocio;
                std::string nombre, domicilio;
                std::cout << "Ingrese el número de socio: ";
                std::cin >> numSocio;
                std::cout << "Ingrese el nombre del socio: ";
                std::cin.ignore(); // Para limpiar el buffer del teclado
                std::getline(std::cin, nombre);
                std::cout << "Ingrese el domicilio del socio: ";
                std::getline(std::cin, domicilio);
                SocioClub nuevoSocio(numSocio, nombre, domicilio);
                listaSocios.insertar(listaSocios.ultimo(), nuevoSocio);
                std::cout << "Socio registrado exitosamente." << std::endl;
                break;
            }
            case 2: {
                int numSocio;
                std::cout << "Ingrese el número de socio a dar de baja: ";
                std::cin >> numSocio;
                
                // Buscar el nodo que contiene al socio por su número de socio
                node<SocioClub>* nodoSocio = listaSocios.buscarId(numSocio);
                
                // Verificar si se encontró el nodo
                if (nodoSocio != nullptr) {
                    // Eliminar el nodo de la lista
                    listaSocios.eliminar(nodoSocio);
                    std::cout << "Socio dado de baja exitosamente." << std::endl;
                } else {
                    std::cout << "No se encontró ningún socio con ese número." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "\nReporte de Socios:" << std::endl;
                listaSocios.imprimir();
                break;
            }
            case 4: {
                std::string nombre;
                std::cout << "Ingrese el nombre del socio a buscar: ";
                std::cin.ignore(); // Para limpiar el buffer del teclado
                std::getline(std::cin, nombre);
                SocioClub* socioEncontrado = listaSocios.buscarPorNombre(nombre);
                if (socioEncontrado != nullptr) {
                    socioEncontrado->imprimir();
                } else {
                    std::cout << "No se encontró ningún socio con ese nombre." << std::endl;
                }
                break;
            }
            case 5: {
                std::string domicilio;
                std::cout << "Ingrese el domicilio del socio a buscar: ";
                std::cin.ignore(); // Para limpiar el buffer del teclado
                std::getline(std::cin, domicilio);
                SocioClub* socioEncontrado = listaSocios.buscarPorDomicilio(domicilio);
                if (socioEncontrado != nullptr) {
                    socioEncontrado->imprimir();
                } else {
                    std::cout << "No se encontró ningún socio con ese domicilio." << std::endl;
                }
                break;
            }
            case 6: {
                int totalSocios = listaSocios.contarSocios();
                std::cout << "Total de socios registrados: " << totalSocios << std::endl;
                break;
            }
            case 7: {
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            }
            default:
                std::cout << "Opción no válida. Por favor, seleccione una opción del menú." << std::endl;
        }
    } while (opcion != 7);

    return 0;
}
