#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <stdio.h>

using namespace std;

int K;
double R[1200];
double dp[11][1200];
int bin[15];

double win(int p, int q){
  return 1.0/(1.0+pow(10.0, (R[q] - R[p])/400.0));
}

int main(){
  cin >> K;
  bin[0] = 1;
  for(int i = 1; i <= K; i++) bin[i] = 2*bin[i-1];
  int member = bin[K];
  for(int i = 0; i < member; i++) cin >> R[i];

  for(int i = 0; i < member; i+=2){
    double p = win(i, i+1);
    dp[0][i] = p;  dp[0][i+1] = 1.0 - p;
  }

  for(int i = 1; i < K; i++){
    int s = bin[i+1], b = bin[i];
    for(int j = 0; j < member; j++){
      int battle_s;
      if(j % s < b){
        battle_s = (j/s)*s + b;
      }
      else{
        battle_s = (j/s)*s;
      }

      double p = 0.0;
      for(int k = battle_s; k < battle_s + b; k++){
        p += dp[i-1][k] * win(j, k);
      }
      dp[i][j] = p * dp[i-1][j];
    }
  }

  for(int i = 0; i < member; i++){
    printf("%.9f\n", dp[K-1][i]);
  }

  return 0;
}
