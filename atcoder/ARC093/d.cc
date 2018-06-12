#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
  int a, b;
  cin >> a >> b;

  int grid[100][100];
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      grid[i][j] = -1;
    }
  }

  int x = 0, y = 0;
  while(a > 1){
    if(x >= 100){
      x = 0;
      y += 2;
    }
    grid[x][y] = 0;
    grid[x+1][y] = 0;
    grid[x][y+1] = 0;
    grid[x+1][y+1] = 1;
    a--;
    x += 2;
  }

  while(x < 100){
    grid[x][y] = 0;
    grid[x][y+1] = 0;
    grid[x+1][y] = 0;
    grid[x+1][y+1] = 0;
    x += 2;
  }

  y += 2;
  for(int i = 0; i < 100; i++){
    grid[i][y] = 0;
  }

  x = 0;
  y += 1;

  while(b > 1){
    if(x >= 100){
      x = 0;
      y += 2;
    }
    grid[x][y] = 1;
    grid[x+1][y] = 1;
    grid[x][y+1] = 1;
    grid[x+1][y+1] = 0;
    b--;
    x += 2;
  }

  while(x < 100){
    grid[x][y] = 1;
    grid[x][y+1] = 1;
    grid[x+1][y] = 1;
    grid[x+1][y+1] = 1;
    x += 2;
  }

  x = 0;
  y += 2;
  for(int i = 0; i < 100; i++){
    grid[i][y] = 1;
  }


  cout << y+1 << " " << 100 << endl;
  for(int i = 0; i <= y; i++){
    for(int j = 0; j < 100; j++){
      if(grid[j][i] == 1) cout << '.';
      else cout << '#';
    }
    cout << endl;
  }

  return 0;
}
