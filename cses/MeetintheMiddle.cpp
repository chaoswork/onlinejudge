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
  LL n, x, t;
  cin >> n >> x;  
  vector<int> nums;

  REP(i, n){
    cin >> t;
    nums.PB(t);
  }
  if (n == 1){
    cout << int(nums[0] == x) << endl;
  } else {
    int left = n / 2;
    int right = n - left;
    unordered_map<LL, LL> left_cnt;
    // LL *left_cnt = new LL[x + 1];
    unordered_map<LL, LL> right_cnt;
    // LL *right_cnt = new LL[x + 1];
    // fill_n(left_cnt, x + 1, 0);
    // fill_n(right_cnt, x + 1, 0);
      
    REP(i, 1 << left){
      LL total = 0;
      REP(j, left){
        int shift_j = (1 << j);
        if (shift_j > i) break;
        if (shift_j & i) total += nums[j];
      }
      if (total > x) continue;      
      if (left_cnt.find(total) == left_cnt.end()) left_cnt[total] = 0;
      left_cnt[total] += 1;
    }

    REP(i, 1 << right){
      LL total = 0;
      REP(j, right){
        int shift_j = (1 << j);
        if (shift_j > i) break;
        if (shift_j & i) total += nums[left + j];
      }
      if (total > x) continue;
      
      if (right_cnt.find(total) == right_cnt.end()) right_cnt[total] = 0;
      right_cnt[total] += 1;
    }

    LL ans = 0;    
    for (const auto& pair : left_cnt){
      LL a = pair.first;
      if (a > x) continue;
      LL b = x - a;
      if (right_cnt.find(b) != right_cnt.end()){
        ans += pair.second * right_cnt[b];
      }
    }
    /*
    FOR(a, 0, x){
      if (left_cnt[a] == 0) continue;
      LL b = x - a;
      ans += left_cnt[a] * right_cnt[b];

    }*/
    cout << ans << endl;
    
    
  }
  return 0;
}
