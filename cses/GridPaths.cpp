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

LL MOD = 1000000007;

int main(){
  int n;
  string line;
  LL dp[1024][1024];
  memset(dp, 0, sizeof(dp));
  cin >> n;
  REP(i, n){
    cin >> line;
    REP(j, n){
      if (line[j] == '*') dp[i][j] = 0;
      else dp[i][j] = -1;
    }
  }
  if (dp[0][0] != 0) dp[0][0] = 1;
  REP(i, n) REP(j, n){
    if (dp[i][j] != -1) continue;
    dp[i][j] = 0;
    if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
    dp[i][j] %= MOD;
    if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
    dp[i][j] %= MOD;    
  }
  cout << dp[n - 1][n - 1] << endl;
  
  return 0;
}
