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
  int n, x;
  cin >> n;
  map<int, int> cnt;
  // map<int, int> largest;
  int best = 0;
  REP(i, n){
    cin >> x;
    if (cnt.find(x) == cnt.end()){
      cnt[x] = 1;
      best = max(best, cnt[x]);
    }
    auto it = cnt.find(x);
    if (it != cnt.end()){
      // update
      if (it != cnt.begin()){
        cnt[x] = cnt[(--it)->first] + 1;
        best = max(best, cnt[x]);
        // delete larger
        auto delit = cnt.find(x);
        delit++;
        while (true){
          if (delit == cnt.end()) break;
          if (delit->second <= cnt[x]) delit = cnt.erase(delit);
          // else delit++;
          else break; // 后面的都更大了，还需要遍历么？
        }
      }
    }
    // cout << "debug " << i << " " << x << " " << cnt[x] << endl;
  }
  cout << best << endl;
  return 0;
}
