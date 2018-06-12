#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  ll h, w; cin >> h >> w;
  ll n, m; cin >> n >> m;
  int a[1010][1010]
  int c[4][1010][1010];
  P x[4][1010][1010];

  ll res = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char c; cin >> c;
      if(c == '#')  a[i][j] = 1;
      else  a[i][j] = 0;
    }
  }
  int xx = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] == 1) xx++;
    }
  }
  if(xx == 0){
    cout << 0 << endl;
    return 0;
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(i == 0 && j == 0){
        if(a[i][j] == 0)  x[0][i][j] = P(-1, -1);
        else x[0][i][j] = P(0, 0);
      }
      else if(i == 0){
        if(a[i][j] == 0) x[0][i][j] = P(-1, x[0][i][j-1].second)
        else x[0][i][j] = P(i, j);
      }
      else if(j == 0){
        if(a[i][j] == 0) x[0][i][j] = P(x[0][i-1][j].first, -1)
        else x[0][i][j] = P(i, j);
      }
      else{
        if(a[i][j] == 0) x[0][i][j] = P(x[0][i-1][j].first, x[0][i][j-1].second)
        else x[0][i][j] = P(i, j);
      }
    }
  }


  return 0;
}
