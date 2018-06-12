#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

ll a[210000];
ll b[210000];
ll c[210000];
ll N;

ll binary_search(ll f[], ll x, ll N){
  ll l = -1, r = N;
  while(r-l > 1){
    ll m = (l+r)/2;
    if(f[m] >= x){
      r = m;
    }
    else{
      l = m;
    }
  }
  return r;
}

int main(){
  cin >> N;
  for(ll i = 0; i < N; i++)  cin >> a[i];
  for(ll i = 0; i < N; i++)  cin >> b[i];

  ll p = 1;
  ll result = 0;
  for(ll i = 0; i < 30; i++){
    p *= 2;
    for(ll j = 0; j < N; j++){
      c[j] = b[j] % p;
    }
    sort(c, c+N);
    ll count = 0;
    for(ll j = 0; j < N; j++){
      ll x = p/2-a[j]%p;
      ll y = p-a[j]%p;
      ll z = p+p/2-a[j]%p;
      ll x_index = binary_search(c, x, N);
      ll y_index = binary_search(c, y, N);
      ll z_index = binary_search(c, z, N);
      count += (y_index-x_index)+(N-z_index);
    }
    result += (p/2)*(count%2);
  }
  cout << result << endl;

  return 0;
}
