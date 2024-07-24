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

int find_kth(multiset<int> S, int k){
  int L = *S.begin() - 1;
  int R = *S.rbegin() + 1;
  if (L == R){
    return L;
  } else if (L + 1 == R){
    if (distance(S.begin(), S.lower_bound(R)) <= k) return R;
    else return L;
  }
  int ans = -1;
  while (L + 1 < R){
    int mid = L + (R - L) / 2;
    // cout << L << " " << R << " mid=" << mid << endl;
    auto it = S.lower_bound(mid);
    auto it2 = S.upper_bound(mid);
    int k1 = distance(S.begin(), it);
    int k2 = distance(S.begin(), it2);
    // cout <<k << " " << *it << " " << distance(S.begin(), it) << endl;
    if (k1 <= k && k2 > k){
      return *it;
    } else if (k1 > k) {
      R = mid;
    } else { // k2 <= k
      L = mid;
    }
  }
  return ans;
}

int main(){
  int n, k, x;
  cin >> n >> k;
  // multiset<int> ss;
  // ss.insert(1); ss.insert(1); ss.insert(2);
  // cout << find_kth(ss, 1) << endl;
  multiset<int> S;
  VI nums;
  REP(i, n){
    cin >> x;
    nums.PB(x);
    if (SIZE(S) < k) S.insert(x);
    else {
      if (x != nums[i - k]){
        S.insert(x);
        auto it = S.find(nums[i - k]);
        S.erase(it);
      }
    }
    
    if (SIZE(S) == k){
      if (i > k - 1) cout << " ";
      cout << find_kth(S, (k - 1) / 2);
    }

    // cout << *S.begin() << " " << *S.rbegin() << endl;
  }
  return 0;
}
