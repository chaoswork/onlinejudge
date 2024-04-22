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

int main(){
  LL n, x, t;
  //  const int MAXV = 1000000000 + 2;
  cin >> n >> x;  
  //int dp[41][MAXV];
  int **dp = new int*[n + 1];
  REP(i, n + 1) {
    dp[i] = new int[x + 1];
    REP(j, x + 1) dp[i][j] = 0;
  }
  //memset(dp, 0, sizeof(dp));
  
  vector<int> nums;

  REP(i, n){
    cin >> t;
    nums.PB(t);
  }
  FOR(i, 0, n) dp[i][0] = 1;
  // F[i, V] = F[i - 1, V] + F[i - 1, V - v[i]]
  // F[i, 0] = 1
  FOR(i, 1, n){
    FOR(V, 1, x){

      dp[i][V] = dp[i - 1][V];
      if (V - nums[i - 1] >= 0) dp[i][V] += dp[i - 1][V - nums[i - 1]];
      //      cout << dp[i][V] << "\t";
    }
    //    cout << endl;
    
  }
  cout << dp[n][x] << endl;
  return 0;
}
