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
#include <unordered_map>

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


VI color;
unordered_map<int, int> color_id;
unordered_map<int, VI > adj;

void dfs(int x, int cnt){
  if (color[x]) return;
  color[x] = cnt;
  color_id[cnt] = x;
  REP(i, SIZE(adj[x])){
    dfs(adj[x][i], cnt);
  }
}


int main(){
  int n, m, a, b;

  cin >> n >> m;
  color.resize(n + 1);
  fill_n(color.begin(), n + 1, 0);
  REP(i, m){
    cin >> a >> b;
    if (adj.find(a) == adj.end()){adj[a] = VI();}
    adj[a].PB(b);
    if (adj.find(b) == adj.end()){adj[b] = VI();}
    adj[b].PB(a);
  }
  int cnt = 0;
  FOR(i, 1, n){
    if (color[i]) continue;
    ++cnt;
    dfs(i, cnt);
  }
  cout << cnt - 1 << endl;
  FOR(i, 1, cnt - 1){
    cout << color_id[i] << " " << color_id[i + 1] << endl;
  }
  
  return 0;
}
