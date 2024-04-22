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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

int main(){
  int n, t, x;
  VI nums;
  //   VI used;
  unordered_map<int, int> cnt;
  unordered_map<int, int> cnt2;  
  cin >> n >> t;
  
  REP(i, n){
    cin >> x;
    if (cnt.find(x) == cnt.end()) cnt[x] = 0;
    cnt[x]++;
  }
  int ans = 0;
  // find sum equal to t
  for(auto pair: cnt){
    int diff = t - pair.first;
    if (diff == pair.first) {
      ans += pair.second / 2;
      if (pair.second & 1){
        cnt2[pair.first] = 1;
        nums.PB(pair.first);
      }
    } else {
      if (cnt.find(diff) != cnt.end()){
        if (diff > pair.first) continue;

        int matched = min(pair.second, cnt[diff]);
        ans += matched;
        if (pair.second > cnt[diff]){
          cnt2[pair.first] = pair.second - matched;
          nums.PB(pair.first);
        } else if (pair.second < cnt[diff]){
          cnt2[diff] = cnt[diff] - matched;
          nums.PB(diff);
        }
      } else{
        nums.PB(pair.first);
        cnt2[pair.first] = pair.second;
      }
    }
  }

  // nums is only the key
  sort(ALL(nums));


  int p = SIZE(nums) - 1;
  int it_num = 0;
  while (p >= 0){
    if (cnt2[nums[p]] == 0) {p--; continue;}
    // find the first less or equal to diff
    int diff = t - nums[p];
    // find the first num less than diff

    int L = -1, R = p; //SIZE(nums);
    while (L + 1 != R) {
      int M = L + (R - L) / 2;
      if (nums[M] >= diff) {
        // if equal
        R = M;
      } else {
        L = M;
      }
    }
    // nums[L] < diff <= nums[R]

    if (L == -1){
      ans += cnt2[nums[p]];
      cnt[nums[p]] = 0;
      p--;
    } else {
      while (L >= 0 && cnt2[nums[L]] == 0){
        L--;
      }
      if (L == -1){
        ans += cnt2[nums[p]];
        cnt2[nums[p]] = 0;
        p--;
      } else {
        if (cnt[nums[p]] <= cnt[nums[L]]){
            ans += cnt2[nums[p]];
            cnt2[nums[L]] -= cnt2[nums[p]];
            cnt2[nums[p]] = 0;

            p--;
        } else {
          ans += cnt2[nums[L]];
          cnt2[nums[p]] -= cnt2[nums[L]];
          cnt2[nums[L]] = 0;
        }
      }

      
      
    }
    if (p >= 0 && it_num++ % 10000 == 0) {

      VI tmp;
      REP(k, p + 1){
        if (cnt2[nums[k]]) {
          tmp.PB(nums[k]);
          //          cout << nums[k] ;
        }
      }
      //      cout << endl;
      nums = tmp;
      p = SIZE(nums) - 1;
    }

    
    
  }

  /*
  // O(n^2) solution, can be O(n log n)?
  int p = SIZE(nums) - 1;


  
  while (p >= 0){
    if (used[p]) {p--; continue;}

    // find the first less or equal to diff
    int diff = t - nums[p];
    int ppl = -1, pl = 0;
    while(pl < p && nums[pl] <= diff){
      if (used[pl]) {pl++;continue;}
      ppl = pl++;
    }
    if (ppl != -1) {used[ppl] = 1;}
    used[p] = 1;
    ans++;
    p--;
  }
  */
  cout << ans << endl;
  return 0;
}
