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



void dfs(int cur, const VVI &adj, VI &vis){
  if (vis[cur]) return;
  vis[cur] = 1;
  REP(i, SIZE(adj[cur])) dfs(adj[cur][i], adj, vis);
}

int main(){
  optimize;
  int n, m, a, b;
  VI vis1;
  VI vis2;
  cin >> n >> m;
  VVI adj(n + 1, VI());
  VVI jda(n + 1, VI());
  VI idx(n + 1, 0);
  REP(i, m){
    cin >> a >> b;
    adj[a].PB(b);
    jda[b].PB(a);
  }
  int start = 1;
  FOR(i, 1, n){
    if (idx[i]) continue;
    vis1 = VI(n + 1, 0);
    vis2 = VI(n + 1, 0);
    dfs(i, adj, vis1);
    dfs(i, jda, vis2);
    // DISP_VEC(vis1);
    // DISP_VEC(vis2);
    // maybe TLE if  1 -> 2 -> 3 -> 4 ... -> n
    FOR(j, 1, n){
      if (vis1[j] && vis2[j]){
        idx[j] = start;
      }
    }
    start++;
  }
  cout << start - 1 << endl;
  FOR(i, 1, n){
    if (i > 1) cout << " ";
    cout << idx[i];
  }
  cout << endl;
  return 0;
}
