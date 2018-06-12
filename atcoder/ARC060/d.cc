#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

ll sqrt(ll x){
    ll res = 0LL;
    while((res+1) * (res+1) <= x){
        res++;
    }
    return res;
}

int main(){
    ll n, s;    cin >> n >> s;
    ll n_sqrt = sqrt(n);

    for(ll b = 2; b <= n_sqrt; b++){
        ll n_tmp = n;
        ll s_can = 0;
        while(b <= n_tmp){
            s_can += n_tmp % b;
            n_tmp /= b;
        }
        s_can += n_tmp;
        if(s_can == s){
            cout << b << endl;
            return 0;
        }
    }

    for(ll a = min(n_sqrt, s); a >= 1; a--){
        if(n-s+a < 0)   continue;
        if((n-s+a) % a == 0) {
            ll b = (n-s+a)/a;
            if(b >= 2 && a < b && (s-a) < b){
                cout << b << endl;
                return 0;
            }
        }
    }

    if(n == s){
        cout << n+1 << endl;
        return 0;
    }

    cout << -1 << endl;

    return 0;

}
