template <typename T = string, typename S = char>
class Manacher{
    T s;
    vector<int> R;

    void construct(){
        int i = 0, j = 0;
        while(i < s.size()){
            while(i - j >= 0 && i + j < s.size() && s[i-j] == s[i+j]) j++;
            R[i] = j;
            int k = 1;
            while(i - k >= 0 && i + k < s.size() && k+R[i-k] < j){
                R[i+k] = R[i-k];
                k++;
            }
            i += k;
            j -= k;
        }
    }

public:
    explicit Manacher(T target, S dummy = '$'){
        s.push_back(dummy);
        for(int i = 0; i < target.size(); i++){
            s.push_back(target[i]);
            s.push_back(dummy);
        }
        unsigned int n = s.size();
        R = vector<int>(n, -1);
        construct();
    }

    /**
     *
     * @param pos: 求めたい半径の中心(0-indexed)
     * @return: posを中心とする奇数長の最長の回文の長さ
     */
    int getOddDiameter(int pos){
        return (R[pos * 2 + 1] / 2 - 1) * 2 + 1;
    }

    /**
     *
     * @param pos: 求めたい半径の中心(0-indexed)
     * @return posとpos+1の間を中心とする偶数長の最長の回文の長さ
     */
    int getEvenDiameter(int pos){
        return (R[pos * 2 + 2] - 1) / 2 * 2;
    }
};
