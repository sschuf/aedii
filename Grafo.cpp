#include "Grafo.h"
#include <iostream>
using namespace std;






int TempMat[100][100] = {}  ;
int v[50] ;
int b[50] ;
int c[50] ;


string nombres[100] = {} ;
string nombresd[100] = {} ;


void Grafo::Inicializa() 
{


h= NULL ;
	
}

bool Grafo::Vacio() 
{
	
if (h == NULL)
 {	
return true ;
}
else
{
return false ;
}
	
}



int Grafo::Tamano()
{

	int cont = 0 ;
Vertice *aux;
aux = h ;
while (aux != NULL) 
{
cont++;
aux = aux->sig ;
}
return cont;


	


}




bool Grafo::NombreExistente(string x)
{
Vertice *aux ;
aux = h ;
while(aux != NULL)
{
	
if (aux->nombre == x )
{
cout << "Ya cargaste un Vertice con ese Nombre , Cambialo Por Otro " << endl ;	
return 0 ;
}

aux = aux->sig ;
}
return 1 ;
	
}



Vertice *Grafo::GetVertice(string nombre)
{
Vertice *aux ;
aux = h ;
while(aux != NULL)
{
	
if (aux->nombre == nombre )
{
return aux ;
}
aux = aux->sig ;

}
return NULL ;
	
}


void Grafo::InsertaVertice(string nombre , int num)
{
	
Vertice *nuevo = new Vertice ;
nuevo->nombre = nombre ;
nuevo->sig = NULL ;
nuevo->ady = NULL ;
nuevo->numero  = num ;
if(Vacio ())
{
h = nuevo ;	
}
else 	
{
Vertice *aux ;
aux = h ;
while(aux->sig != NULL)
{
	aux = aux->sig ;	

}
aux->sig = nuevo ;
}
}


int Grafo::DijsOrigen(int origen)
{
int x = 0 ;
x = origen ;	
return x ;		
}


int Grafo::DijsDestino(int destino)
{
int x = 0 ;
x = destino ;	
return x ;		
}




void Grafo::InsertaArista(Vertice *origen , Vertice *destino , int peso)
{

Arista *nueva =new Arista ;
nueva->peso = peso;
nueva->sig = NULL ;
nueva->ady = NULL ;

Arista *aux ;
aux = origen->ady ;

if(aux ==NULL) 
{
origen->ady = nueva ;
nueva->ady = destino ;
}
else
{
while(aux->sig != NULL)
{
aux = aux->sig ;
}
aux->sig = nueva;
nueva->ady = destino;
}
}






void Grafo::RecorridoAristas( int x    )
{
	


Vertice *VertAux;
Arista *ArisAux;
int num = 0  ;
string nom , nomd;
VertAux = h;
int destino = 0 ;
int peso = 0 ;
int k = CantArist() ;
int i = 0 ; 



while (VertAux != NULL )
{
ArisAux = VertAux->ady ;
while (ArisAux != NULL) 
{
cout << "Nombre Del Vertice Origen:  " <<  VertAux->nombre<< endl ;
nom = VertAux->nombre ;
nombres[i] = nom  ;

num = VertAux->numero ;

cout<< "Nombre Del Vertice Destino: " << ArisAux->ady->nombre<< endl ;
destino = ArisAux->ady->numero ;


cout << VertAux->nombre<<"----" << ArisAux->peso << "------>" << " " <<  ArisAux->ady->nombre ; 
nomd = ArisAux->ady->nombre ;
nombresd[i] = nomd ;
peso = ArisAux->peso ;
cout << " " << endl ;
cout << "Peso: " << peso << endl ;
cout << " " << endl ;

v[i] = num ;
b[i] = destino ;
c[i] = peso ;
 
TempMat[num][destino] = peso ;


ArisAux = ArisAux ->sig ;
i++ ;
}




VertAux = VertAux->sig ;



}	
}

int Grafo::Matriz(int x , int i )
{
	



return TempMat[x][i]  ;
}



