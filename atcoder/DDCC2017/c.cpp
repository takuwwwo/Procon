#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n, c; cin >> n >> c;
  ll l[100100];
  for(int i = 0; i < n; i++)  cin >> l[i];

  sort(l, l+n);
  int s = 0, e = n-1;
  int x = 0;
  while(1){
    if(s > e) break;
    if(l[s] + l[e] + 1 <= c){
      x++; s++; e--;
    }
    else{
      x++; e--;
    }
  }
  cout << x << endl;

  return 0;
}
