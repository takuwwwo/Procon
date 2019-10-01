struct edge{int to, cost;};
vector<edge> edge[MAX_V];
ll d[MAX_V];

void dijkstra(int s, int ind){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.sc;
        if(d[v] < p.fs){
            continue;
        }
        for(auto e: edge[v]){
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
