#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int N;
int x_1[210], y_1[210];
int x_2[210], y_2[210];
int main(){
  fill(x_1, x_1+210, -1);
  fill(y_1, y_1+210, -1);
  fill(x_2, x_2+210, -1);
  fill(y_2, y_2+210, -1);

  int a[200], b[200], c[200], d[200];
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> a[i] >> b[i];
    x_1[a[i]] = i; y_1[b[i]] = i;
  }
  for(int i = 0; i < N; i++){
    cin >> c[i] >> d[i];
    x_2[c[i]] = i; y_2[d[i]] = i;
  }

  int count = 0;
  for(int i = 2*N-1; i >= 0; i--){
    if(x_1[i] == -1) continue;
    int j_min = -1;
    int mi = 1000;
    for(int j = i+1; j < 2*N; j++){
      if(x_2[j] == -1) continue;
      if(b[x_1[i]] < d[x_2[j]]){
        if (d[x_2[j]] < mi){
          mi = d[x_2[j]];
          j_min = j;
        }
      }
    }
    if(j_min != -1){
      x_2[j_min] = -1;
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
