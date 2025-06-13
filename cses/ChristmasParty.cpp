#pragma GCC optimize("O3,unroll-loops,Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
const int MAXN = 2e5 + 64;


int main(){
  optimize;
  int n;
  cin >> n;
  LL f[int(1e6 + 10)];
  LL g[int(1e6 + 10)];
  // f(n) = (n - 1) * (f(n - 2) + (n - 2) * g(n - 2)
  // g(n) = f(n - 1) + (n - 1) * g(n - 1)
  // f(4) = 3 * (f(2) + 2 * g(2)) = 9
  // f(2) = 1
  // g(2) = 1
  // f(3) = 2 * (f(1) + 1 * g(1)) = 2
  // f(1) = 0
  // g(1) = 1

  f[1] = 0; f[2] = 1;
  g[1] = 1; g[2] = 1;
  FOR(i, 3, n){
    f[i] = (i - 1) * ((f[i - 2] + (i - 2) * g[i - 2] % MOD) % MOD) % MOD;
    g[i] = (f[i - 1] + (i - 1) * g[i - 1] % MOD) % MOD;
  }
  cout << f[n] << endl;

  
  return 0;
}
