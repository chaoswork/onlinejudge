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

#define MP(A,B) make_pair(A,B)
#define ALL(A) A.begin(),A.end()

#define PB push_back
#define SIZE(X) ((int)(X.size()))
#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, l, h) for(int i=(l); i<=(h); ++i)
#define FORD(i, h, l) for(int i=(h); i>=(l);--i)
#define ALL(A) A.begin(),A.end()
#define MATRIX(n, m, v) vector<vector<int> >((n), vector<int>((m), (v)))
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


VVI adj;

VI euler;
VI first;
VI height;
int cnt = 0;


void dfs(int root, int rank){
  if (first[root] == -1) first[root] = cnt;
  euler.PB(root);
  height.PB(rank);
  cnt++;
  REP(i, SIZE(adj[root])){
    if (first[adj[root][i]] != -1) continue;
    dfs(adj[root][i], rank + 1);
    euler.PB(root);
    height.PB(rank);
    cnt++;
  }
}

typedef struct node{
  node(int _s, int _e, int _v, int _id):s(_s), e(_e), v(_v), id(_id), left(0), right(0) {}
  int s;
  int e;
  int v;
  int id;
  node *left;
  node *right;
}node;

node * build_tree(int s, int e){
  if (s == e){
    return new node(s, s, height[s], euler[s]);
  }
  node *root = new node(s, e, -1, -1);
  int mid = s + (e - s) / 2;
  root->left = build_tree(s, mid);
  root->right = build_tree(mid + 1, e);
  if (root->left->v < root->right->v) {
    root->v = root->left->v;
    root->id = root->left->id;
  } else {
    root->v = root->right->v;
    root->id = root->right->id;
  }
  return root;
}

PII query(node *root, int s, int e){
  if (s > e) return query(root, e, s);
  if (root->s == s && root->e == e){
    return MP(root->v, root->id);
  }
  if (root->left->e >= e) return query(root->left, s, e);
  else if (root->right->s <= s) return query(root->right, s, e);
  else {
    PII a = query(root->left, s, root->left->e);
    PII b = query(root->right, root->right->s, e);
    if (a.first < b.first) return a;
    else return b;
  }
}

int main(){
  optimize;
  int n, q, a, b;
  cin >> n >> q;
  first = VI(n + 1, -1);
  REP(i, n + 1){
    adj.PB(VI());
  }
  REP(i, n - 1){
    cin >> a >> b;
    adj[a].PB(b);
    adj[b].PB(a);
  }
  dfs(1, 1);
  // DISP_VEC(euler);
  // DISP_VEC_N(height, SIZE(height));
  node *root = build_tree(0, SIZE(euler) - 1);
  REP(i, q){
    cin >> a >> b;
    // cout << first[a] << " " << first[b] << endl;
    int lca = query(root, first[a], first[b]).second;
    // cout << "lca=" << lca << endl;
    // cout << height[first[a]] << " " << height[first[b]] << " " << height[first[lca]] << endl;
    cout << abs(height[first[a]] - height[first[lca]])  + abs(height[first[b]] - height[first[lca]])<< endl;
  }

  
  return 0;
}
