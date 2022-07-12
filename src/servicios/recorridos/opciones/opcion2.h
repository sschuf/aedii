#include "../../../clases/Grafo/Grafo.h"
#include "../src/profundidad.h"

extern void clear(), pause(), loading();

Grafo profundidad(Grafo G) {
	clear();
    string nombre;

    if (G.Vacio()) {
        G.empty();
        return G;
    }

    cout << "Recorrido En Profundidad  : " << endl;
    G.ListaAdyacencia();
    cout << "Ingrese el nombre del vertice inicial: ";
    cin >> nombre;

    if (G.GetVertice(nombre) == NULL) {
        cout << "Ese vertice es invalido" << endl;
        pause();
        return G;
    }

    loading();

    recorridoProfundidad(G.GetVertice(nombre));

    pause();
    return G;
}
