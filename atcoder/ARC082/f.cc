#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
  int X, K, Q;
  int r[100010];
  cin >> X;
  cin >> K;
  for(int i = 0; i < K; i++)  cin >> r[i];
  cin >> Q;
  r[K] = 1e9 + 1;

  int x, y, z;
  int t, a;
  int tim = 0, dir = 1, rin = 0;
  x = 0; y = X; z = 0;
  for(int i = 0; i < Q; i++){
    cin >> t >> a;
    while(1){
      int tt = min(r[rin], t);
      if(dir == 1){
        z = max(z-(tt - tim), -X);
        x = max(x, -z);
        y = max(x, y);
      }
      else{
        z = min(z+(tt - tim), X);
        y = min(y, X-z);
        x = min(x, y);
      }

      if(tt == r[rin]){
        tim = r[rin++];
        dir = 1 - dir;
      }
      if(tt == t){
        tim = t;
        break;
      }
    }
    if(a <= x) cout << max(0, min(x + z, X)) << endl;
    else if(a >= y) cout << max(0, min(y + z, X)) << endl;
    else  cout << max(0, min(a + z, X)) << endl;

    //cout << x << " " << y << " " << z << endl;
    //cout << dir << endl;

  }

  return 0;
}
