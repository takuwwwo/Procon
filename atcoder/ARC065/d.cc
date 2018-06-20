#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define MAX_N 200010
struct Union_Find {
    int par[MAX_N];
    int rank[MAX_N];

    void init(int n){
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }

//木の根を求める
    int find(int x){
        if(par[x] == x){
            return x;
        }
        else{
            return par[x] = find(par[x]);
        }
    }

// xとyの属する集合を併合
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y)  return;

        if(rank[x] < rank[y]){
            par[x] = y;
        }
        else{
            par[y] = x;
            if(rank[x] == rank[y])  rank[x]++;
        }
    }

//xとyが同じ集合に属するかどうか
    bool same(int x, int y){
        return find(x) == find(y);
    }
};


int main(){
    int N, K, L;
    cin >> N >> K >> L;

    Union_Find u1, u2;
    u1.init(N);
    u2.init(N);

    for(int i = 0; i < K; i++){
        int p, q;   cin >> p >> q;
        p--; q--;
        u1.unite(p, q);
    }

    for(int i = 0; i < L; i++){
        int p, q;   cin >> p >> q;
        p--; q--;
        u2.unite(p, q);
    }

    map<P, int> m;
    for(int i = 0; i < N; i++){
        int x = u1.find(i);
        int y = u2.find(i);
        m[P(x, y)] += 1;
    }

    for(int i = 0; i < N; i++){
        int x = u1.find(i);
        int y = u2.find(i);
        cout << m[P(x, y)] << " ";
    }
    cout << endl;

    return 0;
}
