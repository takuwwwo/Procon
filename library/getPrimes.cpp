// nの素因数を返す。
vector<int> getPrimes(int n){
    vector<int> ret;
    for(int i = 2; i * i <= n; i++){
        int count = 0;
        while(n % i == 0){
            n /= i;
            if(count == 0){
                count++;
                ret.push_back(i);
            }
        }
    }

    if(n != 1){
        ret.push_back(n);
    }

    return ret;
}
