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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

typedef struct node{
  node():left(0), right(0){}
  node *left;
  node *right;
  int start;
  int end;
  int value;
} node;
VI nums;

node * build_seg_tree(int start, int end){
  node *root = new node();
  root->start = start;
  root->end = end;
  root->value = nums[start];

  if (start == end){
    return root;
  }

  int mid = start + (end - start) / 2;
  root->left = build_seg_tree(start, mid);
  root->right = build_seg_tree(mid + 1, end);
  root->value = min(root->left->value, root->right->value);

  return root;
}

int query(node *root, int start, int end){
  if (root->start == start && root->end == end){
    return root->value;
  }
  if (root->left->end >= end) return query(root->left, start, end);
  if (root->right->start <= start) return query(root->right, start, end);
  return min(query(root->left, start, root->left->end),
             query(root->right, root->right->start, end));
  
}

int main(){
  int n, q, x, a, b;

  cin >> n >> q;
  REP(i, n){
    cin >> x;
    nums.PB(x);
  }
  node *root = build_seg_tree(0, SIZE(nums) - 1);
  // cout << root->left->value << endl;
  REP(i, q){
    cin >> a >> b;
    cout << query(root, a - 1, b - 1) << endl;
  }
  return 0;
}
