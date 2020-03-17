/**
 *
 * @param s 始点
 * @param g グラフ
 * @return sから各頂点への距離
 */
vector<ll> dijkstra2(int s, Graph g, ll INF=LONG_LONG_MAX / 3){
    typedef pair<ll, int> Ptmp;  // firstは最短距離、secondは頂点の番号

    unsigned int n = g.get_num_vertices();
    priority_queue<Ptmp, vector<Ptmp>, greater<Ptmp>> que;
    vector<ll> d(n, INF);

    d[s] = 0;
    que.push(Ptmp(d[s], s));

    while(!que.empty()){
        Ptmp p = que.top();   que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(auto e: g[v]){
            if(d[e.vertice] > d[v] + e.weight){
                d[e.vertice] = d[v] + e.weight;
                que.push(Ptmp(d[e.vertice], e.vertice));
            }
        }
    }

    return d;
}
