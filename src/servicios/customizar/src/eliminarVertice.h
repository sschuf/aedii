Grafo eliminarVertice(Grafo G, int& num) {
	clear();
    string vert;

    if (G.Vacio()) {
        G.empty();
        return G;
    }

    cout << "Nombre del vertice a eliminar:  ";
    cin >> vert;

    if (G.EliminarVertice(G.GetVertice(vert))) {
        num--;
        cout << "Vertice eliminado con exito.." << endl;
	    G.RecorridoAristas(0);
	    pause();
	    return G;
    }

	cout << "Vertice no encontrado.." << endl;
	pause();

    G.RecorridoAristas(0);
    return G;
}
