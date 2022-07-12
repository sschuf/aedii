Grafo eliminarArista(Grafo G) {
	clear();
	string origen, destino;

	if (G.Vacio()) {
	    G.empty();
	    return G;
	}

	cout << "Ingrese del nombre del vertice origen: ";
	cin >> origen;
	cout << "Ingrese el nombre del vertice destino: ";
	cin >> destino;

	if (G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL) {
	    cout << "Vertices no validos" << endl;
	    pause();
	    return G;
	}

	G.EliminarArista(G.GetVertice(origen), G.GetVertice(destino), 0);
	G.EliminarArista(G.GetVertice(destino), G.GetVertice(origen), 0);

	cout << "Arista eliminada con exito.." << endl;
	pause();

	G.RecorridoAristas(0);
	return G;
}
