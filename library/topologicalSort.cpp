
#define MAX_V 101000
vector<int> edge[MAX_V];

/**
 *
 * @param N 頂点数(0-indexed)
 * @return
 * もし、グラフがDAGでなければ、全ての頂点を含まないvectorを返す
 */
vector<int> topologicalSort(int N){
    stack<int> st;
    int h[MAX_V];
    fill(h, h+MAX_V, 0);
    for(int i = 0; i < N; i++){
        for(auto j: edge[i]){
            h[j]++;
        }
    }

    for(int i = 0; i < N; i++){
        if(h[i] == 0){
            st.push(i);
        }
    }

    vector<int> ans;
    while(st.size()){
        int i = st.top(); st.pop();
        ans.push_back(i);
        for(auto j: edge[i]){
            h[j]--;
            if(h[j] == 0){
                st.push(j);
            }
        }
    }
    return ans;
}