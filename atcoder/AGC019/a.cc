#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int main(){
  ll q, h, s, d, n;
  cin >> q >> h >> s >> d;
  cin >> n;

  ll buy1 = min(min(q*4, h*2), s);
  ll buy2 = min(buy1*2, d);
  cout << (n / 2) * buy2 + (n % 2) * buy1 << endl;
  return 0;
}
