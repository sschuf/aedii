#include "../../../clases/Grafo/Grafo.h"
#include "../src/eliminarVertice.h"

Grafo opcion5(Grafo G, int& num){
	G = eliminarVertice(G, num);
	return G;
}
