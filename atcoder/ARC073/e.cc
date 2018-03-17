#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int N;
P x[200100];

bool comp(P p, P q){
  if(p.first == q.first)  return p.second < q.second;
  else  return p.first < q.first;
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    ll a, b;
    cin >> a >> b;
    x[i].first = min(a, b);
    x[i].second = max(a, b);
  }
  sort(x, x+N, comp);
  ll y_min = 1e9, y_max = 0;
  for(int i = 0; i < N; i++){
    y_min = min(y_min, x[i].second);
    y_max = max(y_max, x[i].second);
  }

  //全体の最大値と最小値がセット。
  ll r = x[N-1].first - x[0].first;
  ll ma = x[N-1].first, mi = 1e9;
  for(int i = 0; i < N-1; i++){
    ma = max(ma, x[i].second);
    mi = min(mi, x[i].second);
    r = min(ma - min(x[i+1].first, mi), r);
    //cout << ma << " " << mi << " " << r << endl;
  }

  //cout << ma << endl;
  //cout << r << endl;
  //全体の最大値と最小値が違うセットも込
  cout << min(r*(y_max - x[0].first), (x[N-1].first - x[0].first)*(y_max - y_min)) << endl;

  return 0;
}
