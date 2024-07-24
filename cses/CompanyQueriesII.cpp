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
#define DISPLAY_MATRIX(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

VI height, euler, first;
VVI adj;

void dfs(int root, int h){
  if (first[root] == -1) first[root] = SIZE(euler);  
  euler.PB(root);
  height.PB(h);


  REP(i, SIZE(adj[root])) {
    dfs(adj[root][i], h + 1);
    euler.PB(root);
    height.PB(h);
  }

}

typedef struct node{
  node(int s, int e, int _v, int _x):start(s), end(e), v(_v), x(_x){}
  int start;
  int end;
  int v;
  int x;
  node * left;
  node * right;
} node;

node * build_tree(int s, int e){
  if (s == e){
    return new node(s, e, height[s], euler[s]);
  }
  int mid = s + (e - s) / 2;
  node * root = new node(s, e, -1, -1);
  root->left = build_tree(s, mid);
  root->right = build_tree(mid + 1, e);
  if (root->left->v < root->right->v){
    root->v = root->left->v;
    root->x = root->left->x;
  } else {
    root->v = root->right->v;
    root->x = root->right->x;
  }
  return root;
}

pair<int, int> query(node *root, int s, int e){
  if (root->start == s && root->end == e){
    return MP(root->v, root->x);
  }
  if (root->left->end >= e) return query(root->left, s, e);
  else if (root->right->start <= s) return query(root->right, s, e);
  else{
    PII left =  query(root->left, s, root->left->end);
    PII right = query(root->right, root->right->start, e);
    if (left.first < right.first) return left;
    else return right;
  }
}

int main(){
  
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, q, x, y;
  cin >> n >> q;
  adj = vector<VI> (n + 1, VI());
  first = VI(n + 1, -1);
  FOR(i, 2, n){
    cin >> x;
    adj[x].PB(i);
  }
  dfs(1, 1);
  /*
  FOR(i, 1, n){
    cout << first[i] << endl;
  }
  REP(i, SIZE(height)){
    cout << height[i] << " " << euler[i] << endl;
  }
  */
  node *root = build_tree(0, SIZE(height) - 1);
  REP(i, q){
    cin >> x >> y;
    int s = first[x];
    int e = first[y];
    if (s > e) swap(s, e);
    cout << query(root, s, e).second << endl;
  }
  return 0;
}
