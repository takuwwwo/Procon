#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int validate[31000];

int main(){
  int n;  cin >> n;
  if (n == 3){
    cout << 2 << " " << 3 << " " << 25 << endl;
    return 0;
  }
  if (n == 4){
    cout << 2 << " " << 3 << " " << 4 << " " << 9 << endl;
    return 0;
  }

  fill(validate, validate+30500, 0);

  int s = 2;
  int t = 3;
  while(n > 2){
    if(s < t){
      cout << s << " ";
      validate[s] += 1;
      s += 2;
      n--;
    }
    else{
      cout << t << " " << t+6 << " ";
      validate[t] += 1;
      validate[t+6] += 1;

      t += 12;
      n -= 2;
    }
  }

  int x = (2+(s-2))*((s-2)/2)/2;
  if(x % 6 == 2){
    if(n == 2){
      validate[30000] += 1;
      cout << 30000 << " ";
    }
    validate[29998] += 1;
    cout << 29998 << endl;
  }
  else if(x % 6 == 4){
    if(n == 2){
      validate[30000] += 1;
      cout << 30000 << " ";
    }
    validate[29996] += 1;
    cout << 29996 << endl;
  }
  else{
    if(n == 2){
      validate[29996] += 1;
      cout << 29996 << " ";
      validate[29998] += 1;
      cout << 29998 << endl;
    }
    else{
      validate[30000] += 1;
      cout << 30000 << endl;
    }
  }

  for(int i = 2; i <= 30500; i++){
    if(validate[i] >= 2){
      cout << i << endl;
    }
    else if(validate[i] >= 1 && i > 30000){
      cout << i << endl;
    }
  }

  return 0;
}
