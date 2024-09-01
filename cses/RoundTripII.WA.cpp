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
#define DISP_VEC(vec)   REP(i, SIZE(vec)){if (i) cout << " ";cout << vec[i];} cout << endl;
#define MATRIX(n, m, v) vector<vector<int> >((n), vector<int>((m), (v)))
#define DISPLAY_MATRIX(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

// const LL INF = 1LL << 62;
VVI adj;
VI pre;
VI vis;
int found = 0;
int color = 1;


void dfs(int cur, int par){
  DISP_VEC(vis);    
    
  if (found) return;
  if (vis[cur] == color){
    found = cur;
    pre[cur] = par;
    return;
  }
  vis[cur] = color;
  pre[cur] = par;
  REP(i, SIZE(adj[cur])){
    dfs(adj[cur][i], cur);
    color++;
  }
}



int main(){
  int n, m, a, b;
  cin >> n >> m;
  adj = VVI(n + 1, VI());
  REP(i, m){
    cin >> a >> b;
    adj[a].PB(b);
  }

  pre = VI(n + 1, 0);
  vis = VI(n + 1, 0);


  FOR(i, 1, n){
    if (vis[i]) continue;
    if (found) break;
    dfs(i, 0);
    cout << i << " " << found << ":";
    DISP_VEC(vis);
    DISP_VEC(pre);

  }
  if (found == 0){
    cout << "IMPOSSIBLE" << endl;
  } else {
    DISP_VEC(pre);
    VI ans;
    int cur = found;
    cout << cur << endl;
    while (1){
      ans.PB(cur);
      cur = pre[cur];
      if (cur == found){
        ans.PB(cur);
        break;
      }
    }
    reverse(ALL(ans));
    cout << SIZE(ans) << endl;
    REP(i, SIZE(ans)){
      if (i) cout << " ";
      cout << ans[i];
    }
  }
  return 0;
}
