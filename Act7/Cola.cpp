#include "include/Cola.h"

persona::persona(){}
persona::persona(std::string n, std::string c, int materias, float promedio)
    : nombre(n), carrera(c), materiasAprobadas(materias), promedioGeneral(promedio) {}

void persona::operator=(const persona& x) {
    nombre = x.nombre;
    carrera = x.carrera;
    materiasAprobadas = x.materiasAprobadas;
    promedioGeneral = x.promedioGeneral;
}


std::ostream& operator<<(std::ostream& o, persona& p) {
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

std::ostream& operator<<(std::ostream & o, Cola& L)
{
    int i=0;
    std::cout<<"\n";
    while(i<=L.ultimo())
    {
        ;
        o<<L.datos[i];
        i++;
    }
    return o;
}

void Cola::enqueue(persona& elem)
{
    inserta(elem,0);
}

persona& Cola::dequeue()
{
    if(vacia()){
        std::cout<<"\n La cola esta vacia"<<std::endl;
    }
    else{
        ult--;
        return datos[ult+1];
    }
}

bool Cola::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n error de eliminacion";
        return true;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
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

int Cola::busquedaLineal(persona& elem){
    if(vacia()){
        std::cout << "Solicitud no encontrada" << std::endl;
        return -1;
    }
    for(int i=0; i<=ult; i++){
        if(elem==datos[i]){
            std::cout << "Su solicitud esta en la posicion: "<< ult-i << std::endl;
            return i;
        }
    }
}

int Cola::busquedaBinaria(persona& elem) {
    int i = 0;
    int j = ult;

    while (i <= j) {
        int medio = (i + j) / 2;

        if (datos[medio] == elem) {
            // Si encontramos el elemento, devolvemos la posición y salimos del bucle
            std::cout << "Su solicitud está en la posición: " << ult - i << std::endl;
            return medio;
        } else if (i < medio) {
            // Si el elemento es menor que el elemento medio, ajustamos el límite superior (j)
            j = medio - 1;
        } else {
            // Si el elemento es mayor que el elemento medio, ajustamos el límite inferior (i)
            i = medio + 1;
        }
    }

    // Si llegamos aquí, significa que no encontramos el elemento en la cola
    std::cout << "La solicitud no fue encontrada en la cola." << std::endl;
    return -1;
}


