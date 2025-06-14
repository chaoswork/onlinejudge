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

LL MOD = 1000000007;

int N = 7;
int cnt = 0;

string path;
vector<char> search = vector<char> (50, 0);
VVI vis = MATRIX(7, 7, 0);
int dirx[4] = {-1, 0, 0, 1};
int diry[4] = {0, -1, 1, 0};

void dfs(int x, int y, int cur){
  if (x < 0 || x >= N || y < 0 || y >= N) return;
  if (vis[x][y]) return;
  if (cur == N * N - 1) {
    if (x == N - 1 && y == 0){
      cnt += 1;
    }
    return;
  }
  REP(i, 4){
    vis[x][y] = 1;
    dfs(x + dirx[i], y + diry[i], cur + 1);
    vis[x][y] = 0;
  }
}
int main(){
  // DLRU

  cin >> path;
  dfs(0, 0, 0);
  cout << cnt << endl;
  return 0;
}
