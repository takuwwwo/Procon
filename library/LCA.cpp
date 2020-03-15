
#define MAX_V 100000
#define MAX_LOG_V 30

vector<int> G[MAX_V];
class LCA{
    int root;
    vector<vector<int>> parent;
    vector<int> depth;

public:
    /**
     *
     * @param V: 頂点数
     */
    LCA(int V){
        root = 0;
        init(V);
    }

    LCA(int root, int V): root(root){
        init(V);
    }

    void dfs(int v, int p, int d){
        parent[0][v] = p;
        depth[v] = d;
        for(auto u: G[v]){
            if(u != p){
                dfs(u, v, d+1);
            }
        }
    }

    void init(int V){
        parent = vector<vector<int>>(MAX_LOG_V, vector<int>(MAX_V, 0));
        depth = vector<int>(MAX_V, 0);

        dfs(root, -1, 0);
        for(int k = 0; k + 1 < MAX_LOG_V; k++){
            for(int v = 0; v < V; v++){
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

        for(int k = 0; k < MAX_LOG_V; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if(u == v){
            return u;
        }
        for(int k = MAX_LOG_V-1; k >= 0; k--){
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
