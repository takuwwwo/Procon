template<typename T>
map<T, T> compress(vector<T> &x){
    map<T, T> zip;  //圧縮前の座標、圧縮後の座標

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    for(int i = 0; i < x.size(); i++){
        zip[x[i]] = i;
    }
    return zip;
}
