#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define N 262144
P x[N+10],b[N+10];
const double pi = 4.0*atan(1.0);
const P I(0, 1);
void fft(int n, double theta, P a[]) {
  for (int m = n; m >= 2; m >>= 1) {
    int mh = m >> 1;
    for (int i = 0; i < mh; i++) {
      P w = exp(i*theta*I);
      for (int j = i; j < n; j += m) {
        int k = j + mh;
        P x = a[j] - a[k];
        a[j] += a[k];
        a[k] = w * x;
      }
    }
    theta *= 2;
  }
  int i = 0;
  for (int j = 1; j < n - 1; j++) {
    for (int k = n >> 1; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
}
int main()
{
	int i,n;
	cin>>n;
	rep(i,n) cin>>x[i].real()>>b[i].real();
	fft(N,2*pi/N,x);fft(N,2*pi/N,b);
	rep(i,N) x[i]*=b[i];
	fft(N,-2*pi/N,x);
	cout<<0<<endl;
	rep(i,2*n-1) cout<<(lint)(x[i].real()/N+0.5)<<endl;
}
