Grafo mostrarGrafo(Grafo G) {
    clear();

    if (G.Vacio()) {
        G.empty();
        return G;
    }
	
	G.RecorridoAristas(0);
    G.ListaAdyacencia();

    return G;
}
