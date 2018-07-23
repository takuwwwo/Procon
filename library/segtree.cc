const ll MAX_N = 1 << 17;
struct SegTree{
  //セグメント木を持つグローバル変数
  int n;
  ll dat[2 * MAX_N - 1];

  void init(int n_, ll init_num){
    n = 1;
    while(n < n_) n *= 2;
    for(int i = 0; i < 2*n-1; i++){
      dat[i] = init_num;
    }
  }
