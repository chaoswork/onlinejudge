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
  LL n, a, b, p;
  vector<pair<LL, pair<LL, LL> > > nums;
  map<LL, LL> ans;
  LL best = 0;
  ans[0] = 0;
  //  ans[4] = 10;
  cin >> n;
  REP(i, n){
    cin >> a >> b >> p;
    nums.PB(MP(b, MP(a, p)));
  }
  sort(ALL(nums));
  REP(i, n){
    auto it1 = ans.lower_bound(nums[i].second.first);
    // auto it2 = ans.upper_bound(nums[i].first); // strategy 1
    auto it2 = ans.end();  // strategy 2
    --it1;
    --it2;
    LL cur = max(it1->second + nums[i].second.second,
                  it2->second);
    ans[nums[i].first] = cur;
    best = max(cur, best);
  }
  cout << best << endl;
  return 0;
}
