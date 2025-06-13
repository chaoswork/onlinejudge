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

template <class T>
class SegmentTree{
public:

  vector<T> pre;
  vector<T> suf;
  vector<T> sum;
  vector<T> sub;
  const vector<int> * val;
  SegmentTree(const vector<int> &values){
    val = &values;
    pre.resize(values.size() * 4); // 4 is safer, 3 maybe work
    suf.resize(values.size() * 4);
    sum.resize(values.size() * 4);
    sub.resize(values.size() * 4);
    build_tree(0, 0, values.size() - 1);
    // info = vector<LL>(values.size() * 4, INF);
    
  }

  void update_func(int root, int L, int R){
    sum[root] = sum[L] + sum[R];
    suf[root] = max(suf[R], sum[R] + suf[L]);
    pre[root] = max(pre[L], sum[L] + pre[R]);
    sub[root] = max(sub[L], sub[R]);
    sub[root] = max(sub[root], suf[L] + pre[R]);
  }

  void build_tree(int root, int s, int e){
    if (s == e){
      suf[root] = (*val)[s];
      pre[root] = (*val)[s];
      sum[root] = (*val)[s];
      sub[root] = (*val)[s];
      return ;
    }
    int mid = s + (e - s) / 2;
    int L = root * 2 + 1;
    int R = root * 2 + 2;
    build_tree(L, s, mid);
    build_tree(R, mid + 1, e);

    update_func(root, L, R);
  }
  /*
  T _query(int cur, int s, int e, int curs, int cure){
    // cout << cur << " " << s << " " << e << " " << curs << " " << cure << endl;
    // cout << cur << " " << (curs == s) << " " << (cure == e) << endl;
    if (s > e || curs > cure) {
      cout << "error" << endl;
      return INF;
    }
    if (curs == s && cure == e) return info[cur];
    int mid = curs + (cure - curs) / 2;
    int L = cur * 2 + 1;
    int R = cur * 2 + 2;
    if (e <= mid) return _query(L, s, e, curs, mid);
    else if (s >= mid + 1) return _query(R, s, e, mid + 1, cure);
    else{
      T ql = _query(L, s, mid, curs, mid);
      T qr = _query(R, mid + 1, e, mid + 1, cure);
      return func(ql, qr);
    }
  }

  LL query(int s, int e){
    return _query(0, s, e, 0, val->size() - 1);
  }
  */
  void _update(int cur, int idx, int v, int curs, int cure){
    if (curs == idx && cure == idx){
      suf[cur] = v;
      pre[cur] = v;
      sum[cur] = v;
      sub[cur] = v;
      
      return;
    }
    int mid = curs + (cure - curs) / 2;
    int L = cur * 2 + 1;
    int R = cur * 2 + 2;
    
    if (idx <= mid){
      _update(L, idx, v, curs, mid);
    } else {
      _update(R, idx, v, mid + 1, cure);
    }
    update_func(cur, L, R);    
    // info[cur] = func(info[L], info[R]);
    
  }

  void update(int idx, int v){
    _update(0, idx, v, 0, val->size() - 1);
  }
  
};


int main(){
  optimize;
  int n, m, x, k;
  VI nums;
  cin >> n >> m;
  REP(i, n){
    cin >> x;
    nums.PB(x);
  }
  SegmentTree<LL> st(nums);
  REP(i, m){
    cin >> k >> x;
    st.update(k - 1, x);
    cout << max(0LL, st.sub[0]) << '\n';
  }
  
  
  return 0;
}
