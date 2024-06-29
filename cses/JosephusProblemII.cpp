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
  node(int _x): x(_x), next(0){}
  int x;
  node *next;
} node;

int main(){
  int n, k;
  cin >> n >> k;

  if (k == 0){
    REP(i, n){
      if (i) cout << " ";
      cout << i + 1;
    }
    cout << endl;
    return 0;
  }

  node *root = new node(1);
  node *p = root;
  FOR(i, 2, n){
    p->next = new node(i);
    p = p -> next;
  }
  p->next = root;
  
  node *prev = p;
  node *q = root;
  if (k % n == 0){
    p = prev;
    q = root;
  } else {
    p = root;
    q = p;
    REP(i, k % n) {
      p = q;
      q = q -> next;
    }
  }
  // p -> q -> r ->
  // 3 7
  bool first = true;
  while (true){
    if (first) first = false;
    else cout << " ";
    cout << q->x;
    //    cout << "debug " << p->x << " " << q->x << endl;
    if (p == q) {
      break;
    } /*else if (q->next == p){
      p->next = p;
      delete q;      
      q = p;

      // p -> q -> p
      node *tmp = q;
      // p -> p
      // q -/
      p->next = q->next;
      // q = p
      q = q->next->next;
      // p
      p = p->next;
      delete tmp;


    }*/ else {
      // p -> q -> r -> x ...
      node *tmp = q;
      // p -> r -> x...
      // q -/
      p->next = q->next;
      // p -> r -> q -> ...
      q = q->next;
      
      if (k % n == -1){
      } else {
        // cout << "debug " <<q->x << " " <<  k % (n - 1) << " " << n << endl;
        REP(i, k % (n - 1)){
          //        REP(i, k){
            p = q;
            q = q->next;
          }
      }
      delete tmp;
      n--;
    }
    
  }
  cout << endl;
  return 0;
}
