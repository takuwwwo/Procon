int N;
vector<int> g[210000];

class Centroids{
public:
    Centroids(){}

    int OneCentroid(int root, const vector<bool> &dead){
        static vector<int> sz(N);
        get_sz(root, -1, sz, dead);
        int n = sz[root];

        function<int (int, int)> dfs = [&](int u, int prev) {
            for (auto v : g[u]) if (v != prev && !dead[v]) {
                    if (sz[v] > n / 2) {
                        return dfs(v, u);
                    }
                }
            return u;
        };

        return dfs(root, -1);
    }

    vector<int> MultiCentroid(int root, const vector<bool> &dead){
        static vector<int> sz(N);
        get_sz(root, -1, sz, dead);
        int n = sz[root];
        vector<int> centroid;
        function<void (int, int)> dfs = [&](int u, int prev) {
            bool is_centroid = true;
            for (auto v : g[u]) if (v != prev && !dead[v]) {
                    dfs(v, u);
                    if (sz[v] > n / 2) is_centroid = false;
                }
            if (n - sz[u] > n / 2) is_centroid = false;
            if (is_centroid) centroid.push_back(u);
        };
        dfs(root, -1);
        return centroid;
    }

private:
    void get_sz(int u, int prev, vector<int> &sz, const vector<bool> &dead){
        sz[u] = 1;
        for(auto v : g[u]){
            if(v != prev && !dead[v]){
                get_sz(v, u, sz, dead);
                sz[u] += sz[v];
            }
        }
    }
};
