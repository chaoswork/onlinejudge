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
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;


LL count(int start, int next_pos, int max_pos){
  // LL res = 0;
  // int min_pos = pos_map.begin()->first;
  // int del_num = pos_map.begin()->second;
  // int max_pos = pos_map.rbegin()->first;
  // int next_pos = (++pos_map.begin())->first;
  // int next_pos = pos_map.begin()->first + 1;

  LL k = next_pos - start;
  LL n = max_pos - start + 1;
  return n * k - k * (k - 1) / 2;
  /*
  FOR(i, start, next_pos - 1){
    res += n;
    n--;
  }
  // start = 5 next_pos = 7, 

  //  cout << start << " " << next_pos << " " << max_pos << "|" << res <<  endl;  
  return res;
  */
}

int main(){
  optimize;
  int n, k, x;
  cin >> n >> k;
  if (n == 1){
    cout << n << endl;
    return 0;
  }
  VI nums;
  unordered_map<int, int> nums_cnt; // 数字存放的最后一个数字。
  nums_cnt.reserve(1024);
  nums_cnt.max_load_factor(0.25);

  int start = 0;
  REP(i, n){
    cin >> x;
    nums.PB(x);
  }
  LL res = 0;

  REP(i, n){
    if (nums_cnt.find(nums[i]) == nums_cnt.end()){
      if (SIZE(nums_cnt) == k) {
        // delete smallest pos
        // change p
        int next_pos = start;
        while (SIZE(nums_cnt) == k){
          nums_cnt[nums[next_pos]]--;
          if (nums_cnt[nums[next_pos]] == 0) nums_cnt.erase(nums[next_pos]);
          next_pos++;
        }

        res += count(start, next_pos, i - 1);
        // start = (++pos_map.begin())->first;
        start = next_pos;
        nums_cnt[nums[i]] = 1;
        
      } else {
        nums_cnt[nums[i]] = 1;

      }
      
    } else {

      nums_cnt[nums[i]]++;

    }
  }
  LL nn = n - 1 - start + 1;
  res += nn * (nn + 1) / 2;//count(start, pos_map);

  cout << res << endl;
  return 0;
}
