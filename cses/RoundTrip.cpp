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

bool found = false;
int start = -1;
VI ans;
VI tried;

void dfs(int cur, int pre, const VVI& adj, VI &vis, VI &next){
  /*  cout << "debug " << cur << " " << pre << " " << next[pre] << endl;
  FOR(i, 1, 5) {
      cout << next[i] << " ";
  }
  cout << endl;
*/
  if (found) return;
  if (vis[cur]) {
    found = true;
    ans.PB(cur);
    int p = next[cur];
    while (p != cur) {
      ans.PB(p);
      p = next[p];
    }
    ans.PB(cur);
    return;
  }
  tried[cur] = 1;


  vis[cur] = true;
  REP(i, SIZE(adj[cur])){
    int j = adj[cur][i];
    if (pre != j && SIZE(adj[j]) >= 2){
      next[cur] = j;
      dfs(j, cur, adj, vis, next);
    }
  }

  vis[cur] = false;
}


int main(){
  int n, m, a, b;
  cin >> n >> m;
  VVI adj(n + 1, VI());
  VI vis(n + 1, 0);
  VI next(n + 1, 0);
  REP(i, n + 1) tried.PB(0);

  REP(k, m){
    cin >> a >> b;
    adj[a].PB(b);
    adj[b].PB(a);
  }
  FOR(i, 1, n){
    if (SIZE(adj[i]) < 2 || tried[i]) continue;
    dfs(i, 0, adj, vis, next);
  }
  if (found) {
    cout << SIZE(ans) << endl;
    REP(i, SIZE(ans)){
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
