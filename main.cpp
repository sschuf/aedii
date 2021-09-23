#include <iostream>
#include <windows.h>
#include "Grafo.h"
#include <vector>
#define MAX 10
#define MAXX 10
#define MAXV 100 // Maxima cantidad de vertices.
#define oo 0x3f3f3f3f // Nuestro valor infinito.
#include<stdio.h>
#include<conio.h>
#define INFINITY 9999

using namespace std;



int VECTTEMP[100][100] = {} ;
 
    
struct t_Grafo {
	int dato;
	int marca;
};



t_Grafo g[MAX][MAX];
int i,j,k,a,o,u,l,n,ne=1 , minimo ;
int mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
void titulo();
void gotoxy(int x,int y);
int spanning[MAX][MAX];
void IngresaMAD(t_Grafo g[MAX][MAX],int n);
void dijkstra(t_Grafo g[MAX][MAX],int n,int startnode);
void mostrar(t_Grafo g[MAX][MAX],int n);
void  Dijktra();
void Kruskal ();
void Prim();
int prims();

vector<int> ady[ MAXV ];  //lista de adyacencia
bool visitado[ MAXV ];    //para nodos visitados
int prev[ MAXV ];         //padre de nodo i, para ver recorrido



 //Formateamos la IGU 
void gotoxy(int x,int y)
	{                         
        HANDLE hcon;                               
      	hcon = GetStdHandle(STD_OUTPUT_HANDLE);     
      	COORD dwPos;                                 
      	dwPos.X = x;                                 
      	dwPos.Y= y;                                 
      	SetConsoleCursorPosition(hcon,dwPos);       
 	}
//Se coloca el título 
void titulo()
	{
		int x,y,i,z,a;
		system("cls");
 		gotoxy(35,10);
 		printf("******RECORRIDOS DE GRAFOS ESTATICOS******");
 		for(i=1; i<90; i++)
 			{
  				gotoxy(i,13);
  				printf("%c",177);
 				for(x=50;x<70;x++)
					{
						for(y=1;y<70;y++)
							{
								gotoxy(y,24);
   							}
  					}
 			}
		gotoxy(20,20);
	}

void Dijktra()
	{
   		int n,u;
    	printf("***CAMINO MINIMO CON DIJKTRA***\n");
    	printf("Ingrese numero  de Nodos: ");
    
    	scanf("%d",&n);
   		printf("\nIngrese La Matriz De Adyacencia :\n");
 		IngresaMAD( g,n); //Función que carga matriz de Adyacencia
    	mostrar( g,n);//Función que muestra la matriz
    	printf("\nIngrese el Nodo De Partida :");
    	scanf("%d",&u);
    	dijkstra(g,n,u);//Función Dijkstra (proceso)
	}
//Función que carga la Matriz de adyancencia
 void IngresaMAD(t_Grafo g[MAX][MAX],int n)
 	{
 		int i,j;
 	 	for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					{
        				g[i][j].dato=0;
						g[i][j].marca=0;       	       	
        			}
    		}
   		for(i=0;i<n;i++)
		   {
    			for(j=0;j<n;j++)
					{
        	   			if((i!=j)&&(g[i][j].marca==0))
						   {
        		   				printf("\nIngrese Peso De Arista %d,%d :\n",i+1,j+1);
        		   				
                   				scanf("%d",&g[i][j].dato);
                   				g[j][i].dato=g[i][j].dato ;
                   				g[j][i].marca= 1;
        					}
        			}     
        	}
   }
 //Función que muestra la Matriz de Adyacencia  
 void mostrar(t_Grafo g[MAX][MAX] , int n)
 	{
 		int i ,j;
 	  	printf("\n Matrix Peso De Arista  \n\n");
        for(i=0;i<n;i++)
			{
        		for(j=0;j<n;j++)
					{
        				printf("%d \t", g[i][j].dato);
        			}
              	printf("\n");
        	}
 	}
 	
//Proceso de Dijkstra
void dijkstra(t_Grafo g[MAX][MAX] ,int n,int startnode)
	{
		startnode=startnode-1;
    	int cost[MAX][MAX],distance[MAX],pred[MAX];
    	int visited[MAX],count,mindistance,nextnode,i,j;
   		for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(g[i][j].dato==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=g[i][j].dato;
   		for(i=0;i<n;i++)
    	{
        	distance[i]=cost[startnode][i];
        	pred[i]=startnode;
        	visited[i]=0;
    	}
   		distance[startnode]=0;
    	visited[startnode]=1;
    count=1;
    while(count<n-1)
    	{
        	mindistance=INFINITY;
        	for(i=0;i<n;i++)
            	if(distance[i]<mindistance&&!visited[i])
            	{
                	mindistance=distance[i];
                	nextnode=i;
           		}
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }

 
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistancia del Nodo %d = %d",i+1,distance[i]);
            printf("\n Camino = %d",i+1);
           
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j+1);
            }while(j!=startnode);
    }
    printf("\n");

}



int find(int i)
{
 while(parent[i])
  i=parent[i];
 return i;
}
int uni(int i,int j)
{
 if(i!=j)
 {
  parent[j]=i;
  return 1;
 }
 return 0;

}

