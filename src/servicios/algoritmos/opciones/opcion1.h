#include "../../../clases/Grafo/Grafo.h"
#include "../src/Prim.h"

Grafo Prim(Grafo G){
	G = prim(G);
	return G;
}
