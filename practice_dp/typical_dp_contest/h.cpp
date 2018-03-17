#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;
typedef long long ll;

string s;
int x[210000][26];

int main(){
    cin >> s;
    int l = s.length();

    for(int i = 0; i < 26; i++) x[l][i] = -1;
    for(int i = l-1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            x[i][j] = x[i+1][j];
        }
        x[i][s[i]-'a'] = i;
    }

    int res[6];
    for(int i = 0; i < 6; i++){
        res[i] = -1;
    }
    res[5] = 0;

    while(1){
        int s = 0;
        bool ok = false;
        for(int i = 0; i < 6; i++){
            if(res[i] == -1)  continue;
            else{
                s = x[s][res[i]];
                if(s == -1){
                    ok = true;
                    break;
                }
                else{
                    s++;
                }
            }
        }
        if(ok)  break;

        for(int i = 5; i >= 0; i--){
            if(res[i] == 26)  res[i-1]++;
        }
    }

    for(int i = 0; i < 6; i++){
        if(res[i] != -1){
            printf("%c", res[i] + 'a');
        }
    }

    return 0;
}
