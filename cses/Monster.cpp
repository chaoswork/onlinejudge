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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int dxr[4] = {0, 0, -1, 1};
int dyr[4] = {1, -1, 0, 0};

string dir = "LRDU";
int main(){
  int n, m;
  string line;
  VS board;
  cin >> n >> m;
  VVI paths = MATRIX(n, m, 0);
  int start_x = -1;
  int start_y = -1;
  VI monster_x;
  VI monster_y;
  REP(i, n){
    cin >> line;
    REP(j, m) {
      if (line[j] == 'A') {start_x = i; start_y = j;}
      else if (line[j] == 'M') {monster_x.PB(i); monster_y.PB(j);}
    }
    board.PB(line);
  }
  vector<PII> man;
  man.PB(MP(start_x, start_y));
  int t = 0;
  bool found_ans = false;
  while (true){
    // monster move first
    VI mx; VI my;
    REP(i, SIZE(monster_x)){
      REP(k, 4){
        int xx = monster_x[i] + dx[k];
        int yy = monster_y[i] + dy[k];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && board[xx][yy] == '.'){
          board[xx][yy] = 'M';
          mx.PB(xx);
          my.PB(yy);
        }
      }
    }
    monster_x = mx;
    monster_y = my;
    // man move
    vector<PII> newman;
    bool found_next = false;
    REP(i, SIZE(man)){
      int x = man[i].first;
      int y = man[i].second;
      if (x == 0 || x == n - 1 || y == 0 || y == m - 1){
        cout << "YES" << endl;
        cout << t << endl;
        // cout << start_x << " " << start_y << endl;
        vector<char> ans;
        while (x != start_x || y != start_y){
          // cout << x << "-" << y << endl;
          int k = paths[x][y];
          ans.PB(dir[k]);
          x += dxr[k];
          y += dyr[k];
        }
        reverse(ALL(ans));
        REP(k, SIZE(ans)){
          cout << ans[k];
        }
        cout << endl;
        found_ans = true;
        break;
      }
      REP(k, 4){
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (board[xx][yy] == '.'){
          board[xx][yy] = 'A';
          newman.PB(MP(xx, yy));
          found_next = true;
          paths[xx][yy] = k;
        }
        
      }
      
    }
    man = newman;
    if (found_ans) break;
    if (!found_next) break;
    
    t++;
  }
  /*
  REP(i, n){
    cout << board[i] << endl;
  }
  REP(i, n){
    REP(j, m){
      cout << paths[i][j];
    }
    cout << endl;
  }
  */
  if (!found_ans) cout << "NO" << endl;

  return 0;
}
