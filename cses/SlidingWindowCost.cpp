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
  multiset<int> S1;
  multiset<int> S2;  
  VI nums;
  LL S1_sum = 0;
  LL S2_sum = 0;  
  REP(i, n){
    cin >> x;
    nums.PB(x);
    // SIZE(S1) == SIZE(S2) or SIZE(S2) + 1
    // 4 4 -> 3 4
    //.    -> 4 3
    // 4 3 -> 3 3
    //     -> 4 2
    if (SIZE(S1) + SIZE(S2) >= k){
      auto it = S1.find(nums[i - k]);
      if (it != S1.end()){
        S1.erase(it);
        S1_sum -= nums[i - k];
      }
      else {
        it = S2.find(nums[i - k]);
        S2.erase(it);
        S2_sum -= nums[i - k];
      }

    }
    //balance
    if (SIZE(S1) + 1 == SIZE(S2)){
      S1.insert(*S2.begin());
      S1_sum += *S2.begin();
      S2_sum -= *S2.begin();
      S2.erase(S2.begin());

    } else if (SIZE(S1) == SIZE(S2) + 2){
      S2_sum += *S1.rbegin();
      S1_sum -= *S1.rbegin();
      S2.insert(*S1.rbegin());
      S1.erase(prev(S1.end()));
    }
    // insert new
    // 4 4 -> 5 4
    //     -> 4 5
    // 4 3 -> 5 3
    //     -> 4 4
    if (SIZE(S1) == 0){
      S1.insert(x);
      S1_sum += x;
    }
    else if (x <= *S1.rbegin()){
      S1.insert(x);
      S1_sum += x;
    } else {
      S2.insert(x);
      S2_sum += x;
    }

    //balance
    if (SIZE(S1) + 1 == SIZE(S2)){
      S1_sum += *S2.begin();
      S2_sum -= *S2.begin();
      S1.insert(*S2.begin());
      S2.erase(S2.begin());
    } else if (SIZE(S1) == SIZE(S2) + 2){
      S2_sum += *S1.rbegin();
      S1_sum -= *S1.rbegin();
      S2.insert(*S1.rbegin());
      S1.erase(prev(S1.end()));
    }
    if (SIZE(S1) + SIZE(S2) == k){
      if (i > k - 1) cout << " ";
      // cout << *S1.rbegin();
      LL median = *S1.rbegin();
      if ((k & 1) == 0) median = 0;
      cout << S2_sum - S1_sum + median;
    }
  }
  cout << endl;
  return 0;
}
