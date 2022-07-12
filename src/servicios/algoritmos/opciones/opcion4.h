#include "../../../clases/Grafo/Grafo.h"
#include "../src/BestFirst.h"

extern void clear(), pause();

Grafo BestFirst(Grafo G) {
    string origen, destino;

	clear();
	if (G.Vacio()) {
        G.empty();
        return G;
    }

    G.ListaAdyacencia();
    cout << "Ingrese el nombre del vertice origen: ";
    cin >> origen;
    cout << "Ingrese el nombre del vertice destino: ";
    cin >> destino;
    
    if (G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL) {
        cout << "Vertices invalidos" << endl;
        pause();
        return G;
    }

    primeroMejor(G.GetVertice(origen), G.GetVertice(destino));

	pause();    
    return G;
}
