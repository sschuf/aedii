/*
*	Primero el Mejor
*/

static bool Comparacion(pair<Vertice *, int> a, pair<Vertice *, int> b) {
	return a.second < b.second;
}

void primeroMejor(Vertice *origen, Vertice *destino) {
	loading();
	
	int CostoActual = 0, band, band2;
	Vertice *VerticeActual, *DestinoActual;
	Arista *aux;
	typedef pair<Vertice *, int> VerticeCosto;
	typedef pair<Vertice *, Vertice *> VerticeVertice;
	list<VerticeCosto> ListaCostos;
	list<VerticeCosto> ListaOrdenada;
	stack<VerticeVertice> pila;
	list<VerticeCosto>::iterator i, j;
	ListaCostos.push_back(VerticeCosto(origen, 0));
	ListaOrdenada.push_back(VerticeCosto(origen, 0));

	while (!ListaOrdenada.empty()) {
		VerticeActual = ListaOrdenada.front().first;
		CostoActual = ListaOrdenada.front().second;
		ListaOrdenada.pop_front();

		if (VerticeActual == destino) {
			band2 = 1,
			DestinoActual = destino;

			while (!pila.empty()) {
				cout << DestinoActual->nombre << "<-";

				while (!pila.empty() && pila.top().second != DestinoActual) {
					pila.pop();
				}

				if (!pila.empty()) {
					DestinoActual = pila.top().first;
				}
			}
			break;
		}

		aux = VerticeActual->ady;
		while (aux != NULL) {
			band = 0;
			CostoActual = CostoActual + aux->peso;

			for (i = ListaCostos.begin(); i != ListaCostos.end(); i++) {
				if (aux->ady == i->first) {
					band = 1;
					if (CostoActual < i->second) {
						(*i).second = CostoActual;

						for (j = ListaOrdenada.begin(); j != ListaOrdenada.end(); j++) {
							if (j->first == aux->ady) {
								(*j).second = CostoActual;
							}
						}
						ListaOrdenada.sort(Comparacion);
						pila.push(VerticeVertice(VerticeActual, aux->ady));
						CostoActual = CostoActual - aux->peso;
					}
				}
			}
			if (band == 0) {
				ListaCostos.push_back(VerticeCosto(aux->ady, CostoActual));
				ListaOrdenada.push_back(VerticeCosto(aux->ady, CostoActual));
				ListaOrdenada.sort(Comparacion);
				pila.push(VerticeVertice(VerticeActual, aux->ady));
				CostoActual = CostoActual - aux->peso;
			}

			aux = aux->sig;
		}
	}

	if (band2 == 0) {
		cout << "No hay una ruta entre esos dos vertices " << endl;
	}
}
