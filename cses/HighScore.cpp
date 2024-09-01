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
#define PB push_back
#define SIZE(X) ((int)(X.size()))
#define REP(i, n) for(int i=0; i<(n); ++i)
#define REPN(n) for(int _=0; _<(n); ++_)
#define FOR(i, l, h) for(int i=(l); i<=(h); ++i)
#define FORD(i, h, l) for(int i=(h); i>=(l);--i)
#define ALL(A) A.begin(),A.end()
#define MATRIX(n, m, v) vector<vector<int> >((n), vector<int>((m), (v)))
#define DISP_SET(S)   {int iforset = 0;for(auto e: S){if (iforset++) cout << " ";cout << e;} cout << endl;}
#define DISP_PAIR(P)   {cout << P.first << " " << P.second << endl;}
#define DISP_VEC(vec)   REP(i, SIZE(vec)){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_VEC_N(vec, n)   REP(i, n){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_MAT(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1000000007;
const LL INF = 1LL<<62;  //std::numeric_limits<LL>::max();

VI vis1;
VI vis2;
vector<vector<PII> > adj;

void dfs(int cur, VI& vis){
  if (vis[cur]) return ;
  vis[cur] = 1;
  REP(i, SIZE(adj[cur])){
    dfs(adj[cur][i].first, vis);
  }
  
}
int main(){
  optimize;
  int n, m, a, b, c;
  cin >> n >> m;
  vector<LL> dist(n + 1, -INF);
  vis1 = VI(n + 1, 0);
  vis2 = VI(n + 1, 0);
  adj = vector<vector<PII> >(n + 1, vector<PII>());
  dist[1] = 0;
  REPN(m){
    cin >> a >> b >> c;
    adj[a].PB(MP(b, c));
  }
  
  VI flags;
  REPN(n){
    flags.clear();
    FOR(i, 1, n){
      REP(jj, SIZE(adj[i])){
        int j = adj[i][jj].first;
        LL w = adj[i][jj].second;
        if (dist[j] < dist[i] + w){
          dist[j] = dist[i] + w;
          flags.PB(j);
        }
      }
    }
  }
  // DISP_VEC(flags);
  // if there are so many circles?
  
  // check if flag can goto n
  /*
  if (flag) {
    dfs(flag, vis1);
    dfs(1, vis2);
  }
  */
  if (SIZE(flags)){
    dfs(1, vis2);
    VI new_flags;
    REP(i, SIZE(flags)){
      if (vis2[flags[i]]) {
        new_flags.PB(flags[i]);
      }
    }

    REP(i, SIZE(new_flags)){
      dfs(new_flags[i], vis1);
    }
    // DISP_VEC(flags);
    // DISP_VEC(new_flags);
  }
  
  // DISP_VEC(dist);

  if (vis1[n]) cout << -1 << endl;
  else cout << dist[n] << endl;
  
  return 0;
}
