#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main(){
  int H, W;
  int a[26];
  cin >> H >> W;

  fill(a, a+26, 0);
  for(int i = 0; i < H*W; i++){
    char c;
    cin >> c;
    a[c - 'a']++;
  }
  int n4, n2, n1;
  if(H % 2 == 1 && W % 2 == 1){
    n4 = (H-1)/2*(W-1)/2;
    n2 = (H + W - 2) / 2;
    n1 = 1;
  }
  else if(H % 2 == 1 && W % 2 == 0){
    n4 = (H-1)/2*W/2;
    n2 = W/2;
    n1 = 0;
  }
  else if(H % 2 == 0 && W % 2 == 1){
    n4 = (W-1)/2*H/2;
    n2 = H/2;
    n1 = 0;
  }
  else{
    n4 = H*W/4;
    n2 = 0;
    n1 = 0;
  }

  int c4 = 0, c2 = 0, c1 = 0;
  for(int i = 0; i < 26; i++){
    c4 += a[i]/4;
    c2 += (a[i]%4)/2;
    c1 += a[i]%2;
  }

  if(c4 >= n4 && (c4-n4)*2+c2 == n2 && c1 == n1){
    cout << "Yes" << endl;
  }
  else  cout << "No" << endl;

  return 0;
}
