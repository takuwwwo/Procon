#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <time.h>
#include <random>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> P2;
int N, K, H, W, T;
int state[100][50][50];
int state2[100][50][50];
P init_x[100];
P direction[4];

inline void InitRand(){
  srand((unsigned int)time(NULL));
}

//何もないところは-1、壁が0, コインが1, 罠が2、今いるところが3.

void init_state(int s1){
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      state2[s1][i][j] = state[s1][i][j];
    }
  }
}

int p1(P x, int j){
  return x.first + direction[j].first;
}
int p2(P x, int j){
  return x.second + direction[j].second;
}

P2 update(int s, P x, int j){   //次の位置と報酬を返す。 state2を更新
  int o_p1 = x.first, o_p2 = x.second;
  state2[s][o_p1][o_p2] = -1;

  int n_p1 = p1(x, j), n_p2 = p2(x, j);
  if(state2[s][n_p1][n_p2] == -1){  //移動先が何もなし
    state2[s][n_p1][n_p2] = 3;
    return P2(P(n_p1, n_p2), 0);
  }
  else if(state2[s][n_p1][n_p2] == 0){ //移動先が壁
    state2[s][o_p1][o_p2] = 3;
    return P2(x, 0);
  }
  else if(state2[s][n_p1][n_p2] == 1){ //移動先がコイン
    state2[s][n_p1][n_p2] = 3;
    return P2(P(n_p1, n_p2), 1);
  }
  else if(state2[s][n_p1][n_p2] == 2){
    return P2(P(n_p1, n_p2), -1); //game_overになったらマイナス1を返す。
  }
  else{
    cout << state2[s][n_p1][n_p2] << endl;
    cout << "runtime_error" << endl;
    return P2(x, 0);
  }
}

void greedy(int s1, int s2, int s3, int result_max[2500]){
  //初期位置を決定
  P x1, x2, x3, init_x1, init_x2, init_x3;
  int ite = 1;
  int reward_max = 0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(state[s1][i][j] == 3){
        x1 = P(i, j);
      }
      if(state[s2][i][j] == 3){
        x2 = P(i, j);
      }
      if(state[s3][i][j] == 3){
        x3 = P(i, j);
      }
    }
  }
  init_x1.first = x1.first; init_x1.second = x1.second;
  init_x2.first = x2.first; init_x2.second = x2.second;
  init_x3.first = x3.first; init_x3.second = x3.second;

  for(int i = 0; i < ite; i++){
    int reward = 0;
    bool game_over = false;
    init_state(s1);
    init_state(s2);
    init_state(s3);
    int result[2500]; fill(result, result+2500, 10);
    x1.first = init_x1.first; x1.second = init_x1.second;
    x2.first = init_x2.first; x2.second = init_x2.second;
    x3.first = init_x3.first; x3.second = init_x3.second;
    for(int s = 0; s < T; s++){
      if (game_over){
        result[s] = rand() % 4;
        continue;
      }
      for(int j = 0; j < 4; j++){
        if(state2[s1][p1(x1, j)][p2(x1, j)] == 1 && state2[s2][p1(x2, j)][p2(x2, j)] == 1 && state2[s3][p1(x3, j)][p2(x3, j)] == 1){
          result[s] = j;
          break;
        }
      }
      if(result[s] == 10){   //まだ行く方向が決まってない場合
        int sel[4];
        int ind = 0;
        for(int j = 0; j < 4; j++){
          if(state2[s1][p1(x1, j)][p2(x1, j)] == 2 || state2[s2][p1(x2, j)][p2(x2, j)] == 2 || state2[s3][p1(x3, j)][p2(x3, j)] == 2){  //どっちも罠
            continue;
          }
          else{
            sel[ind] = j;
            ind++;
          }
        }
        if (ind == 0){
          game_over = true;
          result[s] = rand() % 4;
        }
        else{
          result[s] = sel[rand() % ind];
        }
      }

      // 行く方向が決まったので、状態を更新する。
      P2 y1 = update(s1, x1, result[s]);
      P2 y2 = update(s2, x2, result[s]);
      P2 y3 = update(s3, x3, result[s]);
      P yy1 = y1.first; P yy2 = y2.first; P yy3 = y3.first;
      reward += (y1.second + y2.second + y3.second);
      x1.first = yy1.first; x1.second = yy1.second;
      x2.first = yy2.first; x2.second = yy2.second;
      x3.first = yy3.first; x3.second = yy3.second;
    }
    if(reward > reward_max){
      reward_max = reward;
      for(int i = 0; i < 2500; i++){
        result_max[i] = result[i];
      }
    }
  }
}

int main(){
  // 状態の読み込み
  InitRand();
  cin >> N >> K >> H >> W >> T;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < H; j++){
      string s; cin >> s;
      for(int k = 0; k < W; k++){
        if(s[k] == '#') state[i][j][k] = 0;
        if(s[k] == 'o') state[i][j][k] = 1;
        if(s[k] == 'x') state[i][j][k] = 2;
        if(s[k] == '@'){
           state[i][j][k] = 3;
           init_x[i] = P(j, k);
        }
      }
    }
  }
  //方向をセット
  direction[0] = P(1, 0);
  direction[1] = P(0, 1);
  direction[2] = P(-1, 0);
  direction[3] = P(0, -1);

  int itr = 1;

  int result_max[2500];
  int reward_max = 0;
  int N_max[8];
  for(int i = 0; i < 20; i++){
    for(int j = i+1; j < 21; j++){
      for(int j2 = j+1; j2 < 22; j2++){
        for(int aa = 0; aa < itr; aa++){
          int result[2500];
          greedy(i, j, j2, result);
          int reward[100]; fill(reward, reward+100, 0);
          for(int s = 0; s < N; s++){
            init_state(s);
            P x = init_x[s];
            for(int k = 0; k < T; k++){
              P2 y = update(s, x, result[k]);
              x.first = (y.first).first; x.second = (y.first).second;
              if(y.second == -1){ //罠にはまってしまった
                break;
              }
              reward[s] += y.second;
            }
          }
          int reward_sum = 0;
          int N_set[8];
          for(int i2 = 0; i2 < 8; i2++){
            int m_rew = 0, m_ind = 0;
            for(int j2 = 0; j2 < N; j2++){
              if(reward[j2] > m_rew){
                m_rew = reward[j2];
                m_ind = j2;
              }
            }
            reward_sum += m_rew;
            N_set[i2] = m_ind;
            reward[m_ind] = -1;
          }
          if(reward_sum > reward_max){
            reward_max = reward_sum;
            for(int l = 0; l < 2500; l++){
              result_max[l] = result[l];
            }
            for(int l = 0; l < 8; l++){
              N_max[l] = N_set[l];
            }
          }
        }
      }
    }
  }

  for(int i = 0; i < 8; i++){
    cout << N_max[i] << " ";
  }
  cout << endl;
  for(int i = 0; i < T; i++){
    if(result_max[i] == 0) cout << 'D';
    if(result_max[i] == 1) cout << 'R';
    if(result_max[i] == 2) cout << 'U';
    if(result_max[i] == 3) cout << 'L';
  }
  cout << endl;

  return 0;
}
