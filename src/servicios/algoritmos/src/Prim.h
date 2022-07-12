/*
*	Algoritmo de Prim
*/

Grafo prim(Grafo G){

	loading();

    int weight[100][100], nodess;
    int visited[100];
    int i = 0, j = 0, min = 0, k = 0, l = 0, m = 0, total_cost = 0;
    int conta = 0;

    for (i = 0; i < 100; i++) {
        for (j = 0; j < nodess; j++) {
            weight[i][j] = 0;
        }
    }

    for (i = 0; i < 100; i++) {
        visited[i] = 0;
    }

    for (i = 0; i < nodess; i++) {
        for (j = 0; j < nodess; j++) {
            if (i == G.perma(conta) && j == G.permb(conta)) {
                weight[G.perma(conta)][G.permb(conta)] = G.permc(conta);
            } else {
                weight[i][j] = 0;
            }
            conta++;
        }
        cout << "\n";
    }

    G.RecorridoAristas(1);

    for (i = 0; i < nodess; i++) {
        visited[i] = 0;
    }
    
    cout << "                                           \n";
    cout << "Algoritmo De Prim : \n";
    cout << "                                           \n";
    cout << "Numero De Nodos :  ";

    nodess = G.CantVert();
    cout << nodess << endl;
    int cont = 0;
    for (i = 0; i < nodess; i++) {
        for (j = 0; j < nodess; j++) {
            weight[G.perma(cont)][G.permb(cont)] = G.permc(cont);
            cont++;
        }
        cout << "\n";
    }

    cout << "Matriz De adyacencia \n ";
    for (i = 0; i < nodess; i++) {
        for (j = 0; j < nodess; j++) {
            cout << "\t" << weight[i][j];
        }
        cout << "\n";
    }

    min = 9999;
    total_cost = 0;
    for (i = 0; i < nodess; i++) {
        for (j = 0; j < nodess; j++) {
            if (weight[i][j] < min && weight[i][j] != 0) {
                min = weight[i][j];
                k = i;
                l = j;
            }
        }
    }
    cout << "\nArista   ";
    G.NumANom(k);
    cout << " - ";
    G.NumANom(l);
    cout << "  Con Peso :  " << min;
    visited[k] = 1;
    visited[l] = 1;
    total_cost = min;
    for (m = 0; m < nodess - 2; m++) {
        min = 9999;
        for (i = 0; i < nodess; i++) {
            if (visited[i] == 1) {
                for (j = 0; j < nodess; j++) {
                    if (visited[j] != 1) {
                        if (weight[i][j] < min && weight[i][j] != 0) {
                            min = weight[i][j];
                            k = i;
                            l = j;
                        }
                    }
                }
            }
        }
        cout << "\nArista   ";
        G.NumANom(k);
        cout << " - ";
        G.NumANom(l);
        cout << "  Con Peso :  " << min;
        total_cost = total_cost + min;
    }

    cout << "\nCosto Total :  " << total_cost;
    cout << "\n";

    cout << " " << endl;

    return G;
}
