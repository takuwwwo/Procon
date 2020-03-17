/**
 * prim法 (O(|E|log(|V|))のアルゴリズム)
 * @param g 連結グラフ
 * @return 連結グラフの最小域木をグラフとして返す
 */
Graph prim2_g(Graph g){
    // Ptmp.fsが今の部分木からのコスト、Ptmp.ｓｃ.fsが次の頂点、Ptmp.sc.scが次の頂点に辺を伸ばす部分木の頂点
    typedef pair<ll, pair<int, int>> Ptmp;

    unsigned int n = g.size();

    Graph mst(n);   // minimum spanning tree
    vector<ll> used(n, false);
    priority_queue<Ptmp, vector<Ptmp>, greater<Ptmp> > que;

    used[0] = true;
    for(auto e: g[0]){
        que.push(Ptmp(e.weight, pair<int, int>(e.vertice, 0)));
    }

    while(!que.empty()){
        Ptmp p = que.top(); que.pop();
        int to = p.second.first, from = p.second.second;
        if(used[to]) continue;

        used[to] = true;
        mst.add_edge(from, to, p.first);
        mst.add_edge(to, from, p.first);

        for(auto e: g[to]){
            if(!used[e.vertice]){
                que.push(Ptmp(e.weight, pair<int, int>(e.vertice, to)));
            }
        }
    }

    return mst;
}


/**
 * prim法 (O(|E|log(|V|))のアルゴリズム)
 * @param g 連結グラフ
 * @return 連結グラフの最小全域木の重みの和を返す
 */
ll prim2(Graph g){
    unsigned int n = g.size();
    Graph mst = prim2_g(g);

    ll res = 0;
    for(int i = 0; i < n; i++){
        for(auto e: mst[i]){
            res += e.weight;
        }
    }

    return res / 2;
}
