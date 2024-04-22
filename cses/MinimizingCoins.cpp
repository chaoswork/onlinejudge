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
  int n, x, c;
  VI coins, dp;
  cin >> n >> x;

  dp.resize(x + 1);
  fill_n(dp.begin(), x + 1, -1);
  dp[0] = 0;
  REP(i, n){
    cin >> c;
    coins.PB(c);
  }
  FOR(i, 1, x){
    REP(j, n){
      int last = i - coins[j];
      if (last >= 0 && dp[last] != -1){
        if (dp[i] == -1 || dp[i] > dp[last] + 1){
          dp[i] = dp[last] + 1;
        }
      }
    }
    //cout << dp[i] << endl;
  }
  cout << dp[x] << endl;
  
  
  return 0;
}
