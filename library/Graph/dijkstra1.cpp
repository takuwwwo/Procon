/**
 *
 * @param s 始点
 * @param g グラフ
 * @return sから各頂点への距離
 */
vector<ll> dijkstra1(int s, Graph g, ll INF=LONG_LONG_MAX / 3){
    unsigned int n = g.get_num_vertices();
    vector<bool> used(n, false);
    vector<ll> d(n, INF);

    d[s] = 0;
    while(true){
        int v = -1;
        for(int u = 0; u < n; u++) {
            if (!used[u] && (v == -1 || d[u] < d[v])) {
                v = u;
            }
        }

        if(v == -1) break;

        used[v] = true;
        for(auto e: g[v]){
            d[e.vertice] = min(d[e.vertice], d[v] + e.weight);
        }
    }

    return d;
}
