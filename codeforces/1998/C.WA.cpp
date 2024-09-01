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
    REP(i, n){
      int p = (n - 1) / 2;
      // cout << i << " " << p << endl;      
      if (n % 2 == 1){
        if (p <= i) p--;
      } else {
        if (p >= i) p++;
      }
      // cout << i << " " << p << endl;


      if (nums[i].second == 1){

        best = max(best, nums[p].first + k + nums[i].first);
      } else {

        map<LL, pair<int, int> > cnt;
        FOR(j, p, n - 1){
          if (j == i) continue;
          LL cur = nums[j].first;
          int b = nums[j].second;
          if (cnt.find(cur) == cnt.end()) cnt[cur] = MP(0, b);
          cnt[cur].first++;
        }
        LL kk = k;
        while(kk && SIZE(cnt) > 1){
          auto it = cnt.begin();
          LL n1 = it->first;
          int n1n = it->second.first;
          int b = it->second.second;
          if(b == 0) break;
          ++it;
          LL n2 = it->first;
          LL diff = n2 - n1;
          if (diff * n1n <= kk){
            kk -= diff * n1n;
            cnt.erase(cnt.begin());

            if (cnt.begin()->second.second == 0) break;
            cnt.begin()->second.first += n1n;
            
          } else {
            n1 += kk / n1n;
            kk -= n1 * n1n;
            cnt.erase(cnt.begin());
            cnt.insert(MP(n1, MP(n1n, b)));
            break;
          }
          

        }
        best = max(best, cnt.begin()->first + nums[i].first);
        }
    }
    cout << best << endl;
    
  }
  return 0;
}
