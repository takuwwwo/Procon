#define MAX_N 100000
int par[MAX_N];
int myrank[MAX_N];

void init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i;
    myrank[i] = 0;
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

  if(myrank[x] < myrank[y]){
    par[x] = y;
  }
  else{
    par[y] = x;
    if(myrank[x] == myrank[y])  myrank[x]++;
  }
}

//xとyが同じ集合に属するかどうか
bool same(int x, int y){
  return find(x) == find(y);
}
