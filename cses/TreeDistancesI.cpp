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


int depth(int root, const VVI &adj, const VI& rank, VI &depth_cache){
  if (depth_cache[root] != -1) return depth_cache[root];
  int best = 0;
  REP(j, SIZE(adj[root])){
    if (rank[adj[root][j]] < rank[root]) continue;
    best = max(best, depth(adj[root][j], adj, rank, depth_cache));
  }
  return depth_cache[root] = best + 1;
}

int height(int root, const VVI &adj, const VI& rank, VI &depth_cache, VI &height_cache){
  if (height_cache[root] != -1) return height_cache[root];
  int best = 0;
  int parent = -1;
  REP(j, SIZE(adj[root])){
    if (rank[adj[root][j]] < rank[root]) {parent = adj[root][j]; break;}
  }
  if (parent == -1) {
    REP(j, SIZE(adj[root])){
      best = max(best, depth(adj[root][j], adj, rank, depth_cache));
    }
    return height_cache[root] = best + 1;
  }
  REP(j, SIZE(adj[parent])){
    if (adj[parent][j] == root) continue;
    if (rank[adj[parent][j]] < rank[parent]) best = max(best, height(adj[parent][j], adj, rank, depth_cache, height_cache));
    else best = max(best, depth(adj[parent][j], adj, rank, depth_cache)) ;
  }
  return height_cache[root] = best + 2;
}

int main(){
  int n, a, b;
  cin >> n;
  VVI adj(n + 1, VI());
  VI rank(n + 1, -1);
  VI depth_cache(n + 1, -1);
  VI height_cache(n + 1, -1);
  REP(i, n - 1){
    cin >> a >> b;
    adj[a].PB(b);
    adj[b].PB(a);
  }
  queue<int> Q;
  rank[1] = 0;
  Q.push(1);
  while (SIZE(Q)){
    int cur = Q.front();
    Q.pop();
    REP(j, SIZE(adj[cur])){
      if (rank[adj[cur][j]] == -1){
        rank[adj[cur][j]] = rank[cur] + 1;
        Q.push(adj[cur][j]);
      }
    }
  }
  FOR(i, 1, n) cout << depth(i, adj, rank, depth_cache) << " " 
                    << height(i, adj, rank, depth_cache, height_cache)
                    << endl;
  
  return 0;
}
