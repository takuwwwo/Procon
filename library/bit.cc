#define MAX_N 200000

ll bit[MAX_N+1];

void init(int n){
    for(int i = 0; i < n; i++){
        bit[i] = 0;
    }
}

// indexが0~iまでの和を求める。
ll sum(int i){
    ll s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & (-i);
    }
    return s;
}

// iがindex, xが加える値, nが全体の配列の大きさ
void add(int i, ll x, int n){
    while(i <= n){
        bit[i] += x;
        i += i & (-i);
    }
}
