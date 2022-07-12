#include "../../../clases/Grafo/Grafo.h"
#include "../src/eliminarArista.h"

Grafo opcion6(Grafo G){
	G = eliminarArista(G);
	return G;
}
