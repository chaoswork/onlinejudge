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

const LL MOD = 1000000007;
LL buff[2][101];

int main(){
  int n, m, x;
  LL ans = 1;
  cin >> n >> m;
  int last = -1;
  int p = 0;
  REP(i, n){
    cin >> x;
    if (last != -1 && last != 0 && x != 0 && abs(x - last) > 1) {
      ans = 0;
      break;
    }
    
    if (x == 0){
      if (last == -1) {
        FOR(j, 1, m) buff[p%2][j] = 1;
      } else if (last == 0){
        //        FOR(k, 1, m) cout << buff[(p - 1)%2][k] << " ";
        // cout << "-" << endl;
        FOR(j, 1, m){
          buff[p%2][j] = 0;
          if (j - 1 >= 1) buff[p%2][j] += buff[(p - 1) % 2][j - 1];
          buff[p%2][j] %= MOD;
          buff[p%2][j] += buff[(p - 1) % 2][j];
          buff[p%2][j] %= MOD;
          if (j + 1 <= m) buff[p%2][j] += buff[(p - 1) % 2][j + 1];
          buff[p%2][j] %= MOD;
        }
        
        
      } else { // last is 1 - 100
        FOR(j, 1, m) buff[p%2][j] = 0;
        if (last - 1 >= 1) buff[p%2][last - 1] = 1;
        buff[p%2][last] = 1;
        if (last + 1 <= m) buff[p%2][last + 1] = 1;
      }
      //      FOR(k, 1, m) cout << buff[p%2][k] << " ";
      //cout << endl << "----" << endl;

      p++;
    } else {
      if (last == 0){
        LL cnt = 0;
        if (x - 1 >= 1) cnt += buff[(p - 1) % 2][x - 1];
        cnt += buff[(p - 1) % 2][x];        
        if (x + 1 <= m) cnt += buff[(p - 1) % 2][x + 1];
        cnt %= MOD;
        ans *= cnt;
        ans %= MOD;
        // cout << ans << " " << cnt << endl;
        if (ans == 0) break;
      }
    }
    last = x;
  }
  if (last == 0){
    LL cnt = 0;
    FOR(j, 1, m){
      cnt += buff[(p - 1) % 2][j];
    }
    cnt %= MOD;        
    ans *= cnt;
    ans %= MOD;
    // cout << ans << " " << cnt << endl;
  }
  cout << ans << endl;
  return 0;
}
