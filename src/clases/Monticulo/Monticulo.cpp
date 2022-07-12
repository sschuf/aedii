

#include "Monticulo.h"
#include "../Grafo/Grafo.h"

using namespace std;

Heap::Heap(int tam) : capacidad(tam), iUltimo(0) {
    heap = new int[tam];
}

Heap::Heap(int *vec, int tam) : capacidad(tam), iUltimo(tam) {
    heap = new int[capacidad];
    for(int i = 0; i < iUltimo; i++) heap[i] = vec[i];
    Convertir();
}

Heap::Heap(Heap &h) : capacidad(h.capacidad), iUltimo(h.iUltimo) {
    heap = new int[capacidad];
    for(int i = 0; i < iUltimo; i++) heap[i] = h.heap[i];
}

Heap::~Heap() {
    delete[] heap;
}


void Heap::Convertir() {
    for(int i = iUltimo/2; i >= 0 ; i--) {
        Bajar(i);
    }
}

void Heap::Insertar(int v) {
    if(iUltimo >= capacidad) Reubicar(capacidad*2);

    heap[iUltimo++] = v;
    Subir(iUltimo-1);
}

void Heap::Borrar(int i) {
    if(i < iUltimo) {
        heap[i] = heap[--iUltimo];
        Bajar(i);
    }
}

int Heap::ExtraerMaximo() {
    int retval = heap[0];

    Borrar(0);

    return retval;
}

void Heap::Reubicar(int ncap) {
    int *heap2;

    heap2 = new int[ncap];
    for(int i = 0; i < iUltimo; i++) heap2[i] = heap[i];
    if(heap) delete[] heap;
    heap = heap2;
    capacidad = ncap;
}

void Heap::Intercambia(int i1, int i2) {
    int aux;

    aux = heap[i1];
    heap[i1] = heap[i2];
    heap[i2] = aux;
}

// Algoritmo no recursivo para subir
void Heap::Subir(int i) {
    int iPadre;

    while(i > 0 && heap[i] > heap[iPadre=Padre(i)]) {
        Intercambia(i, iPadre);
        i = iPadre;
    }
}

void Heap::Bajar(int i){
    int iIzq, iDer, maximo;

    maximo = i;
    do{
        i = maximo;
        iIzq=Izquierdo(i);
        iDer=Derecho(i);
        if(iDer < iUltimo && heap[iDer] > heap[maximo]) maximo = iDer;
        if(iIzq < iUltimo && heap[iIzq] > heap[maximo]) maximo = iIzq;
        if(i != maximo) Intercambia(i, maximo);
    } while (i != maximo && maximo < iUltimo/2);
}

void Heap::Mostrar() {
	
    if(Vacio()) cout << "Heap vacio" << endl;
    else {
        for(int i = 0; i < iUltimo; i++) cout << heap[i] << ",";
        cout << endl;
    }
}


