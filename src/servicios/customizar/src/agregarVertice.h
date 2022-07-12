extern void clear();

Grafo agregarVertice(Grafo G, int& temp, int& num) {

    string nombre;
    int valor;

    clear();

    cout << "Vertices Ingresados: " << endl;
    G.ListaAdyacencia();
    cout << "Ingrese el nombre del vertice: ";
    cin >> nombre;
	
    cout << "Ingrese el valor del vertice: ";
    cin >> valor;

    if (G.NombreExistente(nombre) == 1) {
        temp = 1;
        G.InsertaVertice(nombre, num, valor);
        num++;
        return G;
    }

	temp = 0;
    return G;
}
