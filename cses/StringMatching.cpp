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

void find(string s, string p){
  int n = 2;
  VI large(n, 0);
  VI small(n, 0);
  VI base; //{3057, 1233, 9527, 2133, 3421, 3891, 7277, 9911, 3141, 592653};;//10;
  int cur = 1;
  REP(i, n){
    base.PB(1000 + cur);
    cur = cur * 333 + cur ^ 0xff61f3221;
    cur %= 1000007;
  }
  VI offset; // = {3, 2, 1, 6, 7, 2, 11, 3, 17, 4};
  cur %= 1007;
  REP(i, n){
    offset.PB(1000 + cur);
    cur = cur * 1333 + cur ^ 0xff61f3221;
    cur %= 1007;
  }
  VI rand = {
    3, 71, 4, 5, 9, 2,
    6, 15, 13, 28, 7, 27,
    8, 10, 17, 12, 11,  72,
    31, 20, 14, 33, 52, 39,
    65, 54
  };
  VI target(n, 0);
  VI scale(n, 1);
  int ans = 0;
  
  REP(j, SIZE(p)){
    REP(k, n) scale[k] *= base[k];
  }

  REP(i, SIZE(p)){
    REP(k, n){
      target[k] *= base[k];    
      target[k] += rand[p[i] - 'a'] + offset[k];
    }


  }

  REP(i, SIZE(s)){
    bool ok = true;
    REP(k, n){
      large[k] *= base[k];    
      large[k] += rand[s[i] - 'a'] + offset[k];

      if (i + 1 > SIZE(p)){
        small[k] *= base[k];
        small[k] += rand[s[i - SIZE(p)] - 'a'] + offset[k];
      }

      if (large[k] - small[k] * scale[k] != target[k]){
        ok = false;
      }
    }
    if (ok) ans++;


  }
  cout << ans << endl;
}


int main(){
  string s, p;
  cin >> s >> p;
  find(s, p);
  return 0;
}
