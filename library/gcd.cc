ll gcd(ll a, ll b){
    if(a == 0 || b == 0){
        return 0;
    }
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
