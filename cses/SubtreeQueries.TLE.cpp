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

struct node{
  vector<node *> childs;
  LL value;
  LL sum;
  int id;
  node(int _id, int v):id(_id), sum(v), value(v){}
};
VI parent;
VI values;
VVI adj;
vector<node *> p_nodes;

node * build_tree(int cur, int p){
  node *root = new node(cur, values[cur]);
  REP(i, SIZE(adj[cur])){
    int j = adj[cur][i];
    if (j == p) continue;
    parent[j] = cur;
    node *child = build_tree(j, cur);
    root->childs.PB(child);
    root->sum += child->sum;
  }
  p_nodes[cur] = root;

  return root;
}

void update(int cur, int value){
  LL diff = value - p_nodes[cur]->value;
  p_nodes[cur]->value = value;

  while (cur){
    node *root = p_nodes[cur];
    root->sum += diff;
    cur = parent[cur];
  }
}

LL query(int cur){
  return p_nodes[cur]->sum;
}

void display(int n){
  FOR(i, 1, n){
    cout << i << " " << p_nodes[i]->value << " " << p_nodes[i]->sum << endl;
  }
  cout << "---" << endl;
}


int main(){
  optimize;
  int n, q, x, a, b;
  cin >> n >> q;

  adj = VVI(n + 1, VI());
  parent = VI(n + 1, 0);
  p_nodes = vector<node *>(n + 1, 0);
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
  build_tree(1, 0);
  REPN(q){
    cin >> a;
    if (a == 1){
      cin >> x >> b;
      update(x, b);
      // display(n);
    } else{
      cin >> x;
      cout << query(x) << endl;
    }
  }
  return 0;
}
