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
  int t, n, k, x;
  cin >> t;
  REP(tt, t){
    cin >> n >> k;
    vector<pair<LL, int> > nums(n, MP(0, 0));
    REP(i, n){
      cin >> x;
      nums[i].first = x;
    }
    REP(i, n){
      cin >> x;
      nums[i].second = x;
    }
    sort(ALL(nums));
    LL best = 0;
    // increase i
    REP(i, n){
      // 1 2 3 p = 1
      // 1 2 3 4 p = 1
      int m = (n - 1) / 2;
      if (n % 2 == 1 && i >= m) m--;
      else if (n % 2 == 0 && i <= m) m++;
      if (nums[i].second)
        best = max(best, nums[i].first + k + nums[m].first);
      else
        best = max(best, nums[i].first + nums[m].first);
    }
    // cout << best << endl;
    // find lowest median
      
    LL L = 0;
    LL R = 1000000001;
    // 1111111000
    while (L + 1 < R){
      // cout << L << " " << R << endl;
      LL m = L + (R - L) / 2;
      int N = 0;
      VI cands;
      REP(i, n - 1){
        if (nums[i].first >= m) N++;
        else if (nums[i].second == 1){
          cands.PB(m - nums[i].first);
        }
      }
      LL kk = k;
      reverse(ALL(cands));
      REP(i, SIZE(cands)){
        if (kk >= cands[i]){
          kk -= cands[i];
          N++;
        } else break;
      }
      if (N >= (n + 1) / 2) L = m;
      else R = m;
    }
    best = max(best, nums[n - 1].first + L);

    cout << best << endl;
    
  }

  return 0;
}
