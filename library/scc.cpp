
#define MAX_V 101000
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = true;
    for(auto u: G[v]){
        if(!used[u]){
            dfs(u);
        }
    }
    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;
    for(auto u: rG[v]){
        if(!used[u]){
            rdfs(u, k);
        }
    }
}

int scc(int N){
    memset(used, 0, sizeof(used));
    vs.clear();

    for(int v = 0; v < N; v++) {
        if (!used[v]) {
            dfs(v);
        }
    }

    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i = vs.size() - 1; i >= 0; i--){
        if(!used[vs[i]]){
            rdfs(vs[i], k++);
        }
    }
    return k;
}