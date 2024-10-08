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
  int n;
  cin >> n;
  int total = n * (n + 1) / 2;
  if (total % 2){
    cout << 0 << endl;
    return 0;
  }
  int target = total / 2;
  vector<LL> ans(target + 1, 0);
  ans[0] = 1;
  FOR(i, 1, n){
    vector<LL> tmp = ans;

    FOR(j, 1, target){
      if (j - i >= 0 and ans[j - i]){
        tmp[j] += ans[j - i];
        tmp[j] %= 1000000007;
      }
    }
    // cout << "debug " << tmp[0] << " " << tmp[1] << " " << tmp[2] << " " << tmp[3] << endl;
    ans = tmp;
  }
  /*
  REP(i, target + 1){
    cout << i << " " << ans[i] << endl;
  }
  */
  if (ans[target] % 2 == 0){
    cout << ans[target] / 2 << endl;
  } else {
    cout << (ans[target] + 1000000007) / 2 << endl;
  }
  return 0;
}
