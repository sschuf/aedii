#ifndef foo_h__2
#define foo_h__2

#include "../../../clases/Grafo/Grafo.h"
#include "../src/agregarArista.h"

inline Grafo opcion2(Grafo G){
	G = agregarArista(G);
	return G;
}

#endif
