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
  node(int _s, int _e):s(_s), e(_e), v(-1), left(0), right(0), parent(0){}
  int s;
  int e;
  int v;
  int index;
  node *left;
  node *right;
  node *parent;
} node;

VI nums;
bool first = true;

node *build_tree(int s, int e){
  if (s == e){
    node *leaf = new node(s, e);
    leaf->v = nums[s];
    leaf->index = s;
    return leaf;
  }
  node *root = new node(s, e);
  int mid = s + (e - s) / 2;
  node *left = build_tree(s, mid);
  node *right = build_tree(mid + 1, e);
  left->parent = root; right->parent = root;
  root->left = left; root->right = right;
  
  root->v = max(left->v, right->v);
  return root;
}
void output(int x){
  if (first){
      first = false;
    } else cout << " ";
    cout << x;

}
void update(node *root, int r){
  if (root->v < r){
    output(0);
    return;
  }
  if (root->left == 0){
    output(root->index + 1);
    root->v -= r;
    node *p = root->parent;
    while(p){
      p->v = max(p->left->v, p->right->v);
      p = p->parent;
    }
    return;
  }
  if (root->left->v >= r) update(root->left, r);
  else update(root->right, r);
}

int main(){
  int n, m, h, r;
  cin >> n >> m;
  multimap<int, int> hotels;
  
  REP(i, n){
    cin >> h;
    // nums.PB(h);
    hotels.insert(MP(h, i));
  }

  REP(i, m){
    if (i) cout << " ";
    cin >> r;
    auto it = hotels.lower_bound(r);
    if (it == hotels.end()){
      cout << 0;
    } else {
      cout << it->second + 1;
      // hotels.insert(MP(it->first - r, it->second));
      hotels.erase(it);
    }

  }
  return 0;
}
