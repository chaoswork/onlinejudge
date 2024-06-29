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

// LL adj[501][501];
LL dist[501][501];

int main(){
  int n, m, q, a, b, v;
  cin >> n >> m >> q;
  FOR(i, 1, n){
    FOR(j, 1, n){
      //      adj[i][j] = -1;
      dist[i][j] = -1;
    }
    dist[i][i] = 0;
  }
  REP(i, m){
    cin >> a >> b >> v;
    if (dist[a][b] < 0 || dist[a][b] > v){
      dist[a][b] = v;
      dist[b][a] = v;
    }
  }
  FOR(k, 1, n){
    FOR(i, 1, n){
      FOR(j, 1, n){
        if (dist[i][k] != -1 && dist[k][j] != -1){
          if (dist[i][j] < 0 || dist[i][j] > dist[i][k] + dist[k][j]){
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }
  }
  REP(i, q){
    cin >> a >> b;
    cout << dist[a][b] << endl;
  }
  return 0;
}
