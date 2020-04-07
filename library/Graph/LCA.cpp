
class LCA{
    Graph g{0};
    int root;
    vector<vector<int>> parent;
    vector<int> depth;
    int n, log_n;

public:
    LCA(Graph& g2){
        root = 0;
        g = g2;
        init();
    }

    LCA(Graph& g2, int root): root(root){
        g = g2;
        init();
    }

    void dfs(int v, int p, int d){
        parent[0][v] = p;
        depth[v] = d;
        for(auto u: g[v]){
            if(u.vertice != p){
                dfs(u.vertice, v, d+1);
            }
        }
    }

    void init(){
        n = g.size();
        log_n = 2;
        int tmp_n = 1;
        while(tmp_n < n){
            tmp_n *= 2;
            log_n++;
        }

        parent = vector<vector<int>>(log_n, vector<int>(n, 0));
        depth = vector<int>(n, 0);

        dfs(root, -1, 0);
        for(int k = 0; k + 1 < log_n; k++){
            for(int v = 0; v < n; v++){
                if(parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }

    /**
     *
     * @param u
     * @param v
     * @return 頂点uと頂点vのLCA
     */
    int lca(int u, int v){
        if(depth[u] > depth[v]){
            swap(u, v);
        }
//        cout << u << " " << v << endl;

        for(int k = 0; k < log_n; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if(u == v){
            return u;
        }
        for(int k = log_n-1; k >= 0; k--){
            if(parent[k][u] != parent[k][v]){
                u = parent[k][u];
                v = parent[k][v];
            }
        }

        return parent[0][u];
    }

    int getDepth(int v){
        return depth[v];
    }

};
