#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int imos[2011][2011];

int main(){
  ll H, W;
  ll N, M;
  cin >> H >> W;
  cin >> N >> M;
  ll x = min(H, 2*N+1);
  ll y = min(W, 2*M+1);

  for(ll i = 0; i < x; i++){
    for(ll j = 0; j < y; j++){
      imos[i][j] = 0;
    }
  }

  ll h = x - N;  //縦方向の動ける範囲
  ll w = y - M;  //横方向の動ける範囲
  for(ll i = 0; i < N; i++){
    for(ll j = 0; j < M; j++){
      char c; cin >> c;
      if(c == '.')  continue;

      ll hmin = i;
      ll hmax = x - (N - i);
      ll wmin = j;
      ll wmax = y - (M - j);
      imos[hmin][wmin]++;
      imos[hmax+1][wmin]--;
      imos[hmin][wmax+1]--;
      imos[hmax+1][wmax+1]++;
    }
  }

  /*
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      cout << imos[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  */

  for(ll i = 0; i < x; i++){
    for(ll j = 1; j < y; j++){
      imos[i][j] += imos[i][j-1];
    }
  }
  for(ll j = 0; j < y; j++){
    for(ll i = 1; i < x; i++){
      imos[i][j] += imos[i-1][j];
    }
  }
  /*
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      cout << imos[i][j] << " ";
    }
    cout << endl;
  }
  */

  ll res = 0;
  for(ll i = 0; i < x; i++){
    if(H >= 2*N+1 && i == N)  continue;
    for(ll j = 0; j < y; j++){
      if(W >= 2*M+1 && j == M)  continue;
      res += (imos[i][j] >= 1);
    }
  }

  if(H >= 2*N+1){
    for(ll j = 0; j < y; j++){
      if(j == M)  continue;
      res += (imos[N][j] >= 1)*(H-2*N);
    }
  }
  if(W >= 2*M+1){
    for(ll i = 0; i < x; i++){
      if(i == N)  continue;
      res += (imos[i][M] >= 1) * (W-2*M);
    }
  }

  if(H >= 2*N+1 && W >= 2*M+1){
    res += (imos[N][M] >= 1) * (W-2*M) * (H-2*N);
  }

  cout << res << endl;

  return 0;
}
