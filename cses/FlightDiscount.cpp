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
#define DISP_VEC_N(vec, n)   REP(i, n){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_MAT(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

vector<vector<PII> > adj;

int main(){
  optimize;
  int n, m, a, b, c;
  cin >> n >> m;
  adj = vector<vector<PII> >(n + 1, vector<PII>());
  REP(i, m){
    cin >> a >> b >> c;
    adj[a].PB(MP(b, c));
  }
  priority_queue<pair<LL, int> > Q;
  VI vis(n + 1, 0);
  vector<LL> dist(n + 1, -1);
  vector<LL> dist2(n + 1, -1);  
  Q.push(MP(0, 1));
  dist[1] = 0;
  dist2[1] = 0;
  while(SIZE(Q)){
    while (vis[Q.top().second]) Q.pop();
    // int v = -Q.top().first;
    int nid = Q.top().second;
    // cout << nid << " " << v << endl;
    if (nid == n) break;
    Q.pop();
    vis[nid] = 1;
    REP(i, SIZE(adj[nid])){
      int next_id = adj[nid][i].first;
      LL w = adj[nid][i].second;
      if (vis[next_id]) continue;
      if (dist[next_id] < 0 || dist[next_id] > dist[nid] + w){
        dist[next_id] = dist[nid] + w;
        Q.push(MP(-dist[next_id], next_id));
      }
    }
  }
  // DISP_VEC(dist);
  Q = priority_queue<pair<LL, int> >();
  Q.push(MP(0, 1));
  dist2[1] = 0;
  vis = VI(n + 1, 0);
    
  while(SIZE(Q)){
    while (vis[Q.top().second]) Q.pop();
    // int v = -Q.top().first;
    int nid = Q.top().second;
    // cout << nid << " " << v << endl;
    if (nid == n) break;
    Q.pop();
    vis[nid] = 1;  
    REP(i, SIZE(adj[nid])){
      int next_id = adj[nid][i].first;
      LL w = adj[nid][i].second;
      if (vis[next_id]) continue;        
      if (dist2[next_id] < 0 || dist2[next_id] > dist[nid] + w/2){
        dist2[next_id] = dist[nid] + w/2;
        Q.push(MP(-dist2[next_id], next_id));
      }
      if (dist2[next_id] < 0 || dist2[next_id] > dist2[nid] + w){
        dist2[next_id] = dist2[nid] + w;
        Q.push(MP(-dist2[next_id], next_id));
      }
         
    }
    
  }

  // DISP_VEC(dist2);
  cout << dist2[n] << endl;
  return 0;
}
