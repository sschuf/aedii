#ifndef opciones_customizar
#define opciones_customizar

#include "opciones/opcion1.h"
#include "opciones/opcion2.h"
#include "opciones/opcion3.h"
#include "opciones/opcion4.h"
#include "opciones/opcion5.h"
#include "opciones/opcion6.h"
#include "opciones/opcion7.h"

Grafo customizarOpcion1(Grafo G, int& temp, int& num) {
	G = opcion1(G, temp, num);
	return G;
}

Grafo customizarOpcion2(Grafo G) {
	G = opcion2(G);
	return G;
}

Grafo customizarOpcion3(Grafo G) {
	G = opcion3(G);
	return G;
}

Grafo customizarOpcion4(Grafo G) {
	G = opcion4(G);
	return G;
}

Grafo customizarOpcion5(Grafo G, int& num) {
	G = opcion5(G, num);
	return G;
}

Grafo customizarOpcion6(Grafo G){
	G = opcion6(G);
	return G;
}

Grafo customizarOpcion7(Grafo G) {
	G = opcion7(G);
	return G;
}

#endif
