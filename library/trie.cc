class Trie{
public:
    Trie *zero, *one;
    ll depth;

    Trie(ll d){
        zero = nullptr;
        one = nullptr;
        depth = d;
    }

    void make_zero(){
        if(zero==nullptr){
            zero = new Trie(depth+1);
        }
    }

    void make_one(){
        if(one==nullptr){
            one = new Trie(depth+1);
        }
    }
};
