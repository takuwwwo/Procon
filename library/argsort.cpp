template<class T>
vector<int> argsort(vector<T> v){
    vector<int> index(v.size());
    iota(index.begin(), index.end(), 0);

    sort(index.begin(), index.end(),
         [&v](const size_t &a, const size_t &b){
             return v[a] < v[b];
         });

    return index;
}

