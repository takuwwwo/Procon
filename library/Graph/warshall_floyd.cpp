vector<vector<ll>> warshall_floyd(Graph& g, ll INF = LONG_LONG_MAX / 3){
    unsigned int n = g.size();
    vector<vector<ll>> d(n, vector<ll>(n, INF));

    for(int i = 0; i < n; i++){
        d[i][i] = 0;
        for(auto e: g[i]){
            d[i][e.vertice] = e.weight;
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    return d;
}
