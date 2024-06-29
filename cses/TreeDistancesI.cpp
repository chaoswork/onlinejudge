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


int dfs(int i, int j, const VVI& adj, VVI &ans, VVI &ans2){
  //  cout << i << "," << j << "| " << ans[i][j] << " " << SIZE(adj[j]) << endl;
  int c = adj[i][j];
  /*
  if (ans2[c][0] != -1){
    if (ans2[c][0] == i) return ans2[c][1] + 1;
    else return  ans2[c][2] + 1;
  }
  */
  if (ans[i][j]) return ans[i][j];

  if (SIZE(adj[c]) == 1) {
    // ans2[i][0] = c;
    // ans2[i][1] = 0;
    return ans[i][j] = 1;
  }
  //  cout << "debug " << i << "," << j << endl;
  if (ans2[c][0] != -1){
    int c_best = ans2[c][2];
    if (ans2[c][0] == i) c_best = ans2[c][1];
    ans[i][j] = c_best + 1;
  } else {
    int u = -1, v = -1, w = -1,ik = -1;
    REP(k, SIZE(adj[c])){
      if (adj[c][k] == i) {
        ik = k;
        continue;
      }
      int d = dfs(c, k, adj, ans, ans2);
      if (d >= u){
        v = u; u = d;w = k;
      } else {
        v = max(v, d);
      }

      // TODO: 这里能不能变成从2个里面找。
      ans[i][j] = max(ans[i][j], d + 1);
    }
    // set ans2
    if (ans[c][ik]){
        int d = dfs(c, ik, adj, ans, ans2);
        if (d >= u){
          v = u; u = d;w = i;
        } else {
          v = max(v, d);
        }
        
        ans2[c][0] = adj[c][w];
        ans2[c][1] = v;
        ans2[c][2] = u;
    }
      
  }
  return ans[i][j];
}

int main(){
  int n, a, b;
  cin >> n;
  VVI adj(n + 1, VI());
  VVI ans(n + 1, VI());
  VVI ans2(n + 1, VI());
  //  VI rank(n + 1, -1);
  //  VI depth_cache(n + 1, -1);
  //  VI height_cache(n + 1, -1);

  REP(i, n - 1){
    cin >> a >> b;
    adj[a].PB(b);
    ans[a].PB(0);
    adj[b].PB(a);
    ans[b].PB(0);
  }
  FOR(i, 1, n){
    if (SIZE(adj[i]) > 1){
      ans2[i].PB(-1);
      ans2[i].PB(-1);
      ans2[i].PB(-1);
    }
  }

  
  FOR(i, 1, n){
    /*
    cout << i << ": ";
    REP(j, SIZE(adj[i])){
      cout << dfs(i, j, adj, ans) << " ";
    }
    cout << endl;
    
    if (SIZE(adj[i]) == 1) best = max(best, dfs(i, 0, adj, ans) + 1);
    else {
      int u = 0;
      int v = 0;
      REP(j, SIZE(adj[i])){
        int d = dfs(i, j, adj, ans);
        if (d >= u) { v = u; u = d;}
        else{
          v = max(d, v);
        }
      }
      best = max(best, u + v + 1);
    }*/
    //    cout << "debug " << i << endl;
    if (i > 1) cout << " ";
    if (SIZE(ans2[i]) && ans2[i][0] != -1){
      cout << max(ans2[i][1], ans2[i][2]);
    } else {
      int best = 0;
      REP(j, SIZE(adj[i])){
        best = max(best, dfs(i, j, adj, ans, ans2));
        
      }
      
      cout << best;
    }
    
  }
  cout << endl;
  /*
  FOR(i, 1, n){
    cout << i << ":" << ans2[i][0] << " " << ans2[i][1] << " " << ans2[i][2] << endl;
  }
  */
  /*
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
  */
  return 0;
}
