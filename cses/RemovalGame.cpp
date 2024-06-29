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

typedef long long LL;
#define PB push_back
#define SIZE(X) ((int)(X.size()))
#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, l, h) for(int i=(l); i<=(h); ++i)
#define FORD(i, h, l) for(int i=(h); i>=(l);--i)
#define ALL(A) A.begin(),A.end()
#define MATRIX(n, m, v) vector<vector<int> >((n), vector<int>((m), (v)))
#define LMATRIX(n, m, v) vector<vector<LL> >((n), vector<LL>((m), (v)))
#define DISPLAY_MATRIX(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;

typedef pair<int, int> PII;

int n;

VI nums;

LL INF = 1000000000L * 5120;

vector<vector<LL> > sum = LMATRIX(5001, 5001, 0);
vector<vector<LL> > ans = LMATRIX(5001, 5001, -INF);

LL dp(int s, int e){
  if (ans[s][e] != -INF) return ans[s][e];
  if (s == e) return ans[s][e] = nums[s];

  LL a = nums[s] + sum[s + 1][e] - dp(s + 1, e);
  LL b = nums[e] + sum[s][e - 1] - dp(s, e - 1);

  return ans[s][e] = max(a, b);
}

int main(){
  int x;
  cin >> n;
  REP(i, n){
    cin >> x;
    if (i == 0) sum[0][i] = x;
    else sum[0][i] = sum[0][i - 1] + x;
      
    nums.PB(x);
  }
  FOR(i, 1, n - 1){
    FOR(j, i, n - 1){
      sum[i][j] = sum[0][j] - sum[0][i - 1];
    }
  }
  // DISPLAY_MATRIX(sum, n, n);
  cout << dp(0, n - 1) << endl;
  return 0;
}