string Grafo::n(int x )
{
Vertice *VertAux;
Arista *ArisAux;
VertAux = h;
int Vert = 0  ;
string f ;
f = nombres[x]  ;
return f ;
}


string Grafo::nd(int x )
{
Vertice *VertAux;
Arista *ArisAux;
VertAux = h;
int Vert = 0  ;
string f ;
f = nombresd[x]  ;
return f ;
}

int Grafo::perma(int x )
{
Vertice *VertAux;
Arista *ArisAux;
VertAux = h;
int Vert = 0  ;
int f ;
f = v[x]  ;
return f ;
}




int Grafo::permb(int x )
{
Vertice *VertAux;
Arista *ArisAux;
VertAux = h;
int Vert = 0  ;
int f ;
f = b[x]  ;
return f ;
}


int Grafo::permc(int x )
{
Vertice *VertAux;
Arista *ArisAux;
VertAux = h;
int Vert = 0  ;
int f ;
f = c[x]  ;
return f ;
}


int Grafo::CantVert()
{
Vertice *VertAux;
Arista *ArisAux;
VertAux = h;
int Vert = 0  ;

while (VertAux != NULL )
{
	
ArisAux = VertAux->ady ;

while (ArisAux != NULL) 
{

ArisAux = ArisAux ->sig ;

}
VertAux = VertAux->sig ;
	
Vert++ ;

}
return Vert ;
Vert = 0 ;
}

int Grafo::CantArist()
{
Vertice *VertAux;
Arista *ArisAux;
VertAux = h;
int Arist = 0  ;

while (VertAux != NULL )
{

ArisAux = VertAux->ady ;

while (ArisAux != NULL) 
{

ArisAux = ArisAux ->sig ;
Arist++ ;
}
VertAux = VertAux->sig ;
	


}
return Arist ;
Arist = 0 ;
}

	








void Grafo::ListaAdyacencia()
{
Vertice *VertAux;
Arista *ArisAux;
VertAux = h;
while (VertAux != NULL )
{
cout << VertAux->nombre<<"->";	
ArisAux = VertAux->ady ;
while (ArisAux != NULL) 
{
cout<<ArisAux->ady->nombre<<"->" ;
cout << " Peso: " << ArisAux->peso  ;
ArisAux = ArisAux ->sig ;

}
VertAux = VertAux->sig ;
cout << endl ;	
}

}

void Grafo::Anular()
{
Vertice *aux ;

while(h != NULL)
{
aux = h ;
h= h->sig ;	
delete(aux) ;
}
}

void Grafo::EliminarArista(Vertice *origen , Vertice *destino) 
{
	int band = 0 ;	
Arista *actual , *anterior ; 
actual = origen->ady ;

if (actual == NULL) 
{
cout <<"El Vertice origen no tiene aristas " << endl ;
	
}
else if (actual->ady == destino ) 
{
origen->ady = actual->sig ;
delete(actual) ;
}	
else
{
while (actual != NULL  )
{
  if (actual->ady == destino) 
  {
  band = 1 ;	
  anterior->sig = actual->sig ;
delete (actual) ;
break ;	
  }
   anterior = actual ; 
   actual = actual->sig ; 	
}	
if (band == 0 ) 
{
cout << "Esos dos vertices no estan conectados " << endl ;	
	
}
}	
}


void Grafo::EliminarVertice(Vertice *vert) 
{
Vertice *actual , *anterior ;
Arista *aux ;

actual = h ; 
while (actual != NULL)
{
	
aux = actual->ady ; 
while(aux != NULL)	{
if (aux->ady == vert )
{
	EliminarArista(actual , aux->ady ) ;
	break ;
	}	
aux = aux->sig ;	
}
actual =actual->sig ;	
}
 actual = h ;
 if (h == vert ) 
 {
 h = h->sig ;
 delete (actual) ;	
 }
else 
{
while (actual != vert ) 
{
anterior = actual ;	
actual = actual->sig ;	
	
	}	
anterior->sig = actual->sig ;
delete(actual) ;	
	
 } 
 	
}
 
