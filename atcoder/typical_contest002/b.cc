#include <iostream>

using namespace std;
typedef long long ll;

ll pow_mod(ll n, ll k, ll m){
  ll r = 1;
  for(; k > 0; k >>= 1){
    if (k & 1) r = (r * n) % m;
    n = (n * n) % m;
  }
  return r;
}

int main(){
  ll N, M, P;
  cin >> N >> M >> P;

  cout << pow_mod(N, P, M) << endl;
  return 0;
}
