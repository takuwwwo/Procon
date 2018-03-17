#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int a, b, c, d, f;
double e;

int main(){
  cin >> a >> b >> c >> d >> e >> f;
  P res = P(100*a, 0);
  double ma = 0.0;
  for(int i = 0; i <= 35; i++){
    for(int j = 0; j <= 20; j++){
      for(int k = 0; k <= 1600; k++){
        for(int l = 0; l <= 800; l++){
          int C = k*c;
          int D = l*d;
          int A = 100*a*i;
          int B = 100*b*j;
          int F = A + B + C + D;
          if(A+B == 0)  continue;
          double x = double(C+D) / (double)(A+B);
          double y = double(C+D) / (double) F;
          if(F <= f){
            if(C+D <= e*(a*i+b*j) && y > ma){
              res = P(F, C+D);
              ma = y;
            }
          }
          else break;
        }
      }
    }
  }

  cout << res.first << " " << res.second << endl;

  return 0;
}
