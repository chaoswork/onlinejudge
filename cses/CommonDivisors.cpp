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



int gcd(int a, int b){
  if (a < b) swap(a, b);
  if (b == 0) return a;
  else return gcd(a - b, b);
}

int main(){
  int n, x;
  cin >> n;
  unordered_map<int, int> m;
  int maxv = 0;
  REP(i, n){
    cin >> x;
    maxv = max(x, maxv);
    if (m.find(x) == m.end()) m[x] = 0;
    m[x]++;
  }
  FORD(i, maxv, 0){
    int cur = i;
    int n = 0;
    while (cur <= maxv){
      if (m.find(cur) != m.end()){
        n += m[cur];
      }
      if (n > 1) break;
      cur += i;
    }
    if (n > 1) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}

/* TLE
int main(){

  int n, x;
  const int maxn = 1000000;
  VI divisor(maxn + 1, 0);
  int maxv = 0;

  cin >> n;
  REP(i, n){
    cin >> x;
    maxv = max(x, maxv);
    FOR(j, 1, int(sqrt(x))){
      // if (j * j > x) break;
      if (x % j == 0){
        int k = x / j;
        if (j == k) divisor[j]++;
        else {
          divisor[j]++;
          divisor[k]++;
        }
      }
    }
  }
  FORD(i, maxv, 1){
    if (divisor[i] >= 2){
      cout << i << endl;
      break;
    }
  }

  return 0;
}
*/
