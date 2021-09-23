#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <vector>
#define MAXV 100 // Maxima cantidad de vertices.
#define oo 0x3f3f3f3f // Nuestro valor infinito.
using namespace std ;




class Arista ;


class Vertice {
public : 	
Vertice *sig ;
Arista *ady;
string nombre ;
int numero ;
friend class Grafo ;

};



class Arista {
public : 	
Arista *sig ;
Vertice *ady ;
int peso;
friend class Grafo ;

};


class Grafo
{
Vertice *h ;
int constante  ;
	public:
		void Inicializa() ;
		bool Vacio() ;
		int Tamano() ;
		
		Vertice *GetVertice(string nombre) ;
		void InsertaArista(Vertice *origen , Vertice *destino , int peso  ) ;
		void InsertaVertice(string nombre , int num ) ;
		
		void ListaAdyacencia() ;
		void EliminarArista(Vertice *origen , Vertice *destino) ;
        void Anular() ;
        void EliminarVertice(Vertice *vert) ;
        void RecorridoAnchura(Vertice *origen) ;
        void RecorridoProfundidad(Vertice *origen ) ;
        void PrimeroAnchura(Vertice *origen , Vertice *destino ) ;
        void PrimeroProfundidad(Vertice *origen , Vertice *destino ) ;
        void PrimeroMejor(Vertice *origen , Vertice *destino ) ;
        int CantVert();
        int CantArist() ;
        int DijsOrigen(int origen) ;
        int DijsDestino(int destino) ;
        void RecorridoAristas( int x  ) ;
        void RecorridoAristasParaMatriz() ;
        string n(int x ) ;
        string nd(int x ) ;
        int perma(int x );
        int permb(int x );
        int permc(int x );
        int Matriz(int x , int i ) ;
        int Origen() ;
        int Destino() ;
        int Peso() ; 
        bool NombreExistente(string x) ;
        
       
};




#endif

