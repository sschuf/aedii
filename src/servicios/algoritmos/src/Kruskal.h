/*
*	Algortimo de Kruskal - Costo Mínimo
*/

static const int MAXXX = 1e4 + 5;
static int id[MAXXX], nodes, edges;

static int root(int x) {
    while(id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

static void union1(int x, int y) {
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[], int edges) {
	loading();

    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i) {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
       
        if(root(x) != root(y)) {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}
