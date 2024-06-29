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
  node(int _s, int _e):s(_s), e(_e), len(e - s), left(0), right(0), parent(0){}
  int s;
  int e;
  int len;
  node *left;
  node *right;
  node *parent;
} node;


void seg_line(node *root, int t){
  if (root->left == 0 && root->right == 0){
    node *left = new node(root->s, t);
    left->parent = root;
    node *right = new node(t, root->e);
    right->parent = root;
    root->left = left;
    root->right = right;
    root->len = max(root->left->len, root->right->len);
    node *p = root->parent;
    while (p){
      int cur = max(p->left->len, p->right->len);
      if (cur == p->len) break;
      else {
        p->len = cur;
        p = p->parent;
      }
    }
  } else {
    if (t <= root->left->e) seg_line(root->left, t);
    else seg_line(root->right, t);
  }
}

int main(){
  int x, n, t;
  cin >> x >> n;

  VI nums;
  int max_v = 0;
  REP(i, n){
    cin >> t;
    nums.PB(t);
    max_v = max(t, max_v);
  }

  node *root = new node(0, x);
  bool skip = false;
  int skip_ans = -1;
  REP(i, n){
    if (i) cout << " ";    
    if (skip){
      cout << skip_ans;
      continue;
    }
    t = nums[i];

    
    seg_line(root, t);

    cout << root->len;
    if (t == max_v && root->right->len > max_v){
      skip = true;
      skip_ans = root->len;
      continue;
    }
    // cout << '(' << root->s << "," << root->e <<"-" << root->left->len << ":" << root->right->len << ")";
    
    if (root->left->len <= 1) root = root->right;
    else if (root->right->len <= 1) root = root->left;
    // cout << '<' << root->s << "," << root->e << ">";
    root->parent = 0;
  }
  cout << endl;
  
  return 0;
}
