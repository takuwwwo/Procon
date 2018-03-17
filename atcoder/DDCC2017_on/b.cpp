#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll ;
typedef pair<ll, ll> P;

ll gcd(ll a, ll b){
  ll c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

ll mcd(ll a, ll b){
  ll x = gcd(a, b);
  return a / x * b;
}

int main(){
  ll N, Z, a[100100];
  cin >> N >> Z;
  for(ll i = 0; i < N; i++){
    cin >> a[i];
  }

  ll x = gcd(Z, a[0]);
  for(ll i = 1; i < N; i++){
    ll y = gcd(Z, a[i]);
    x = mcd(x, y);
  }

  cout << x << endl;


  return 0;
}
