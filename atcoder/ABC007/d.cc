#include <iostream>

using namespace std;
typedef long long ll;

ll fun(ll a, ll b, ll x){
  if(x == 1){
    return (a <= 4 and b >= 4) + (a <= 9 and b >= 9);
  }
  ll a_x = a / x;
  ll b_x = b / x;
  ll a_y = a % x;
  ll b_y = b % x;

  ll res = 0;
  if (a_x > b_x)  return 0;
  ll already = -1;
  for(int k = 0; k < 10; k++){
    if (k < a_x)  continue;
    else if(k > b_x)  continue;
    else{
      ll aa = 0, bb = x-1;
      if(k == a_x) aa = a_y;
      if(k == b_x) bb = b_y;
      if(k == 4 || k == 9){
        res += bb - aa + 1;
      }
      else if(a_x < k && b_x > k){
        if (already == -1){
          already = fun(aa, bb, x/10);
        }
        res += already;
      }
      else{
        res += fun(aa, bb, x/10);
      }
    }
  }
  return res;
}

ll a, b;
int main(){
  ll a, b;
  cin >> a >> b;

  ll x = 1;
  for (int i = 0; i < 17; i++)  x *= 10;

  cout << fun(a, b, x) << endl;

  return 0;
}
