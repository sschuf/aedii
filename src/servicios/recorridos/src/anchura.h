/*
*	Recorrido en Anchura
*/

void recorridoAnchura(Vertice *origen) {
	int band;
	Vertice *actual;
	queue<Vertice *> cola;
	list<Vertice *> lista;
	list<Vertice *>::iterator i;
	cola.push(origen);

	while (!cola.empty()) {
		int band = 0, band2 = 0;
		actual = cola.front();
		cola.pop();
		for (i = lista.begin(); i != lista.end(); i++) {
			if (*i == actual) {
				band = 1;
			}
		}

		cout << DEFAULT_LEFT_SPACING;

		if (band == 0) {
			cout << actual->nombre << ", ";
			lista.push_back(actual);
		}

		Arista *aux;
		aux = actual->ady;
		
		while (aux != NULL) {
			band2 = 0;
			for (i = lista.begin(); i != lista.end(); i++) {
				if (aux->ady == *i) {
					band2 = 1;
				}
			}

			if (band2 == 0) {
				cola.push(aux->ady);
			}

			aux = aux->sig;
		}
	}
}
