#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, K;
ll mo = 1000000007;

ll dp[1000010][3];

ll m(ll x, ll y){
    if(x >= 0)   return x % y;
    else return (y - (-x) % y) % y;
}

int main(){
    cin >> N >> K;
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    dp[1][0] = 1; dp[1][1] = 0; dp[1][2] = 1;
    dp[2][0] = 0; dp[2][1] = (K == 2) ? 0 : 1; dp[2][2] = dp[2][1];

    ll s = dp[1][2] + dp[2][2];
    for(int i = 3; i <= N; i++){
        if(i < K){
            dp[i][0] = m(s - dp[i-1][2], mo);
            dp[i][1] = m(dp[i-1][2], mo);
            dp[i][2] = m(dp[i][0] + dp[i][1], mo);
            s = m(s + dp[i][2], mo);
        }
        else {
            dp[i][0] = m(s - dp[i - 1][2], mo);
            dp[i][1] = m(dp[i - 1][2] - dp[i - K + 1][0], mo);
            dp[i][2] = m(dp[i][0] + dp[i][1], mo);
            s = m(s + dp[i][2], mo);
        }
    }

    cout << dp[N][2] << endl;

    return 0;
}
