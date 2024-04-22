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
#include <random>

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
  node(int v):parent(0), left(0),right(0), value(v), num(1){}
  node *parent;
  node *left;
  node *right;
  int value;
  int num;
} node;

void insert(node *root, node *cur){
  if (cur->value == root->value){
    root->num++;
  } else if (cur->value > root->value){
    if (root->right) insert(root->right, cur);
    else {
      root->right = cur;
      cur->parent = root;
    }
  } else{
    if (root->left) insert(root->left, cur);
    else {
      root->left = cur;
      cur->parent = root;
    }
  }
}

void find_le(node *root, int v, node * &res){
  if (root == 0) return;
  if (root->value == v){
    res = root;
  } else if (root->value < v){
    if (res == 0 || res->value < root->value){
      res = root;
    }
    find_le(root->right, v, res);    
  } else {
    find_le(root->left, v, res);
  }
}

void pop(node *cur){
  node *parent = cur->parent;  
  if (cur->right){
    // find min
    node *p_min = cur->right;
    while(p_min->left) p_min = p_min->left;
    // put cur->left to p_min->left
    p_min->left = cur->left;
    if (cur->left) cur->left->parent = p_min;

    // put cur->right to cur->parent
    if (parent->left == cur){
      parent->left = cur->right;
      if (cur->right) cur->right->parent = parent;
    } else {
      parent->right = cur->right;
      if (cur->right) cur->right->parent = parent;
    }
    

  } else{

    if (parent->left == cur){
      parent->left = cur->left;
      if (cur->left) cur->left->parent = parent;
    } else {
      parent->right = cur->left;
      if (cur->left) cur->left->parent = parent;
    }
    
    
  }
  delete cur;

}

node* build_bst(VI& tickets){
  node *fake = new node(-1);
  if (SIZE(tickets) == 0){
    return fake;
  }
  std::random_device rd;
  default_random_engine rng(rd());
  shuffle(ALL(tickets), rng);


  node *root = new node(tickets[0]);
  FOR(i, 1, SIZE(tickets) - 1){
    insert(root, new node(tickets[i]));
  }
  
  fake->left = root;
  root->parent = fake;
  return fake;
}

int main(){
  int n, m, x;
  cin >> n >> m;
  VI tickets;
  VI used;

  
  REP(i, n){
    cin >> x;
    tickets.PB(x);
    used.PB(0);
  }
  node *fake = build_bst(tickets);
  node *root = fake->left;
  
  // sort(ALL(tickets));
  // add next and prev pointer??
  REP(i, m){
    cin >> x;
    // find the tickets <= x
    node *res = 0;
    find_le(fake->left, x, res);
    if (res){
      cout << res->value << endl;
      if(res->num > 1) res->num--;
      else pop(res);
    } else {
      cout << -1 << endl;
    }
    // if ((i + 1) % 10000 == 0){
    if (i == m / 2){
      VI tmp;
      while(fake->left){
        REP(k, fake->left->num){
          tmp.PB(fake->left->value);
        }
        pop(fake->left);
      }
      fake = build_bst(tmp);
      root = fake->left;
    }
  }
  return 0;
}
