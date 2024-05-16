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

const LL MOD = 1000000000 + 7;
LL cache[1000005][6];

LL dp(int n, int type){
  if (cache[n][type] != -1) return cache[n][type];
  if (n == 1) return cache[n][type] = 1;

  // type 0
  //+-+-+
  //|   |
  if (type == 0){
    return cache[n][type] = (dp(n - 1, 0) + dp(n - 1, 1) + dp(n - 1, 2)) % MOD;
  }

  // type 1
  //+   +
  //|   |
  else if (type == 1){
    return cache[n][type] = (dp(n - 1, 0) + dp(n - 1, 1) + dp(n - 1, 2)) % MOD;
  }

  // type 2
  //+-+-+
  //| | |
  else if (type == 2){
    return cache[n][type] = (dp(n - 1, 0) + dp(n - 1, 2) + dp(n - 1, 3) + dp(n - 1, 4) + dp(n - 1, 5)) % MOD;
  }

  // type 3
  //+ +-+
  //| | |
  else if(type == 3){
    return cache[n][type] = (dp(n - 1, 0) + dp(n - 1, 2) + dp(n - 1, 3) + dp(n - 1, 4) + dp(n - 1, 5)) % MOD;
  }

  // type 4
  //+-+ +
  //| | |
  else if(type == 4) {
    return cache[n][type] = (dp(n - 1, 0) + dp(n - 1, 2) + dp(n - 1, 3) + dp(n - 1, 4) + dp(n - 1, 5)) % MOD;
  }

  // type 5
  //+ + +
  //| | |
  else if(type == 5) {
    return cache[n][type] = (dp(n - 1, 0) + dp(n - 1, 2) + dp(n - 1, 3) + dp(n - 1, 4) + dp(n - 1, 5)) % MOD;
  }
  
  
  return -1;
}

int main(){
  int t, n;
  REP(i, 1000001) REP(j, 6) cache[i][j] = -1;
  cin >> t;
  REP(it, t){
    cin >> n;
    cout << (dp(n, 0) + dp(n, 2)) % MOD << endl;
  }
}
