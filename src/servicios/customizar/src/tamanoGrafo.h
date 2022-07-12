Grafo tamanoGrafo(Grafo G) {
    clear();

    if (G.Vacio()) {
        G.empty();
        return G;
    }
    
	cout << "Tamano: " << G.Tamano() << endl;

	return G;
}
