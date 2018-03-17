#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int p[100];
int dp[101][10010];

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> p[i];
    fill(dp[i], dp[i]+10010, 0);
  }
  fill(dp[N], dp[N]+10010, 0);

  sort(p, p+N);
  dp[0][0] = 1;
  for(int i = 1; i < 10010; i++){
    dp[0][i] = 0;
  }
  for(int i = 1; i <= N; i++){
    for(int j = 0; j < 10010; j++){
      if(j >= p[i-1]) dp[i][j] = dp[i-1][j-p[i-1]] | dp[i-1][j];
      else  dp[i][j] = dp[i-1][j];
    }
  }

  int sum = 0;
  for(int i = 0; i < 10010; i++){
    sum += dp[N][i];
  }
  cout << sum << endl;
  return 0;
}
