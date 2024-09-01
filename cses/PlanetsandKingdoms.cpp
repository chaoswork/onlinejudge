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


struct SCC{

  int t;
  VVI adj;
  VI comp_id;
  VI comp_seq;
  VI ts;
  VI st;
  int N;
  int n_comp;

  void init(int n){
    adj = VVI(n + 1, VI());
    comp_id = VI(n + 1, 0);
    ts = VI(n + 1, 0);
    st = VI();
    t = 0;
    N = n;
    n_comp = 0;
  }
  int dfs(int cur){
    int low = ts[cur] = ++t;
    st.PB(cur);
    for(int j: adj[cur]){
      if (!comp_id[j]) {
        low = min(low, ts[j] ?: dfs(j));
      }
    }
    if (low == ts[cur]){
      comp_seq.PB(cur);
      ++n_comp;
      int p = -1;
      while (p != cur){
        p = st.back();
        // comp_id[p] = cur;
        comp_id[p] = n_comp;        
        st.pop_back();
      }
      
    }
    return low;
  }
  void gen(){
    FOR(i, 1, N){
      if (!ts[i]) dfs(i);
    }
    reverse(ALL(comp_seq));
  }
  

  void add_edge(int a, int b) {adj[a].PB(b);}
};


void dfs(int cur, const VVI &adj, VI &vis){
  if (vis[cur]) return;
  vis[cur] = 1;
  REP(i, SIZE(adj[cur])) dfs(adj[cur][i], adj, vis);
}

int main(){
  optimize;
  int n, m, a, b;
  SCC graph;
  cin >> n >> m;
  graph.init(n);
  REP(i, m){
    cin >> a >> b;
    graph.add_edge(a, b);
  }
  graph.gen();

  // DISP_VEC(graph.ts);
  // DISP_VEC(graph.comp_seq);
  cout << graph.n_comp << endl;
  // DISP_VEC(graph.comp_id);
  FOR(i, 1, n){
    if (i > 1) cout << " ";
    cout << graph.comp_id[i];
  }
  cout << endl;
  // DISP_VEC(graph.st);

  return 0;
}
