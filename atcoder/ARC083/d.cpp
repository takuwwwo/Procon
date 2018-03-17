#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int N;
ll a[310][310];
bool x[310][310];
int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> a[i][j];
      x[i][j] = true;
    }
  }

  ll res = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i == j)  continue;
      for(int k = 0; k < N; k++){
        if(i == k || j == k)  continue;
        if(a[i][k] + a[j][k] < a[i][j]){
          res = -1;
        }
        else if(a[i][k] + a[j][k] == a[i][j]){
          x[i][j] = false;
        }
      }
    }
  }

  if(res == -1) cout << -1 << endl;
  else{
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(x[i][j]) res += a[i][j];
      }
    }
    cout << res / 2 << endl;
  }


  return 0;
}