void Grafo::RecorridoAnchura(Vertice *origen) 
{
int band  ;
Vertice *actual ;
queue <Vertice*> cola ;
list<Vertice*>lista;
list<Vertice*>::iterator i ;	
cola.push(origen) ;


while(!cola.empty()) 
{
	
int band = 0 , band2 = 0 ;	
actual = cola.front() ;
cola.pop() ;	
for (i = lista.begin(); i != lista.end(); i++  )
{
 if(*i == actual ) {
 band = 1 ;	
 } 	
}
if (band == 0 ) 
{
cout <<actual->nombre<<", " ;
lista.push_back(actual) ;	
}
Arista *aux ;
aux = actual->ady ;
while(aux != NULL) 
{
band2= 0 ;	
for(i=lista.begin() ; i!=lista.end(); i++ )
{
if (aux->ady == *i)	
{
band2 = 1 ;
}
}
if (band2 == 0 ) 
{
cola.push(aux->ady) ;	
} 	
aux = aux ->sig ;
	
}	
}
}

void Grafo::RecorridoProfundidad(Vertice *origen) 
{
int band = 0  , band2 = 0 ;	
Vertice *actual;
stack<Vertice*> pila;
list<Vertice*> lista;
list<Vertice*>::iterator i;

pila.push(origen) ;

while(!pila.empty())
{
band = 0 ;	
actual = pila.top() ;
pila.pop() ;
for (i = lista.begin() ; i!=lista.end() ; i++)	
{
if (*i == actual )	
{
band = 1 ;	
}
}
if (band == 0)
{
cout << actual->nombre<< ", " ;
lista.push_back(actual)	;
Arista *aux ;
aux = actual->ady;

while (aux != NULL) 
{
band2 = 0 ;	
for (i=lista.begin(); i!=lista.end() ; i++ ) 
{
if (*i == aux->ady )
{
band2 = 1 ;	
}	
}
if (band2 == 0)
{
pila.push(aux->ady) ;	
}	
aux = aux->sig ;	
}
}



}	
}

void Grafo::PrimeroAnchura(Vertice *origen , Vertice *destino ) 
{
	int band,band2 ,band3 = 0  ;
Vertice *VerticeActual , *DestinoActual;
Arista *aux ;
typedef pair<Vertice*,Vertice*>  VerticeVertice;
queue<Vertice*> cola;
stack<VerticeVertice> pila;
list<Vertice*> lista;
list<Vertice*>::iterator i;
cola.push(origen) ;

while(!cola.empty())
{
VerticeActual = cola.front() ;
cola.pop() ;

for(i=lista.begin(); i!=lista.end(); i++)
{
if (VerticeActual == *i) 
{
band = 1 ;	
}
}
if(band == 0 ) 
{
if (VerticeActual == destino) 
{
	band3 = 1 ;
DestinoActual == destino ;

while(!pila.empty())
{
cout <<DestinoActual->nombre<<"<-" ;
while(!pila.empty() && pila.top().second != DestinoActual)
{
pila.pop() ;	
}
if(!pila.empty())	
{
DestinoActual = pila.top().first ;	
}
}

}

lista.push_back(VerticeActual) ;
aux = VerticeActual->ady ;
while (aux !=NULL )
{
band2 = 0 ;	
for(i=lista.begin(); i!=lista.end();i++ )
{
if(aux->ady == *i) 	
{
band2 = 1 ;	
}
}

if(band2 == 0 ) 
{
cola.push(aux->ady)	;
pila.push(VerticeVertice(VerticeActual, aux->ady )) ;


}
	
aux = aux->sig ;	
}


	
}

}

if (band3 == 0  )
{
cout << "No hay una ruta entre esos dos vertices "	 << endl ;
}

}
 
 
 void Grafo::PrimeroProfundidad(Vertice *origen , Vertice *destino )
{
int band  ,band2 ,band3 = 0 ;
Vertice * VerticeActual , *DestinoActual;	
Arista *aux;
typedef pair<Vertice*, Vertice*> ParVertices ;	
stack<Vertice*> pila;
list<Vertice*> lista ;
stack<ParVertices> PilaPar;
list<Vertice*>::iterator i ;
pila.push(origen) ;

while(!pila.empty() )
{
VerticeActual = pila.top();
pila.pop() ;

for(i=lista.begin(); i!=lista.end(); i++)
{
if(VerticeActual== *i) 	
{
band = 1 ;	
}

}

if (band == 0 )
{
if(VerticeActual == destino )
{
band3 = 1 ;	
DestinoActual = destino ;
while(!PilaPar.empty())
{
cout <<DestinoActual->nombre<<"<-" ;


while(!PilaPar.empty() && PilaPar.top().second !=DestinoActual) 	
{
PilaPar.pop() ;	
}
if(PilaPar.empty())
{
DestinoActual = PilaPar.top().first;	
}


}



	
}
break ;
lista.push_back(VerticeActual) ;
aux = VerticeActual->ady ;

while(aux !=NULL) 
{
band2 = 0 ;	
for (i=lista.begin();i !=lista.end();i++)

{
if(aux->ady == *i)	
{
band2 = 1 ;	
}
}
if (band2 == 0 ) 
{
pila.push(aux->ady) ;
PilaPar.push(ParVertices(VerticeActual,aux->ady ) )	;
}
aux = aux->sig ; 
	
}

	
}
}
if(band3 == 0 ) {
cout << "No Hay una ruta entre esos dos vertices " << endl ;	
}

}


