/*
*	Recorrido en Profundidad
*/

void recorridoProfundidad(Vertice *origen) {
	int band, band2;
	Vertice *actual;
	stack<Vertice *> pila;
	list<Vertice *> lista;
	list<Vertice *>::iterator i;

	pila.push(origen);

	while (!pila.empty()) {
		band = 0;
		actual = pila.top();
		pila.pop();
		for (i = lista.begin(); i != lista.end(); i++) {
			if (*i == actual) {
				band = 1;
			}
		}

		cout << DEFAULT_LEFT_SPACING;

		if (band == 0) {
			cout << actual->nombre << ", ";
			lista.push_back(actual);
			Arista *aux;
			aux = actual->ady;

			while (aux != NULL) {
				band2 = 0;
				for (i = lista.begin(); i != lista.end(); i++) {
					if (*i == aux->ady) {
						band2 = 1;
					}
				}
				if (band2 == 0) {
					pila.push(aux->ady);
				}
				aux = aux->sig;
			}
		}
	}
}
