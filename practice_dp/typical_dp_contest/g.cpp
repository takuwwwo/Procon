#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <limits.h>

using namespace std;
typedef long long ll;
string s;
ll dp[1000100];
ll K;
int place[1000100][26];
ll ma = LLONG_MAX/2;

int l(int x){
    return s[x] - 'a';
}

int main(){
    cin >> s;
    cin >> K;

    int len = s.length();

    fill(place[len], place[len]+26, -1);
    for(int i = len-1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            place[i][j] = place[i+1][j];
        }
        place[i][l(i)] = i;
    }


    dp[len] = 1;
    dp[len-1] = 2;
    for(int i = len-2; i >= 0; i--){
        if(place[i+1][l(i)] == -1){
            dp[i] = min(2 * dp[i+1], ma);
        }
        else{
            dp[i] = min(2 * dp[i+1] - dp[place[i+1][l(i)]+1], ma);
        }
    }

    int locate = -1, c = 0;
    ll su = 0;
    while(locate < len){
        if(su == K) break;
        if(c >= 26) {
            cout << "Eel" << endl;
            break;
        }

        int p = place[locate+1][c];
        if(p == -1) {
            c++;
            continue;
        }

        if(su + dp[p+1] < K){
            su += dp[p + 1];
            c++;
        }
        else{
            c = 0;
            su++;
            locate = p;
            cout << s[p];
        }
    }
    cout << endl;

    /*for(int i = 0; i <= len; i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    */

    return 0;
}
