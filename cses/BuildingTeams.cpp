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

bool fail = false;

void dfs(int cur_id, int cur_color, const VVI &adj, VI &color, bool check){
  if (fail) return;
  if (color[cur_id] != 0){
    if (check && color[cur_id] != cur_color) fail = true;
    return;
  }
  int next_color = cur_color + 1;
  if (next_color > 2) next_color = 1;
  color[cur_id] = cur_color;
  REP(i, SIZE(adj[cur_id])){
    dfs(adj[cur_id][i], next_color, adj, color, true);
  }
  
}

int main(){
  int n, m, a, b;
  cin >> n >> m;
  VVI adj(n + 1, VI());
  VI color(n + 1, 0);
  REP(i, m){
    cin >> a >> b;
    adj[a].PB(b);
    adj[b].PB(a);
  }
  FOR(i, 1, n) dfs(i, 1, adj, color, false);
  if (fail) cout << "IMPOSSIBLE" << endl;
  else{
    FOR(i, 1, n){
      if (i) cout << " ";
      cout << color[i];
    }
    cout << endl;
  }
  return 0;
}
