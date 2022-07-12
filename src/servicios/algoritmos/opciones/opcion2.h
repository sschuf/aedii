/*
*	Algoritmo de Dijkstra - Camino más corto
*/

#include "../src/Dijkstra.h"

Grafo Dijkstra(Grafo G) {
	clear();

    int verticestotales = 0, aristastotales = 0;
    verticestotales = G.CantVert();
    aristastotales = G.CantArist();
    cout << "Cantidad de vertices "
         << " " << verticestotales << endl;
    cout << "Aristas Totales :  "
         << " " << aristastotales << endl;

    bool out = false;
    char salir;

    Graphd graph;

    int opc;
    int V, E, o[50];
    int comienzo, fin;
    string nom, nomd;

    V = G.CantVert();
    E = G.CantArist();

    graph.V = V;
    graph.E = E;
    cout << " V "
         << " " << V << endl;
    cout << " E "
         << " " << E << endl;

    G.RecorridoAristas(V);

    for (int i = 0; i < E; ++i) {
        int a, b, c, x;

        int Origen, Destino, Peso;

        nom = G.n(i);
        nomd = G.nd(i);
        Origen = G.perma(i);
        Destino = G.permb(i);
        Peso = G.permc(i);

        cout << " " << endl;
        if (i < V) {
            cout << "Remplazar En El Siguente Ingreso El Origen " << nom << " "
                 << "por: " << Origen << endl;
            cout << "Remplazar En El Siguente Ingreso El Destino " << nomd << " "
                 << "por: " << Destino << endl;
        }

        graph.g[Origen].push_back(Edge(Destino, Peso));
        graph.g[Destino].push_back(Edge(Origen, Peso));
    }

    cout << "Ingrese Vertice Inicial: " << endl;
    cin >> comienzo;
    cout << "Ingrese Vertice Final: " << endl;
    cin >> fin;

    int n = dijkstra(comienzo, fin, graph);
    cout << "Longitud del Camino mas Corto: " << n << endl;
    
    pause();

	return G;
}
