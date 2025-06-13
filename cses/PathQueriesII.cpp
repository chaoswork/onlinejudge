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

int timer = 0;
VI start;
VI finish;
VI eular;
VVI adj;
VI values;

void dfs(int x, int p){
  start[x] = timer++;
  eular.PB(values[x]);
  for(auto y: adj[x]){
    if (y == p) continue;
    dfs(y, x);
    finish[x] = timer++;
    eular.PB(values[x]);

  }
}

class Node{
public:
  int s;
  int e;
  LL maxv;
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
      cur_root->maxv = (*val)[s];
      return cur_root;
    }
    int mid = s + (e - s) / 2;
    cur_root->left = build_tree(s, mid);
    cur_root->right = build_tree(mid + 1, e);

    cur_root->maxv = max(cur_root->left->maxv,cur_root->right->maxv);
    
    return cur_root;
  }

  LL _query(Node *cur, int s, int e){
    if (cur->s == s && cur->e == e) return cur->maxv;

    if (e <= cur->left->e) return _query(cur->left, s, e);
    else if (s >= cur->right->s) return _query(cur->right, s, e);
    else{
      auto L = _query(cur->left, s, cur->left->e);
      auto R = _query(cur->right, cur->right->s, e);
      return max(L, R);
    }
  }

  LL query(int s, int e){
    return _query(root, s, e);
  }

  void _update(Node *cur, int idx, int v){
    if (cur->s == idx && cur->e == idx){
      cur-> maxv = v;
      return;
    }
    if (idx <= cur->left->e){
      _update(cur->left, idx, v);
    } else {
      _update(cur->right, idx, v);
    }
    cur->maxv = max(cur->left->maxv, cur->right->maxv);
    
  }

  void update(int idx, int v){
    _update(root, idx, v);
  }
  
};



int main(){
  optimize;
  int n, q, x, a, b;
  cin >> n >> q;
  start = VI(n + 1, 0);
  finish = VI(n + 1, 0);
  adj = VVI(n + 1, VI());
  values.PB(0);
  FOR(i, 1, n){
    cin >> x;
    // values.PB(x);
    values.PB(i);
  }
  REPN(n - 1){
    cin >> a >> b;
    adj[a].PB(b);
    adj[b].PB(a);
  }

  
  dfs(1, 0);

  DISP_VEC(eular);
  DISP_VEC(start);
  DISP_VEC(finish);

  SegmentTree st = SegmentTree(eular);

  REPN(q){
    cin >> x;
    if (x == 1){
      cin >> a >> b;
      LL diff = b - values[a];
      st.update(start[a], diff);
      st.update(finish[a], diff);
    } else {
      cin >> a >> b;
      
    }
  }
  
  return 0;
}
