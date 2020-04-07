// a と b の最大公約数を返す
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    // 再帰的に解く (x, y を入れ替えておく)
    ll d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

/**
 * ax + by = gcd(a, b)を満たすx, yを求める
 * @param a
 * @param b
 * @return P_res(gcd(a, b), P(x, y))
 */
pair<ll, pair<ll, ll>> extGCD(ll a, ll b){
    using P_xy = pair<ll, ll>;
    using P_res = pair<ll, pair<ll, ll>>;

    ll x, y;
    ll d = extGCD(a, b, x, y);
    P_res res = P_res(d, P_xy(x, y));
    return res;
}


ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}



// 素数判定
bool is_prime(ll N) {
    if (N == 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}


// 約数列挙
vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}


// 素因数分解
vector<pair<ll, ll>> prime_factorize(ll N){
    vector<pair<ll, ll>> res;
    for(ll i = 2; i * i <= N; i++){
        if(N % i != 0)  continue;
        ll ex = 0;

        while(N % i == 0){
            ex++;
            N /= i;
        }

        res.push_back({i, ex});
    }

    if(N != 1)  res.push_back({N, 1});
    return res;
};


ll euler(ll N){
    vector<P> f = prime_factorize(N);
    ll res = N;
    for(auto p: f){
        res /= p.fs;
        res *= p.fs - 1;
    }

    return res;
}
