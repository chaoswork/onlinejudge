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
#define DISP_VEC(vec)   REP(i, SIZE(vec)){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_SET(S)   {int i = 0;for(auto e: S){if (i++) cout << " ";cout << e;} cout << endl;}
#define DISP_VEC_N(vec, n)   REP(i, n){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_MAT(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

int main(){
  optimize;
  int n, m, a, b;
  cin >> n >> m;
  vector<set<int> > adj(n + 1, set<int>());
  vector<set<int> > jda(n + 1, set<int>());
  VI vis(n + 1, 0);
  VI ans;
  REP(i, m){
    cin >> a >> b;
    adj[a].insert(b);
    jda[b].insert(a);
  }
  priority_queue<PII> Q;
  FOR(i, 1, n){
    Q.push(MP(-SIZE(jda[i]), i));
  }
  while(SIZE(Q)){
    while(SIZE(Q) && vis[Q.top().second]){
      Q.pop();
    }
    // DISP_VEC(vis);
    if (SIZE(Q) == 0) break;
    int nid = Q.top().second;
    int degree = -Q.top().first;
    // cout << nid << " " << degree << endl;
    // FOR(k, 1, n){cout << k << ": "; DISP_SET(jda[k]);}
    if (degree != 0) break;
    Q.pop();
    vis[nid] = 1;
    ans.PB(nid);
    for(auto j: adj[nid]){
      if (vis[j]) continue;
      jda[j].erase(nid);
      Q.push(MP(-SIZE(jda[j]), j));      
    }

  }

  if (SIZE(Q)) cout << "IMPOSSIBLE" << endl;
  else {
    DISP_VEC(ans);
  }
  return 0;
}
