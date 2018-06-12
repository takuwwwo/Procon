#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
  ll N, x[100010];
  ll d;
  ll left[100010], right[100010];

  cin >> N >> d;
  for(ll i = 0; i < N; i++){
    cin >> x[i];
  }

  for(int i = 0; i < N; i++){
    ll l = -1, r = i;
    while(r - l > 1){
      ll c = (l + r) / 2;
      // cout << i << " " << l << " " << r << " " << c << endl;
      if(x[c] >= x[i]-d){
        r = c;
      }
      else{
        l = c;
      }
    }
    left[i] = r;

    l = i-1;
    r = N;
    while(r - l > 1){
      ll c = (l + r) / 2;
      // cout << l << " " << r << endl;
      if(x[c] > x[i]+d){
        r = c;
      }
      else{
        l = c;
      }
    }
    right[i] = l;
  }

  ll res = 0;
  for(ll i = 0; i < N; i++){
    // cout << left[i] << " " << i << " " << right[i] << endl;
    res += ((i-left[i])*(right[i]-i));
  }
  // cout << res << endl;
  for(ll i = 0; i < N; i++){
    ll x = (right[i]-i)*(right[i]-i-1)/2;
    if (x > 0){
      // cout << i << " " << x << endl;
      res -= x;
    }
  }
  cout << res << endl;

  return 0;
}
