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
#include <unordered_map>

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
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n, x;
  VI nums;
  unordered_map<int, int> cache;
  cache.reserve(8192);
  cache.max_load_factor(0.25);
  cin >> n;
  REP(i, n){
    cin >> x;
    nums.PB(x);
    cache[x] = -1;
  }
  if (SIZE(cache) == n) {
    cout << n << endl;
    return 0;
  }
  //cout << SIZE(nums) << endl;
  

  int ans = 0;
  int cur = 0;
  int pos = 0;
  REP(i, n){
    //    if (cache.find(nums[i]) != cache.end() && cache[nums[i]] >= 0){
    if (cache.find(nums[i]) != cache.end() && cache[nums[i]] >= pos){

      ans = max(ans, cur);
      int s = pos;
      int e = cache[nums[i]];
      cur -= cache[nums[i]] - pos + 1;
      pos = cache[nums[i]] + 1;
      /*
      FOR(j, s, e){
        // cache.erase(nums[j]);
        cache[nums[j]] = -1;
      }
      */

      
    }
    cache[nums[i]] = i;
    cur += 1;
    // cout << i << " " << SIZE(cache) << " " << pos << " " << ans << endl;
  }
  ans = max(ans, cur);
  cout << ans << endl;
  return 0;
}
