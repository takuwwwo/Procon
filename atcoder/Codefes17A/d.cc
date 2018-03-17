#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int H, W, d;
  cin >> H >> W >> d;
  if(d % 2 == 1){
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        if(i % 2 == 0 && j % 2 == 0){
          cout << 'R';
        }
        else if(i % 2 == 1 && j % 2 == 0){
          cout << 'Y';
        }
        else if(i % 2 == 0 && j % 2 == 1){
          cout << 'G';
        }
        else if(i % 2 == 1 && j % 2 == 1){
          cout << 'B';
        }
      }
      cout << endl;
    }
  }
  else{
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        int x = ((i-j+500)/d)%2;
        int y = ((i+j+500)/d)%2;
        if(x == 0 && y == 0){
          cout << 'R';
        }
        else if(x == 0 && y != 0){
          cout << 'Y';
        }
        else if(x != 0 && y == 0){
          cout << 'G';
        }
        else{
          cout << 'B';
        }
      }
      cout << endl;
    }
  }


  return 0;
}
