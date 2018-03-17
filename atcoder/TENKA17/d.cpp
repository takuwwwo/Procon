#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, ll> P;
ll d[33];

ll solve(int index, P* a, int K, int N){
  ll su = 0;
  for(int i = 0; i < N; i++){
    if(a[i].first < d[index] && a[i].first <= K){
      su += a[i].second;
    }
    else if(a[i].first <= K){
      a[i].first -= d[index];
    }
  }

  if(index == 0)  return 0;
  else if(K - d[index] < 0) return max(su, solve(index-1, a, K, N));
  else return max(su, solve(index-1, a, K-d[index], N));
}

int main(){
  int N, K;
  P a[100100];
  cin >> N >> K;
  for(int i = 0; i < N; i++){
    cin >> a[i].first >> a[i].second;
  }
  ll x = 1;
  d[0] = 0;
  for(int i = 1; i <= 32; i++){
    d[i] = x;
    x *= 2;
  }

  int index = 0;
  for(index = 0; index <= 31; index++){
    if (K >= d[index] && K < d[index+1])  break;
  }
  cout << solve(index, a, K, N) << endl;

  return 0;
}
