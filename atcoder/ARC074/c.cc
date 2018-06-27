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


int main(){
    ll H, W;    cin >> H >> W;

    ll res = min(H*(H % 3 != 0), W*(W % 3 != 0));


    for(int i = 1; i <= H; i++){
        ll S_max = max(i*W, (W-W/2)*(H-i));
        ll S_min = min(i*W, (W/2)*(H-i));
        res = min(res, S_max - S_min);
    }

    for(int i = 1; i <= W; i++){
        ll S_max = max(i*H, (H-H/2)*(W-i));
        ll S_min = min(i*H, (H/2)*(W-i));
        res = min(res, S_max - S_min);
    }

    cout << res << endl;

    return 0;
}
