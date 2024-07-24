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
  //123456789 101112131415
  // 1-9: 9 x 1
  // 10-99: 90 x 2
  // 100 - 999: 900 x 3
  // 1000 - 9999: 9000 x 4
  LL q, k;
  vector<LL> cnts;
  cin >> q;
  LL cnt = 0;
  LL base = 9;
  FOR(i, 1, 17){
    cnt += i * base;
    base *=10;
    // cout << cnt << " " << cnt - 1e18 << endl;
    cnts.PB(cnt);
  }
  
  REP(i, q){
    cin >> k;
    if (k < 10){
      cout << k << endl;
      continue;
    }
    auto it = upper_bound(ALL(cnts), k);
    // cout << *it << endl;
    it--;
    // cout << k - *it << " " << distance(cnts.begin(), it) + 2 <<  endl;
    LL left = k - *it;
    if (left == 0){
      cout << 9 << endl;
      continue;
    }
    LL dist = distance(cnts.begin(), it) + 2;
    LL prefix = 1;
    REP(k, dist - 1) prefix *= 10;
    LL target = (left - 1) / dist +  prefix;
    LL R = (left - 1) % dist;
    //        cout << left << " " << dist << " " << target << " " << R << endl;
    LL ans = 0;
    LL base = 1;
    REP(k, dist - 1){
      base *= 10;
    }
    while (R-- > -1){
      ans = target / base;
      target = target % base;
      base /= 10;
    }
    cout << ans << endl;
  }
  return 0;
}
