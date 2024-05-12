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

int main(){
  int n;
  cin >> n;
  if (n == 4){
    cout << 2 << endl << 1 << " " << 4 << endl
         << 2 << endl << 2 << " " << 3 << endl;
    return 0;
  }
  LL total = (n + 1) * n / 2;
  if (total & 1) {
    cout << "NO" << endl;
  } else {
    LL target = total / 2;
    VI vis(n + 1, 0);
    if (target & 1){
      LL half_t = (target - 1) / 2;
      vis[1] = 1;
      if (half_t & 1) {
        vis[half_t / 2] = 1;
        vis[half_t / 2 + 1] = 1;
        vis[half_t / 2 - 1] = 1;
        vis[half_t / 2 + 2] = 1;
      } else {
        vis[half_t / 2 - 1] = 1;
        vis[half_t / 2 - 2] = 1;
        vis[half_t / 2 + 1] = 1;
        vis[half_t / 2 + 2] = 1;
      }
    } else {
      LL half_t = target / 2;

      if (half_t & 1) {
        vis[half_t / 2] = 1;
        vis[half_t / 2 + 1] = 1;
        vis[half_t / 2 - 1] = 1;
        vis[half_t / 2 + 2] = 1;
      } else {
        vis[half_t / 2 - 1] = 1;
        vis[half_t / 2 - 2] = 1;
        vis[half_t / 2 + 1] = 1;
        vis[half_t / 2 + 2] = 1;
      }
      
    }
    LL cur = 0;
    int k = 0;
    FOR(i, 1, n){
      if (vis[i]) {
        cur += i;
        k++;
      }
      
    }
    if (cur == target){
      cout << k << endl;
      int j = 0;
      FOR(i, 1, n) {
        if (vis[i]){
          if (j++) cout << " ";
          cout << i;
        }
      }
      cout << endl;
      cout << n - k << endl;
      j = 0;
      FOR(i, 1, n) {
        if (!vis[i]){
          if (j++) cout << " ";
          cout << i;
        }
      }
      cout << endl;

    } else {
      cout << "NO" << endl;
    }
  }
  
  return 0;
}
