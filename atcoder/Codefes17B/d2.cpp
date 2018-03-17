#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int s[500100];
int N;
int dp[500100];

int main(){
  cin >> N;
  string ss;
  cin >> ss;
  ss = "00" + ss + "00";
  N += 4;
  for(int i = 0; i < N; i++){
    if(ss[i] == '1') s[i] = 1;
    else s[i] = 0;
  }
  fill(dp, dp+N+1, 0);

  for(int i = 2; i < N;){
    if(s[i-1] == 1 && s[i] == 0 && s[i+1] == 1){
      dp[i] = dp[i-1];
      int a = i-1, b = i+1;
      while(s[a] == 1){
        a--;
      }
      dp[i+1] = max(dp[a-1]+(i-a-1), dp[a+1]+(i-a-2));

      while(s[b] == 1){
        dp[b] = max(dp[b], dp[i-2] + (b-i));
        b++;
      }
      i++;
    }
    else{
      dp[i] = max(dp[i], dp[i-1]);
      i++;
    }
  }


  for(int i = 0; i < N; i++){
    cout << dp[i] << " ";
  }


  cout << dp[N-1] << endl;

  return 0;
}
