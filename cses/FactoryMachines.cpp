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

vector<LL> nums;

bool ok(LL cur, LL tgt){
  int t = 0;
  REP(i, SIZE(nums)){
    t += cur / nums[i];
  }
  return t >= tgt;
}

int main(){
  LL n, t, k;
  cin >> n >> t;

  REP(i, n){
    cin >> k;
    nums.PB(k);
  }
  LL L = 0;
  LL R = 1;
  while (!ok(R, t)){
    R = R << 1;
    //    cout << R << endl;
  }

  while (L + 1 < R){
    LL mid = L + (R - L) / 2;
    if (ok(mid, t)) R = mid;
    else L = mid;
  }
  cout << R << endl;
  return 0;
}
