#ifndef _global
#define _global

#include <iostream>
#include <vector>
#include <string>

#define MAX 100
#define MAXX 100
#define MAXV 100 // Maxima cantidad de vertices.
#define oo 0x3f3f3f3f // Nuestro valor infinito.
#define INFINITY 9999

using namespace std;

struct OpcionSeleccionada {
	string desc;
	int num;
};

struct Edge {
	int node; // El nodo destino de la arista.
	int cost; // El costo de la arista.
	Edge(int _node, int _cost) : node(_node), cost(_cost) {} // Constructor parametrizado.
	Edge() : node(-1), cost(-1) {} // Constructor por defecto.
};

struct Graphd {
	vector<Edge> g[MAXV]; // Lista de adyacencias.
	int V; // Cantidad de vertices.
	int E; // Cantidad de arista
};

struct State {
	int node; // El nodo actual.
	int cost; // El peso de la arista.
	State(int _node, int _cost) : node(_node), cost(_cost) {} // Constructor .
	bool operator <(const State &b) const {
		return cost > b.cost;
	}
};

#endif
