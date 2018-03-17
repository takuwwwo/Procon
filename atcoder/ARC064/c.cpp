#include <iostream>

using namespace std;
typedef long long ll;

int main(){
  ll N, x;
  ll a[100100];
  cin >> N >> x;
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  ll res = 0;
  for(int i = 0; i < N-1; i++){
    if(a[i] + a[i+1] > x){
      ll r = a[i] + a[i+1] - x;
      res += r;
      a[i+1] = max(0LL, a[i+1]-r);
    }
  }
  cout << res << endl;

  return 0;
}
