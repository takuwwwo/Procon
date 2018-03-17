#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int N, M;
  int D[200010], T[200010];

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> D[i];
  }
  cin >> M;
  for(int i = 0; i < M; i++){
    cin >> T[i];
  }

  sort(D, D+N);
  sort(T, T+M);

  int di = 0, ti = 0;
  bool res = true;
  while(ti < M){
    if(D[di] < T[ti]){
      di++;
    }
    else if(D[di] == T[ti]){
      di++;
      ti++;
    }
    else{
      res = false;
      break;
    }
  }

  if(res) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