void Prim(){
	int i,j,total_cost;
	printf("***RECORRIDO MINIMO GRAFO  CON PRIM ***\n");
    printf("Ingrese numero de Nodos :");
    scanf("%d",&n);
   
    printf("\nIngrese La Matriz De Adyacencia :\n");
    IngresaMAD( g,n);
    mostrar( g,n);
       
         
   
    total_cost=prims();
    printf("\n \n ARBOL DE EXPANSION MINIMO MATRIZ :\n");
   
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d \t",spanning[i][j]);
    }
   
    printf("\n\n Costo Total  De Arbol de Expansion  Minimo = %d",total_cost);
    printf("\n");
}


int prims()
{
    int cost[MAX][MAX];
    int u,l,min_distance,distance[MAX],from[MAX];
    int visited[MAX],no_of_edges,i,min_cost,j;
   
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(g[i][j].dato==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=g[i][j].dato;
                spanning[i][j]=0;
        }
       
 
    distance[0]=0;
    visited[0]=1;
   
    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
   
    min_cost=0;     
    no_of_edges=n-1;   
   
    while(no_of_edges>0)
    {
        min_distance=INFINITY;
        for(i=1;i<n;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                l=i;
                min_distance=distance[i];
            }
           
        u=from[l];
       
       
        spanning[u][l]=distance[l];
        spanning[l][u]=distance[l];
        no_of_edges--;
        visited[l]=1;
       
     
        for(i=1;i<n;i++)
            if(visited[i]==0&&cost[i][l]<distance[i])
            {
                distance[i]=cost[i][l];
                from[i]=l;
            }
       
        min_cost=min_cost+cost[u][l];
    }
   
    return(min_cost);
   
}






void bfs(){
    int ini , fin;
    cout<<"Nodo raiz: "<<endl;
    cin>>ini;
	cout<<"Nodo final: "<<endl;
    cin>>fin;
    queue<int> Q;
    Q.push( ini );
    int pasos = 0 , maxi = 0;
    while( !Q.empty() ){
       maxi = max( maxi , ( int ) Q.size() );//simplemente para ver la memoria usada en la cola
       int actual = Q.front(); Q.pop();
       pasos++;
       if( actual == fin )break;                               //si se llego al destino

       visitado[ actual ] = true;
       for( int i = 0 ; i < ady[ actual ].size() ; ++i )
	   {              //vemos adyacentes de nodo actual
          if( !visitado[ ady[ actual ][ i ] ] )
		  {                   //si no esta visitado insertamos
             cout<<"El recorrido es ..."<<endl;
			 cout<<actual <<" --> "<<ady[ actual ][ i ] <<endl; //vemos recorrido BFS
             Q.push( ady[ actual ][ i ] );
          }
       }
    }
    cout<< "Memoria maxima: " << maxi<<endl;
    cout<< "Nro Pasos: " << pasos <<endl;

    
}

void dfs(){

    int ini, pasos, maxi , actual, fin;
    printf("Nodo raiz: ");
    scanf("%d" , &ini );
    printf("Nodo final: ");
    scanf("%d" , &fin );

   // memset( visitado , 0 , sizeof( visitado ) );           //inicializamos como no visitado
    stack<int> S;
    S.push( ini );
    prev[ ini ] = -1;
    visitado[ ini ] = true;
    pasos = 0; maxi = 0;

    while( !S.empty() ){
       maxi = max( maxi , (int) S.size() );                //simplemente para ver la memoria usada en la pila
       actual = S.top(); S.pop();
       pasos++;

       if( actual == fin )break;

       for(int i = 0 ; i < ady[ actual ].size() ; ++i ){  //vemos adyacentes de nodo actual
          int v = ady[ actual ][ i ];
          if( !visitado[ v ]){                   //si no esta visitado insertamos
             visitado[ v ] = true;
             prev[ v ] = actual;                 //padre de adyacente es el actual
             S.push( v );
          }
       }
    }


    //vemos recorrido de inicial a final
    printf("Recorrido DFS con Stack\n");
    vector<int> path;
    actual = fin;
    while( 1 ){
        path.push_back( actual );
        if( prev[ actual ] == -1 )break;
        actual = prev[ actual ];
    }

    for( int i = path.size() - 1 ; i >= 0 ; --i )
        ( i == path.size() - 1 )?printf("%d" , path[ i ] ): printf("->%d" , path[ i ] );
    printf("\n");


    printf( "Memoria maxima: %d\n" , maxi );
    printf( "Nro Pasos: %d\n" , pasos );

}

struct Edge
{
	int node; // El nodo destino de la arista.
	int cost; // El costo de la arista.
	Edge(int _node, int _cost) : node(_node), cost(_cost) {} // Constructor parametrizado.
	Edge() : node(-1), cost(-1) {} // Constructor por defecto.
};

struct Graphd
{
	vector<Edge> g[MAXV]; // Lista de adyacencias.
	int V; // Cantidad de vertices.
	int E; // Cantidad de arista
	
};

struct State
{
	int node; // El nodo actual.
	int cost; // El costo del camino.
	State(int _node, int _cost) : node(_node), cost(_cost) {} // Constructor parametrizado.
	bool operator <(const State &b) const // Sobrecarga del operador de prioridad <.
	{
		return cost > b.cost;
	}
};


int origen( int ori) 
{
	
}



