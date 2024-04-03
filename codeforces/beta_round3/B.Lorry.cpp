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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;


typedef struct good {
  good(int v, int i): value(v), index(i){}
  int value;
  int index;
} good;

bool cmp(good a, good b){
  return a.value  > b.value;
}


int main(){
  const int MAXN = 10002;
  int N, V, t, v;
  cin >> N >> V;
  vector<good> ones;
  vector<good> twos;
  
  REP(i, N) {
    cin >> t >> v;
    if (t == 1){
      ones.PB(good(v, i + 1));
    } else {
      twos.PB(good(v, i + 1));
    }
  }

  sort(ALL(ones), cmp);
  sort(ALL(twos), cmp);

  int p1[3] = {0, 0, 0};
  int p2[3] = {0, 0, 0};
  int best[3] = {0, 0, 0};
  // VI idx[3] = {VI(), VI(), VI()};
  VI idx;
  VI from;
  int max_v = 0;
  int best_V = 0;

  int chance = 0;
  
  FOR(v, 1, V) {
    // cout << "debug v =" << v << endl;
    int v1 = 0, v2 = 0;
    int v1m = (v - 1) % 3;
    int v2m = (v - 2 + 3) % 3;
    int pp1 = p1[v1m];
    int pp2 = p2[v2m];
    // cout << "debug pp1 =" << pp1 << endl;
    // cout << "debug pp2 =" << pp2 << endl;

    if (pp1 < SIZE(ones)) {
      v1 = best[v1m] + ones[pp1].value;
    }

    if (v >= 2){
      if (pp2 < SIZE(twos)){
        v2 = best[v2m] + twos[pp2].value;
      }
    }

    if (v1 == 0 && v2 == 0) {
      chance ++;
      if (chance == 2)  break;
    }
    else chance = 0;

    if (v2 > v1){
      p2[v % 3] = p2[v2m] + 1;
      p1[v % 3] = p1[v2m];
      best[v % 3] = v2;
      // pp2 is valid
      idx.PB(twos[pp2].index);
      from.PB(-2);
    } else {
      p2[v % 3] = p2[v1m];
      p1[v % 3] = p1[v1m] + 1;
      best[v % 3] = v1;
      // pp1 may not valid
      if (pp1 < SIZE(ones)){
        idx.PB(ones[pp1].index);
        from.PB(-1);
      }
    }
    // cout << "debug " << v << ":" << best[v % 3] << endl;
    if (best_V < best[v % 3]){
      max_v = v;
      best_V = best[v % 3];
    }
    // cout << "debug " << best_V << " " << max_v << endl;    
  }

  cout << best_V << endl;

  if (best_V) {
    int n = 0;
    while (max_v > 0) {
      if (n) cout << " ";
      cout << idx[max_v - 1];
      max_v += from[max_v - 1];
      n++;
    }

  }
  cout << endl;

  

  

  /* 两个两个的尝试也fail
  while (V && (p1 < SIZE(ones) || p2 < SIZE(twos))){
    if (V >= 2){
      int v2 = -1;
      int v1 = -1;
      int n1 = 1;

      if (p2 < SIZE(twos)) v2 = twos[p2].value;
      if (p1 < SIZE(ones)) {
        v1 = ones[p1].value;
        if (p1 + 1 < SIZE(ones)) {n1++; v1 += ones[p1 + 1].value;}
      }

      if (v2 >= v1){
        V -= 2;
        best += v2;
        idx.PB(twos[p2++].index);
      } else{
        best += v1;
        REP(j, n1){
          V -= 1;
          idx.PB(ones[p1++].index);
        }
      }
      // V -= 2;
    }
    else{ // only one
      if (p1 < SIZE(ones)){
        best += ones[p1].value;
        V--;
        idx.PB(ones[p1].index);
        p1++;
      }
      break;
    }
  }
  cout << best << endl;
  string ans = "";
  REP(i, SIZE(idx)){
    if (i) ans += " ";
    ans += to_string(idx[i]);
  }
  cout << ans << endl;
  */

  /*
  // _ _ 选最大的
  // _ 2 放不进去。
  // ##_
  int p = 0;
  int best = 0;
  vector<int> idx;
  int last_one = -1;
  int missed_two = -1;
  while (V && p < N) {
    //    cout << goods[p].index << "" << goods[p].value << endl;
    if (V >= goods[p].type){
      best += goods[p].value;
      V -= goods[p].type;
      idx.PB(p);
      if (goods[p].type == 1) last_one = p;
    } else if (missed_two == -1){
      missed_two = p;
    }
    p++;      

  }
  if (V and last_one != -1){
    
  }
    
  cout << best << endl;
        if (ans.size()){
        ans += " ";
      }

      ans += to_string(goods[p].index + 1);

  cout << ans << endl;
  */
  return 0;
  
  
}
