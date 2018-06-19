#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

map<P, ll> m;
ll mod = 1e9+7;

ll f(ll S, ll X){
  if(S == 1){
    return 2;
  }
  else if(S == 0){
    return 1;
  }
  else if(m.find(P(S, X)) == m.end()){
    ll res = (f(S/2, X/2) + f((S-1)/2, (X-1)/2) + f((S-2)/2, X/2)) % mod;
    m[P(S, X)] = res;
    return res;
  }
  else{
    ll res = m[P(S, X)];
    return res;
  }
}

int main(){
  ll N;   cin >> N;
  cout << f(N, N) << endl;

  return 0;
}
