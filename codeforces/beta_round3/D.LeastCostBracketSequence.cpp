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
#define REPS(i, n, t) for(int i=0; i<(n); i += t)
#define FOR(i, l, h) for(int i=(l); i<=(h); ++i)
#define FORD(i, h, l) for(int i=(h); i>=(l);--i)
#define PQ(T) priority_queue<T>

#define ALL(A) A.begin(),A.end()

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

typedef struct node {
  node(int p, LL c):pos(p), cost(c){}
  int pos;
  LL cost;

  bool operator<(const node& other) const {
    return cost > other.cost;
  }
} node;


int main(){
  string buckets;
  PQ(node) Q;
  string ans;
  int nl = 0, nr = 0, a, b;
  LL cost = 0;
  cin >> buckets;
  if (SIZE(buckets) % 2) {cout << -1 << endl; return 0;}
  REP(i, SIZE(buckets)){
    if (buckets[i] == '('){
      ans += "(";
      ++nl;
    }
    else if (buckets[i] == ')'){
      ans += ")";
      ++nr;
    } else {
      // handle '?'
      cin >> a >> b;
      ans += ")";
      ++nr;
      cost += b;
      Q.push(node(i, a - b));
      //      cout << "debug " << Q.top().cost << " " << a - b << endl;
    }
    // check nl and nr
    if (nl < nr){
      if (Q.empty()) {cost = -1; break;}
      auto cur = Q.top();
      //      cout << i << " " << cur.pos << " " << cur.cost << endl;
      Q.pop();

      cost += cur.cost;
      ans[cur.pos] = '(';
      --nr; ++nl;
      
    }
  }
  if (nl != nr) {cost = -1;}

  cout << cost << endl;
  if (cost != -1) {
    cout << ans << endl;
  }
  
  return 0;
}

