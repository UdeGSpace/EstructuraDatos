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
    friend std::ostream& operator<<( std::ostream&, persona&);
    friend std::istream& operator>>( std::istream&, persona&);
    bool operator==(persona&p){
        return p.nombre==nombre; 
    }
};

class Cola {
private:
    persona datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(const persona& elem, int pos);

public:
    Cola():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    int ultimo()const;
    friend std::ostream& operator<<(std::ostream & o, Cola& L);
    void enqueue(persona& elem);
    persona& dequeue();
    int busquedaLineal(persona&);
    int busquedaBinaria(persona&);

};

#endif // COLA_H