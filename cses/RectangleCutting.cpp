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

LL cache[512][512];

LL solve(int a, int b){
  if (a > b) return solve(b, a);
  if (cache[a][b] != -1) return cache[a][b];
  if (a == b) return cache[a][b] = 0;

  LL best = -1;
  FOR(i, 1, a - 1){
    LL cur = solve(i, b) + solve(a - i, b);
    if (best < 0 || best > cur){
      best = cur;
    }
  }
  FOR(j, 1, b - 1){
    LL cur = solve(a, j) + solve(a, b - j);
    if (best < 0 || best > cur){
      best = cur;
    }
  }
  return cache[a][b] = best + 1;
}

int main(){
  int a, b;
  cin >> a >> b;
  REP(i, 512) REP(j, 512) cache[i][j] = -1;
  cout << solve(a, b) << endl;
  return 0;
}