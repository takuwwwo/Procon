template<typename T>
class ZAlgorithm{
    T s;
    vector<int> a;

    void construct(){
        int c = 0;
        for(int i = 1; i < s.size(); i++){
            if(i + a[i-c] < c + a[c]){
                a[i] = a[i-c];
            }
            else{                                             // １つめのif文でjまでは一致していることが分かる
                int j = max(0, c+a[c]-i);
                while(i+j < s.size() && s[j] == s[i+j]) j++;
                a[i] = j;
                c = i;
            }
        }
        a[0] = s.size();
    }

public:
    ZAlgorithm(T ss){
        s = ss;
        a = vector<int>(ss.size());
        construct();
    }

    int get(int pos){   // 0-index
        return a[pos];
    }

    int operator[](int pos){
        return a[pos];
    }
};
