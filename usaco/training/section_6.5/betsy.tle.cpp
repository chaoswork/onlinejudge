/*
ID:huangch7
PROB: betsy
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

int n;
int step = 1;
int ans = 0;
int visited[10][10];
int chi[10][10];
VI dx = {0, 0, 1, -1};
VI dy = {1, -1, 0, 0};

void change_chi(int r, int c, int v){
  REP(i, 4){
    int rr = r + dx[i];
    int cc = c + dy[i];
    if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;
    chi[rr][cc] += v;
  }
}

bool check_alone(int r, int c){
  bool left_visited = c - 1 < 0 || visited[c - 1];
  bool right_visited = c + 1 >= n || visited[c + 1];
  bool up_visited = r - 1 < 0 || visited[r - 1];
  bool down_visited = r + 1 >= n || visited[r + 1];

  if (left_visited && right_visited && !up_visited && !down_visited) return true;
  if (!left_visited && !right_visited && up_visited && down_visited) return true;
  return false;
}

void dfs(int r, int c){
  // cout << r << " " << c << endl;
  if (r == n - 1 && c == 0){
    if (step == n * n) ans++;
    return;
  }
  // check alone
  if (check_alone(r, c)) return;

  
  step++;
  visited[r][c] = 1;
  change_chi(r, c, -1);
  VI valid_r;
  VI valid_c;

  int chi_1_cnt = 0;
  int chi_1_x;
  int chi_1_y;


  REP(i, 4){
    int rr = r + dx[i];
    int cc = c + dy[i];
    if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;
    if (visited[rr][cc]) continue;
    valid_r.PB(rr);
    valid_c.PB(cc);
    if (rr != n - 1 && cc != 0 && chi[rr][cc] == 1){
      chi_1_cnt++;
      chi_1_x = rr;
      chi_1_y = cc;
    }
    // dfs(rr, cc);
    
  }

  if (chi_1_cnt == 1){
    dfs(chi_1_x, chi_1_y);
  } else if (chi_1_cnt < 1){
    REP(i, SIZE(valid_r)) dfs(valid_r[i], valid_c[i]);
  }
  
  step--;
  visited[r][c] = 0;
  change_chi(r, c, 1);
    
  
  
}


int main() {
  freopen("betsy.in","r",stdin);
  freopen("betsy.out","w",stdout);

  cin >> n;
  memset(visited, 0, sizeof(visited));
  
  REP(i, n) REP(j, n) chi[i][j] = 4;
  REP(i, n){
    chi[0][i]--;
    chi[i][0]--;
    chi[n - 1][i]--;
    chi[i][n - 1]--;
  }
  /*
  REP(i, n){
    REP(j, n) cout << chi[i][j] << "\t";
    cout << endl;
  }
  */

  dfs(0, 0);

  cout << ans << endl;
  return 0;
}



