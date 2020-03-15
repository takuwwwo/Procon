ll d[MAX_V][MAX_V];
ll inf = 1e9+7;
void init(int V){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(i == j){
                d[i][j] = 0;
            }
            else{
                d[i][j] = 1e8;
            }
        }
    }
}

void warshall_floyd(int V){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
