class RollingHash{
private:
    static ll mod;

public:
    set<ll> hash[1001000];
    RollingHash(){
        random_device rnd;
        mt19937 mt(rnd());
        uniform_int_distribution<> rand_mod(100000, 1000000);

        mod = rand_mod(mt);
    }

    void add(ll hash_num){
       hash[hash_num % mod].insert(hash_num);
    }

    bool search(ll hash_num){
        return hash[hash_num % mod].find(hash_num) != hash[hash_num % mod].end();
    }
};
