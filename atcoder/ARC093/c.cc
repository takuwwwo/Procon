#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;


ll ab(ll x){
  if(x >= 0)  return x;
  else return -x;
}

int main(){
  ll N;
  ll a[1000000];
  cin >> N;
  a[0] = 0;
  a[N+1] = 0;
  for(int i = 1; i <= N; i++){
    cin >> a[i];
  }
  ll s = 0;
  for(int i = 1; i <= N+1; i++){
    s += ab(a[i] - a[i-1]);
  }

  for(int i = 1; i <= N; i++){
    ll x = ab(a[i+1]-a[i-1]) - (ab(a[i+1]-a[i])+ab(a[i]-a[i-1]));
    cout << s + x << endl;
  }

  return 0;
}
