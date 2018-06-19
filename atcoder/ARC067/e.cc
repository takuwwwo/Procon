#include<iostream>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1000000007;
ll fact[1500];
ll invfact[1500];

inline ll take_mod(ll a){
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b){
    return take_mod(a+b);
}

inline ll sub(ll a, ll b){
    return take_mod(a-b);
}


inline ll mul(ll a, ll b){
    return take_mod(a * b);
}

inline ll pow(ll x, ll n){
    ll res = 1LL;
    while(n > 0){
        if(n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return pow(x, mod-2);
}

// nは上限
void make_fact(ll n){
    fact[0] = 1;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = res;
        res = mul(res, i+1);
    }
}

// nは上限
void make_invfact(ll n){
    invfact[0] = 1;
    invfact[n] = mod_inv(fact[n]);
    for(int i = n-1; i >= 1; i--){
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}


ll comb(ll n, ll k){
    return mul(mul(fact[n], invfact[n-k]), invfact[k]);
}

ll dp[1010][1010];

int main(){
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  make_fact(N+10);
  make_invfact(N+10);

  for(int i = 0; i < 1010; i++){
    for(int j = 0; j < 1010; j++){
      dp[i][j] = 0;
    }
  }
  dp[A-1][0] = 1;

  for(int j = A; j <= B; j++){
    for(int i = 0; i <= N; i++){
      ll c = 1LL;
      int n = N-i;
      ll x = dp[j-1][i];
      for(int k = 1; k <= min(i/j, D); k++){
        c = mul(c, comb(n+k*j, j));
        if(k < C) continue;

        x = add(x, mul(mul(c, dp[j-1][i-j*k]), invfact[k]));
      }
      dp[j][i] = x;
    }
  }

  cout << dp[B][N] << endl;

  return 0;
}
