#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  string s;
  cin >> s;

  if(s.length() >= 4 && s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I'){
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
  return 0;
}
