#define fs first
#define sc second

int n;
vector<int> edge[100100];

// Pのfirstが最短距離、secondが頂点番号
int prev_node[100100];
int d[100100];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+n, INT_MAX);

    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.sc;
        if(d[v] < p.fs) continue;
        for(int i = 0; i < edge[v].size(); i++){
            int e = edge[v][i];  //vからeへの道
            if(d[e] > d[v] + 1){
                d[e] = d[v] + 1;
                que.push(P(d[e], e));
                prev_node[e] = v;
            }
        }
    }
}
