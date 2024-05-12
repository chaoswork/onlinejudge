/*
ID:huangch7
PROB: checker
LANG:C++
*/

#pragma GCC optimize("O3,unroll-loops,Ofast")
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

int n;
int total_sum = 0;
int n_sol = 0;
int used_row[13];
int used_col[13];
int used_diaga[30]; // r + c
int used_diagb[30]; // c - r + n
int cols[13];
int cur_sum[13];


void dfs(int cur){
  if (cur == n){
    n_sol++;
    if (n_sol <= 3){
      REP(i, n){
        if (i) cout << " ";
        cout << cols[i] + 1;
      }
      cout << endl;
    }
    return;
  }
    

  REP(i, n){
    if (used_col[i]) continue;
    if (used_diaga[cur + i]) continue;
    if (used_diagb[i - cur + n]) continue;

    cols[cur] = i;
    cur_sum[cur] = i;
    if (cur > 0) cur_sum[cur] += cur_sum[cur - 1];
    used_col[i] = 1;
    used_diaga[cur + i] = 1;
    used_diagb[i - cur + n] = 1;
    dfs(cur + 1);
    used_col[i] = 0;
    used_diaga[cur + i] = 0;
    used_diagb[i - cur + n] = 0;
    
  }
}
int main(){

  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("checker.in","r",stdin);
  freopen("checker.out","w",stdout);

  cin >> n;
  REP(i, n) total_sum += i;
  dfs(0);
  cout << n_sol << endl;
  return 0;
}
