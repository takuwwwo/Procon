#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll N, M;
vector<int> v[100010];
int check[100010];

void dfs(int s, int s2, int x){
  for(int i = 0; i < v[s].size(); i++){
    if(v[s][i] == s2)  continue;
    if(check[v[s][i]] == -1){
      check[v[s][i]] = x;
      dfs(v[s][i], s, 1-x);
    }
    else if(check[v[s][i]] == 2){
      continue;
    }
    else if(check[v[s][i]] != x){
      check[v[s][i]] = 2;
      dfs(v[s][i], s, 1-x);
    }
    else{
      continue;
    }
  }
}

int main(){
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i = 0; i <= N; i++) check[i] = -1;
  check[1] = 0;
  dfs(1, 0, 1);
  ll res0 = 0, res1 = 0, res2 = 0;
  for(int i = 1; i <= N; i++){
    if(check[i] == 0) res0++;
    else if(check[i] == 1) res1++;
    else if(check[i] == 2) res2++;
  }
  //cout << res0 << " " << res1 << endl;
  if(res2 > 0){
    cout << N*(N-1)/2 - M << endl;
  }
  else{
    cout << res0*res1 - M << endl;
  }

  return 0;
}
