#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int A, B;
int a[1002], b[1002];
int dp[1002][1002];  //dp[B][A]

int main(){
  cin >> A >> B;
  for(int i = 1; i <= A; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= B; i++){
    cin >> b[i];
  }

  if((B+A)%2 == 1){
    dp[B][A-1] = a[A];
    dp[B-1][A] = b[B];
  }
  else  dp[B][A] = 0;
  dp[B][A+1] = dp[B+1][A] = 1e7;
  for(int i = A-1; i >= 0; i--){
    if((i+B) % 2 == 0)  dp[B][i] = dp[B][i+1] + a[i+1];
    else dp[B][i] = dp[B][i+1];
    dp[B+1][i] = 1e7;
  }
  for(int i = B-1; i >= 0; i--){
    if((i+A) % 2 == 0) dp[i][A] = dp[i+1][A] + b[i+1];
    else dp[i][A] = dp[i+1][A];
    dp[i][A+1] = 1e7;
  }

  for(int i = B-1; i >= 0; i--){
    for(int j = A-1; j >= 0; j--){
      if((i+j) % 2 == 0){
        dp[i][j] = max(min(dp[i+1][j+1], dp[i+2][j])+b[i+1],
                       min(dp[i+1][j+1], dp[i][j+2])+a[j+1]);
      }
    }
  }

  cout << dp[0][0] << endl;

/*
  for(int i = 0; i <= B; i++){
    for(int j = 0; j <= A; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
*/
  return 0;
}
