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

VI nums;

typedef struct node{

  node(int s, int e):start(s), end(e), updates(0), left(0), right(0){}
  int start;
  int end;
  LL updates;
  node *left;
  node *right;
} node;

node *root;

node * build_tree(int start, int end){
  if (start == end){
    return new node(start, end);
  }
  node *root = new node(start, end);
  int mid = start + (end - start) / 2;
  root->left = build_tree(start, mid);
  root->right = build_tree(mid + 1, end);
  return root;
}

void update(node *root, int start, int end, int value){
  if (root->start == start && root->end == end){
    root->updates += value;
    return;
  }
  if (end <= root->left->end){
    update(root->left, start, end, value);
  } else if (start >= root->right->start) {
    update(root->right, start, end, value);
  } else {
    update(root->left, start, root->left->end, value);
    update(root->right, root->right->start, end, value);
  }
  
}

LL query(node *root, int k){
  LL cur = 0;
  // REP(i, SIZE(root->updates)) cur += root->updates[i];
  cur = root->updates;
  if (k == root->start && k == root->end) return cur;
  
  if (k <= root->left->end){
    return cur + query(root->left, k);
  } else {
    return cur + query(root->right, k);
  }
}

int main(){
  int n, q, a, b, u, k, t;
  cin >> n >> q;
  REP(i, n){
    cin >> t;
    nums.PB(t);
  }
  root = build_tree(1, n);
  while (q--){
    cin >> t;
    if (t == 1){
      cin >> a >> b >> u;
      update(root, a, b, u);
    } else {
      cin >> k;
      cout << query(root, k) + nums[k - 1] << endl;
    }
    
  }
  return 0;
}
