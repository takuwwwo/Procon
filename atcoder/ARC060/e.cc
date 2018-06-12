#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int N, Q, L;
int x[100010];
int h[20][100010];
int p2[30];

int main(){
    int p = 1;
    for(int i = 0; i < 30; i++){
        p2[i] = p;
        p *= 2;
    }

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    cin >> L >> Q;

    for(int i = 0; i < N; i++){
        int l = i, r = N;
        while(r - l > 1){
            int m = (r + l) / 2;
            if(x[m] - x[i] <= L)   l = m;
            else r = m;
        }
        h[0][i] = l;
    }

    for(int k = 1; k < 20; k++){
        for(int i = 0; i < N; i++){
            h[k][i] = h[k-1][h[k-1][i]];
        }
    }

    for(int q = 0; q < Q; q++){
        int a, b; cin >> a >> b;
        a--; b--;
        if(a > b)   swap(a, b);
        int res = 0;
        int cur = a;

        while(cur != b) {
            int l = 0, r = 20;
            while(r - l > 1){
                int m = (l + r) / 2;
                if(h[m][cur] <= b)  l = m;
                else r = m;
            }
            int k = l;
            res += p2[k];
            cur = h[k][cur];
        }
        cout << res << endl;
    }

    return 0;
}
