#ifndef foo_h__
#define foo_h__

#include "../../../clases/Grafo/Grafo.h"
#include "../src/agregarVertice.h"

inline Grafo opcion1(Grafo G, int& temp, int& num){
	G = agregarVertice(G, temp, num);
	return G;
}

#endif
