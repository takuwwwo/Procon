#include <iostream>
#include <complex>

using namespace std;

typedef long long ll;

typedef complex<double> P;
const double pi = 4.0*atan(1.0);
const P I(0, 1);

void *fft(P f[], int n, int sign){
  if (n==1){
    return f;
  }

  P *f_0;
  P *f_1;
  f_0 = new P[n/2];
  f_1 = new P[n/2];
  for(int i = 0; i < n/2; i++){
    f_0[i] = f[2*i+0];  //f0(x)を求めた
    f_1[i] = f[2*i+1];  //f1(x)を求めた
  }
  fft(f_0, n/2, sign);
  fft(f_1, n/2, sign);
  double theta = sign*2*pi/n;

  for(int i = 0; i < n; i++){
    P pow_zeta = exp(i*theta*I);
    f[i] = f_0[i % (n/2)] + pow_zeta * f_1[i%(n/2)];
  }
  free(f_0);
  free(f_1);
}

int N;

int main(){
  P a[265000],b[265000];
  cin >> N;

  ll n = 1;
  while(n < 2*N-1){
    n *= 2;
  }
  for(int i = 0; i < n; i++){
    a[i] = P(0.0, 0.0);
    b[i] = P(0.0, 0.0);
  }

  for(int i = 0; i < N; i++){
    double x, y;
    cin >> x >> y;
    a[i] = P(x, 0.0);
    b[i] = P(y, 0.0);
  }

  fft(a, n, 1);
  fft(b, n, 1);
  for(int i = 0; i < n; i++)  a[i] *= b[i];
  fft(a, n, -1);

  cout << 0 << endl;
  for(int i = 0; i < 2*N-1; i++){
    cout << (ll)(a[i].real()/n+0.5) << endl;
  }

  return 0;
}
