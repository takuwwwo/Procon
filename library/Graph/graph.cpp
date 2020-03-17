class Graph{
    struct edge{
        int vertice;
        ll weight;
    };

    vector<vector<edge>> g;
    unsigned int n;

public:
    Graph(unsigned int n): n{n}{
        g.resize(n);
    }

    void add_edge(int u, int v){
        g[u].emplace_back(edge{v, 1});
    };

    void add_edge(int u, int v, ll w){
        g[u].emplace_back(edge{v, w});
    }

    vector<edge>& get_edge(int v){
        return g[v];
    }

    unsigned int get_num_vertices(){
        return n;
    }

    vector<edge>& operator[](int v){
        return get_edge(v);
    }
};
