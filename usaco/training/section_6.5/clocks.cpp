/*
ID:huangch7
PROB: clocks
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









const int MAX_N = 1 << 18;
int target = MAX_N - 1;
int pre[MAX_N];
int path[MAX_N];

int rotate_pos(int x, int pos){
  int mask = 3;
  int y = x;
  REP(i, pos){
    mask <<= 2;
    y >>= 2;
  }
  mask = target ^ mask;
  y &= 3;

  y = (y + 1) & 3;
  
  REP(i, pos) y <<= 2;

  return (x & mask) | y;
}

VS ops = {"ABDE", "ABC", "BCEF",
         "ADG", "BDEFH", "CFI",
         "DEGH", "GHI", "EFHI"};

int rotate(int x, int index){
  REP(i, SIZE(ops[index])) {
    x = rotate_pos(x, ops[index][i] - 'A');
  }
  return x;
}
                            
/*
1	ABDE
2	ABC
3	BCEF
4	ADG
5	BDEFH
6	CFI
7	DEGH
8	GHI
9	EFHI

 */



int main() {
  freopen("clocks.in","r",stdin);
  freopen("clocks.out","w",stdout);


  fill_n(pre, MAX_N, -1);
  
  int state = 0;
  int x;
  REP(i, 9){
    cin >> x;
    state |= ((x / 3) - 1) << (2 * i);
  }
  // cout << state << endl;

  queue<int> Q;
  Q.push(state);
  while (SIZE(Q)){
    int cur = Q.front();

    Q.pop();
    if (cur == target) break;
    REP(i, SIZE(ops)){
      int next_state = rotate(cur, i);
      if (pre[next_state] == -1){
        pre[next_state] = cur;
        path[next_state] = i + 1;
        Q.push(next_state);
      }
    }
    
  }

  VI ans;
  int cur = target;
  while (cur != state){
    ans.PB(path[cur]);
    cur = pre[cur];
  }
  reverse(ALL(ans));
  REP(i, SIZE(ans)){
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}



