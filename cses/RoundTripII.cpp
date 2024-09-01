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

#define MIN_HEAP(type1, type2) priority_queue<pair<type1, type2>, vector<pair<type1, type2> >, greater<pair<type1, type2> > >
#define MAX_HEAP(type) priority_queue<type>
#define ADJ(type1, type2) vector<pair<type1, type2> > 

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
#define DISP_VEC(vec)   {REP(_i, SIZE(vec)){if (_i) cout << " ";cout << vec[_i];} cout << endl;}
#define DISP_VEC_PLUS(vec, x)   {REP(_i, SIZE(vec)){if (_i) cout << " ";cout << vec[_i] + x;} cout << endl;}
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
const int MAXN = 2e5 + 64;


struct Graph{
  int N;
  vector<vector<int> > adj;
  vector<int> vis;
  vector<int> st;
  vector<int> topo;
  vector<int> circle;
  void init(int n){
    N = n;
    adj = vector<vector<int> >(n, vector<int>());
    vis = vector<int>(n, 0);
    
  }

  void add_edge(int a, int b){
    adj[a].push_back(b);
  }

  bool dfs(int x){
    if (vis[x] == 1){
      int i = st.size() - 1;
      circle.push_back(x);
      while (1){
        circle.push_back(st[i]);
        if (st[i] == x) break;
        --i;
        
      }
      reverse(circle.begin(), circle.end());
      
      return false;
    }
    vis[x] = 1;
    st.push_back(x);
    
    for(int y: adj[x]){
      if (vis[y] == 2) continue;
      if (!dfs(y)) return false;
    }
    st.pop_back();
    vis[x] = 2;
    topo.push_back(x);
    return true;
  }

  bool toposort(){
    for(int i = 0; i < N; ++i){
      if (vis[i] == 2) continue;
      if (!dfs(i)) return false;
    }
    reverse(topo.begin(), topo.end());
    return true;
  }

};

int main(){
  optimize;
  int n, m, a, b;
  cin >> n >> m;
  Graph graph;
  graph.init(n);
  
  REP(i, m){
    cin >> a >> b;
    graph.add_edge(a - 1, b - 1);
  }

  if (graph.toposort()){
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << SIZE(graph.circle) << endl;
    DISP_VEC_PLUS(graph.circle, 1);
  }

  return 0;
}
