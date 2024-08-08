#pragma GCC optimize("O3,unroll-loops,Ofast")
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
#define DISP_VEC(vec)   REP(i, SIZE(vec)){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_SET(S)   {int i = 0;for(auto e: S){if (i++) cout << " ";cout << e;} cout << endl;}
#define DISP_VEC_N(vec, n)   REP(i, n){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_MAT(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

int main(){
  optimize;
  int n, x, w;
  cin >> n >> x;
  multiset<LL> nums;
  REP(i, n){
    cin >> w;
    nums.insert(w);
  }
  int ans = 0;
  while (SIZE(nums)){
    // DISP_SET(nums);
    LL target = x - *nums.rbegin();
    nums.erase(--nums.end());
    
    set<LL> S;
    S.insert(0);
    map<LL, LL> pre;
    pre[0] = -1;


    for(auto w: nums){
      set<LL> oldS(S);
      for(auto e: oldS){
        LL cur = e + w;
        if (S.find(cur) == S.end()){
          pre[cur] = e;
          S.insert(cur);
        }
      }
    }
    // DISP_SET(S);
    LL maxv = *(--S.upper_bound(target));
    // cout << "maxv = " << maxv << endl;
    while (pre[maxv] != -1){
      // cout << maxv << " " << pre[maxv] << endl;
      nums.erase(nums.find(maxv - pre[maxv]));
      maxv = pre[maxv];
    }
    ans++;

  }
  cout << ans << endl;
  return 0;
}
