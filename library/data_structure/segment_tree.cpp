template <typename T>
class SegmentTree {
private:
    using F = function<T(T, T)>;
    int n, sz;
    vector<T> node;
    T u;
    F f;

    T query(int a, int b, int i, int l, int r) {
        if(r <= a || b <= l) {
            return u;
        }
        else if(a <= l && r <= b) {
            return node[i];
        }
        else {
            T vl = query(a, b, 2 * i + 1, l, (l + r) / 2);
            T vr = query(a, b, 2 * i + 2, (l + r) / 2, r);
            return f(vl, vr);
        }
    }

public:
    /**
     *
     * @param v  初期配列
     * @param func  nodeに対する操作
     * @param u2  Tの単位元
     */
    SegmentTree(vector<T> &v, const F func, T u2) : f(func), u(u2) {
        sz = v.size();
        n = 1;
        while(n < sz) {
            n *= 2;
        }
        node.resize(2 * n - 1, u2);
        for(int i = 0; i < sz; i++) {
            node[i + n - 1] = v[i];
        }
        for(int i = n - 2; i >= 0; i--) {
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    void update(int i, T val) {
        i += (n - 1);
        node[i] = val;
        while(i > 0) {
            i = (i - 1) / 2;
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    T query(int l, int r){
        return query(l, r, 0, 0, n);
    }

    T operator[](const int &i) const { return node[i + n - 1]; }
};