int algoritmo(const int begin, const int end, const Graphd graph)
{
	priority_queue<State> pq; // La cola de prioridad.
	vector<int> Dist(graph.V, oo); // La distancia hacia todos los vertices. Inicialmente para cada vertice su valor es infinito.
	vector<bool> mark(graph.V, false); // Este arreglo nos permitira determinar los nodos procesados.

	Dist[begin] = 0; // Valor inicial del vertice de partida.
	pq.push(State(begin, 0)); // Agregamos el primer elemento, que no es mas que el vertice de partida.
	while(!pq.empty()) // Mientras existan vertices por procesar.
	{
		State st = pq.top(); pq.pop(); // Se desencola el elemento minimo.
		mark[st.node] = true; // Se marca el nodo como visitado.
		if (st.node == end)
			return st.cost; // Retornamos el valor del camino, hemos llegado al vertice destino.

		int T = (int)graph.g[st.node].size();
		for(int i = 0; i < T; ++i) // Se recorren las adyacencias de "a".
		{
			// Si no ha sido procesado el vertice "vi" y la distancia hacia "vi" es menor a la distancia
			// en Dist entonces hemos encontrado un camino mas corto a "vi".
			if (!mark[graph.g[st.node][i].node] && ((Dist[st.node] + graph.g[st.node][i].cost) < Dist[graph.g[st.node][i].node]))
			{
				Dist[graph.g[st.node][i].node] = st.cost + graph.g[st.node][i].cost;
				pq.push(State(graph.g[st.node][i].node, st.cost + graph.g[st.node][i].cost));
			}
		}
	}
	return -1; // Si no se puede llegar al destino, retornar -1.
}



int main()
{

    Grafo G;
    G.Inicializa();
    int opc , opc1 , opc2 , opc3 , opc4 , num = 0 , num2 = 0 , temp = 0 ;  

 do
    {
     system("cls");
        cout<<"1. Administracion de grafo "<<endl;
        cout<<"2. Algoritmos " <<endl;
        cout<<"3. Recorridos "<<endl;
        cout<<"4. Salir "<<endl;
        cin>>opc1;
        
switch(opc1)
        {  
 do
{		      	
case 1 :
system("cls") ;	
cout << "1 Carga De Vertices / Nodos  " << endl ;
cout << "2 Carga De Aristas           " << endl ;
cout << "3 Lista De adyacencia        " << endl ;
cout << "4 Tamano Del Grafo           " << endl ;
cout << "5 Eliminar Arista            " << endl ;
cout << "6 Salir                      " << endl ;
cin >> opc2 ;	
switch(opc2)
{

       case 1:
        {
    	
            string nombre;
			string confirmar ;    
            system("cls");
            cout << " Vertices Ingresados: " << endl ;
            G.ListaAdyacencia() ;
            cout<<"Ingrese el nombre del vertice: " << endl ;
            cin.ignore();
            cin>>nombre;
            cout<<"Ingreso el nombre del vertice: " <<  nombre  << endl ;;
            cout<<"Para Confirmar ingrese el mismo nombre , de lo contrario no se inseratara el vertice LLamado:  " <<  nombre  << endl ; ;
            cin >> confirmar ;
           if (confirmar ==  nombre ) 
           {
                     
            if (G.NombreExistente(nombre) == 1 )
            {
			temp = 1 ;           
            G.InsertaVertice(nombre , num );
            num ++ ;
            num2 ++ ;
            }      
            break;
        }else{
        temp = 0 ;
        break ;
		}
					
		break;
        }
    case 2:
        {
            string origen, destino;
            int peso;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese del nombre del vertice origen: ";
                cin.ignore();
                cin>> origen;
                cout<<"Ingrese el nombre del vertice destino: ";
                cin>>destino;
                cout<<"Ingrese el peso: ";
                cin>>peso;

                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Uno de los vertices no es valido"<<endl;
                }
                else
                {
                    G.InsertaArista(G.GetVertice(origen), G.GetVertice(destino), peso);
                }
            }
            cin.get();
            cin.get();
            break;
        }        
        case 3:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                G.ListaAdyacencia();
            }
            cin.get();
            cin.get();
            break;
        }
        case 4:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout<<"Tamano: "<<G.Tamano()<<endl;
            }
            cin.get();
            cin.get();
            break;
        }
       case 5:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese del nombre del vertice origen: ";
                cin.ignore();
                cin>>origen;
                cout<<"Ingrese el nombre del vertice destino: ";
                cin>>destino;
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices no validos"<<endl;
                }
                else
                {
                    G.EliminarArista(G.GetVertice(origen), G.GetVertice(destino));
                    
                }
            }
            cin.get();
            cin.get();
            break;
        }

         default:
        {
            cout<<"Elija una opcion valida"<<endl;
           
        }
  
}

}
  while(opc2 != 6);
      	




	
break ;

case 2 :
	

