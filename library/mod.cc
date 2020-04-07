class modInt{
    ll value;
    static const ll mod = 1000000007;

public:
    modInt(ll x=0): value{x % mod}{}

    inline modInt& operator+=(modInt x){
        value = (value + x.value) % mod;
        return *this;
    }

    inline modInt& operator-=(modInt x){
        value = (value + mod - x.value) % mod;
        return *this;
    }

    inline modInt& operator*=(modInt x){
        value = (value * x.value) % mod;
        return *this;
    }


    inline modInt operator/=(modInt x){
        *this *= x.inv();
        return *this;
    }

    inline modInt pow(modInt x, int n){
        modInt res = modInt(1LL);
        while(n > 0){
            if(n & 1)   res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    inline modInt inv(){
        modInt res = pow(value, mod-2);
        return res;
    }

    inline ll get(){
        return value;
    }
};

modInt operator+(modInt x, modInt y){
    return x += y;
}

modInt operator-(modInt x, modInt y){
    return x -= y;
}

modInt operator*(modInt x, modInt y){
    return x *= y;
}

modInt operator/(modInt x, modInt y){
    return x /= y;
}

ostream& operator<<(ostream& os, modInt x){
    return os << x.get();
}


class modIntCombinations{
    vector<modInt> factArray;

    void make_fact(ll x){
        for(auto i = factArray.size(); i <= x+1; i++){
            modInt y = factArray[i-1] * i;
            factArray.push_back(y);
        }
    }

public:
    modIntCombinations(){
        factArray.emplace_back(1);
    }

    modInt fact(ll x){
        if(factArray.size() < x+1){
            make_fact(x);
        }
        return factArray[x];
    }

    modInt comb(ll n, ll k){
        if(n < k){
            return modInt{0};
        }
        else{
            return fact(n) / fact(k) / fact(n - k);
        }
    }

    modInt perm(ll n, ll k){
        if(n < k){
            return modInt{0};
        }
        else{
            return fact(n) / fact(k);
        }
    }
};
