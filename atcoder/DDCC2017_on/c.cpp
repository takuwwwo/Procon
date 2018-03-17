#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, ll> P;

vector<P> v[310];
int e[310][310];
ll cost[310];

void make_spanning(int s, int co){
  for(int i = 0; i < v[s][i].size(); i++){
    int b = v[s][i].first, c = v[s][i].second;
    if(cost[b] == -1){
      e[s][b] = 1;
      cost[b] = co + c;
      make_spanning(b, co+c);
    }
    else continue;
  }
}

int main(){
  int N, M; cin >> N >> M;
  fill(cost, cost+N, -1);
  for(int i = 0; i < N; i++){`
    for(int j = 0; j < N; j++){
      e[i][j] = -1;
    }
`  }
  for(int i = 0; i < M; i++){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    v[a].push_back(P(b, c));
    e[a][b] = 0;
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(e[i][j] == 1)
    }
  }

  make_spanning(0, 0);





  return 0;
}
