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
#define DISPLAY_MATRIX(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << " ";} cout << endl;}

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

unordered_map<int, VI> tmp;
unordered_map<int, VI> tree;
vector<int> visited; //(n + 1, false);




int solve(VVI &dp, int root, int type){
  if (SIZE(tree[root]) == 0) {
    dp[root][type] = 0;
    return 0;
  }
  if (dp[root][type] != -1) return dp[root][type];
  int total_max = 0;
  REP(i, SIZE(tree[root])){
    total_max += max(solve(dp, tree[root][i], 0),
                     solve(dp, tree[root][i], 1));
  }
  
  if (type == 0){
    dp[root][type] = total_max;

  } else {
    REP(i, SIZE(tree[root])){
      dp[root][type] = max(dp[root][type],
                           total_max - max(solve(dp, tree[root][i], 0),
                                           solve(dp, tree[root][i], 1)) + solve(dp, tree[root][i], 0) + 1);
    }
    
  }
  


  
  return dp[root][type];
}

void build_tree(int root){
  if (visited[root]) return;
  visited[root] = 1;
  if (tree.find(root) == tree.end()) tree[root] = VI();
  REP(i, SIZE(tmp[root])){
    if (visited[tmp[root][i]]) continue;
    tree[root].PB(tmp[root][i]);
  }
  REP(i, SIZE(tmp[root])){
    build_tree(tmp[root][i]);
  }
  
}



int main(){
  int n, a, b;
  cin >> n;
  if (n == 1){
    cout << 0 << endl;
    return 0;
  }
  REP(i, n - 1){
    cin >> a >> b;
    if (tmp.find(a) == tmp.end()) tmp[a] = VI();
    if (tmp.find(b) == tmp.end()) tmp[b] = VI();
    tmp[a].PB(b);
    tmp[b].PB(a);
  }
  visited.resize(n + 1);
  fill_n(visited.begin(), n + 1, 0);

  int root = a;
  build_tree(root);
  auto dp = MATRIX(n + 1, 2, -1);
  /*
  cout << root << endl;
  for(auto pair: tree){
    cout << pair.first << " | ";
    REP(j, SIZE(pair.second)){
      cout << pair.second[j] << " ";
    }
    cout << endl;
  }

  cout << solve(dp, root, 0) << endl;
  cout << solve(dp, root, 1) << endl;
  */
  // dp[i][0] means this node do not use, otherwise dp[i][1]

  cout << max(solve(dp, root, 0), solve(dp, root, 1)) << endl;
  

  
  return 0;
}
