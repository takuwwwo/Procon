#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int N;
int a[100020];

int main(){
  cin >> N;
  for(int i = 0; i < N; i++)  cin >> a[i];

  int c1 = 0, c2 = 0, c4 = 0;
  for(int i = 0; i < N; i++){
    if(a[i] % 2 == 1) c1++;
    else if(a[i] % 4 == 0)  c4++;
    else c2++;
  }

  if(c4 >= c1)  cout << "Yes" << endl;
  else if(c1 - c4 == 1 && c2 == 0)  cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
