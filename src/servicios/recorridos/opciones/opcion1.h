#include "../../../clases/Grafo/Grafo.h"
#include "../src/anchura.h"

extern void clear(), pause(), loading();

Grafo anchura(Grafo G) {
    clear();
	string nombre;
    
	if (G.Vacio()){
        G.empty();
        return G;
    }

    cout << "Recorrido En Anchura: " << endl;
    G.ListaAdyacencia();
    cout << "Ingrese el nombre del vertice inicial: ";
    cin >> nombre;

    if (G.GetVertice(nombre) == NULL) {
        cout << "Ese vertice es invalido" << endl;
        pause();
        return G;
    }

    loading();

    recorridoAnchura(G.GetVertice(nombre));

	pause();
    return G;
}
