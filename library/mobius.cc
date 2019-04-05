bool isprime[101000];
ll meb[101000];


void mobius(ll m){
    fill(isprime, isprime+m+1, true);
    fill(meb, meb+m+1, -1);
    for(ll i = 2; i <= m; i++){
        if(!isprime[i]){
            continue;
        }
        for(ll j = 2; i*j <= m; j++){
            isprime[i*j] = false;
        }
        meb[i] = 1;
        for(ll j = 2; i*j <= m; j++){
            meb[i*j] *= (-1);
            if(j % i == 0){
                meb[i*j] = 0;
            }
        }
    }
}
