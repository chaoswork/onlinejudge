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

vector<vector<PII> > adj;

int main(){
  optimize;
  LL n, m, a, b, c;
  cin >> n >> m;
  adj = vector<vector<PII> >(n + 1, vector<PII>());
  REP(i, m){
    cin >> a >> b >> c;
    adj[a].PB(MP(b, c));
  }
  vector<LL> dist(n + 1, INF);
  vector<LL> cnt(n + 1, 0);
  vector<LL> maxlen(n + 1, 0);
  vector<LL> minlen(n + 1, 0);  
  vector<int> vis(n + 1, 0);
  dist[1] = 0;
  cnt[1] = 1;
  minlen[1] = 1;
  maxlen[1] = 1;
  priority_queue<pair<LL, int> > Q;
  Q.push(MP(0, 1));
  while (SIZE(Q)){
    int cur = Q.top().second;
    LL cur_dist = -Q.top().first;
    Q.pop();
    if (vis[cur]) continue;
    vis[cur] = 1;
    REP(i, SIZE(adj[cur])){
      int j = adj[cur][i].first;
      LL w = adj[cur][i].second;
      if (cur_dist + w < dist[j]){
        dist[j] = cur_dist + w;
        cnt[j] = cnt[cur];
        minlen[j] = minlen[cur] + 1;
        maxlen[j] = maxlen[cur] + 1;
        Q.push(MP(-dist[j], j));
      } else if (cur_dist + w == dist[j]){
        cnt[j] += cnt[cur];
        cnt[j] %= MOD;
        minlen[j] = min(minlen[j], minlen[cur] + 1);
        maxlen[j] = max(maxlen[j], maxlen[cur] + 1);
      }
    }
  }
  cout << dist[n] << " " << cnt[n] << " " << minlen[n] - 1 << " " << maxlen[n] - 1 << endl;
  return 0;
}