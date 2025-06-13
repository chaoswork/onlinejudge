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
  vector<int> values;
public:
  BIT(LL _maxv){
    maxv = _maxv;
    values = vector<int> (maxv, 0);
  }

  void update(LL x, int v){
    while(x <= maxv){
      values[x] += v;
      x += (x & -x);
    }
  }

  int query(int x){
    int res = 0;
    while (x > 0){
      res += values[x];
      x -= (x & -x);
    }
    return res;
  }
  
};


int main(){
  optimize;
  int n, q, x, a, b;
  cin >> n >> q;
  BIT bit = BIT(2e5 + 10);
  VI nums;
  VI ans(q + 1, -1);
  vector<vector<PII> > queries = vector<vector<PII> >(n + 1, vector<PII>());
  FOR(i, 1, n){
    cin >> x;
    nums.PB(x);
  }
  REP(i, q){
    cin >> a >> b;
    queries[a].PB(MP(b, i));
  }
  map<int, int> last_index;
  FORD(i, n, 1){
    int v = nums[i - 1];
    if (last_index.find(v) != last_index.end()){
      bit.update(last_index[v], -1);
    }
    last_index[v] = i;
    bit.update(last_index[v], 1);

    REP(j, SIZE(queries[i])){
      b = queries[i][j].first;
      int index = queries[i][j].second;
      ans[index] = bit.query(b);
      
    }
  }
  // DISP_VEC(ans);
  
  REP(i, q){
    cout << ans[i] << endl;
  }



  return 0;
}
