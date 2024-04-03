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

int hit[10][10];

int main(){
  string s, t;
  cin >> s >> t;
  int xs = s[0] - 'a';
  int ys = s[1] - '1';
  int xt = t[0] - 'a';
  int yt = t[1] - '1';

  memset(hit, 0, sizeof(hit));

  queue<PII > q;
  map<PII, PII > last;
  q.push(MP(xs, ys));
  hit[xs][ys] = 1;
  while (true){
    PII cur = q.front();
    q.pop();
    // cout << cur.first << " " << cur.second << endl;
    if (cur == MP(xt, yt)) break;
    FOR(x, -1, 1) FOR(y, -1, 1){
      if (x == 0 and y == 0) continue;
      int xn = cur.first + x;
      int yn = cur.second + y;
      if (xn < 0 || xn >= 8 || yn < 0 || yn >= 8) continue;
      if (hit[xn][yn]) continue;
      // cout << xn << "-" << xn << endl;
      q.push(MP(xn, yn));
      hit[xn][yn] = 1;
      last[MP(xn, yn)] = cur;
    }
    
  }
  VS ans;
  PII tt = MP(xt, yt);
  while (tt != MP(xs, ys)){
    PII p = last[tt];
    //    cout << "debug" << p.first << " " << p.second << endl;
    // p (6, 2) tt (7, 1)
    int dx = tt.first  - p.first;
    int dy = p.second - tt.second;
    if (dx == -1){
      if (dy == 1) ans.PB("LD");
      if (dy == 0) ans.PB("L");
      if (dy == -1) ans.PB("LU");
    } else if(dx == 0){
      if (dy == 1) ans.PB("D");
      if (dy == -1) ans.PB("U");
    } else if(dx == 1){
      if (dy == 1) ans.PB("RD");
      if (dy == 0) ans.PB("R");
      if (dy == -1) ans.PB("RU");
    }
    tt = p;
    
  }
  reverse(ALL(ans));
  cout << ans.size() << endl;
  REP(i, SIZE(ans)) cout << ans[i] << endl;
  
  

  
  return 0;
}
