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

int main(){
  int n, m;
  int a, b, c, d;
  string line;
  VS forest;
  cin >> n >> m;
  VVI cache = MATRIX(n + 1, n + 1, 0);
  REP(i, n) {
    cin >> line;
    forest.PB(line);
  }
  FOR(i, 1, n){
    int cur = 0;
    FOR(j, 1, n){
      if (forest[i - 1][j - 1] == '*') cur++;
      cache[i][j] = cache[i - 1][j] + cur;
    }
  }
  // DISPLAY_MATRIX(cache, n + 1, n + 1);
  REP(i, m){
    cin >> a >> b >> c >> d;
    cout << cache[c][d] - cache[a - 1][d] - cache[c][b - 1] + cache[a - 1][b - 1] << endl;
  }
    
  
  return 0;
}