do
{
system("cls") ;		
cout << "1 Prim " << endl ;
cout << "2 Dijstra " << endl ;
cout << "3 KRUSKAL " << endl ;
cout << "4 Mejor Camino / Primero El Mejor " << endl ;
cout << "5 Salir " << endl ;

cin >> opc3 ;
switch(opc3)
{
     case 1:
        {
 
	int i,j,total_cost;
	    int x , c , temporig , tempdestino ;
    G.RecorridoAristas(  c) ;  
   int k = 0  ;   
	t_Grafo g[MAXX][MAXX];
	
	printf("***RECORRIDO MINIMO GRAFO  CON PRIM ***\n");
    printf("Ingrese numero de Nodos :");
    n = G.CantVert() ;
    
    printf("\nIngrese La Matriz De Adyacencia :\n");
    
    
    
    
 	 	for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					{
        				g[i][j].dato=0;
						g[i][j].marca=0;       	       	
        			}
    		}
    		
    
   
     int origenaux   , destinoaux   , conta = 0   ;
    		
   		for(i=0;i<n;i++)
		   {
    			for(j=0;j<n;j++)
					{
        	   			if((i!=j)&&(g[i][j].marca==0))
						   {
						   	
						   	origenaux   = G.perma(conta)   ;
						   	destinoaux   = G.permb(conta)  ;
					        
							   						   	
        		   				printf("\nIngrese Peso De Arista %d,%d :\n",i+1,j+1);
        		   		
        		   			
        		   			if (i == origenaux && j == destinoaux  ) 
        		   			{
        		   			g[i][j].dato = 	G.Matriz(origenaux , destinoaux ) ;
        		   			g[j][i].dato=g[i][j].dato ;
        		   			g[j][i].marca= 1;
        		   			conta ++ ;
							}else{
							g[i][j].dato = 0 ;	
							}
        		   			
        
                   			
                   				
                   				
                   				
                   			
                   				
        					}
        			}     
        	}
    conta = 0 ;
    


	
 	  	printf("\n Matrix Peso De Arista  \n\n");
        for(i=0;i<n;i++)
			{
        		for(j=0;j<n;j++)
					{
        				printf("%d \t", g[i][j].dato);
        			}
              	printf("\n");
        	}
        
   
   
   
   int cost[MAXX][MAXX];
    int u,l,min_distance,distance[MAXX],from[MAXX];
    int visited[MAXX],no_of_edges,min_cost;
   
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(g[i][j].dato==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=g[i][j].dato;
                spanning[i][j]=0;
        }
       
 
    distance[0]=0;
    visited[0]=1;
   
    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
   
    min_cost=0;     
    no_of_edges=n-1;   
   
    while(no_of_edges>0)
    {
        min_distance=INFINITY;
        for(i=1;i<n;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                l=i;
                min_distance=distance[i];
            }
           
        u=from[l];
       
       
        spanning[u][l]=distance[l];
        spanning[l][u]=distance[l];
        no_of_edges--;
        visited[l]=1;
       
     
        for(i=1;i<n;i++)
            if(visited[i]==0&&cost[i][l]<distance[i])
            {
                distance[i]=cost[i][l];
                from[i]=l;
            }
       
        min_cost=min_cost+cost[u][l];
    }
    total_cost = min_cost ;
    printf("\n \n ARBOL DE EXPANSION MINIMO MATRIZ :\n");
   
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d \t",spanning[i][j]);
    }
   
    printf("\n\n Costo Total  De Arbol de Expansion  Minimo = %d",total_cost);
    printf("\n");

   
  
		
     cout << " " << endl ;
          
		  
		 cin.get();
            cin.get();
            break;   
        }
                case 2:
        {
     int verticestotales  = 0 , aristastotales = 0 ;    	
     verticestotales = G.CantVert() ;
     aristastotales = G.CantArist() ;
      cout << "Cantidad de vertices " << " " <<  verticestotales  << endl ;
      cout << "Aristas Totales :  " << " " << aristastotales << endl ;
        	
	bool out=false;
	char salir;


	Graphd graph; // Grafo.


	while (!out)
	{


    int opc;
	int V, E , o[50] ;
	int comienzo, fin;
	string nom , nomd ;

		V = G.CantVert() ;
	    E = G.CantArist() ;

		graph.V = V;
		graph.E = E;
	cout << " V "  << " " << V <<  endl ;
    cout << " E "  << " " << E <<  endl  ;
      G.RecorridoAristas( V ) ;
		for (int i = 0; i < E; ++i)
		{
			 int a , b ,c , x  ;
		
		
			int Origen, Destino, Peso;

			
		        
                
             
                nom = G.n(i) ;
	            nomd = G.nd(i) ;
                Origen = G.perma(i) ;
                Destino = G.permb(i) ;
                Peso = G.permc(i) ;
                cout << " " << endl ;
				cout << "Remplazar En El Siguente Ingreso El Origen " << nom  << " "<<  "por: "   << Origen  << endl ;	
				cout << "Remplazar En El Siguente Ingreso El Destino Por "<< nomd  << " "<<"por: " << Destino << endl ;		
			graph.g[Origen].push_back(Edge(Destino, Peso));
			graph.g[Destino].push_back(Edge(Origen, Peso));
		}
		cout << "Ingrese Vertice Inicial: " << endl;
		cin >> comienzo;
		cout << "Ingrese Vertice Final: " << endl;
		cin >> fin;
		int n = algoritmo(comienzo, fin, graph);
		cout << "Longitud del Camino mas Corto: " << n << endl;

   cin.get();
            cin.get();
            break;



	}
break ;
    }
     case 3:
       {
      
            
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
         	
   int x , c , temporig , tempdestino ;
    G.RecorridoAristas(  c) ;  
   int k = 0  ;   
	t_Grafo g[MAX][MAX];
 	printf("*** RECORRIDO MINIMO DE GRAFO CON KRUSKAL ***\n");
	printf("INGRESE NUMERO DE NODOS : ");
    n = G.CantVert()  ;
    cout << "Numero Nodos : " << n << endl ;
    int mat[n+1][n+1];
    printf("\nIngrese La Matriz De Adyacencia :\n");
    
    int origenaux   , destinoaux   , conta = 0   ;  
    	int i,j;
 	 	for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					{
        				g[i][j].dato=0;
						g[i][j].marca=0;       	       	
        			}
    		}
    		
    
   
   
    		
   		for(i=0;i<n;i++)
		   {
    			for(j=0;j<n;j++)
					{
        	   			if((i!=j)&&(g[i][j].marca==0))
						   {
						   	
						   	origenaux   = G.perma(conta)   ;
						   	destinoaux   = G.permb(conta)  ;
					        
							   						   	
        		   				printf("\nIngrese Peso De Arista %d,%d :\n",i+1,j+1);
        		   		
        		   			
        		   			if (i == origenaux && j == destinoaux  ) 
        		   			{
        		   			g[i][j].dato = 	G.Matriz(origenaux , destinoaux ) ;
        		   			g[j][i].dato=g[i][j].dato ;
        		   			g[j][i].marca= 1;
        		   			cout << "g[i][j].dato " << g[i][j].dato << endl ;
        		   			conta ++ ;
							}else{
							g[i][j].dato = 0 ;	
							
							}
        		   			
        
                   			
                   				
                   				
                   				
                   			
                   				
        					}
        			}     
        	}
    conta = 0 ;
    


	
 	  	printf("\n Matrix Peso De Arista  \n\n");
        for(i=0;i<n;i++)
			{
        		for(j=0;j<n;j++)
					{
        				printf("%d \t", g[i][j].dato);
        			}
              	printf("\n");
        	}
    	
        	
