#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int H, W, N;
int a[10020];
int x[100][100];

int main(){
  cin >> H >> W;
  cin >> N;
  for(int i = 0; i < N; i++)  cin >> a[i];
  int n = 1;

  for(int i = 0; i < H; i++){
    if(i % 2 == 0){
      for(int j = 0; j < W; j++){
        if(a[n-1] == 0) n++;
        x[i][j] = n;
        a[n-1]--;
      }
    }
    else{
      for(int j = W-1; j >= 0; j--){
        if(a[n-1] == 0) n++;
        x[i][j] = n;
        a[n-1]--;
      }
    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cout << x[i][j] << " ";
    }
    cout << endl;
  }


  return 0;
}
