#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int dp[2][5010];
vector<int> a;

int main(){
    int N, K; cin >> N >> K;

    ll s = 0;
    for(int i = 0; i < N; i++) {
        int b;
        cin >> b;
        a.push_back(b);
        s += b;
    }
    if(s < K){
        cout << N << endl;
        return 0;
    }
    sort(a.begin(), a.end());

    int l = -1, r = N-1;
    while(r - l > 1){
        int m = (r + l) / 2;
        int b = a[m];
        int res = 0;
        if(b >= K)  res = 1;
        fill(dp[0], dp[0]+5010, 0);
        fill(dp[1], dp[1]+5010, 0);
        dp[0][0] = 1; dp[1][0] = 1;

        int x = -1;
        for(int i = 0; i < N; i++){
            if(i == m)  continue;
            x++;
            for(int j = a[i]; j < K; j++){
                dp[x%2][j] = max(dp[(x+1)%2][j], dp[(x+1)%2][j-a[i]]);
                if(j >= K-b && dp[x%2][j] == 1){
                    res = 1;
                    break;
                }
            }
            if(res == 1){
                break;
            }
        }

        if(res == 1){
            r = m;
        }
        else{
            l = m;
        }
    }

    cout << r << endl;

    return 0;
}
