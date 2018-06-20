#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int x[100010][26];

int main(){
    string s;
    cin >> s;

    int len = s.length();

    if(((s[0] == s[len-1]) + (len % 2 == 0)) % 2 == 0){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }


    return 0;
}
