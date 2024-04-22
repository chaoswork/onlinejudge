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


typedef struct node{
  node(int _x, int _y, int _v): x(_x), y(_y), v(_v){}
  int x;
  int y;
  int v;
} node;

int main(){
  int n, m;
  string s;
  VS labyrinth;
  cin >> n >> m;
  int sx, sy, ex, ey;
  int ans[n * m];
  char prev_ans[n * m];
  int prev[n * m];
  fill_n(ans, n * m, -1);
  
  REP(i, n){
    cin >> s;
    labyrinth.PB(s);
    REP(j, m){
      if (s[j] == 'A') {sx = i; sy = j;}
      if (s[j] == 'B') {ex = i; ey = j;}
    }
  }
  queue<node> Q;
  vector<VI> dir_xy = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  string dirs = "UDLR";

  Q.push(node(sx, sy, 0));
  ans[sx * m + sy] = 0;
  prev[sx * m + sy] = -1;

  while (Q.size()){
    auto cur = Q.front();
    if (cur.x == ex && cur.y == ey) break;
    REP(i, 4){
      int x = cur.x + dir_xy[i][0];
      int y = cur.y + dir_xy[i][1];
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      if (ans[x * m + y] >= 0) continue;
      if (labyrinth[x][y] == '#') continue;

      ans[x * m + y] = cur.v + 1;
      prev_ans[x * m + y] = dirs[i];
      prev[x * m + y] = cur.x * m + cur.y;
      Q.push(node(x, y, cur.v + 1));
    }
    Q.pop();
  }
  /*
  REP(i, n){
    REP(j, m){
      cout << ans[i * m + j] << "\t";
    }
    cout << endl;
    }*/
  if (ans[ex * m + ey] != -1){
    cout << "YES" << endl;
    cout << ans[ex * m + ey] << endl;
    int cur = ex * m + ey;
    string path;
    while (cur != sx * m + sy){
      // cout << "cur = " << cur << "(" << cur / m << "," << cur % m << ")" << endl;
      path += prev_ans[cur];
      cur = prev[cur];
    }
    reverse(ALL(path));
    cout << path << endl;

  } else {
    cout << "NO" << endl;
  }

  
  return 0;
}
