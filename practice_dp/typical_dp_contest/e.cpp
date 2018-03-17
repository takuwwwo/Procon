#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int D;
string s;
ll dp[100][10010];
ll mo = 1000000007;

int surplus(int x, int y){
    if(x >= 0)   return x % y;
    else return (y - (-x) % y) % y;
}

int main(){
    cin >> D;
    cin >> s;

    int digits = s.length();

    for(int i = 0; i < D; i++){
        for(int j = 0; j <= digits; j++)
            dp[i][j] = 0;
    }
    for(int i = 0; i < 10; i++){
        dp[i % D][0]++;
    }

    for(int j = 1; j < digits; j++){
        for(int i = 0; i < D; i++){
            for(int k = 0; k < 10; k++){
                dp[(i+k)%D][j] = (dp[(i+k)%D][j] + dp[i][j-1]) % mo;
            }
        }
    }


    ll su = 0;
    su = (su + dp[0][digits-2] - 1) % mo;
    int x = s[0] - '0';
    int y = x;
    for(int j = 1; j < x; j++) {
        su = (su + dp[surplus(-j, D)][digits-2]) % mo;
    }
    for(int i = digits-2; i >= 1; i--){
        x = s[digits - i - 1] - '0';
        for(int j = 0; j < x; j++) {
            su = (su + dp[surplus(-y-j, D)][i - 1]) % mo;
        }
        y += x;
    }
    x = s[digits-1] - '0';
    su = (su + (y%D+x+1)/D) % mo;

    cout << su << endl;


    return 0;

}
