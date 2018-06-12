#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
  int a, b;
  cin >> a >> b;
  int x = 0;
  while(x*b <= a){
    x += 1;
  }
  cout << (x-1)*b << endl;

  return 0;
}
