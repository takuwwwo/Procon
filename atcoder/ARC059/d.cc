#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int s[100010];
int x[26];

int main(){
    string ss;  cin >> ss;
    for(int i = 0; i < ss.length(); i++) {
        s[i] = ss[i] - 'a';
    }

    for(int i = 0; i < 26; i++){
        x[i] = -30;
    }

    for(int i = 0; i < ss.length(); i++){
        if (i - x[s[i]] <= 2) {
            cout << x[s[i]]+1 << " " << i+1 << endl;
            return 0;
        }
        else{
            x[s[i]] = i;
        }
    }

    cout << -1 << " " << -1 << endl;

    return 0;

}
