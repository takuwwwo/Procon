#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;
typedef long long ll;

string s;
int x[26];

int main(){
  cin >> s;
  int l = s.length();
  int y = 0, c = 0;
  int fis = 0, las = -1;

  for(int i = 0; i < 26; i++) x[i] = 0;
  for(int i = 0; i < l; i++){
    int z = s[i] - 'a';
    if(x[z] == 0){
      x[z]++;
      c++;
    }
    if(c == 26){
      for(int j = 0; j < 26; j++) x[j] = 0;
      c = 0;
      y++;
      las = i;
    }
  }

  c = 0;
  for(int i = 0; i < 26; i++) x[i] = 0;
  for(int i = l-1; i >= 0; i--){
    int z = s[i] - 'a';
    if(x[z] == 0){
      x[z]++;
      c++;
    }
    if(c == 26){
      fis = i;
    }
  }

  for(int i = 0; i < 26; i++) x[i] = -1;
  for(int i = fis; i <= las; i++){
    int z = s[i] - 'a';
    x[z] = i;
  }

  int l2;
  for(int i = 0; i < 26; i++){
    if(x[i] != -1){
      l2 = i;
      las = x[i];
    }
  }

  for(int i = 0; i < 26; i++) x[i] = 0;
  for(int i = las+1; i < l; i++){
    int z = s[i] - 'a';
    x[z]++;
  }
  int l1;
  for(int i = 0; i < 26; i++){
    if(x[i] == 0){
      l1 = 1;
    }
  }

  if(y == 0){
    printf("%c", l1 + 'a');
  }
  else{
    for(int j = y-2; j > 0; j--){
      putchar('a');
    }
    printf("%c", l2 + 'a');
    printf("%c", l1 + 'a');
  }
  cout << endl;

  return 0;
}
