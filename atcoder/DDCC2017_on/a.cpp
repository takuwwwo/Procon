#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

double squ(double x){
  return x * x;
}

int main(){
  int K;
  cin >> K;
  int x = 200 / K, y = 300 / K;
  int s1 = 0, s2 = 0;
  double center = 100;
  double center2 = 150;
  for(int i = 0; i < x; i++){
    for(int j = 0; j < x; j++){
      double xx = (double)(i * K);
      double yy = (double)(j * K);
      if(squ(xx - center) + squ(yy - center) > squ(100.0)) continue;
      if(squ(xx+K - center) + squ(yy - center) > squ(100.0)) continue;
      if(squ(xx - center) + squ(yy+K - center) > squ(100.0)) continue;
      if(squ(xx+K - center) + squ(yy+K - center) > squ(100.0)) continue;
      s1++;
    }
  }

  for(int i = 0; i < y; i++){
    for(int j = 0; j < y; j++){
      double xx = (double)(i * K);
      double yy = (double)(j * K);
      if(squ(xx - center2) + squ(yy - center2) > squ(150.0)) continue;
      if(squ(xx+K - center2) + squ(yy - center2) > squ(150.0)) continue;
      if(squ(xx - center2) + squ(yy+K - center2) > squ(150.0)) continue;
      if(squ(xx+K - center2) + squ(yy+K - center2) > squ(150.0)) continue;
      s2++;
    }
  }

  cout << s1 << " " << s2 << endl;

  return 0;
}
