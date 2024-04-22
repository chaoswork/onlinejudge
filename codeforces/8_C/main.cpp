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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

LL dist[30][30];
LL dist2bag[30];
int used[30];
LL dp[1 << 24];

LL solve(int state){
  if (dp[state] > 0) return dp[state];
  if (state == 0) return 0;

  


  return dp[state];
}
           

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int xb, yb, n, x, y;
    LL w, h;

    memset(dp, 0, sizeof(dp));
    vector<PII> ob;
    std::cin >> xb >> yb >> n;
    REP (i, n) {
      std::cin >> x >> y;
      ob.PB(MP(x, y));
    }

    REP(i, n) {
      FOR(j, i + 1, n - 1){
        w = ob[i].first - ob[j].first;
        h = ob[i].second - ob[j].second;
        dist[i][j] = w * w + h * h;
      }
      w = ob[i].first - xb;
      h = ob[i].second - yb;
      dist2bag[i] = w * w + h * h;


    }
    
    cout << dp[(1 << n) - 1] << endl;


    return 0;
}
