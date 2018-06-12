#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

vector<P> edge2[100010];
vector<int> edge[400010];
map<P, int> m;
queue<int> que;
int cost[400010];
int index;

queue<int> que2[200010];

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

void bfs2(int p){
  for(int i = 0; i < edge2[p].size(); i++){
      if(m.find(edge2[p][i]) == m.end()){
        m[P(p, edge2[p][i].second)] = index;
        index++;
      }
  }
  m[P(p, c)] = index;
  edge[p].push_back(index);
  edge[index].push_back(p);
  for(int i = 0; i < edge2[p].size(); i++){
    if(m.find(edge2[p][i]) == m.end())
    if(edge2[p][i].first == prior) continue;
    if(m.find(edge2[p][i]) == m.end()){
      dfs(m[P(p, c)], edge2[p][i].first, c, p);
    }
  }
}

int main(){
  int N, M;
  cin >> N >> M;

  index = N;
  for(int i = 0; i < M; i++){
    int p, q, c;  cin >> p >> q >> c;
    p--; q--; c--;
    edge2[p].push_back(P(q, c));
    edge2[q].push_back(P(p, c));
  }

  dfs(index, 0, edge2[i][j].second, -1);

  for(int i = 0; i < N + index; i++){
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
