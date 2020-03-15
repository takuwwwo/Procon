int n, k;
int rank[MAX_N+1];
int tmp[MAX_N+1];

// (rank[i], rank[i+k])と(rank[j], rank[j+k])を比較
bool compare_sa(int i, int j){
    if(rank[i] != rank[j]){
        return rank[i] < rank[j];
    }
    else{
        int ri = i + k <= n ? rank[i+k] : -1;
        int rj = j + k <= n ? rank[j+k] : -1;
        return ri < rj;
    }
}

void construct_sa(string s, vector<int> sa){
    n = s.length();

    for(int i = 0; i <= n; i++){
        sa[i] = i;
        rank[i] = i < n ? s[i] : -1;
    }

    for(int k = 1; k <= n; k *= 2){
        sort(sa.begin(), sa.end(), compare_sa);

        tmp[sa[0]] = 0;
        for(int i = 1; i <= n; i++){
            tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
        }
        for(int i = 0; i <= n; i++){
            rank[i] = tmp[i];
        }
    }
}
