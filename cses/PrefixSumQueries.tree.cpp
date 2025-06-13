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

class Node{
public:
  int s;
  int e;
  LL prefix;
  LL total;
  Node *left;
  Node *right;

  Node(int _s, int _e):s(_s), e(_e), left(0), right(0){}
};

class SegmentTree{
private:
  Node *root;
  const vector<int> *val;
public:
  SegmentTree(const vector<int> &values){
    val = &values;
    root = build_tree(0, SIZE(values) - 1);
  }

  Node *build_tree(int s, int e){
    Node *cur_root = new Node(s, e);
    if (s == e){
      cur_root->total = (*val)[s];
      cur_root->prefix = (*val)[s];
      return cur_root;
    }
    int mid = s + (e - s) / 2;
    cur_root->left = build_tree(s, mid);
    cur_root->right = build_tree(mid + 1, e);

    cur_root->total = cur_root->left->total + cur_root->right->total;
    cur_root->prefix = max(cur_root->left->prefix, cur_root->left->total + cur_root->right->prefix);
    
    return cur_root;
  }

  pair<LL, LL> _query(Node *cur, int s, int e){
    if (cur->s == s && cur->e == e) return MP(cur->prefix, cur->total);

    if (e <= cur->left->e) return _query(cur->left, s, e);
    else if (s >= cur->right->s) return _query(cur->right, s, e);
    else{
      auto L = _query(cur->left, s, cur->left->e);
      auto R = _query(cur->right, cur->right->s, e);
      return MP(max(L.first, L.second + R.first), L.second + R.second);
    }
  }

  LL query(int s, int e){
    return _query(root, s, e).first;
  }

  void _update(Node *cur, int idx, int v){
    if (cur->s == idx && cur->e == idx){
      cur-> prefix = cur->total = v;
      return;
    }
    if (idx <= cur->left->e){
      _update(cur->left, idx, v);
    } else {
       _update(cur->right, idx, v);
    }
    cur->total = cur->left->total + cur->right->total;
    cur->prefix = max(cur->left->prefix, cur->left->total + cur->right->prefix);
    
  }

  void update(int idx, int v){
    _update(root, idx, v);
  }
  
};

int main(){
  optimize;
  int n, q, x, a, b;
  cin >> n >> q;
  VI nums;

  REP(i, n){
    cin >> x;
    nums.PB(x);
  }
  SegmentTree st(nums);
  //   cout << "build\n";
  REP(i, q){
    cin >> x >> a >> b;
    if (x == 2)
      cout << max(0LL, st.query(a - 1, b - 1)) << '\n';
    else
      st.update(a - 1, b);
  }
  return 0;
}
