map<ll, ll> zip;  //圧縮前の座標、圧縮後の座標

int compress(vector<ll> &x){
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    for(int i = 0; i < x.size(); i++){
        zip[x[i]] = i;
    }
    return (int)x.size();
}
