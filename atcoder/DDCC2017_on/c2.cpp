#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, ll> P;

vector<P> x[300];
P e[90000];
bool e_check[90000];
int N, M;

int judge(int v, int f, int* track, int c, int index, vector<int>& c_list){
  int track2[300];
  for(int i = 0; i < N; i++){
    track2[i] = track[i];
  }
  for(int i = 0; i < x[v].size(); i++){
    int ne = x[v][i].first;
    if(ne == f){
      c_list.push_back(c);
      return index+1;
    }
    else if(track2[ne] == 1){
      continue;
    }
    else{
      track2[ne] = 1;
      int wei = x[v][i].second;
      index = judge(ne, f, track2, c+wei, index, c_list);
    }
  }
}


int main(){
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    x[a].push_back(P(b, c));
    x[b].push_back(P(a, c));
    e[i] = P(a, b);
  }

  int track[300];
  fill(track, track+300, 0);

  for(int i = 0; i < M; i++){
    vector<int> c_list;
    int st = e[i].first, en = e[i].second;
    int track[300];
    fill(track, track+300, 0);
    track[st] = 1;
    int index = judge(st, en, track, 0, 0, c_list);

    int k = 0, count = 0;
    for(int j = 0; j < index; j++){
      if(c_list[i] != 0 && c_list[i] != k){
        cout << "No" << endl;
        return 0;
      }
      else if(c_list[i] != 0){
        k = c_list[i];
      }
      else continue;
    }
    if(k != 0){
      count++;
    }
  }

  if(count )


  return 0;
}
c2
