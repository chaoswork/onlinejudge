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
const LL INF = std::numeric_limits<LL>::max();


int vis[2560];
int n;
vector<vector<LL> > dist;
vector<vector<PII> > adj;
VVI hit = MATRIX(2560, 2560, 0);;
int last_pre[2560];

PII bellman_ford(int start, int target){
  if (hit[start][target]) return MP(1, dist[start][target]);
  // memset(vis, 0, sizeof(vis));
  memset(last_pre, 0, sizeof(last_pre));
  vector<LL> cur_dist(n + 1, 0);
  // VI cur_hit(n + 1, 0);
  // cur_dist[start] = 0;
  // cur_hit[start] = 1;
  hit[start][start] = 1;
  dist[start][start] = 0;

  REP(k, n){
    FOR(i, 1, n){
      REP(jj, SIZE(adj[i])){
        int j = adj[i][jj].first;
        int w = adj[i][jj].second;
        if (hit[start][i]){
          if (!hit[start][j] || dist[start][i] + w < dist[start][j]){
            dist[start][j] = dist[start][i] + w;
            last_pre[j] = i;
            hit[start][j] = 1;
          }
        }
      }
    }
  }

  return MP(hit[start][target], dist[start][target]);
  
  // hit[start][target] = 1;
  // return dist[start][target];
}
  

PII dijkstra(int start, int target){
  if (hit[start][target]) return MP(1, dist[start][target]);
  memset(vis, 0, sizeof(vis));
  memset(last_pre, 0, sizeof(last_pre));
  vector<LL> cur_dist(n + 1, 0);
  VI cur_hit(n + 1, 0);
  priority_queue<pair<LL, int> > Q;
  // vis[start] = 1;
  cur_hit[start] = 1;
  Q.push(MP(0, start));
  while(SIZE(Q)){
    // DISP_PAIR(Q.top());
    LL cur = -Q.top().first;
    int cur_node = Q.top().second;
    Q.pop();
    if (vis[cur_node]) continue;

    
    vis[cur_node] = 1;
    dist[start][cur_node] = cur;
    hit[start][cur_node] = 1;
    // cout << cur_node << " " << cur << endl;

    if (cur_node == target) break;

    REP(i, SIZE(adj[cur_node])){
      // DISP_PAIR(adj[cur_node][i]);
      // DISP_VEC_N(vis, n + 1);
      int next_node = adj[cur_node][i].first;
      int w = adj[cur_node][i].second;
      if (vis[next_node]) continue;
      if (!cur_hit[next_node] || (cur + w < cur_dist[next_node])){
        cur_dist[next_node] = cur + w;
        cur_hit[next_node] = 1;
        Q.push(MP(-cur_dist[next_node], next_node));
        last_pre[next_node] = cur_node;
      }
    }
    // DISP_VEC(cur_dist);
  }

  return MP(hit[start][target], dist[start][target]);
  
  // hit[start][target] = 1;
  // return dist[start][target];
}

int main(){
  optimize;
  int m, a, b, c;
  cin >> n >> m;

  dist = vector<vector<LL> >(n + 1, vector<LL>(n + 1, MOD));
  adj = vector<vector<PII> >(n + 1, vector<PII>());
  // vector<vector<LL> > adj = vector<vector<LL> >(n + 1, vector<LL>(n + 1, -MOD));
  // FOR(i, 1, n){
  // dist[i][i] = 0;
  // }
  REP(i, m){
    cin >> a >> b >> c;
    adj[a].PB(MP(b, c));
  }
  // DISP_PAIR(dijkstra(2, 1));
  // DISP_PAIR(bellman_ford(2, 1));
  // return 0;
  int neg = 0;
  int neg_a = 0;
  // int neg_b = 0;
  FOR(i, 1, n){
    REP(j, SIZE(adj[i])){
      int node = adj[i][j].first;
      LL w = adj[i][j].second;
      // PII walk = dijkstra(node, i);
      PII walk = bellman_ford(node, i);
      LL u = walk.second;
      int is_hit = walk.first;
      if (is_hit && w + u < 0){
        neg = 1;
        neg_a = i;
        // neg_b = node; 
        break;
      }
    }
    if (neg) break;
  }
  /*
  FOR(i, 1, n){
    FOR(j, 1, n){
      if (j) cout << " ";
      cout << dist[i][j];
    }
    cout << endl;
  }
  */
  // DISP_VEC_N(last_pre, n + 1);
  VI ans;
  if (neg) {
    cout << "YES" << endl;
    int tmp = neg_a;
    while (1){
      ans.PB(neg_a);
      neg_a = last_pre[neg_a];
      if (neg_a == tmp) break;
      if (neg_a == 0) break;
    }
    ans.PB(tmp);
    reverse(ALL(ans));
    DISP_VEC(ans);

  } else {
    cout << "NO" << endl;    
  }
  
  /*
  FOR(k, 1, n){
    FOR(i, 1, n) {
      FOR(j, 1, n){
        if (hit[i][k] && hit[k][j]){
          LL cur = dist[i][k] + dist[k][j];
          if (!hit[i][j] || dist[i][j] > cur){
            dist[i][j] = cur;
            hit[i][j] = 1;
            prex[i][j] = k;
          }
        }
      }
    }
  }
  int neg = 0;
  FOR(i, 1, n){
    FOR(j, 1, n){
      // if (j) cout << " ";
      // cout << dist[i][j];
      if (dist[i][j] < 0) neg = 1;

    }
    //cout << endl;
  }
  // DISP_MAT(prex, n + 1, n + 1);
  if (neg) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;    
  }
  */
  return 0;
}
