#include "../../../clases/Grafo/Grafo.h"
#include "../src/Kruskal.h"

#include <iostream>
#define MAX 100
#define MAXX 100
#define MAXV 100 // Maxima cantidad de vertices.
#include <algorithm>

extern void pause();

static const int MAXXXX = 1e4 + 5;
static pair <long long, pair<int, int> > p[MAXXXX];

static void initialize() {
    for(int i = 0;i < MAXXX;++i)
        id[i] = i;
}

Grafo Kruskal(Grafo G) {
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    nodes = G.CantVert();
    G.RecorridoAristas(nodes);
    edges = G.CantArist();

    for (int i = 0; i < edges; ++i) {
        x = G.perma(i);
        y = G.permb(i);
        weight = G.permc(i);

        p[i] = make_pair(weight, make_pair(x, y));
    }

    // Ordena los Aristas en orden ascendente
    sort(p, p + edges);
    minimumCost = kruskal(p, edges);
    cout << "Costo Minimo Kurskal : " << endl;
    cout << minimumCost << endl;

    pause();
    return G;
}
