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

// const LL INF = 1LL << 62;
VVI adj;



int main(){
  int n, m, a, b;
  cin >> n >> m;
  adj = VVI(n + 1, VI());
  REP(i, m){
    cin >> a >> b;
    adj[a].PB(b);
  }
  vector<LL> dist(n + 1, 0);
  VI pre(n + 1, 0);
  int flag = 0;
  REP(t, n){
    flag = 0;
    FOR(i, 1, n){
      REP(jj, SIZE(adj[i])){
        int j = adj[i][jj];
        if (dist[j] < dist[i] + 1){
          dist[j] = dist[i] + 1;
          flag = j;
          pre[j] = i;
        }
      }
    }
  }
  if (flag == 0){
    cout << "IMPOSSIBLE" << endl;
  } else {
    REP(i, n){
      flag = pre[flag];
    }
    int cur = flag;
    VI ans;
    while(1){
      ans.PB(cur);
      cur = pre[cur];
      if (cur == flag) {
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
