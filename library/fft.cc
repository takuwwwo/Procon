typedef complex<double> P;

const P I(0, 1);

typedef complex<double> P;
const double pi = 4.0*atan(1.0);
const P I(0, 1);

void *fft(P f[], int n, int sign){
  if (n==1){
    return f;
  }

  P *f0;
  P *f1;
  f0 = new P[n/2];
  f1 = new P[n/2];
  for(int i = 0; i < n/2; i++){
    f0[i] = f[2*i+0];  //f0(x)を求めた
    f1[i] = f[2*i+1];  //f1(x)を求めた
  }
  fft(f0, n/2, sign);
  fft(f1, n/2, sign);
  double theta = sign*2*pi/n;

  for(int i = 0; i < n; i++){
    P pow_zeta = exp(i*theta*I);
    f[i] = f0[i % (n/2)] + pow_zeta * f1[i%(n/2)];
  }
  free(f0);
  free(f1);
}
