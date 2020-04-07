template<typename T>
class KMP{
    vector<int> a;
    T s;

public:
    KMP(T s_arg): s(s_arg){
        int n = s_arg.size();
        a = vector<int>(n+1, -1);   // a[j+1]が[0, j]のboarderの最大の長さ
        constructBorderArray();
    }

    void constructBorderArray(){
        int j = -1;
        for(int i = 0; i < s.size(); i++){
            while(j >= 0 && s[i] != s[j]){
                j = a[j];
            }

            j++;
//            if(s[i+1] == s[j]) a[i+1] = a[j];
//            else a[i+1] = j;
            a[i+1] = j;
        }
    }

    /**
     *
     * @param x: sとマッチングさせる配列
     * @return : マッチング位置
     */
    vector<int> search(T x, int pos=0){
        int j = 0;
        vector<int> res;
        for(int i = pos; i < x.size(); i++){
            while(j >= 0 && x[i] != s[j]){
                j = a[j];
            }
            j++;
            if(j == s.size()){
                res.push_back(i - j + 1);
                j = a[j];
            }
        }
        return res;
    }

    int periodicity(int pos){
        return pos - a[pos];
    }

};
