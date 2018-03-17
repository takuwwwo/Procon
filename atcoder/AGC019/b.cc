#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

ll x[26];

int main(){
  string s;
  cin >> s;
  fill(x, x+26, 0);

  ll len = s.length();
  ll su = len * (len-1) / 2 + 1;
  for(int i = 0; i < len; i++){
    x[s[i] - 'a']++;
  }
  for(int i = 0; i < 26; i++){
    su -= x[i] * (x[i] - 1) / 2;
  }

  cout << su << endl;

  return 0;
}