for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
     cost[i][j]=g[i-1][j-1].dato;
     cout << "g[i-1][j-1].dato; " << endl ;
     cout << "i " << i << endl ;
     cout << "j " << i << endl ;
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 }
  for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
     mat[i][j]=0;
  }
 }
 printf("");
  printf("\n ARISTAS DEL ARBOL EXPANSION MINIMO : \n",mincost);

 while(ne<n  )
 {
  for(i=1,minimo=999;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(cost[i][j]<minimo)
    {
     minimo=cost[i][j];
   
    a=u=i;
    o=l=j;
    }
   }
  }

  u=find(u);
  l=find(l);

  if(uni(u,l))
  {
  printf("\n%d ARISTA   de nodo %d a %d  = %d\n",ne++,a,o,minimo);
  mat[a][o]=minimo;
   mincost +=minimo;
  }else{
cout << "Error De la Ejecuccion del algoritmo de KRUSKAL , La Union De Una Arista Con Su Vertice no fue encontrada , volviendo al menu principal " << endl  ;
ne = n + 1 ;
  }
  cost[a][o]=cost[o][a]=999;
 }

  for(i=1;i<=n;i++)
 {printf("\n");
  for(j=1;j<=n;j++)
  {
     printf(" %d ",mat[i][j]);
  }
 }
 printf("\n Peso Minimo = %d \n",mincost);
 getch();
        	
 		

        }
          cin.get();
            cin.get();
            break; 
        }
        
        case 4:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
            	G.ListaAdyacencia() ;
                cout<<"Ingrese el nombre del vertice origen: ";
                cin.ignore();
                cin >> origen;
                cout<<"Ingrese el nombre del vertice destino: ";
                cin >> destino;
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    G.PrimeroMejor(G.GetVertice(origen), G.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }

}


   default:
        {
            cout<<"Elija una opcion valida"<<endl;
           
        }


}
  while(opc3 != 5);		

		



	
break ;
case 3 :
	
do
{
system("cls") ;		
cout << "1 Recorrido Anchura " << endl ;
cout << "2 Recorrido Profundidad " << endl ;
cout << "3 Salir " << endl ;


cin >> opc4 ;
switch(opc4)
{	
    case 1:
        {
            string nombre;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout << "Recorrido En Anchura : " << endl ;
				G.ListaAdyacencia() ;	
                cout<<"Ingrese el nombre del vertice inicial: ";
                cin.ignore();
                cin>>nombre;
                if(G.GetVertice(nombre) == NULL)
                {
                    cout<<"Ese vertice es invalido"<<endl;
                }
                else
                {
                    G.RecorridoAnchura(G.GetVertice(nombre));
                }
            }
            cin.get();
            cin.get();
            break;
        }
     case 2:
        {
            string nombre;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout << "Recorrido En Profundidad  : " << endl ;
				G.ListaAdyacencia() ;
                cout<<"Ingrese el nombre del vertice inicial: ";
                cin.ignore();
                cin>> nombre;
                if(G.GetVertice(nombre) == NULL)
                {
                    cout<<"Ese vertice es invalido"<<endl;
                }
                else
                {
                	cout << "Aqui va recorrido en profundidad" << endl ;
                     G.RecorridoProfundidad(G.GetVertice(nombre));
                    
               
                }
            }
            cin.get();
            cin.get();
            break;
        }





  default:
        {
            cout<<"Elija una opcion valida"<<endl;
           
        }











	
	
}
        }



  while(opc4 != 3);		
	
