#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <random>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll H, W, N;
vector<P> st;

int main(){
  cin >> H >> W >> N;
  ll res[10];

  for(int i = 0; i < 10; i++) res[i] = 0;

  for(int i = 0; i < N; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    for(int i = max(a-2, 0); i <= a; i++){
      if(i + 2 >= H)  break;
      for(int j = max(b-2, 0); j <= b; j++){
        if(j + 2 >= W)  break;
        st.push_back(P(i, j));
      }
    }
  }
  sort(st.begin(), st.end());
  int num = 0;
  int i = 0;
  while(1){
    if(i >= st.size())  break;
    int l = i, r = st.size();
    while(r - l > 1){
      int m = (l + r) / 2;
      if(st[i] == st[m]){
        l = m;
      }
      else{
        r = m;
      }
    }
    res[l-i+1]++;
    i = l+1;
  }
  ll sum = 0;
  for(int i = 1; i < 10; i++) sum += res[i];
  res[0] = (H-2)*(W-2) - sum;

  for(int i = 0; i < 10; i++){
    cout << res[i] << endl;
  }

  return 0;
}
