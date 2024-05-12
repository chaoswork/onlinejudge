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



int depth(int root, const VVI &adj, vector<int> &depth_cache, const VI &rank){
  if (depth_cache[root] != -1) return depth_cache[root];
  int best = 0;
  REP(j, SIZE(adj[root])){
    if (rank[adj[root][j]] < rank[root]) continue;
    best = max(best, depth(adj[root][j], adj, depth_cache, rank));
  }
  return depth_cache[root] = best + 1;
}

int main(){
  int n, a, b;
  cin >> n;
  vector<VI> adj(n + 1, VI());
  vector<int> cache(n + 1, -1);
  VI rank(n + 1, -1);
  REP(i, n - 1){
    cin >> a >> b;
    adj[a].PB(b);
    adj[b].PB(a);
  }
  rank[1] = 1;
  queue<PII> Q;
  Q.push(MP(1, 1));
  while (SIZE(Q)){
    int cur = Q.front().first;
    int r = Q.front().second;
    Q.pop();
    REP(j, SIZE(adj[cur])){
      if (rank[adj[cur][j]] != -1) continue;
      rank[adj[cur][j]] = r + 1;
      Q.push(MP(adj[cur][j], r + 1));
    }

  }
  /*int root = -1;
  FOR(i, 1, n) {
    if (par[i] == -1) root = i;
    }*/
  int best = 0;
  FOR(i, 1, n) {
    //     cout << depth(i, adj, cache, rank) << endl;
    //    if (SIZE(adj[i]) == 0){
    //best = max(best, 1);
      //    } else if (SIZE(adj[i]) == 1){
      //      best = max(best, depth(i, adj, cache));
    //    } else{
      int m1 = 0, m2 = 0;
      REP(j, SIZE(adj[i])){
        // cout << i << ":" << adj[i][j] << " " << rank[adj[i][j]] << " " << rank[i] << endl;
        if (rank[adj[i][j]] < rank[i]) continue;
        if (m1 <= depth(adj[i][j], adj, cache, rank)){
          m2 = m1;
          m1 = depth(adj[i][j], adj, cache, rank);
        } else {
          m2 = max(m2, depth(adj[i][j], adj, cache, rank));
        }
      }
      // cout << i << " " << m1 << " " << m2 << endl;
      best = max(best, m1 + m2 + 1);
      //    }
  }
  cout << best - 1 << endl;
  return 0;
}
