#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int N, A, B, C, D;
int mo = 1e9+7;
int dp[1010][1010];
ll fact[1004];
ll invfact[1004];

ll extgcd(int a, int b, int& x, int& y){
  int d = a;
  if(b != 0){
    d = extgcd(b, a%b, y, x);
    y -= (a / b) * x;
  }
  else{
    x = 1; y = 0;
  }
  return d;
}
//mod mにおけるaの逆元
ll mod_inverse(ll a, int m){
  int x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

void make_facttable(){
  fact[0] = 1;
  for(int i = 1; i <= 1000; i++){
    fact[i] = (fact[i-1] * i) % mo;
  }
  for(int i = 0; i <= 1000; i++){
    invfact[i] = mod_inverse(fact[i], mo);
  }
}

ll iexp(ll x, ll y){
  ll res = 1;
  for(int i = 0; i < y; i++)  res = (res * x) % mo;
  return res;
}


int main(){
  cin >> N >> A >> B >> C >> D;
  make_facttable();
  ll su = 0;

  for(int i = 0; i <= N+1; i++) fill(dp[i], dp[i]+N+1, 0);
  dp[A][0] = 1;
  for(int i = A; i <= B; i++){
    for(int j = 0; j <= N; j++){
      ll kfact = iexp(invfact[i], C);
      dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mo;
      for(int k = C; k <= D; k++){
        su++;
        if(j - k*i >= 0){
          dp[i+1][j] = ((dp[i+1][j] + ((((((((dp[i][j-k*i] * fact[N-j+k*i]) % mo) * invfact[N-j]) % mo) * kfact) % mo) * invfact[k]) % mo)) % mo);
          kfact = (kfact * invfact[i]) % mo;
        }
        else break;
      }
    }
  }
  cout << su << endl;
  cout << dp[B+1][N] << endl;

  return 0;
}
