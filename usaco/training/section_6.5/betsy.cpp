/*
ID:huangch7
PROB: betsy
LANG:C++
*/

/*
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
*/

#include <iostream>
#include <fstream>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, l, h) for(int i=(l); i<=(h); ++i)

int n;
int n2;
int step = 1;
int ans = 0;
bool visited[10][10];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};



int get_chi(int r, int c){
  int n = 0;
  REP(i, 4){
    if (!visited[r + dx[i]][c + dy[i]]) ++n;
  }
  return n;
  
}
/*
bool check_alone(int r, int c){
  bool left_visited = visited[r][c - 1];
  bool right_visited = visited[r][c + 1];
  bool up_visited = visited[r - 1][c];
  bool down_visited = visited[r + 1][c];

  if (left_visited && right_visited && !up_visited && !down_visited) return true;
  if (!left_visited && !right_visited && up_visited && down_visited) return true;
  return false;
}
*/
void dfs(int r, int c, int step){
  // cout << r << " " << c << endl;
  if (r == n && c == 1){
    if (step == n2) ans++;
    return;
  }
  // check alone
  // if (check_alone(r, c)) return;
  if (( visited[r][c - 1] &&  visited[r][c + 1] && !visited[r - 1][c] && !visited[r + 1][c]) ||
      (!visited[r][c - 1] && !visited[r][c + 1] &&  visited[r - 1][c] &&  visited[r + 1][c])) return;

  
  // step++;
  // visited[r][c] = 1;
  //  change_chi(r, c, -1);
  // VI valid_r;
  // VI valid_c;

  int chi_1_cnt = 0;
  int chi_1_x, chi_1_y, rr, cc;



  REP(i, 4){
    rr = r + dx[i];
    cc = c + dy[i];
    if (visited[rr][cc] || (rr == n && cc == 1)) continue;
    // valid_r.PB(rr);
    // valid_c.PB(cc); // 去掉 vector 存储后，时间从 4s 下降到 1.9s
    if (get_chi(rr, cc) < 2){
    // if (rr != n && cc != 1 && chi[rr][cc] == 1){
      chi_1_cnt++;
      chi_1_x = rr;
      chi_1_y = cc;
    }
    // dfs(rr, cc);
    
  }

  

  if (chi_1_cnt > 1)
    return;
  else{
    if (chi_1_cnt == 1){
      // visited[r][c] = true;   << Here: 2s -> 0.2s
      visited[chi_1_x][chi_1_y] = true;
      dfs(chi_1_x, chi_1_y, step + 1);
      visited[chi_1_x][chi_1_y] = false;
      // visited[r][c] = false;
      //    } else if (chi_1_cnt < 1){
    } else {
      //REP(i, SIZE(valid_r)) dfs(valid_r[i], valid_c[i], step + 1);
        REP(i, 4){
          rr = r + dx[i];
          cc = c + dy[i];
          if (visited[rr][cc]) continue;
          // visited[r][c] = true;
          visited[rr][cc] = true;
          dfs(rr, cc, step + 1);
          visited[rr][cc] = false;
          
          // visited[r][c] = false;
        }
    }

  }
  
  // step--;
  // visited[r][c] = 0;
  //  change_chi(r, c, 1);
    
  
  
}


int main() {
  freopen("betsy.in","r",stdin);
  freopen("betsy.out","w",stdout);

  cin >> n;
  n2 = n * n;
  //memset(visited, 0, sizeof(visited));
  
  
  //FOR(i, 1, n) FOR(j, 1, n) chi[i][j] = 4;
  FOR(i, 0, n + 1){
    // chi[1][i]--;
    // chi[i][1]--;
    // chi[n][i]--;
    // chi[i][n]--;
    visited[0][i] = true;
    visited[n + 1][i] = true;
    visited[i][0] = true;
    visited[i][n + 1] = true;
            
  }
  visited[1][1] = true;
  /*
  REP(i, n){
    REP(j, n) cout << chi[i][j] << "\t";
    cout << endl;
  }
  */

  dfs(1, 1, 1);

  cout << ans << endl;
  return 0;
}



