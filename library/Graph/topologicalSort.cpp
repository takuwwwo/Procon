vector<int> topologicalSort(Graph g){
    int n = g.size();
    vector<int> h(n, 0);

    for(int i = 0; i < n; i++){
        for(auto e: g[i]){
            h[e.vertice]++;
        }
    }

    stack<int> st;
    for(int i = 0; i < n; i++){
        if(h[i] == 0){
            st.push(i);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        int v = st.top(); st.pop();    // 次数が0の頂点を取り出す
        ans.push_back(v);
        for(auto e: g[v]){
            if(--h[e.vertice] == 0){
                st.push(e.vertice);
            }
        }
    }

    return ans;
}
