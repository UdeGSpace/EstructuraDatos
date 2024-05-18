#include "include/Cola.h"

persona::persona() : nombre("juanito"), carrera("sin especificar"), materiasAprobadas(0), promedioGeneral(0.0) {}
persona::persona(std::string n, std::string c, int materias, float promedio)
    : nombre(n), carrera(c), materiasAprobadas(materias), promedioGeneral(promedio) {}

void persona::operator=(const persona& x) {
    nombre = x.nombre;
    carrera = x.carrera;
    materiasAprobadas = x.materiasAprobadas;
    promedioGeneral = x.promedioGeneral;
}

std::ostream& operator<<(std::ostream& o, const persona& p) {
    o << "Nombre: " << p.nombre << "\t Carrera: " << p.carrera
      << "\t Materias Aprobadas: " << p.materiasAprobadas
      << "\t Promedio General: " << p.promedioGeneral << std::endl;
    return o;
}

std::istream& operator>>(std::istream& o, persona& p) {
    std::cout << "\n Inserta nombre: ";
    o >> p.nombre;
    std::cout << "\n Inserta carrera: ";
    o >> p.carrera;
    std::cout << "\n Inserta total de materias aprobadas: ";
    o >> p.materiasAprobadas;
    std::cout << "\n Inserta promedio general: ";
    o >> p.promedioGeneral;
    return o;
}

bool Cola::vacia() const {
    return ult == -1;
}

bool Cola::llena() const {
    return ult == TAM - 1;
}

int Cola::ultimo() const {
    return ult;
}

std::ostream& operator<<(std::ostream& o, const Cola& L) {
    int i = 0;
    std::cout << "\n";
    while (i <= L.ultimo()) {
        o << L.datos[i];
        i++;
    }
    return o;
}

void Cola::enqueue(const persona& elem) {
    inserta(elem, 0);
}

persona Cola::dequeue() {
    if (vacia()) {
        std::cout << "\n La cola está vacía" << std::endl;
        return persona(); // Devuelve una persona por defecto en caso de cola vacía
    } else {
        ult--;
        return datos[ult + 1];
    }
}

bool Cola::elimina(int pos) {
    if (vacia() || pos < 0 || pos > ult) {
        std::cout << "\n error de eliminación";
        return true;
    }
    int i = pos;
    while (i < ult) {
        datos[i] = datos[i + 1];
        i++;
    }
    ult--;
    return false;
}

int Cola::inserta(const persona& elem, int pos) {
    if (llena() || pos < 0 || pos > ult + 1) {
        std::cout << "\n Error de inserción";
        return 0;
    }
    int i = ult + 1;
    while (i > pos) {
        datos[i] = datos[i - 1];
        i--;
    }
    datos[pos] = elem;
    ult++;
    return 1;
}
