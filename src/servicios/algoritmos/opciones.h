/*
*	- No hace falta que retornen G los algoritmos
*/

#ifndef opciones_algoritmos
#define opciones_algoritmos

#include "opciones/opcion1.h"
#include "opciones/opcion2.h"
#include "opciones/opcion3.h"
#include "opciones/opcion4.h"

#include <stdio.h>
#include <conio.h>
#include <utility>
#include <algorithm>
#include <queue>

/* PRIM */
Grafo algoritmosOpcion1(Grafo G) {
	G = Prim(G);
	return G;
}


/* DIJKSTRA */
Grafo algoritmosOpcion2(Grafo G) {
	G = Dijkstra(G);
	return G;
}


// Kruskal
Grafo algoritmosOpcion3(Grafo G) {
	G = Kruskal(G);
	return G;
}


// Costo Mínimo
Grafo algoritmosOpcion4(Grafo G) {
	G = BestFirst(G);
	return G;
}

#endif
