#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

vector<P> company[1000010];
vector<int> edge[400010];
vector<int> edge2[100010];
int check[100010];
queue<int> que;
int cost[400010];

void bfs(){
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int i = 0; i < edge[v].size(); i++){
            int v2 = edge[v][i];
            if(cost[v2] > cost[v]+1){
                cost[v2] = cost[v]+1;
                que.push(v2);
            }
        }
    }
}

void dfs(int cur, int v, int id){
    if(check[v] == cur) return;
    check[v] = cur;
    edge[v].push_back(id);
    edge[id].push_back(v);
    for(int i = 0; i < edge2[v].size(); i++){
        dfs(cur, edge2[v][i], id);
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int p, q, c;  cin >> p >> q >> c;
        p--; q--; c--;
        company[c].emplace_back(p, q);
    }

    int id = N;
    fill(check, check+N, -1);
    for(int i = 0; i < 1000010; i++){
        if(company[i].size() == 0)  continue;
        vector<int> V;

        for(int j = 0; j < company[i].size(); j++){
            P e = company[i][j];
            edge2[e.first].push_back(e.second);
            edge2[e.second].push_back(e.first);
            V.push_back(e.first);
            V.push_back(e.second);
        }

        for(int j = 0; j < V.size(); j++){
            int v = V[j];
            if(check[v] == i) continue;
            dfs(i, v, id);
            id++;
        }
        for(int j = 0; j < company[i].size(); j++){
            P e = company[i][j];
            edge2[e.first].clear();
            edge2[e.second].clear();
        }
    }


    for(int i = 0; i < id; i++){
        cost[i] = 100000000;
    }
    cost[0] = 0;
    que.push(0);
    bfs();

    if(cost[N-1] == 100000000){
        cout << -1 << endl;
    }
    else{
        cout << cost[N-1]/2 << endl;
    }

    return 0;
}
