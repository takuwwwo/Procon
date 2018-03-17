#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int N;
int q[210000];
int dat[2][300000];   //偶数位置
int MA = 3e6;
int halfN;
int n;

class T{
public:
  int a;
  int b;
  int c;
  int d;
  int i;

  T(int aa, int bb, int cc, int dd, int ii):a(aa), b(bb), c(cc), d(dd), i(ii){}

};

bool comp(T p, T q){
  if(p.c < q.c) return false;
  else return true;
}

priority_queue<T, vector<T>, decltype(&comp)> pq(&comp);

void init(int n_, int* da){
  n = 1;
  while(n < n_) n *= 2;

  for(int i = 0; i < 2*n-1; i++){
    da[i] = MA;
  }
}

//k番目をaに変更
void update(int k, int a, int* da){
  k += n-1;
  da[k] = a;
  while(k > 0){
    k = (k-1)/2;
    da[k] = min(da[k*2+1], da[k*2+2]);
  }
}

int query(int a, int b, int k, int l, int r, int* da){
  if(r <= a || b <= l) {
    //cout << 40 << endl;
    return MA;
  }
  if(a <= l && r <= b){
    //cout << 43 << " " << dat[k] << endl;
    return da[k];
  }
  else{
    int vl = query(a, b, k*2+1, l, (l+r)/2, da);
    int vr = query(a, b, k*2+2, (l+r)/2, r, da);
    //cout << "vl vr" << vl << " " << vr << endl;
    return min(vl, vr);
  }
}

void deal(){
  if(pq.empty())  return;
  T t = pq.top();
  cout << t.c << " " << t.d << " ";
  int s = t.a, e = t.b;
  pq.pop();

  int m1, m2;
  int i = t.i;
  m1 = query(s/2, q[t.c]/2, 0, 0, n, dat[i]);
  if (m1 < MA) {
    m2 = query((q[m1]+i)/2, (q[t.c]+i)/2, 0, 0, n, dat[1-i]);
    if(m2 < MA && s < q[t.c]) pq.push(T(s, q[t.c], m1, m2, i));
  }

  i = 1 - t.i;
  m1 = query((q[t.c]+1)/2, q[t.d]/2, 0, 0, n, dat[i]);
  if(m1 < MA){
    m2 = query((q[m1]+i)/2, (q[t.d]+i)/2, 0, 0, n, dat[1-i]);
    if(m2 < MA && q[t.c]+1 < q[t.d]) pq.push(T(q[t.c]+1, q[t.d], m1, m2, i));
  }

  i = t.i;
  m1 = query((q[t.d]+1)/2, e/2, 0, 0, n, dat[i]);
  if(m1 < MA){
    m2 = query((q[m1]+i)/2, (e+i)/2, 0, 0, n, dat[1-i]);
    if(m2 < MA && q[t.d]+1 < e) pq.push(T(q[t.d]+1, e, m1, m2, i));
  }

  deal();

  /*if(e <= s)  return ;

  //cout << 58 << endl;
  //cout << s/2 << " " << e/2 << endl;
  int m1 = query(s/2, e/2, 0, 0, n, dat[i]);
  if(m1 == MA)  return;
  //cout << 53 << endl; //cout << m1 << endl;
  int m2 = query((q[m1]+i)/2, (e+i)/2, 0, 0, n, dat[1-i]);
  if(m2 == MA)  return;
  //cout << 54 << " " << m2 << endl;
  pq.push(T(s, e, m1, m2));
  //cout << 66 << endl;
  //cout << q[m1] << " " << q[m2] << endl;
  deal(i, s, q[m1]);
  deal(1-i, q[m1]+1, q[m2]);
  deal(i, q[m2]+1, e);*/
}

int main(){
  cin >> N;
  init(N/2, dat[0]);
  init(N/2, dat[1]);
  for(int i = 0; i < N; i++){
    int x;
    cin >> x;
    update(i/2, x, dat[i%2]);
    q[x] = i;
  }

  int m1 = query(0, N/2, 0, 0, n, dat[0]);
  int m2 = query((q[m1]+1)/2, N/2, 0, 0, n, dat[1]);
  pq.push(T(0, N, m1, m2, 0));
  deal();

/*
  for(int i = 0; i < N/2; i++){
    if(pq.empty())  break;
    T p = pq.top();
    cout << p.c << " " << p.d << " ";
    pq.pop();
  }
  */
  cout << endl;

  return 0;
}
