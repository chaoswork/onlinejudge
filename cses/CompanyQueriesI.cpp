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
  int n, q, x, k;
  cin >> n >> q;
  VI par(n + 1, -1);
  VVI ans = MATRIX(n + 1, 21, -1);
  FOR(i, 2, n){
    cin >> x;
    par[i] = x;
    ans[i][1] = x;
    ans[i][0] = 1;
    FOR(j, 2, 20){
      int y = ans[i][j - 1];
      if (y == -1) break;
      if (ans[y][j - 1] != -1) {
        ans[i][j] = ans[y][j - 1];
        ans[i][0]++;
      } else {
        break;
      }
    }
  }
  REP(i, q){
    cin >> x >> k;
    if (x == 1){
      cout << -1 << endl;
      continue;
    }
    /*
    FOR(j, 0, 5){
       cout << ans[x][j] << " ";
    }
    cout << endl;
    */
    int cur = x;
    while (1){
      if (cur == 1){
        if (k == 0) cout << cur << endl;
        else cout << -1 << endl;
        break;
      }
      int idx = ans[cur][0];
      int max_step = 1 << (idx - 1);
      //  cout << max_step << " " << idx << " " << k << " " << cur << endl;
      while (max_step > k && idx > 1){
        idx--;
        max_step = 1 << (idx - 1);
      }
      // cout << max_step << "  " << idx << " " << k << " " << cur << endl;
      /*
      cout << "idx = "  << idx << endl;
      if(idx == 0){
        cout << "idx = 0; break" << endl;
        break;
      }
      */
      if (k > max_step){
        cur = ans[cur][idx];
        k -= max_step;
      } else if (k == max_step){
        cout << ans[cur][idx] << endl;
        break;
      }
    }

  }
  return 0;
}
