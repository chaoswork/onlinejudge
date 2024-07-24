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
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;


typedef struct node {
  node(int _s, int _e): s(_s), e(_e), minv(-1), maxv(-1), left(0), right(0){}
  int s;
  int e;
  int minv;
  int maxv;
  node *left;
  node *right;
}node;

vector<PII> ranges;
map<int, PII> uniqs;
vector<pair<int, PII> > uniq_ranges;


node *build_tree(int L, int R){

  node *root = new node(uniq_ranges[L].first, uniq_ranges[R].first);
  if (L == R){
    root->minv = uniq_ranges[L].second.first;
    root->maxv = uniq_ranges[L].second.second;
    return root;
  }

  int mid = L + (R - L) / 2;
  root->left = build_tree(L, mid);
  root->right = build_tree(mid + 1, R);
  root->minv = min(root->left->minv, root->right->minv);
  root->maxv = max(root->left->maxv, root->right->maxv);
  return root;
}

int query_been_contained(node *root, int x, int y){
  if (x < root->s) return 0;
  if (y > root->maxv) return 0;
  if (root->s == root->e){
    // leaf
    if (root->s == x && root->maxv == y) return 0;
    else return 1;
  }
  if (query_been_contained(root->left, x, y)) return 1;
  if (query_been_contained(root->right, x, y)) return 1;  

  return 0;
}
int query_contained(node *root, int x, int y){
  if (x > root->e) return 0;
  if (y < root->minv) return 0;
  if (root->s == root->e){
    // leaf
    if (root->s == x && root->minv == y) return 0;
    else return 1;
  }
  if (query_contained(root->left, x, y)) return 1;
  if (query_contained(root->right, x, y)) return 1;  

  return 0;
}

int main(){
  optimize;
  int n, x, y;
  cin >> n;

  REP(i, n){
    cin >> x >> y;
    ranges.PB(MP(x, y));
    if (uniqs.find(x) == uniqs.end()){
      uniqs[x] = MP(y, y);
    } else {
      if (y < uniqs[x].first)
        uniqs[x].first = y;
      if (y > uniqs[x].second)
        uniqs[x].second = y;
    }
  }
  // sort(ALL(ranges));
  for(auto e: uniqs){
    uniq_ranges.PB(MP(e.first, e.second));
  }
  /*
  REP(i, SIZE(uniq_ranges)){
    cout << uniq_ranges[i].first << " " << uniq_ranges[i].second.first << " " << uniq_ranges[i].second.second << endl;
  }
  */
  node *root = build_tree(0, SIZE(uniq_ranges) - 1);
  // cout << root->s << " " << root->e << " " << root->minv << " " << root->maxv << endl;
  REP(i, SIZE(ranges)){
    if (i) cout << " ";
    cout << query_contained(root, ranges[i].first, ranges[i].second);
  }
  cout << endl;
  REP(i, SIZE(ranges)){
    if(i) cout << " ";
    cout << query_been_contained(root, ranges[i].first, ranges[i].second);
  }
  cout << endl;
     
  return 0;
}
