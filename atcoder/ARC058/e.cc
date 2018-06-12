#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
ll fact[200200];
ll invfact[200200];

inline ll take_mod(ll a){
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b){
    return take_mod(a+b);
}

inline ll sub(ll a, ll b){
    return take_mod(a-b);
}


inline ll mul(ll a, ll b){
    a = take_mod(a);
    b = take_mod(b);
    return take_mod(a*b);

}

inline ll pow(ll x, ll n){
    ll res = 1LL;
    while(n > 0){
        if(n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return pow(x, mod-2);
}

// nは上限
void make_fact(ll n){
    fact[0] = 1;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = res;
        res = mul(res, i+1);
    }
}

// nは上限
void make_invfact(ll n){
    invfact[0] = 1;
    invfact[n] = mod_inv(fact[n]);
    for(int i = n-1; i >= 1; i--){
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}

ll comb(ll n, ll k){
    return mul(mul(fact[n], invfact[n-k]), invfact[k]);
}

ll dp[41][1<<16];
int bit16 = (1<<16)-1;

int main(){
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    for(int i = 0; i < 41; i++){
        for(int j = 0; j <= bit16; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < (1<<16); j++){
            for(int k = 1; k <= 10; k++){
                int hist = ((j << k) | (1 << (k-1)));
                if(((hist>>(Z-1)) & 1) == 1 && ((hist>>(Y+Z-1)) & 1) == 1 && ((hist>>(X+Y+Z-1) & 1) == 1)){
                    continue;
                }
                int pos = hist & bit16;
                dp[i][pos] = add(dp[i][pos], dp[i-1][j]);
            }
        }
    }

    ll res = 1;
    for(int i = 0; i < N; i++){
        res = mul(res, 10);
    }
    for(int i = 0; i < (1<<16); i++){
        res = sub(res, dp[N][i]);
    }
    cout << res << endl;

    return 0;

}
