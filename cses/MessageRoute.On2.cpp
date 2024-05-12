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




int main(){
  int n, m, x, y;
  cin >> n >> m;
  VVI adj(n, VI());
  VI pre(n, -1);
  REP(i, m){
    cin >> x >> y;
    adj[x - 1].PB(y - 1);
    adj[y - 1].PB(x - 1);
  }
  VI vis(n, 0);
  VI dist(n, -1);
  dist[0] = 0;
  REP(i, n){
    // find minimum
    int best_id = -1;
    int min_dist = -1;
    REP(j, n){
      if (vis[j]) continue;
      if (dist[j] == -1) continue;
      if (min_dist == -1 || min_dist > dist[j]) {
        min_dist = dist[j];
        best_id = j;
      }
    }
    if (best_id == -1) break;
    if (best_id == n - 1) break;
    vis[best_id] = 1;
    REP(j, SIZE(adj[best_id])){
      int cur = adj[best_id][j];
      if (vis[cur]) continue;
      if (dist[cur] == -1 || dist[cur] > dist[best_id] + 1){
        dist[cur] = dist[best_id] + 1;
        pre[cur] = best_id;
      }
    }
  }
  if (dist[n - 1] == -1) cout << "IMPOSSIBLE\n";
  else{
    cout << dist[n - 1] + 1 << endl;
    VI path;
    int p = n - 1;
    path.PB(n);
    while (pre[p] != -1) {
      path.PB(pre[p] + 1);
      p = pre[p];
    }
    reverse(ALL(path));
    REP(i, SIZE(path)){
      if (i) cout << " ";
      cout << path[i];
    }
    cout << endl;
  }
  return 0;
}
