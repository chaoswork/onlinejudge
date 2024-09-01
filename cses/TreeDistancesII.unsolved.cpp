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
#define DISPLAY_MATRIX(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;





LL dfs(int i, int j, const VVI& adj, vector<vector<LL>> &ans, vector<LL> &ans2){
  //  cout << i << "," << j << "| " << ans[i][j] << " " << SIZE(adj[j]) << endl;
  int c = adj[i][j];
  if (ans[i][j]) return ans[i][j];

  if (SIZE(adj[c]) == 1) {
    return ans[i][j] = 1;
  }
  cout << "debug " << i << "," << j << endl;
  //  if (ans2[c] != -1){
  if (false){
    int ik = -1;
    REP(k, SIZE(adj[c])) if (adj[c][k] == i) {ik = k; break;}
    return ans2[c] - dfs(c, ik, adj, ans, ans2);
  } else {
    int ik = -1;
    LL total = 0;
    LL total_c = 0;
    REP(k, SIZE(adj[c])){
      if (adj[c][k] == i) {
        ik = k;
        continue;
      }
      LL d = dfs(c, k, adj, ans, ans2);
      total += d + 1;
      total_c += d;
      cout << "debug, " <<i << "," <<  c << " " << d << " " << total << endl;
    }
    ans[i][j] = total + 1;
    cout << "debug, " <<i << "," <<  j << " " << ans[i][j] << endl;

    // set ans2
    if (ans[c][ik]){
        int d = dfs(c, ik, adj, ans, ans2);
        ans2[c] = total_c + d;
    }
      
  }
  return ans[i][j];
}

int main(){
  int n, a, b;
  cin >> n;
  VVI adj(n + 1, VI());
  vector<vector<LL>> ans(n + 1, vector<LL>());
  vector<LL> ans2(n + 1, -1);
  

  REP(i, n - 1){
    cin >> a >> b;
    adj[a].PB(b);
    ans[a].PB(0);
    adj[b].PB(a);
    ans[b].PB(0);
  }

  
  FOR(i, 1, n){
    if (i > 1) cout << " ";
    
    // if (ans2[i] != -1){
    if (false){
      cout << ans2[i];
    } else {
      LL total = 0;
      REP(j, SIZE(adj[i])){
        if (SIZE(adj[adj[i][j]]) == 1) {total += 1;}
        else
          total += dfs(i, j, adj, ans, ans2) + 1;
        cout << "ddbug " << i << "," << j << " " << total << endl;
      }
      ans2[i] = total;
      cout << "ddbug " << i << "=" << ans2[i] << endl;
      cout << ans2[i];

    }
    
  }
  cout << endl;

  return 0;
}
