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
    if (b == 0) return 0;
    ll res = mul(add(a, a), b >> 1);
    if(b & 1) res = add(res, a);
    return res;
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
