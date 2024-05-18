#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>

const int TAM = 100;

class persona {
private:
    std::string nombre;
    std::string carrera;
    int materiasAprobadas;
    float promedioGeneral;

public:
    persona();
    persona(std::string n, std::string c, int materias, float promedio);
    void operator=(const persona& x);
    friend std::ostream& operator<<(std::ostream& o, const persona& p);
    friend std::istream& operator>>(std::istream& o, persona& p);
};

class Cola {
private:
    persona datos[TAM];
    int ult;

    bool elimina(int pos);
    int inserta(const persona& elem, int pos);

public:
    Cola() : ult(-1) {}

    bool vacia() const;
    bool llena() const;
    int ultimo() const;
    friend std::ostream& operator<<(std::ostream& o, const Cola& L);

    void enqueue(const persona& elem);
    persona dequeue();
};

#endif // COLA_H