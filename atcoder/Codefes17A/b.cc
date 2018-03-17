#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int H, W, K;
  cin >> H >> W >> K;

  int x = W, y = H;
  bool res = false;
  for(int i = 0; i <= x; i++){
    for(int j = 0; j <= y; j++){
      if(i * H + j * W - 2*i*j == K){
        res = true;
      }
    }
  }

  if(res) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
