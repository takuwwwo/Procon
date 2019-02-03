#define MAX_V 100
#define INF LONG_LONG_MAX

// 行き先、容量、逆辺(反対側の辺)
struct edge{int to, rev; ll cap;};

vector<edge> G[MAX_V];  //グラフ
ll level[MAX_V];   //sからの距離
int iter[MAX_V];   //どこまで調べ終わったか

// fromからtoへ向かう容量capの変をグラフに追加する
void add_edge(int from, int to, ll cap){
    G[from].push_back((edge){to, G[to].size(), cap});
    G[to].push_back((edge){from, G[from].size()-1, 0});
}

// sからの最短距離をBFSで計算する
void bfs(int s){
    fill(level, level+MAX_V, -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

// 増加パスをDFSで探す
ll dfs(int v, int t, ll f){
    if(v == t)  return f;
    for(int &i = iter[v]; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            ll d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
    }
    return 0;
}


ll max_flow(int s, int t){
    ll flow = 0;
    for(;;){
        bfs(s);
        if(level[t] < 0){
            return flow;
        }
        fill(iter, iter+MAX_V, 0);
        ll f;
        while((f = dfs(s, t, INF)) > 0){
            flow += f;
        }
    }
}
