/*
ID:huangch7
PROB:wissqu
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

// ABCDE
// 33343
VS board;
int used[4][4];
int cnt[5] = {3,3,3,4,3};
string cows = "ABCDE";
int n_sol = 0;
VI rows(16, 0);
VI cols(16, 0);
string ans = "0000000000000000";

bool check_ok(int r, int c, char t){
  FOR(i, -1, 1) FOR(j, -1, 1){
    int x = r + i;
    int y = c + j;
    if (x < 0 || x >= 4) continue;
    if (y < 0 || y >= 4) continue;
    if (board[x][y] == t) return false;
  }
  return true;
}

void dfs(int cur){
  if (cur == 16){
    if (++n_sol == 1){
      REP(i, 16){
        cout << ans[i] << " " << rows[i] + 1 << " " << cols[i] + 1 << endl;
      }
    }

    return;
  }
  if (cur == 0){
    REP(i, 4) REP(j, 4){
      if (used[i][j] == 0 && check_ok(i, j, 'D')){
        cnt[3]--;
        char old = board[i][j];
        board[i][j] = 'D';
        used[i][j] = 1;
        rows[cur] = i;
        cols[cur] = j;
        ans[cur] = 'D';
        dfs(cur + 1);
        cnt[3]++;
        board[i][j] = old;
        used[i][j] = 0;
      }
    }
  } else {
     REP(k, 5) REP(i, 4) REP(j, 4){
      if(used[i][j] == 0 && cnt[k] && check_ok(i, j, cows[k])){
        cnt[k]--;
        char old = board[i][j];
        board[i][j] = cows[k];
        used[i][j] = 1;
        rows[cur] = i;
        cols[cur] = j;
        ans[cur] = cows[k];
        
        dfs(cur + 1);
        
        cnt[k]++;
        board[i][j] = old;
        used[i][j] = 0;
      }
    }
  }
  
}

int main(){
  freopen("wissqu.in","r",stdin);
  freopen("wissqu.out","w",stdout);

  string line;
  memset(used, 0, sizeof(used));

  REP(i, 4){
    cin >> line;
    board.PB(line);
  }
  dfs(0);
  cout << n_sol << endl;
  return 0;
}
