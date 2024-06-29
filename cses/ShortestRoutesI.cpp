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
#include <unordered_map>
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
#define DISPLAY_MATRIX(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

int main(){
  int n, m, a, b, v;
  cin >> n >> m;
  vector<unordered_map<int, int> > adj(n + 1, unordered_map<int, int>());
  REP(i, m){
    cin >> a >> b >> v;
    if (adj[a].find(b) == adj[a].end()){
      adj[a][b] = v;
    } else {
      if (adj[a][b] > v) adj[a][b] = v;
    }
  }

  vector<bool> vis(n + 1, false);
  vector<LL> dist(n + 1, -1);
  int start = 1;
  dist[start] = 0;
  priority_queue<pair<LL, int> > Q;
  Q.push(MP(-dist[start], start));

  REP(k, n){
    // find min unvisited node
    while (vis[Q.top().second]) Q.pop();
    if (Q.empty()) break;

    int cur = Q.top().second;
    LL cur_dist = -Q.top().first;

    Q.pop();
    vis[cur] = true;

    for(auto e: adj[cur]){
      int i = e.first;
      int v = e.second;
      if (vis[i]) continue;

      if (dist[i] < 0 || dist[i] > cur_dist + v){
        
        dist[i] = cur_dist + v;
        Q.push(MP(-dist[i], i));
      }

    }
    
  }
  FOR(i, 1, n){
    if (i > 1) cout << " ";
    cout << dist[i];
  }
  cout << endl;
  
  return 0;
}
