/**
 * prim法 (O(V^2)のアルゴリズム)
 * @param g 連結グラフ
 * @return 連結グラフの最小全域木の重み
 */
ll prim1(Graph g, ll INF = LONG_LONG_MAX / 3){
    unsigned int n = g.size();
    vector<ll> mincost(n, INF);
    vector<bool> used(n, false);

    mincost[0] = 0;
    ll res = 0;
    while(true){
        int v = -1;
        for(int u = 0; u < n; u++) {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) {
                v = u;
            }
        }

        if(v == -1) break;
        used[v] = true;
        res += mincost[v];

        for(auto e: g[v]){
            mincost[e.vertice] = min(mincost[e.vertice], e.weight);
        }
    }

    return res;
}
