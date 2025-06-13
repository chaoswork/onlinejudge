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

class Shrink{
private:
  vector<int> _values;
public:

  Shrink(){}
  
  Shrink(const vector<int> &values){
    _values = values;
    shrink();
  }
  size_t size(){
    return _values.size();
  }
  void shrink(){
    sort(_values.begin(), _values.end());
    _values.erase(unique(_values.begin(), _values.end()), _values.end());
  }
  int id_map(int x){
    return upper_bound(_values.begin(), _values.end(), x) - _values.begin();
  }  
};

class BIT{
private:
  LL maxv;
  vector<LL> values;
public:
  BIT(LL _maxv){
    maxv = _maxv;
    values = vector<LL> (maxv, 0);
  }

  void update(LL x, LL v){
    // never updae 0
    // cout << "debug " << x << " " << v << endl;
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


Shrink sk;

VVI adj;
VI euler;
VI start;
VI finish;
VI colors;
int timer = 0;
void dfs(int x, int p){
  start[x] = timer++;
  euler.PB(sk.id_map(colors[x]));
  for(auto y: adj[x]){
    if (y == p) continue;
    dfs(y, x);
  }
  euler.PB(sk.id_map(colors[x]));
  finish[x] = timer++;
}

int main(){
  optimize;
  int n, c, d;
  cin >> n;
  colors = VI(n + 1, 0);
  adj = VVI(n + 1, VI());
  start = VI(n + 1, 0);
  finish = VI(n + 1, 0);
  VI ans = VI(n + 1, 0);
  VI query = VI(n * 2 + 10, -1);
  VI query_index = VI(n * 2 + 10, -1);

  REP(i, n){
    cin >> c;
    colors[i + 1] = c;
  }
  sk = Shrink(colors);
  
  REP(i, n - 1){
    cin >> c >> d;
    adj[c].PB(d);
    adj[d].PB(c);
  }

  dfs(1, 0);
  // DISP_VEC(euler);
  FOR(i, 1, n){
    query[start[i]] = finish[i];
    query_index[start[i]] = i;
  }
  // DISP_VEC(query);
  // DISP_VEC(query_index);  

  BIT bit = BIT(n * 2 + 10);
  VI last = VI(n + 10, -1);
  // cout << "size:" << SIZE(euler) << endl;
  //  FORD(i, SIZE(euler) - 1, 0){
  for(int i = SIZE(euler) - 1; i>=0; --i){
    int x = euler[i];

    if (last[x] == 0){
      // last 0 394630 200001 200001
      // cout << "last " << last[x] << " " << i + 1 << " " << SIZE(last) <<  " " << x << endl;
    }
    if (last[x] != -1){
      bit.update(last[x], -1);
    }

    last[x] = i + 1;
    bit.update(i + 1, 1);
    

    if (query[i] != -1){
      
      ans[query_index[i]] = bit.query(query[i] + 1);
      // cout << i << " " << query_index[i] << " " << query[i] << endl;      
    }
    // cout << i << endl;
  }
  // DISP_VEC(ans);
  FOR(i, 1, n){
    if (i > 1) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
