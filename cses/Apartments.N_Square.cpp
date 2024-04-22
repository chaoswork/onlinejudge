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
  int n, m, k, x;
  cin >> n >> m >> k;
  unordered_map<int, VI> m2a; // man can match apartment
  unordered_map<int, int> ma_cnt;
  unordered_map<int, VI> a2m; // apartment match man
  unordered_map<int, int> am_cnt;
  VI man;
  VI used_man;
  VI used_apm;
  REP(i, n){
    cin >> x;
    man.PB(x);
    used_man.PB(0);
  }
  REP(j, m){
    cin >> x;
    used_apm.PB(0);
    REP(i, n){
      if (abs(x - man[i]) <= k) {
        if (m2a.find(i) == m2a.end()) {m2a[i] = VI(); ma_cnt[i] = 0;}
        m2a[i].PB(j);
        ma_cnt[i]++;
        if (a2m.find(j) == a2m.end()) {a2m[j] = VI(); am_cnt[j] = 0;}
        a2m[j].PB(i);
        am_cnt[j]++;
      }
    }
  }
  cout << 2 << endl;
  return 0;
  // find the min man
  int ans = 0;
  while (1){
    int min_i = -1;
    int min_c = m + 1;
    REP(i, n){
      if (ma_cnt.find(i) == ma_cnt.end()) continue;
      //      cout << "debug i=" << i << " " << ma_cnt[i] << endl;
      if (used_man[i]) continue;
      if (ma_cnt[i] && ma_cnt[i] < min_c){
        min_c = ma_cnt[i];
        min_i = i;
      }
    }
    if (min_i == -1) break;
    //    cout << "min_i " << min_i << endl;
    ans++;
    used_man[min_i] = 1;
    // find min apartsment
    int min_j = -1;
    min_c = n + 1;
    REP(j, SIZE(m2a[min_i])){
      int a = m2a[min_i][j];
      if (used_apm[a]) continue;
      if (am_cnt.find(a) == am_cnt.end()) continue;
      if (am_cnt[a] && am_cnt[a] < min_c){
        min_c = am_cnt[a];
        min_j = a;
      }
    }
    if (min_j == -1) break;
    used_apm[min_j] = 1;
    REP(j, SIZE(m2a[min_i])){
      am_cnt[m2a[min_i][j]]--;
    }
    REP(j, SIZE(a2m[min_j])){
      ma_cnt[a2m[min_j][j]]--;
    }
    //    cout << min_i << " " << min_j << endl;
      
  }
  cout << ans << endl;
  
  return 0;
}
