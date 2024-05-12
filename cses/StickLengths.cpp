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

LL dist(int x, const VI &nums){
  LL res = 0;
  REP(i, SIZE(nums)){
    res += abs(x - nums[i]);
  }
  return res;
}

int main(){
  // |x - a| + |x - b| + |x - c| + ... + |x - z| 其中，a,b,c,z都是常数，x是变量。请问该函数是凹函数么？
  int n, x;
  cin >> n;
  VI nums;
  int min_v = -1;
  int max_v = -1;
  REP(i, n){
    cin >> x;
    nums.PB(x);
    if (min_v < 0 || min_v > x) min_v = x;
    if (max_v < 0 || max_v < x) max_v = x;    
  }
  int L = min_v;
  int R = max_v;
  while (L + 1 < R){
    int mid = L + (R - L) / 2;
    LL cur = dist(mid, nums);
    int mid_p = mid - 1;
    LL prev = dist(mid_p, nums); // possible equal?
    // cout << L << " " << R << " " << mid << cur << " " << prev << endl;
    while (prev == cur) {
      prev = dist(mid_p, nums);
    }
    if (prev > cur) {L = mid;}
    else {R = mid;}
  }
  cout << min(dist(L, nums), dist(R, nums)) << endl;
  
  return 0;
}
