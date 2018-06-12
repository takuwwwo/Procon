#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
  int a, b;
  int N;
  cin >> a >> b >> N;

  char c;
  for(int i = 0; i < N; i++){
    cin >> c;
    if (c == 'S'){
      a = max(a-1, 0);
    }
    else if(c == 'C'){
      b = max(b-1, 0);
    }
    else{
      if(a >= b){
        a = max(a-1, 0);
      }
      else{
        b = max(b-1, 0);
      }
    }
  }
  cout << a << endl;
  cout << b << endl;


  return 0;
}
