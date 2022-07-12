#ifndef opciones_recorridos
#define opciones_recorridos

#include "opciones/opcion1.h"
#include "opciones/opcion2.h"

Grafo recorridosOpcion1(Grafo G) {
	G = anchura(G);
	cin.ignore();
	return G;
}

Grafo recorridosOpcion2(Grafo G) {
	G = profundidad(G);
	cin.ignore();
	return G;
}

#endif
