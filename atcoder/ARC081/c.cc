#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main(){
  int N;
  int a[200000];

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  sort(a, a+N);

  ll x[2];
  int y = 0;
  for(int i = N-1; i > 0; i--){
    if(y == 2)  break;
    if(a[i] == a[i-1]){
      x[y] = a[i];
      i--;
      y++;
    }
  }

  if(y == 2){
    cout << x[0] * x[1] << endl;
  }
  else cout << 0 << endl;

  return 0;
}
