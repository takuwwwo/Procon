#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
typedef long long ll;

ll N;
ll D;
double dp[2][205][103][103];  //N, 2, 3, 5

int main(){
    cin >> N >> D;
    int x2 = 0, x3 = 0, x5 = 0;
    while(D % 2 == 0){
        D /= 2; x2++;
    }
    while(D % 3 == 0){
        D /= 3; x3++;
    }
    while(D % 5 == 0){
        D /= 5; x5++;
    }
    if(D != 1){
        cout << 0.0 << endl;
        return 0;
    }

    dp[0][2][1][1] = 1.0;
    int count = 1;
    for(int i = 1; count <= N; i = 1 - i, count++){
        for(int j2 = 2; j2 <= count*2+2; j2++){
            for(int j3 = 1; j3 <= count+1; j3++){
                for(int j5 = 1; j5 <= count+1; j5++){
                    dp[i][j2][j3][j5] = (dp[1-i][j2][j3][j5] +
                                        dp[1-i][j2-1][j3][j5] +
                                        dp[1-i][j2][j3-1][j5] +
                                        dp[1-i][j2-2][j3][j5] +
                                        dp[1-i][j2][j3][j5-1] +
                                        dp[1-i][j2-1][j3-1][j5])/6.0;
                }
            }

        }
    }

    double p = 0.0;
    for(int i2 = x2+2; i2 <= N*2+2; i2++){
        for(int i3 = x3+1; i3 <= N+1; i3++){
            for(int i5 = x5+1; i5 <= N+1; i5++) {
                p += dp[N%2][i2][i3][i5];
            }
        }
    }

    printf("%.10f\n", p);

    return 0;
}

