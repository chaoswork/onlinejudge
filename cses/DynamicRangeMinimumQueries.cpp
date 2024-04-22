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

  node(int s, int e, int v): start(s), end(e), value(v),
                             left(0), right(0), parent(0){}
  int start;
  int end;
  int value;
  node *left;
  node *right;
  node *parent;
}node;

vector<node *> index2p;

node *build_tree(const VI &nums, int start, int end){
  if (start == end) {
    node *root = new node(start, end, nums[start]);
    index2p[start] = root;
    return root;
  }
  int mid = start + (end - start) / 2;
  node *root = new node(start, end, -1);
  root->left = build_tree(nums, start, mid);
  root->right = build_tree(nums, mid + 1, end);
  root->value = min(root->left->value, root->right->value);
  root->left->parent = root;
  root->right->parent = root;
  return root;
}

int query(node *root, int start, int end){
  if (root->start == start && root->end == end) return root->value;
  if (root->right->start <= start) return query(root->right, start, end);
  else if (root->left->end >= end) return query(root->left, start, end);
  else{
    return min(query(root->left, start, root->left->end),
               query(root->right, root->right->start, end));
  }
  
}

void update(int pos, int value){
  node *p = index2p[pos];
  p->value = value;
  p = p->parent;
  while (p){
    p->value = min(p->left->value, p->right->value);
    p = p->parent;
  }
}

int main(){
  int n, q, x, a, b;
  VI nums;
  cin >> n >> q;
  REP(i, n){
    cin >> x;
    nums.PB(x);
  }
  index2p.resize(n);
  node *root = build_tree(nums, 0, n - 1);
  
  REP(i, q){
    cin >> x >> a >> b;
    if (x == 1){
      update(a - 1, b);
    } else {
      cout << query(root, a - 1, b - 1) << endl;
    }
  }
  return 0;
}
