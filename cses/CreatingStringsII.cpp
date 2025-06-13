#pragma GCC optimize("O3,unroll-loops,Ofast")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}


#define MIN_HEAP(type1, type2) priority_queue<pair<type1, type2>, vector<pair<type1, type2> >, greater<pair<type1, type2> > >
#define MAX_HEAP(type) priority_queue<type>
#define ADJ(type1, type2) vector<pair<type1, type2> > 
#define MP(A,B) make_pair(A,B)
#define PB push_back
#define SIZE(X) ((int)(X.size()))
#define REP(i, n) for(int i=0; i<(n); ++i)
#define REPN(n) for(int _=0; _<(n); ++_)
#define FOR(i, l, h) for(int i=(l); i<=(h); ++i)
#define FORD(i, h, l) for(int i=(h); i>=(l);--i)
#define ALL(A) A.begin(),A.end()
#define MATRIX(n, m, v) vector<vector<int> >((n), vector<int>((m), (v)))
#define DISP_SET(S)   {int iforset = 0;for(auto e: S){if (iforset++) cout << " ";cout << e;} cout << endl;}
#define DISP_PAIR(P)   {cout << P.first << " " << P.second << endl;}
#define DISP_VEC(vec)   REP(i, SIZE(vec)){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_VEC_N(vec, n)   REP(i, n){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_MAT(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1000000007;
const LL INF = 1LL<<62;  //std::numeric_limits<LL>::max();
const int MAXN = 1e6 + 64;

LL fac[MAXN];
LL inv[MAXN];

LL exp_mod(LL x, LL n, LL mod){

  LL res = 1;
  LL base = x;
  while (n){
    if (n & 1) res = res * base % mod;
    base = base * base % mod;    
    n >>= 1;
  }
  return res;
  
}

LL Cnm_mod(LL n, LL m, LL mod){
  return (fac[n] * inv[n - m] % mod) * inv[m] % mod;
}


int main(){
  optimize;
  string line;
  fac[0] = 1;
  FOR(i, 1, MAXN - 1){
    fac[i] = fac[i - 1] * i % MOD;
  }
  inv[MAXN - 1] = exp_mod(fac[MAXN - 1], MOD - 2, MOD);
  FORD(i, MAXN - 2, 0) inv[i] = (i + 1) * inv[i + 1] % MOD;
  // cout << exp_mod(2, 16, MOD) << endl;
  cin >> line;
  map<char, int> cnt;
  LL n = SIZE(line);  
  REP(i, SIZE(line)){
    if (cnt.find(line[i]) == cnt.end()) cnt[line[i]] = 0;
    cnt[line[i]]++;
  }

  LL ans = 1;
  for (auto e: cnt){
    // cout << n << " " << e.second << endl;
    ans *= Cnm_mod(n, e.second, MOD);
    ans %= MOD;
    n -= e.second;
  }
  cout << ans << endl;
  return 0;
}
