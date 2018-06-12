#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define MAX_N 100000
using namespace std;

int par[MAX_N];
int depth[MAX_N];

void init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i;
    depth[i] = 0;
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

  if(depth[x] < depth[y]){
    par[x] = y;
  }
  else{
    par[y] = x;
    if(depth[x] == depth[y])  depth[x]++;
  }
}

//xとyが同じ集合に属するかどうか
bool same(int x, int y){
  return find(x) == find(y);
}

int N, Q;
int main(){
  cin >> N >> Q;
  init(N);

  for(int i = 0; i < Q; i++){
    int p, a, b;  cin >> p >> a >> b;
    if(p == 0){
      unite(a, b);
    }
    else{
      if(same(a, b)){
        cout << "Yes" << endl;
      }
      else{
        cout << "No" << endl;
      }
    }
  }

  return 0;
}
