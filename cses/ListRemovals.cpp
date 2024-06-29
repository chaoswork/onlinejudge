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
    leaf->v = 1;
    leaf->index = s;
    return leaf;
  }
  node *root = new node(s, e);
  int mid = s + (e - s) / 2;
  node *left = build_tree(s, mid);
  node *right = build_tree(mid + 1, e);
  left->parent = root; right->parent = root;
  root->left = left; root->right = right;
  
  root->v = left->v + right->v;
  return root;
}
void output(int index){
  if (first){
      first = false;
    } else cout << " ";
    cout << nums[index];

}
void update(node *root, int r){

  if (root->left == 0){
    output(root->index);
    root->v = 0;
    node *p = root->parent;
    while(p){
      p->v = p->left->v + p->right->v;
      p = p->parent;
    }
    return;
  }
  if (root->left->v >= r) update(root->left, r);
  else update(root->right, r - root->left->v);
}

int main(){
  int n, h, r;
  cin >> n;

  
  REP(i, n){
    cin >> h;
    nums.PB(h);
  }
  node *root = build_tree(0, n - 1);
  //  cout << root-> v << " " << root->left->v << " " << root->right->v << endl;
  REP(i, n){
    cin >> r;
    update(root, r);
  }
  return 0;
}
