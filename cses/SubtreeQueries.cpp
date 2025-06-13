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
const int MAXN = 2e5 + 64;


class BIT{
private:
  LL maxv;
  vector<LL> values;
public:
  BIT(LL _maxv){
    maxv = _maxv;
    values = vector<LL> (maxv, 0);
  }

  void update(LL x, int v){
    while(x <= maxv){
      values[x] += v;
      x += (x & -x);
    }
  }

  LL query(int x){
    LL res = 0;
    while (x > 0){
      res += values[x];
      x -= (x & -x);
    }
    return res;
  }
  
};


VVI adj;
VI values;
VI start;
VI finish;
int timer = 0;

void dfs(int x, int p){
  start[x] = ++timer;
  for(auto j: adj[x]){
    if (j == p) continue;
    dfs(j, x);
  }
  finish[x] = timer;
}

int main(){
  optimize;
  int n, q, x, a, b;
  cin >> n >> q;

  adj = VVI(n + 1, VI());
  start = VI(n + 1, 0);
  finish = VI(n + 1, 0);
  values.PB(0);
  REPN(n){
    cin >> x;
    values.PB(x);
  }
  REPN(n - 1){
    cin >> a >> b;
    adj[a].PB(b);
    adj[b].PB(a);
  }
  dfs(1, 0);
  BIT bit = BIT(timer + 10);
  FOR(i, 1, n){
    bit.update(start[i], values[i]);
  }
  

  REPN(q){
    cin >> a;
    if (a == 1){
      cin >> x >> b;
      bit.update(start[x], b - values[x]);
      values[x] = b;
      
      // display(n);
    } else{
      cin >> x;
      cout << bit.query(finish[x]) - bit.query(start[x] - 1) << endl;
    }
  }
  return 0;
}
