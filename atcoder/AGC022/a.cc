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
  int c[26];
  fill(c, c+26, 0);

  for(int i = 0; i < s.length(); i++){
    c[s[i]-'a'] = 1;
  }
  if (s.length() <= 25){
    for(int i = 0; i < 26; i++){
      if(c[i] == 0){
        char z = 'a'+i;
        cout << s << z << endl;
        return 0;
      }
    }
  }
  else{
    for(int i = 25; i >= 1; i--){
      if(s[i-1] > s[i]){
        c[s[i]-'a'] = 0;
      }
      else{
        c[s[i]-'a'] = 0;
        int z = s[i-1] - 'a';
        for(int j = z; j < 26; j++){
          if(c[j] == 0){
            for(int k = 0; k < i-1; k++){
              cout << s[k];
            }
            char p = 'a' + j;
            cout << p << endl;
            return 0;
          }
        }
      }
    }
    cout << -1 << endl;
  }

  return 0;
}
