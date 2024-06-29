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

void display(int x, int n){
  std::bitset<16> binary(x);
  string s = binary.to_string();
  cout << s.substr(s.size() - n) << endl;
}

VI vis(1<<16, 0);
VI cnt(1<<16, 0);
int ans[1<<16];
bool found = false;

void dfs(int cur, int idx, int n){
  if (found) return;
  if (idx == (1 << n)){
    found = true;
    return;
  }
  // cout << "debug " << cur << " " << idx << endl;
  bitset<16> x(cur);  
  vis[cur] = 1;
  REP(i, n){
    x.flip(i);
    cnt[x.to_ulong()]--;
    x.flip(i);    
  }

  
  
  ans[idx] = cur;

  int best = -1;
  int maxn = -1;
  REP(i, n){
    x.flip(i);
    int y = x.to_ulong();
    if (!vis[y]){
      /*      int count = __builtin_popcount(y ^ cur);
      if (count <= 1){
        dfs(y, idx + 1, n);
      }
      */
      //      cout << cur << " " << y << " " << cnt[y] << endl;
      if (maxn < 0 || maxn > cnt[y]){
      //      if (maxn < cnt[y]){
        best = y;
        maxn = cnt[y];
      }
    }
    x.flip(i);
  }
  if (best >= 0){
    dfs(best, idx + 1, n);
  }
  vis[cur] = 0;
  REP(i, n){
    x.flip(i);
    cnt[x.to_ulong()]++;
    x.flip(i);    
  }
  
  
}

int main(){
  int n;
  cin >> n;
  REP(x, 1 << n){
    bitset<16> xb(x);
    REP(i, n){
      xb.flip(i);
      cnt[xb.to_ulong()]++;
      xb.flip(i);
    }
  }
  /*
  REP(i, 1 << n){
    cout << i << " " << cnt[i] << endl;
  }
  */
  dfs(0, 0, n);
  REP(i, 1 << n){
    display(ans[i], n);
  }
  /*
  display(0, n);
  int last = 0;
  int lim = 1 << n;
  VI vis(lim, 0);
  vis[0] = 1;
  int i = 1;
  while (i < lim){
    if (vis[i]) {
      ++i;
      continue;
    }
    int valid = -1;
    FOR(j, i, lim - 1){
      if (vis[j]) continue;
      int count = __builtin_popcount(j ^ last);
      if (count <= 1){
        valid = j;
        vis[j] = 1;
        display(j, n);
        last = j;
        break;
      }
    }
    if (valid == i){
      i++;
    }

    }*/
  return 0;
}
