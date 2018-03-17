#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

ll mo = 1000000007;
int N;
ll dp[100];

int main(){
  cin >> N;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  int i = 0;
  int x = 0;
  if(s1[i] == s2[i])  dp[i++] = 3;
  else{
    dp[i++] = 6;
    dp[i++] = 6;
    x = 1;
  }
  for(; i < N;){
    if(s1[i] == s2[i]){
      if(x == 0){
        dp[i] = (2 * dp[i-1]) % mo;
      }
      else{
        dp[i] = dp[i-1];
      }
      i++;
      x = 0;
    }
    else{
      if(x == 0){
        dp[i] = (2 * dp[i-1]) % mo;
        dp[i+1] = dp[i];
      }
      else{
        dp[i] = (3 * dp[i-1]) % mo;
        dp[i+1] = dp[i];
      }
      i += 2;
      x = 1;
    }
  }
  cout << dp[N-1] << endl;


  return 0;
}
