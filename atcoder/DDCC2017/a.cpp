#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  string s; cin >> s;
  if(s[0] == s[1] && s[1] != s[2] && s[2] == s[3])  cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
