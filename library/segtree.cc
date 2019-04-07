
#define MAX_N 210000
template<typename T>
class SegTree{
public:
    //セグメント木を持つグローバル変数
    int n;
    T dat[2 * MAX_N - 1];

    void init(int n_, T init_num){
        n = 1;
        while(n < n_) n *= 2;
        for(int i = 0; i < 2*n-1; i++){
            dat[i] = init_num;
        }
    }

    // k番目の値(0-indexed)をaに変更
    void update(int k, T a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }

    // [a, b)の最小値を求める。
    // kは節点の番号、l, rはその節点が[l, r)に対応づいていることを表す。
    // query(a, b, 0, 0, n)で外からは呼び出す。
private: T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return (1LL<<31)-1;
        }

        if (a <= l && r <= b) {
            return dat[k];
        } else {
            ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    // [a, b)の最小値を求める。
public: T query(int a, int b){
        return query(a, b, 0, 0, this->n);
    }
};
