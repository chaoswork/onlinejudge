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
#define DISP_SET(S)   {int iforset = 0;for(auto e: S){if (iforset++) cout << " ";cout << e;} cout << endl;}
#define DISP_VEC(vec)   REP(i, SIZE(vec)){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_VEC_N(vec, n)   REP(i, n){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_MAT(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MOD = 1000000007;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;


VVI jda;
VI pre;
VI cnt;

int get_route(int cur){
  if (cnt[cur] != -1) return cnt[cur];
  int best = 0;
  int best_id = 0;
  REP(i, SIZE(jda[cur])){
    // best = max(best, get_route(jda[cur][i]));
    int tmp = get_route(jda[cur][i]);
    if (tmp && best < tmp) {
      best = tmp;
      best_id = jda[cur][i];
    }
  }
  if (best) {
    best++;
    pre[cur] = best_id;
  }
  return cnt[cur] = best;
}


int main(){
  optimize;
  int n, m, a, b;
  cin >> n >> m;
  jda = VVI(n + 1, VI());
  pre = VI(n + 1, 0);
  cnt = VI(n + 1, -1);
  cnt[1] = 1;
  REP(i, m){
    cin >> a >> b;
    jda[b].PB(a);
  }

  int res = get_route(n);
  // DISP_VEC(pre);
  if (res) {
    cout << res << endl;
    int cur = n;
    VI path;
    while(cur){
      path.PB(cur);
      cur = pre[cur];
    }
    reverse(ALL(path));
    DISP_VEC(path);
  }
  else cout << "IMPOSSIBLE\n";

  // DISP_VEC(cnt);
  return 0;
}
