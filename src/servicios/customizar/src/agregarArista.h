Grafo agregarArista(Grafo G) {
    string origen, destino;
    int peso;

	clear();

    if (G.Vacio()) {
    	G.empty();
    	return G;
	}

    cout << "Nombre del vertice origen: ";
    cin >> origen;

	cout << "Nombre del vertice destino: ";
    cin >> destino;

	cout << "Ingrese el peso: ";
    cin >> peso;

    if (G.CheckAristas(origen, destino) == true) {
        cout << "                                                                    " << endl;
        cout << "Esta Arista Ya Fue Cargada,  Presione enter Para regresar al menu   " << endl;
        pause();
        return G;
    }

    if (G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL) {
        cout << "Uno de los vertices no es valido" << endl;
        pause();
        return G;
    }

    G.InsertaArista(G.GetVertice(origen), G.GetVertice(destino), peso);
    G.InsertaArista(G.GetVertice(destino), G.GetVertice(origen), peso);

    pause();
    return G;
}
