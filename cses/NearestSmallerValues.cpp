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

typedef struct node{
  node(int _s, int _e, int _v): s(_s), e(_e), minv(_v), left(0), right(0){}
  int s;
  int e;
  int minv;
  node *left;
  node *right;
}node;

VI nums;

node * build_tree(int s, int e){
  if (s == e){
    return new node(s, e, nums[s]);
  }
  int mid = s + (e - s) / 2;
  node *root = new node(s, e, -1);
  root->left = build_tree(s, mid);
  root->right = build_tree(mid + 1, e);
  root->minv = min(root->left->minv, root->right->minv);
  return root;
}

int query(node *root, int s, int e, int v){
  if (e < 0) return 0;
  if (root->minv >= v) return 0;
  if (root->s == root->e){
    if (root->minv >=v) return 0;
    else return root->s + 1;
  }
  if (e <= root->left->e) {
    if (root->left->minv >= v) return 0;
    else return query(root->left, s, e, v);
  }
  else if (s >= root->right->s){
    if (root->right->minv >= v) return 0;
    else return query(root->right, s, e, v);
  } else {
    // find right part first
    int ret = query(root->right, root->right->s, e, v);
    if (ret) return ret;
    else return query(root->left, s, root->left->e, v);

  }
  return 0;
}

int main(){
  int n, x;
  cin >> n;
  REP(i, n){
    cin >> x;
    nums.PB(x);
  }
  node *root = build_tree(0, n - 1);
  //  cout << query(root, 0, 4, 3) << endl;
  //  return 0;
  REP(i, n){
    if (i) cout << " ";
    cout << query(root, 0, i - 1, nums[i]);
  }
  cout << endl;
  return 0;
}