break ;
case 4 :
break ;
        	
        }
}
while(opc1 != 4);
}
/**  do
    {
        system("cls");
        cout<<"1. Ingresar Vertice"<<endl;
        cout<<"2. Ingresar arista"<<endl;
        cout<<"3. Lista de adyacencia"<<endl;
        cout<<"4. TamaÃ±o"<<endl;
        cout<<"5. Prim "<<endl;
        cout<<"6. Eliminar arista"<<endl;
        cout<<"7. Anular"<<endl;
        cout<<"8. Recorrido en anchura"<<endl;
        cout<<"9. Recorrido en profundidad"<<endl;
       cout<<"10. Primero en anchura"<<endl;
        cout<<"11. Primero en profundidad"<<endl;
        cout<<"12. Primero el mejor"<<endl;
        cout<<"13. Salir"<<endl;
        cout << "14. Dijkstra" << endl ;
        cout << "15 . BFS " << endl ;
        cout << "16 . DFS " << endl ;
        cout<<endl<<"Elija una opcion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
        {
    	
            string nombre;
			string confirmar ;    
            system("cls");
            cout << " Vertices Ingresados: " << endl ;
            G.ListaAdyacencia() ;
            cout<<"Ingrese el nombre del vertice: " << endl ;
            cin.ignore();
            cin>>nombre;
            cout<<"Ingreso el nombre del vertice: " <<  nombre  << endl ;;
            cout<<"Para Confirmar ingrese el mismo nombre , de lo contrario no se inseratara el vertice LLamado:  " <<  nombre  << endl ; ;
            cin >> confirmar ;
           if (confirmar ==  nombre ) 
           {
                     
            if (G.NombreExistente(nombre) == 1 )
            {
			temp = 1 ;           
            G.InsertaVertice(nombre , num );
            num ++ ;
            num2 ++ ;
            }      
            break;
        }else{
        temp = 0 ;
        break ;
		}
					
		break;
        }
        case 2:
        {
            string origen, destino;
            int peso;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese del nombre del vertice origen: ";
                cin.ignore();
                cin>> origen;
                cout<<"Ingrese el nombre del vertice destino: ";
                cin>>destino;
                cout<<"Ingrese el peso: ";
                cin>>peso;

                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Uno de los vertices no es valido"<<endl;
                }
                else
                {
                    G.InsertaArista(G.GetVertice(origen), G.GetVertice(destino), peso);
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 3:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                G.ListaAdyacencia();
            }
            cin.get();
            cin.get();
            break;
        }
        case 4:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout<<"Tamano: "<<G.Tamano()<<endl;
            }
            cin.get();
            cin.get();
            break;
        }
        case 5:
        {
 
	int i,j,total_cost;
	    int x , c , temporig , tempdestino ;
    G.RecorridoAristas(  c) ;  
   int k = 0  ;   
	t_Grafo g[MAXX][MAXX];
	
	printf("***RECORRIDO MINIMO GRAFO  CON PRIM ***\n");
    printf("Ingrese numero de Nodos :");
    n = G.CantVert() ;
    
    printf("\nIngrese La Matriz De Adyacencia :\n");
    
    
    
    
 	 	for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					{
        				g[i][j].dato=0;
						g[i][j].marca=0;       	       	
        			}
    		}
    		
    
   
     int origenaux   , destinoaux   , conta = 0   ;
    		
   		for(i=0;i<n;i++)
		   {
    			for(j=0;j<n;j++)
					{
        	   			if((i!=j)&&(g[i][j].marca==0))
						   {
						   	
						   	origenaux   = G.perma(conta)   ;
						   	destinoaux   = G.permb(conta)  ;
					        
							   						   	
        		   				printf("\nIngrese Peso De Arista %d,%d :\n",i+1,j+1);
        		   		
        		   			
        		   			if (i == origenaux && j == destinoaux  ) 
        		   			{
        		   			g[i][j].dato = 	G.Matriz(origenaux , destinoaux ) ;
        		   			g[j][i].dato=g[i][j].dato ;
        		   			g[j][i].marca= 1;
        		   			conta ++ ;
							}else{
							g[i][j].dato = 0 ;	
							}
        		   			
        
                   			
                   				
                   				
                   				
                   			
                   				
        					}
        			}     
        	}
    conta = 0 ;
    


	
 	  	printf("\n Matrix Peso De Arista  \n\n");
        for(i=0;i<n;i++)
			{
        		for(j=0;j<n;j++)
					{
        				printf("%d \t", g[i][j].dato);
        			}
              	printf("\n");
        	}
        
   
   
   
   int cost[MAXX][MAXX];
    int u,l,min_distance,distance[MAXX],from[MAXX];
    int visited[MAXX],no_of_edges,min_cost;
   
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(g[i][j].dato==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=g[i][j].dato;
                spanning[i][j]=0;
        }
       
 
    distance[0]=0;
    visited[0]=1;
   
    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
   
    min_cost=0;     
    no_of_edges=n-1;   
   
    while(no_of_edges>0)
    {
        min_distance=INFINITY;
        for(i=1;i<n;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                l=i;
                min_distance=distance[i];
            }
           
        u=from[l];
       
       
        spanning[u][l]=distance[l];
        spanning[l][u]=distance[l];
        no_of_edges--;
        visited[l]=1;
       
     
        for(i=1;i<n;i++)
            if(visited[i]==0&&cost[i][l]<distance[i])
            {
                distance[i]=cost[i][l];
                from[i]=l;
            }
       
        min_cost=min_cost+cost[u][l];
    }
    total_cost = min_cost ;
    printf("\n \n ARBOL DE EXPANSION MINIMO MATRIZ :\n");
   
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d \t",spanning[i][j]);
    }
   
    printf("\n\n Costo Total  De Arbol de Expansion  Minimo = %d",total_cost);
    printf("\n");

   
  
		
     cout << " " << endl ;
          
		  
		 cin.get();
            cin.get();
            break;   
        }
        
        case 6:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese del nombre del vertice origen: ";
                cin.ignore();
                cin>>origen;
                cout<<"Ingrese el nombre del vertice destino: ";
                cin>>destino;
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices no validos"<<endl;
                }
                else
                {
                    G.EliminarArista(G.GetVertice(origen), G.GetVertice(destino));
                    
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 7:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
               G.Anular();
            }
            cin.get();
            cin.get();
            break;
        }
        case 8:
        {
            string nombre;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice inicial: ";
                cin.ignore();
                cin>>nombre;
                if(G.GetVertice(nombre) == NULL)
                {
                    cout<<"Ese vertice es invalido"<<endl;
                }
                else
                {
                    G.RecorridoAnchura(G.GetVertice(nombre));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 9:
        {
            string nombre;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice inicial: ";
                cin.ignore();
                cin>> nombre;
                if(G.GetVertice(nombre) == NULL)
                {
                    cout<<"Ese vertice es invalido"<<endl;
                }
                else
                {
                	cout << "Aqui va recorrido en profundidad" << endl ;
                     G.RecorridoProfundidad(G.GetVertice(nombre));
                    
               
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 10:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice origen: ";
                cin.ignore();
                cin>>origen;
                cout<<"Ingrese el nombre del vertice destino: ";
                cin>>destino;
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    G.PrimeroAnchura(G.GetVertice(origen), G.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 11:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
            	G.ListaAdyacencia()            ;
				cout<<"Ingrese el nombre del vertice origen: ";
                cin.ignore();
                cin>>origen;
                cout<<"Ingrese el nombre del vertice destino: ";
                cin>>destino;
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    G.PrimeroProfundidad(G.GetVertice(origen), G.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 12:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice origen: ";
                cin.ignore();
                cin >> origen;
                cout<<"Ingrese el nombre del vertice destino: ";
                cin >> destino;
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    G.PrimeroMejor(G.GetVertice(origen), G.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
       
        
        case 13:
        {
            break;
        }
                case 14:
        {
     int verticestotales  = 0 , aristastotales = 0 ;    	
     verticestotales = G.CantVert() ;
     aristastotales = G.CantArist() ;
      cout << "Cantidad de vertices " << " " <<  verticestotales  << endl ;
      cout << "Aristas Totales :  " << " " << aristastotales << endl ;
        	
	bool out=false;
	char salir;


	Graphd graph; // Grafo.


	while (!out)
	{


    int opc;
	int V, E , o[50] ;
	int comienzo, fin;
	string nom , nomd ;

		V = G.CantVert() ;
	    E = G.CantArist() ;

		graph.V = V;
		graph.E = E;
	cout << " V "  << " " << V <<  endl ;
    cout << " E "  << " " << E <<  endl  ;
      G.RecorridoAristas( V ) ;
		for (int i = 0; i < E; ++i)
		{
			 int a , b ,c , x  ;
		
		
			int Origen, Destino, Peso;

			
		        
                
             
                nom = G.n(i) ;
	            nomd = G.nd(i) ;
                Origen = G.perma(i) ;
                Destino = G.permb(i) ;
                Peso = G.permc(i) ;
                cout << " " << endl ;
				cout << "Remplazar En El Siguente Ingreso El Origen " << nom  << " "<<  "por: "   << Origen  << endl ;	
				cout << "Remplazar En El Siguente Ingreso El Destino Por "<< nomd  << " "<<"por: " << Destino << endl ;		
			graph.g[Origen].push_back(Edge(Destino, Peso));
			graph.g[Destino].push_back(Edge(Origen, Peso));
		}
		cout << "Ingrese Vertice Inicial: " << endl;
		cin >> comienzo;
		cout << "Ingrese Vertice Final: " << endl;
		cin >> fin;
		int n = algoritmo(comienzo, fin, graph);
		cout << "Longitud del Camino mas Corto: " << n << endl;



	//Desea Salir?

	}
break ;
    }
  
          case 15:
       {
           system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
           	
            int V , E , x , y ,c ; 	
            string nom , nomd  ; 
             G.RecorridoAristas( c ) ;
        V = G.CantVert() ;
	    E = G.CantArist() ;
	   
	    

         
  	for (int i = 0; i < E  ; ++i)
		{
		 nom = G.n(i) ;
	    nomd = G.nd(i) ;
	
		 x = G.perma(i) ;
         y = G.permb(i) ;
  
         cout << " " << endl ;
				cout << "Remplazar En El Siguente Ingreso El Origen " << nom  << " "<<  "por: "   << x << endl ;	
				cout << "Remplazar En El Siguente Ingreso El Destino Por "<< nomd  << " "<<"por: " << y << endl ;
        ady[ x ].push_back( y );
    }
  
  
   int ini , fin;
    cout<<"Nodo raiz: "<<endl;
    cin>>ini;
	cout<<"Nodo final: "<<endl;
    cin>>fin;
    
    queue<int> B;
    B.push( ini );
    int pasos = 0 , maxi = 0;
    while( !B.empty() ){
       maxi = max( maxi , ( int ) B.size() );
       int actual = B.front(); B.pop();
       pasos++;
       if( actual == fin )break;                               

       visitado[ actual ] = true;
       for( int i = 0 ; i < ady[ actual ].size() ; ++i )
	   {              
          if( !visitado[ ady[ actual ][ i ] ] )
		  {              
             cout<<"El recorrido es ..."<<endl;
			 cout<<actual <<" --> "<<ady[ actual ][ i ] <<endl;
             B.push( ady[ actual ][ i ] );
          }
       }
    }
    cout<< "Memoria maxima: " << maxi<<endl;
    cout<< "Nro Pasos: " << pasos <<endl;

   

    
    
    
    
            cin.get();
            cin.get();
       break;
        }

        }
        
        
        
      case 16:
       {
      
            
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
         	
   int x , c , temporig , tempdestino ;
    G.RecorridoAristas(  c) ;  
   int k = 0  ;   
	t_Grafo g[MAX][MAX];
 	printf("*** RECORRIDO MINIMO DE GRAFO CON KRUSKAL ***\n");
	printf("INGRESE NUMERO DE NODOS : ");
    n = G.CantVert()  ;
    cout << "Numero Nodos : " << n << endl ;
    int mat[n+1][n+1];
    printf("\nIngrese La Matriz De Adyacencia :\n");
    
    	int i,j;
 	 	for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					{
        				g[i][j].dato=0;
						g[i][j].marca=0;       	       	
        			}
    		}
    		
    
   
     int origenaux   , destinoaux   , conta = 0   ;
    		
   		for(i=0;i<n;i++)
		   {
    			for(j=0;j<n;j++)
					{
        	   			if((i!=j)&&(g[i][j].marca==0))
						   {
						   	
						   	origenaux   = G.perma(conta)   ;
						   	destinoaux   = G.permb(conta)  ;
					        
							   						   	
        		   				printf("\nIngrese Peso De Arista %d,%d :\n",i+1,j+1);
        		   		
        		   			
        		   			if (i == origenaux && j == destinoaux  ) 
        		   			{
        		   			g[i][j].dato = 	G.Matriz(origenaux , destinoaux ) ;
        		   			g[j][i].dato=g[i][j].dato ;
        		   			g[j][i].marca= 1;
        		   			conta ++ ;
							}else{
							g[i][j].dato = 0 ;	
							}
        		   			
        
                   			
                   				
                   				
                   				
                   			
                   				
        					}
        			}     
        	}
    conta = 0 ;
    


	
 	  	printf("\n Matrix Peso De Arista  \n\n");
        for(i=0;i<n;i++)
			{
        		for(j=0;j<n;j++)
					{
        				printf("%d \t", g[i][j].dato);
        			}
              	printf("\n");
        	}
        	
        	
for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
     cost[i][j]=g[i-1][j-1].dato;
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 }
  for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
     mat[i][j]=0;
  }
 }
 printf("");
  printf("\n ARISTAS DEL ARBOL EXPANSION MINIMO : \n",mincost);

 while(ne<n)
 {
  for(i=1,minimo=999;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(cost[i][j]<minimo)
    {
     minimo=cost[i][j];
   
    a=u=i;
    o=l=j;
    }
   }
  }

  u=find(u);
  l=find(l);

  if(uni(u,l))
  {
  printf("\n%d ARISTA   de nodo %d a %d  = %d\n",ne++,a,o,minimo);
  mat[a][o]=minimo;
   mincost +=minimo;
  }else{
cout << "Error De la Ejecuccion del algoritmo de KRUSKAL , La Union De Una Arista Con Su Vertice no fue encontrada , volviendo al menu principal " << endl  ;
ne = n + 1 ;
  }
  cost[a][o]=cost[o][a]=999;
 }

  for(i=1;i<=n;i++)
 {printf("\n");
  for(j=1;j<=n;j++)
  {
     printf(" %d ",mat[i][j]);
  }
 }
 printf("\n Peso Minimo = %d \n",mincost);
 getch();
        	
 		

        }
      
        }
		
		  
        
          case 17:
     {
            
            if(G.Vacio())
            {
                cout<<"El grafo esta Vacio"<<endl;
            }
            else
            {
           	
             int  E , V , x , y ,c ; 	
             G.RecorridoAristas( c ) ;
        V = G.CantVert() ;
	    E = G.CantArist() ;
		cout << " V "  << " " << V <<  endl ;
    cout << " E "  << " " << E <<  endl  ;
         
  	for (int i = 0; i < E; ++i)
		{
		 x = G.perma(i) ;
         y = G.permb(i) ;
         cout << " " << endl ;
				cout << "Remplazar El Nombre Por: " << x << endl ;	
				cout << "Remplazar El Destino Por " << y << endl ;
          ady[ x ].push_back( y );
        //ady[ y ].push_back( x );  //Para grafo no dirigido
    }
   dfs();


    
    
    
    
            cin.get();
            cin.get();
       break;
        }
        default:
        {
            cout<<"Elija una opcion valida"<<endl;
           
        }
        }
    }
}
    while(opc != 13);
    return 0;
}

*/



