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
const LL INF = 1LL << 62;// std::numeric_limits<LL>::max();



int n;
int main(){
  optimize;
  int m, a, b, c;
  cin >> n >> m;

  vector<vector<PII> > adj = vector<vector<PII> >(n + 1, vector<PII>());

  REP(i, m){
    cin >> a >> b >> c;
    adj[a].PB(MP(b, c));
  }
  // bellman ford
  vector<LL> dist(n + 1, INF);
  VI par(n + 1, 0);
  dist[1] = 0;
  int flag = 0;
  REPN(n){
    flag = 0;
    FOR(i, 1, n){
      REP(jj, SIZE(adj[i])){
        int j = adj[i][jj].first;
        LL w = adj[i][jj].second;
        if (dist[j] > dist[i] + w){
          dist[j] = dist[i] + w;
          par[j] = i;
          flag = j;
        }
        
      }
    }
  }
  if (flag) {
    REPN(n + 1) flag = par[flag]; // make sure in the cycle    
    int cur = flag;

    VI ans;
    cout << "YES" << endl;
    // cout << flag << endl;
    // DISP_VEC(par);
    while (1){
      ans.PB(cur);
      cur = par[cur];
      if (cur == flag) {
        ans.PB(cur);
        break;
      }
    }

    reverse(ALL(ans));
    DISP_VEC(ans);
  } else cout << "NO" << endl;

  
  return 0;
}
