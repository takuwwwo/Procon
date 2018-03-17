#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <time.h>
#include <random>

using namespace std;
typedef pair<int, int> P;
P direction[4];

int H, W, D, K;
P data[16100];
priority_queue<P> dis; //次との距離
P object[16100];
int state[210][210];

int intabs(int x){
  if( x > 0) return x;
  else return -x;
}

void det_object(int h, int w){
  int x = 0;
  for(int i = 0; i < H;){
    for(int j = 0; j < W; j++){
      object[x] = P(i, j);
      if (x >= D){
        return;
      }
      x++;
    }
    i++;
    for(int j = W-1; j >= 0; j--){
      object[x] = P(i, j);
      if (x >= D){
        return;
      }
      x++;
    }
    i++;
  }
}


int main(){
  direction[0] = P(-1, 0); //上
  direction[1] = P(0, -1); //左
  direction[2] = P(1, 0); //下
  direction[3] = P(0, 1); //右

  cin >> H >> W >> D >> K;
  int h = H/2;
  int w = W/2;
  det_object(h, w);

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      state[i][j] = -1;
    }
  }

  for(int i = 0; i < D; i++){
    cin >> data[i].first >> data[i].second;
    state[data[i].first][data[i].second] = i;
  }
  for(int i = 0; i < D; i++){
    int x = intabs(data[i].first - object[i].first);
    int y = intabs(data[i].second - object[i].second);
    dis.push(P(x+y, i));
  }

  for(int i = 0; i < K; i++){
    if(dis.empty()) break;

    P tmp = dis.top();

    int d = tmp.first;
    int x = tmp.second;

    /*int xx = abs(data[x].first - object[x].first);
    int yy = abs(data[x].second - object[x].second);
    if(xx + yy != d){ //もし距離が違うなら、もうそこにはない。
      dis.pop();
      continue;
    }*/

    int ox = object[x].first, oy = object[x].second;
    int dx = data[x].first, dy = data[x].second;
    cout << dx << " " << dy << " " << ox << " " << oy << endl;
    dis.pop();

    /*
    if (state[ox][oy] >= 0){ //(ox, oy)にデータが入っていたら、
      int ind = state[ox][oy];
      data[ind] = P(dx, dy);
      xx = abs(data[ind].first - object[ind].first);
      yy = abs(data[ind].second - object[ind].second);
      dis.push(P(xx+yy, ind));
      state[dx][dy] = ind;
    }
    else{
      state[dx][dy] = -1;
    }
    */
    data[x] = P(ox, oy);
    state[ox][oy] = x;

  }

  return 0;

}
