template<typename T>
class Manacher{
public:
    vector<int> r;
    T s;

    Manacher(T s2, int n){
        s = s2;
        for(int i = 0; i < n; i++){
            r.push_back(0);
        }
    }

    void exec(){
       int i = 0, j = 0;
       while(i < s.size()){
           while(i - j >= 0 && i + j <= s.size() && s[i-j] == s[i+j]){
               j++;
           }
           r[i] = j;
           int k = 1;
           while(i - k >= 0 && i + k < s.size() && k+r[i-k] < j){  //はみ出るまで続ける
               r[i+k] = r[i-k];
               k++;
           }
           i += k;  //はみ出たら最初から
           j -= k;
       }
    }
};
