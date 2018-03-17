#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int s[500010];
int au[5][2];

int main(){
  int N;
  cin >> N;
  char c ;
  for(int i = 0; i < N; i++){
    cin >> c; s[i] = c - '0';
  }
  s[N] = 0; s[N+1] = 0;
  au[0][0] = 1; au[0][1] = 2;
  au[1][0] = 1; au[1][1] = 2;
  au[2][0] = 3; au[2][1] = 2;
  au[3][0] = 1; au[3][1] = 4;

  int l = 0, r = 0, state = 0, state2 = 0, x = 0;
  ll res = 0;
  for(int i = 0; i < N;){
    state = au[state2][s[i]];
    if(state == 2){
      l++;
      state2 = state;
      i++;
    }
    else if(state == 4){
    //  cout << i << endl;
      i++;
      while(s[i] == 0 && s[i+1] == 1){
        x++;
        i+=2;
      }
      while(s[i] == 1){
        r++;
        i++;
      }
      if(x % 2 == 1){
        res += max(l, r) + x/2 + 1;
      }
      res += (max(l, r) + 1);
      l = 0; r = 0;
      state2 = 1;
    }
    else{
      l = 0; r = 0;
      state2 = state;
      i++;
    }
  }
  cout << res << endl;

  return 0;
}
