#ifndef monticulo
#define monticulo

#include "../Grafo/Grafo.h"

#include <iostream>
#include <cstdlib>

//using namespace std;

class Heap {
    public:
        Heap(int tam=10);
        Heap(int *vec, int tam);
        Heap(Heap &);
        ~Heap();
        void Convertir();
        void Insertar(int v);
        void Borrar(int i);
        int ExtraerMaximo();
        bool Vacio() { return iUltimo == 0; }
        void Mostrar();
        int iUltimo;
        int *heap;
        int capacidad;

    private:
        void Reubicar(int ncap);
        void Intercambia(int i1, int i2);
        void Subir(int i);
        void Bajar(int i);
        int Padre(int i) { return (i-1)/2; }
        int Izquierdo(int i) { return 2*i+1; }
        int Derecho(int i) { return 2*i+2; }
};

#endif

