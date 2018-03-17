#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int s[500010];
int N;
ll dp[500010];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        char c; cin >> c;
        if(c == '1') s[i] = 1;
        else s[i] = 0;
    }

    int prior = 0, state = 0, state2 = 0;
    int su = 0;

    dp[0] = 0;
    if(s[0] == 1){
        state = 1;
        su = 1;
    }


    // state 0 -> 00, state 1 -> 1, state 2 -> 10
    // state2 0 -> not exist 101 left side. state2 1 -> exist 101 left side.
    for(int i = 1; i < N; i++){
        cout << su << " ";
        if(s[i] == 1){
            if(state == 0){
                state = 1;
                su++;
            }
            else if(state == 1){
                state = 1;
                su++;
            }
            else{      //state == 2, complete 101
                state = 1;
                state2 = 1;
                dp[i] = dp[prior]+su;
                prior = i-1;
                su = 1;
                continue;
            }

            if(state2 == 1){
                dp[i] = max(dp[prior]+su, dp[prior+1]);
            }
            else{
                dp[i] = dp[i-1];
            }
        }

        else if(s[i] == 0){
            if(state == 1){
                state = 2;
            }
            else{   //state == 0 or state == 2
                state = 0;
                su = 0;
            }
            state2 = 0;
            dp[i] = dp[i-1];
        }
    }


    cout << endl;
    for(int i = 0; i < N; i++){
        cout << dp[i] << " ";
    }
    cout << endl;


    cout << dp[N-1] << endl;


    return 0;
}
