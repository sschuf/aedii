#include "Grafo.h"
#include "math.h"
#include <list>

extern void clear(), paddingLeft();

void showlist(list<int> g)
{
	list<int>::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << *it;

	cout << '\n';
}

int TempMat[100][100] = {};

// Carga de Aristas
int v[100]; // este vector guarda los vertices origen
int b[100]; // este vector guarda los vertices destino
int c[100]; // este vector guarda los pesos de la conexion origen destino
int limitA = 0;

int MatAux[100][100] = {};

string nombres[100] = {};
string nombresd[100] = {};

void Grafo::empty()
{
	paddingLeft();
	cout << "No se ha encontrado informacion del Grafo." << endl;
	paddingLeft();
	cout << "Por favor, cargue datos y vuelva a intentarlo..";
	cout << endl
		 << endl;
}

void Grafo::Inicializa()
{
	h = NULL;
}

bool Grafo::Vacio()
{
	if (h == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Grafo::Tamano()
{

	int cont = 0;
	Vertice *aux;
	aux = h;
	while (aux != NULL)
	{
		cont++;
		aux = aux->sig;
	}
	return cont;
}

bool Grafo::NombreExistente(string x)
{
	Vertice *aux;
	aux = h;
	while (aux != NULL)
	{

		if (aux->nombre == x)
		{
			cout << "Ya cargaste un Vertice con ese Nombre , Cambialo Por Otro " << endl;
			return 0;
		}

		aux = aux->sig;
	}
	return 1;
}

Vertice *Grafo::GetVertice(string nombre)
{
	Vertice *aux;
	aux = h;
	while (aux != NULL)
	{

		if (aux->nombre == nombre)
		{

			return aux;
		}
		aux = aux->sig;
	}
	return NULL;
}

void Grafo::InsertaVertice(string nombre, int num, int valor)
{

	Vertice *nuevo = new Vertice;
	nuevo->nombre = nombre;
	nuevo->sig = NULL;
	nuevo->ady = NULL;
	nuevo->numero = num;
	nuevo->valor = valor;
	if (Vacio())
	{
		h = nuevo;
	}
	else
	{
		Vertice *aux;
		aux = h;
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void Grafo::InsertaArista(Vertice *origen, Vertice *destino, int peso)
{

	Arista *nueva = new Arista;
	nueva->peso = peso;
	nueva->sig = NULL;
	nueva->ady = NULL;

	Arista *aux;
	aux = origen->ady;

	if (aux == NULL)
	{
		origen->ady = nueva;
		nueva->ady = destino;
	}
	else
	{
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nueva;
		nueva->ady = destino;
	}
}

bool Grafo::CheckAristas(string origen, string destino)
{

	Vertice *VertAux;
	Arista *ArisAux;
	string origenn, destinoo;

	VertAux = h;
	while (VertAux != NULL)
	{
		cout << VertAux->nombre << "->";
		ArisAux = VertAux->ady;
		origenn = VertAux->nombre;

		while (ArisAux != NULL)
		{
			destinoo = ArisAux->ady->nombre;
			cout << ArisAux->ady->nombre << "->";
			ArisAux = ArisAux->sig;
			if (origenn == destino && destinoo == origen)
			{
				return true;
			}
		}

		if (origenn == origen && destinoo == destino)
		{
			return true;
		}

		VertAux = VertAux->sig;
		cout << endl;
	}

	return false;
}

void Grafo::RecorridoAristas(int x)
{
	int cont = 0;
	int clean;
	Vertice *VertAux;
	Arista *ArisAux;
	int num = 0;
	string nom, nomd;
	VertAux = h;
	int destino = 0;
	int peso = 0;
	int k = CantArist();
	int i = 0, d, j;
	int *pointer = NULL;

	clean = CantArist();

	for (d = 0; d < 100; d++)
	{
		for (j = 0; j < 100; j++)
		{
			TempMat[d][j] = 0;
		}
	}

	for (int f = 0; f < 100; f++)
	{
		v[f] = 0;
		b[f] = 0;
		c[f] = 0;
	}

	while (VertAux != NULL)
	{
		ArisAux = VertAux->ady;
		while (ArisAux != NULL)
		{
			pointer = &i;

			nom = VertAux->nombre;
			nombres[i] = nom;

			num = VertAux->numero;

			destino = ArisAux->ady->numero;

			TempMat[num][destino] = peso;

			nomd = ArisAux->ady->nombre;
			nombresd[i] = nomd;
			peso = ArisAux->peso;

			v[i] = num;
			b[i] = destino;
			c[i] = peso;

			ArisAux = ArisAux->sig;
			i++;
		}

		VertAux = VertAux->sig;
	}
	cont = 0;
	VertAux = h;
	while (VertAux != NULL)
	{

		ArisAux = VertAux->ady;
		while (ArisAux != NULL)
		{
			if (MatAux[VertAux->numero][ArisAux->ady->numero] != 1)
			{

				cout << "Nombre Del Vertice Origen:  " << VertAux->nombre << endl;
				cout << "Nombre Del Vertice Destino: " << ArisAux->ady->nombre << endl;
				cout << VertAux->nombre << "----" << ArisAux->peso << "------>"
					 << " " << ArisAux->ady->nombre;
				cout << " " << endl;
				cout << "Peso: " << ArisAux->peso << endl;
				cout << " " << endl;
				cont++;
				MatAux[ArisAux->ady->numero][VertAux->numero] = 1;
			}
			ArisAux = ArisAux->sig;
		}

		VertAux = VertAux->sig;
	}
	d = 0;
	j = 0;
	for (d = 0; d < 100; d++)
	{
		for (j = 0; j < 100; j++)
		{
			MatAux[d][j] = 0;
		}
	}
}

int Grafo::Matriz(int x, int i)
{
	return TempMat[x][i];
}

string Grafo::n(int x)
{
	Vertice *VertAux;
	Arista *ArisAux;
	VertAux = h;
	int Vert = 0;
	string f;
	f = nombres[x];
	return f;
}

string Grafo::nd(int x)
{
	Vertice *VertAux;
	Arista *ArisAux;
	VertAux = h;
	int Vert = 0;
	string f;
	f = nombresd[x];
	return f;
}

int Grafo::perma(int x)
{
	Vertice *VertAux;
	Arista *ArisAux;
	VertAux = h;
	int Vert = 0;
	int f;
	f = v[x];
	return f;
}

int Grafo::permb(int x)
{
	Vertice *VertAux;
	Arista *ArisAux;
	VertAux = h;
	int Vert = 0;
	int f;
	f = b[x];
	return f;
}

int Grafo::permc(int x)
{
	Vertice *VertAux;
	Arista *ArisAux;
	VertAux = h;
	int Vert = 0;
	int f;
	f = c[x];
	return f;
}

int Grafo::CantVert()
{
	Vertice *VertAux;
	Arista *ArisAux;
	VertAux = h;
	int Vert = 0;

	while (VertAux != NULL)
	{

		ArisAux = VertAux->ady;

		while (ArisAux != NULL)
		{

			ArisAux = ArisAux->sig;
		}
		VertAux = VertAux->sig;

		Vert++;
	}
	return Vert;
	Vert = 0;
}

int Grafo::CantArist()
{
	Vertice *VertAux;
	Arista *ArisAux;
	VertAux = h;
	int Arist = 0;

	while (VertAux != NULL)
	{

		ArisAux = VertAux->ady;

		while (ArisAux != NULL)
		{

			ArisAux = ArisAux->sig;
			Arist++;
		}
		VertAux = VertAux->sig;
	}
	return Arist;
	Arist = 0;
}

void Grafo::ListaAdyacencia()
{
	Vertice *VertAux;
	Arista *ArisAux;
	VertAux = h;
	while (VertAux != NULL)
	{
		cout << VertAux->nombre << "->";
		ArisAux = VertAux->ady;
		while (ArisAux != NULL)
		{
			cout << ArisAux->ady->nombre << "->";
			ArisAux = ArisAux->sig;
		}
		VertAux = VertAux->sig;
		cout << endl;
	}
}

void Grafo::Anular()
{
	Vertice *aux;

	while (h != NULL)
	{
		aux = h;
		h = h->sig;
		delete (aux);
	}
}

void Grafo::EliminarArista(Vertice *origen, Vertice *destino, int check)
{

	int peso, ori, dest, cantari, CantAri;
	int pos = 0;
	CantAri = CantArist();
	ori = origen->numero;
	dest = destino->numero;
	int band = 0;
	Arista *actual, *anterior;
	actual = origen->ady;

	if (actual == NULL)
	{
		cout << "El Vertice origen no tiene aristas " << endl;
	}
	else if (actual->ady == destino)
	{
		origen->ady = actual->sig;
		delete (actual);
		limitA++;
		if (check == 0)
		{
			for (int i = 0; i < CantAri; i++)
			{
				if (v[i] == ori)
				{
					v[i] = 0;
					pos = i;
				}

				if (b[i] == dest)
				{
					b[i] = 0;
					c[i] = 0;
				}
			}

			for (int i = pos; i < CantAri; i++)
			{
				v[i] = v[i + 1];
				b[i] = b[i + 1];
				c[i] = c[i + 1];
			}
		}
		else
		{
			for (int i = 0; i < CantAri; i++)
			{
				if (v[i] == ori || b[i] == ori)
				{
					v[i] = 0;
					b[i] = 0;
					c[i] = 0;
					pos = i;
					for (int k = pos; k < CantAri; k++)
					{
						v[k] = v[k + 1];
						b[k] = b[k + 1];
						c[k] = c[k + 1];
					}
				}
			}
		}
	}
	else
	{
		while (actual != NULL)
		{
			if (actual->ady == destino)
			{
				band = 1;
				anterior->sig = actual->sig;
				delete (actual);
				limitA++;
				peso = actual->peso;
				if (check == 0)
				{
					for (int i = 0; i < CantAri; i++)
					{

						if (v[i] == ori)
						{
							v[i] = 0;
							pos = i;
						}

						if (b[i] == dest)
						{
							b[i] = 0;
							c[i] = 0;
						}
					}

					for (int i = pos; i < CantAri; i++)
					{
						v[i] = v[i + 1];
						b[i] = b[i + 1];
						c[i] = c[i + 1];

						for (int i = 0; i < CantAri; i++)
						{
							if (v[i] == ori || b[i] == ori)
							{
								v[i] = 0;
								b[i] = 0;
								c[i] = 0;
								pos = i;
								for (int k = pos; k < CantAri; k++)
								{
									v[k] = v[k + 1];
									b[k] = b[k + 1];
									c[k] = c[k + 1];
								}
							}
						}
					}
				}
				else
				{
				}

				break;
			}
			anterior = actual;
			actual = actual->sig;
		}
		if (band == 0)
		{
			cout << "Esos dos vertices no estan conectados " << endl;
		}
	}
}

int Grafo::EliminarVertice(Vertice *vert)
{
	Vertice *actual, *anterior;
	int AuxBorradoNumVertice = 0;
	Arista *aux;
	int cont = 0;
	int check = 0;

	int NumeroDelVertice = vert->numero;

	actual = vert;

	int ori = v[NumeroDelVertice];

	actual = h;
	while (actual != NULL)
	{

		aux = actual->ady;
		while (aux != NULL)
		{
			if (aux->ady == vert)
			{

				EliminarArista(actual, aux->ady, 1);

				break;
			}
			aux = aux->sig;
		}
		actual = actual->sig;
	}
	actual = h;

	if (h->numero == vert->numero)
	{

		if (CantVert() == 1)
		{
			h = NULL;
			check = 1;
		}
		else
		{

			h = h->sig;
			delete (actual);
			check = 1;
			anterior = h;
			anterior->numero = cont;
			cont++;
			for (int i = 1; i < CantVert(); i++)
			{
				anterior = anterior->sig;
				anterior->numero = cont;
				cont++;
			}
		}
	}
	else
	{

		for (int i = 0; i < CantVert(); i++)
		{
			anterior = actual;
			actual = actual->sig;
			if (actual == vert)
			{
				actual = actual->sig;
				if (actual == NULL)
				{
					actual = anterior->sig;
					anterior->sig = NULL;

					delete (actual);
					check = 1;
					return check;
				}
				else
				{
					actual = anterior->sig;
					anterior->sig = actual->sig;
					delete (actual);
					check = 1;
					cont--;
				}
			}

			if (check)
			{
				anterior = anterior->sig;
				anterior->numero = cont;
				cont++;
			}
			cont++;
		}
	}
	return (check);
}

void Grafo::NumANom(int x)
{
	Vertice *reco = h;
	while (reco != NULL)
	{
		if (reco->numero == x)
		{
			cout << reco->nombre;
			break;
		}
		reco = reco->sig;
	}
}

void Grafo::PrimeroAnchura(Vertice *origen, Vertice *destino)
{
	int band, band2, band3 = 0;
	Vertice *VerticeActual, *DestinoActual;
	Arista *aux;
	typedef pair<Vertice *, Vertice *> VerticeVertice;
	queue<Vertice *> cola;
	stack<VerticeVertice> pila;
	list<Vertice *> lista;
	list<Vertice *>::iterator i;
	cola.push(origen);

	while (!cola.empty())
	{
		VerticeActual = cola.front();
		cola.pop();

		for (i = lista.begin(); i != lista.end(); i++)
		{
			if (VerticeActual == *i)
			{
				band = 1;
			}
		}
		if (band == 0)
		{
			if (VerticeActual == destino)
			{
				band3 = 1;
				DestinoActual == destino;

				while (!pila.empty())
				{
					cout << DestinoActual->nombre << "<-";
					while (!pila.empty() && pila.top().second != DestinoActual)
					{
						pila.pop();
					}
					if (!pila.empty())
					{
						DestinoActual = pila.top().first;
					}
				}
			}

			lista.push_back(VerticeActual);
			aux = VerticeActual->ady;
			while (aux != NULL)
			{
				band2 = 0;
				for (i = lista.begin(); i != lista.end(); i++)
				{
					if (aux->ady == *i)
					{
						band2 = 1;
					}
				}

				if (band2 == 0)
				{
					cola.push(aux->ady);
					pila.push(VerticeVertice(VerticeActual, aux->ady));
				}

				aux = aux->sig;
			}
		}
	}

	if (band3 == 0)
	{
		cout << "No hay una ruta entre esos dos vertices " << endl;
	}
}

void Grafo::PrimeroProfundidad(Vertice *origen, Vertice *destino)
{
	int band, band2, band3 = 0;
	Vertice *VerticeActual, *DestinoActual;
	Arista *aux;
	typedef pair<Vertice *, Vertice *> ParVertices;
	stack<Vertice *> pila;
	list<Vertice *> lista;
	stack<ParVertices> PilaPar;
	list<Vertice *>::iterator i;
	pila.push(origen);

	while (!pila.empty())
	{
		VerticeActual = pila.top();
		pila.pop();

		for (i = lista.begin(); i != lista.end(); i++)
		{
			if (VerticeActual == *i)
			{
				band = 1;
			}
		}

		if (band == 0)
		{
			if (VerticeActual == destino)
			{
				band3 = 1;
				DestinoActual = destino;
				while (!PilaPar.empty())
				{
					cout << DestinoActual->nombre << "<-";

					while (!PilaPar.empty() && PilaPar.top().second != DestinoActual)
					{
						PilaPar.pop();
					}
					if (PilaPar.empty())
					{
						DestinoActual = PilaPar.top().first;
					}
				}
			}
			break;
			lista.push_back(VerticeActual);
			aux = VerticeActual->ady;

			while (aux != NULL)
			{
				band2 = 0;
				for (i = lista.begin(); i != lista.end(); i++)

				{
					if (aux->ady == *i)
					{
						band2 = 1;
					}
				}
				if (band2 == 0)
				{
					pila.push(aux->ady);
					PilaPar.push(ParVertices(VerticeActual, aux->ady));
				}
				aux = aux->sig;
			}
		}
	}
	if (band3 == 0)
	{
		cout << "No Hay una ruta entre esos dos vertices " << endl;
	}
}

void Grafo::Monticulo()
{
	if (Vacio())
	{
		clear();
		this->empty();
		return;
	}
	else
	{
		Heap h1;
		Vertice *reco = h;
		int cont = 0, cont2 = 1;
		int x = 1;
		system("cls");
		cout << endl
			 << "Monticulo creado con exito!!" << endl;
		cout << endl
			 << "Impresion de Heap.." << endl
			 << endl;
		while (reco != NULL)
		{
			h1.Insertar(reco->valor);
			reco = reco->sig;
		}

		//IMPRESION por NOMBRE-HEAP
		for (int i = 0; i < h1.iUltimo; i++)
		{
			reco = h;
			for (int j = 0; j < CantVert(); j++)
			{
				if (h1.heap[i] == reco->valor)
				{
					cout << reco->nombre << " - ";
					j = CantVert();
				}
				reco = reco->sig;
			}
		}
		cout << endl;

		//IMPRESION por VALORES-HEAP
		for (int i = 0; i < h1.iUltimo; i++)
		{
			cout << h1.heap[i] << " - ";
		}

		cout << endl
			 << endl
			 << endl
			 << "Impresion por Niveles..";

		//IMPRESION por NOMBRE-NIVELES
		cout << endl
			 << endl
			 << "Nivel 0: ";
		for (int i = 0; i < h1.iUltimo; i++)
		{
			reco = h;
			if (cont == x)
			{
				x = pow(2, x);
				cout << endl
					 << "Nivel " << cont2 << ": ";
				cont = 0;
				cont2++;
			}

			for (int j = 0; j < CantVert(); j++)
			{
				if (h1.heap[i] == reco->valor)
				{
					cout << reco->nombre << " - ";
					j = CantVert();
					cont++;
				}
				reco = reco->sig;
			}
		}

		cout << endl;
		cout << endl;
	}
}
