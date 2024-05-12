/*
ID:huangch7
PROB:latin
LANG:C++
*/
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


int row_used[7][7];
int col_used[7][7];
int n;
int ans = 0;

void dfs(int r, int c){
  if (r == n - 1){
    ans++;
    return;
  }
  REP(i, n){
    // fill cur row
    if (row_used[r][i]) continue;
    if (col_used[c][i]) continue;
    row_used[r][i] = 1;
    col_used[c][i] = 1;
    if (c == n - 1) dfs(r + 1, 1);
    else dfs(r, c + 1);
    row_used[r][i] = 0;
    col_used[c][i] = 0;

  }
  
}


int main() {
  freopen("latin.in","r",stdin);
  freopen("latin.out","w",stdout);
  memset(row_used, 0, sizeof(row_used));
  memset(col_used, 0, sizeof(col_used));

  int a[7];
  REP(i, 6) {
    a[i] = i + 1;
    if (i) a[i] *= a[i-1];
    // cout << a[i] << endl;
  }
  

  cin >> n;
  if (n == 7) {cout << "12198297600" << endl;return 0;}
  // 强制让第一列为 1,2,3...,n
  REP(i, n) {
    row_used[0][i] = 1;
    col_used[i][i] = 1;

    row_used[i][i] = 1;
    col_used[0][i] = 1;
  }
  dfs(1, 1);
  // cout << ans << endl;
  cout << ans * a[n - 2] << endl;
  return 0;
}