bool Comparacion(pair <Vertice*,int> a, pair<Vertice*,int>b)
{
return a.second < b.second;	
}

void Grafo::PrimeroMejor(Vertice *origen , Vertice *destino)
{
int CostoActual = 0 ,band ,band2;
Vertice *VerticeActual , *DestinoActual;	
Arista *aux ;
typedef pair<Vertice*, int> VerticeCosto ;
typedef pair<Vertice*, Vertice*> VerticeVertice;
list<VerticeCosto> ListaCostos;
list<VerticeCosto> ListaOrdenada;
stack<VerticeVertice> pila;
list<VerticeCosto>::iterator i , j ;
ListaCostos.push_back(VerticeCosto(origen,0)) ;	
ListaOrdenada.push_back(VerticeCosto(origen,0)) ;	

while(!ListaOrdenada.empty())
{
VerticeActual = ListaOrdenada.front().first;
CostoActual = ListaOrdenada.front().second;
ListaOrdenada.pop_front() ;	

if(VerticeActual == destino ) 
{
band2 = 1  ,
DestinoActual = destino ;

while (!pila.empty())
{
cout << DestinoActual->nombre<<"<-" ;	

while(!pila.empty() && pila.top().second !=DestinoActual)
{
pila.pop() 	;
}


if(!pila.empty() )
{
DestinoActual = pila.top().first ;	
}

}
break ;
	
}

aux = VerticeActual->ady ;
while(aux !=NULL) 
{
band = 0 ;	
CostoActual = CostoActual + aux->peso ;

for(i=ListaCostos.begin();i!=ListaCostos.end();i++)
{
if(aux->ady == i->first) 
{
band = 1 ;	
if (CostoActual < i->second )
{
(*i).second = CostoActual ;

for (j=ListaOrdenada.begin() ; j!=ListaOrdenada.end(); j++ ) 
{
if (j->first == aux->ady) 
{
(*j).second = CostoActual ; 
	
}	
}
ListaOrdenada.sort(Comparacion) ;
pila.push(VerticeVertice(VerticeActual,aux->ady)) ;
CostoActual = CostoActual -aux->peso ;




	
}
}	
}
if (band == 0 ) 
{
ListaCostos.push_back(VerticeCosto(aux->ady,CostoActual) )	;
ListaOrdenada.push_back(VerticeCosto(aux->ady,CostoActual)) ;
ListaOrdenada.sort(Comparacion) ;
pila.push(VerticeVertice(VerticeActual,aux->ady)) ;
CostoActual = CostoActual - aux->peso ;
}

aux = aux->sig ;	
}
}
if (band2 == 0 ) 
{
cout << "No hay una ruta entre esos dos vertices " << endl ;	
}
}


 
 
