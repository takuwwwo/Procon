#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll N;
int main(){
  cin >> N;
  ll h=0, n=0, w=0;
  ll x = 3*N/4;
  for(ll i = 1; i <= x+1; i++){
    for(ll j = i; j <= 3500; j++){
      ll x2 = 4*i*j - N*i - N*j;
      if (x2 <= 0) continue;
      ll kk = N*i*j / x2;
      if (kk >= 3500) continue;
      for(ll k = kk; k <= kk+1; k++){
        ll xx = 4*i*j*k;
        ll yy = N*(i*j+j*k+k*i);
        if(xx == yy){
          h = i; n = j; w = k;
          i = x*2; j = 4000; k = 4000;
        }
      }
    }
  }
  cout << h << " " << n << " " << w << endl;

  return 0;
}
