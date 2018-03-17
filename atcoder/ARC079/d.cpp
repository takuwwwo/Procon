#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

ll K;

int main(){
    cin >> K;
    ll N = 50;

    cout << N << endl;
    ll x = K / N;
    ll y = K % N;
    for(int i = 0; i < N; i++){
        if(i < y)
            cout << N + x << " ";
        else
            cout << max(N + x - y - 1, 0ll) << " ";
    }
    cout << endl;


    return 0;
}
