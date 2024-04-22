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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

int ans[200000 + 5];
map<int, VI> node;
int dfs(int node_id){
  if (node.find(node_id) == node.end()){
    ans[node_id] = 0;
    return 0;
  }
  if (ans[node_id] != -1) return ans[node_id];
  int n = SIZE(node[node_id]);
  REP(i, SIZE(node[node_id])){
    n += dfs(node[node_id][i]);
  }

  return ans[node_id] = n;

}

int main(){
  int n, x;

  // memset(ans, 0, sizeof(ans));

  cin >> n;
  fill_n(ans, n + 1, -1);  
  FOR(i, 2, n){
    cin >> x;
    // add child
    if (node.find(x) == node.end()) node[x] = VI();
    node[x].PB(i);
  }
  FOR(i, 1, n){
    if (i > 1) cout << " ";
    cout << dfs(i);
  }
  cout << endl;
  
  return 0;
}
