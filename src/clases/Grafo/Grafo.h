#ifndef grafo
#define grafo

#include "../Monticulo/Monticulo.h"

#include <string>
#include <queue>
#include <list>
#include <stack>
#include <vector>

using namespace std;

void showlist(list<int> g);
int ListToVectorOrigin(int x);

class Arista;

class Vertice {
	public:
	    Vertice *sig;
	    Arista *ady;
	    string nombre;
	    int numero;
	    int valor;
};

class Arista {
	public:
	    Arista *sig;
	    Vertice *ady;
	    int peso;
	    friend class Grafo;
};

class Grafo {
    Vertice *h;
    int constante;

	public:
	    void Inicializa();
	    bool Vacio();
	    int Tamano();
	    
	    void empty();
	
	    Vertice *GetVertice(string nombre);
	
	    void InsertaArista(Vertice *origen, Vertice *destino, int peso);
	    void InsertaVertice(string nombre, int num, int valor);
	    void ListaAdyacencia();
	    void EliminarArista(Vertice *origen, Vertice *destino, int check);
	    void Anular();
	    int EliminarVertice(Vertice *vert);
	    void PrimeroAnchura(Vertice *origen, Vertice *destino);
	    void PrimeroProfundidad(Vertice *origen, Vertice *destino);
	    void Monticulo();
	    bool CheckAristas(string origen, string destino);
	    int CantVert();
	    int CantArist();
	    void RecorridoAristas(int x);
	    void NumANom(int x);
	    void RecorridoAristasParaMatriz();
	    string n(int x);
	    string nd(int x);
	    int perma(int x); // esta funcion recibe una posicion y devuelve el contenido del vector de vertices origenes que se solicito por la posicion recibida
	    int permb(int x); // esta funcion recibe una posicion y devuelve el contenido del vector de vertices destino que se solicito por la posicion recibida
	    int permc(int x); // esta funcion recibe una posicion y devuelve el contenido del vector de peso de la conexion de las aristas destino origen
	    int Matriz(int x, int i);
	    int Origen();
	    int Destino();
	    int Peso();
	    bool NombreExistente(string x);
};

#endif