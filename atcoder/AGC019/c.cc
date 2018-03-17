#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int N;
P x[210000];
double pi = 3.1415926535897932384626433832;
int dp[210000];

int main(){
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> N;
  int in = 0;
  for(int i = 0; i < N; i++){
    ll a, b;
    cin >> a >> b;
    if((x1-a)*(x2-a) <= 0 && (y1-b)*(y2-b) <= 0){
      x[in].first = a;
      x[in].second = b;
      in++;
    }
  }

  N = in;
  sort(x, x + N);


  double z = 100.0;
  double tu = 5.0 * pi - 20.0;
  double st = 10.0 * pi - 20.0;

  fill(dp, dp+N, 100000001);
  if((x2 - x1) * (y2 - y1) >= 0){
    for(int i = 0; i < N; i++){
      *lower_bound(dp, dp+N, x[i].second) = x[i].second;
    }
  }
  else{
    for(int i = 0; i < N; i++){
      *lower_bound(dp, dp+N, -x[i].second) = -x[i].second;
    }
  }
  int n = lower_bound(dp, dp+N, 100000001) - dp;

  /*for(int i = 0; i < N; i++){
    cout << x[i].first << " " << x[i].second << endl;
  }*/

  if(n == min(abs(x1 - x2), abs(y1 - y2)) + 1){
    printf("%.15f\n", tu * (n-1) + st + (abs(x1 - x2) + abs(y1 - y2)) * z);
  }
  else
    printf("%.15f\n",  tu * n + (abs(x1 - x2) + abs(y1 - y2)) * z);



  return 0;
}
