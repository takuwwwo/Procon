#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int H, W, A, B;
  int vh=0, vw=0, ph=0, pw=0, pd=0;
  cin >> H >> W;
  cin >> A >> B;
  int m[220][220];
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      char c; cin >> c;
      if(c == '.')  m[i][j] = 0;
      else m[i][j] = 1;
      //cout << m[i][j];
    }
    //cout << endl;
  }

  int hn = 0, wn = 0;
  int h, w;
  if (H % 2 == 1) h = H/2;
  else h = H/2-1;
  if (W % 2 == 1) w = W/2;
  else w = W/2-1;

  int s = 0;
  for(int i = 0; i <= h; i++){
    for(int j = 0; j <= w; j++){
      int js = 0;
      if(m[i][j] == m[H-1-i][j] && m[i][j] == m[i][W-1-j] && m[H-i-1][W-j-1] == m[i][j] && m[i][j] == 1){
        pd++;
        js = 1;
      }
      else {
        if((m[i][j] == m[H-1-i][j] && m[i][j] == 1)|| (m[i][W-1-j] == m[H-1-i][W-1-j] && m[i][W-1-j] == 1)){
          ph++;
          js = 1;
        }
        if((m[i][j] == m[i][W-1-j] && m[i][j] == 1)|| (m[H-1-i][j] == m[H-1-i][W-1-j] && m[H-1-i][j] == 1)){
          pw++;
          js = 1;
        }
      }
      if(js == 0 && (m[i][j] == 1 || m[i][W-1-j] == 1 || m[H-1-i][j] == 1 || m[H-1-i][W-1-j] == 1))
        s = 1;
    }
  }

  int res = 0;
  //cout << ph << " " << pw << " " << pd << " " << s <<  endl;
  //cout << 77 << s << endl;
  if(s == 0 && min(ph, pw) == 0){
    res += max(max((ph-1)*A, (pw-1)*B), 0);
  }
  else{
    res += max(ph*A, pw*B);
  }
  //cout << res << endl;
  if(pd > 0){
    if(s == 0 && ph == 0 && pw == 0) res += 0;
    else res += (A+B);
    //cout << res << endl;
    res += (max(A, B)*pd + (A + B) * (pd-1));
    //cout << res << endl;
  }
  res += (A+B);
  cout << res << endl;

  return 0;
}
