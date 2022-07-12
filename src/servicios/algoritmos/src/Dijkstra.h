/*
*	Dijkstra
*/

int dijkstra(const int begin, const int end, const Graphd graph) {
	loading();

    priority_queue<State> pq;
    vector<int> Dist(graph.V, oo);
    vector<bool> mark(graph.V, false);

    Dist[begin] = 0;
    pq.push(State(begin, 0));
    while (!pq.empty()) {
        State st = pq.top();
        pq.pop();
        mark[st.node] = true;
        if (st.node == end)
            return st.cost;

        int T = (int)graph.g[st.node].size();
        for (int i = 0; i < T; ++i) {
            if (!mark[graph.g[st.node][i].node] && ((Dist[st.node] + graph.g[st.node][i].cost) < Dist[graph.g[st.node][i].node])) {
                Dist[graph.g[st.node][i].node] = st.cost + graph.g[st.node][i].cost;
                pq.push(State(graph.g[st.node][i].node, st.cost + graph.g[st.node][i].cost));
            }
        }
    }
    return -1;
}
