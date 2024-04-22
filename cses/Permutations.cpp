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

int found = 0;

void dfs(int start, VI &used, VI &ans){
  if (found) return;
  if (start == SIZE(used)){
    REP(i, SIZE(ans)){
      if(i) cout << " ";
      cout << ans[i] + 1;
    }
    cout << endl;
    found = 1;
    return;
  }
  REP(i, SIZE(ans)){
    if (used[i]) continue;
    if (start > 0 and abs(i - ans[start - 1]) <= 1) continue;
    ans[start] = i;
    used[i] = 1;
    dfs(start + 1, used, ans);
    used[i] = 0;
  }
  
}

int main(){
  int n;
  cin >> n;
  /*
  VI used(n, 0);
  VI ans(n, 0);
  dfs(0, used, ans);
  if (found == 0){
    cout << "NO SOLUTION" << endl;
  }
  */
  if (n == 1){
    cout << "1" << endl;
  }
  else if (n <= 3){
    cout << "NO SOLUTION" << endl;
  } else if (n == 4){
    cout << "2 4 1 3" << endl;
  } else{
    cout << "1";
    FOR(i, 2, n){
      if (i & 1) cout << " " << i;
    }
    FOR(i, 1, n){
      if ((i & 1) == 0) cout << " " << i;
    }
  }
  return 0;
}
