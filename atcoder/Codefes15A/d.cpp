#include <iostream>

using namespace std;
typedef long long ll;
ll N, M;
ll x[100100];

bool check(ll m){
  ll y = 0;
  for(int i = 0; i < M; i++){
    ll xx = x[i];
    ll n1 = (m + xx - y) / 2;
    if(m+y < xx) return false;
    ll n2 = m - abs(xx-y);
    ll n = max(n1, n2);

    y = y + max(n+1, 1LL);
    if(y >= N)  return true;
  }
  return y >= N;
}

int main(){
  cin >> N >> M;
  for(ll i = 0; i < M; i++){
    ll xx; cin >> xx;
    x[i] = xx-1;
  }

  ll s = max(N / M - 2, -1LL), e = N*3;
  while(e - s > 1){
    ll m = (s + e) / 2;
    if(check(m))  e = m;
    else s = m;
  }

  cout << e << endl;

  return 0;

}
