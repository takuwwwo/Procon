#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long ll;

ll dp[30][2][2];

ll a, b;

ll cal(ll a){
  vector<int> t;
  t.push_back(0);
  for(int i = 0; i <= 20; i++){
    t.push_back(int(a%10));
    a /= 10;
  }

  memset(dp, 0, sizeof(dp));
  dp[20][0][0] = 1;
  for(int k = 20; k > 0; k--){
    for(int j = 0; j < t[k]; j++){
      if(j == 4 || j == 9){
        dp[k-1][1][1] += dp[k][0][0] + dp[k][0][1] + dp[k][1][0] + dp[k][1][1];
      }
      else{
        dp[k-1][1][0] += dp[k][0][0] + dp[k][1][0];
        dp[k-1][1][1] += dp[k][0][1] + dp[k][1][1];
      }
    }
    for(int j = t[k]; j < t[k]+1; j++){
      if(j == 4 || j == 9){
        dp[k-1][0][1] += dp[k][0][0] + dp[k][0][1];
        dp[k-1][1][1] += dp[k][1][0] + dp[k][1][1];
      }
      else{
        dp[k-1][0][0] += dp[k][0][0];
        dp[k-1][0][1] += dp[k][0][1];
        dp[k-1][1][0] += dp[k][1][0];
        dp[k-1][1][1] += dp[k][1][1];
      }
    }
    for(int j = t[k]+1; j < 10; j++){
      if(j == 4 || j == 9){
        dp[k-1][1][1] += dp[k][1][0] + dp[k][1][1];

      }
      else{
        dp[k-1][1][0] += dp[k][1][0];
        dp[k-1][1][1] += dp[k][1][1];
      }
    }
  }
  return dp[0][0][1] + dp[0][1][1];
}

int main(){
  cin >> a >> b;
  cout << cal(b) - cal(a-1) << endl;

  return 0;
}
