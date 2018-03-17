#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  string s;
  cin >> s;
  for(int i = 0; i < s.length() - 8; i++){
    cout << s[i];
  }
  cout << endl;
  return 0;
}
