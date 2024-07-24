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

LL exp(LL a, LL b){
  if (a == 1 || b == 0){
    return 1;
  }
  if (a == 0) {return 0;}
  unsigned long long base = a;
  unsigned long long ans = 1;
  while (b) {

    if (b % 2){
      ans = (ans * base) % 1000000007;
    }
    base *= base;
    base = base % 1000000007; // mod need here
    b >>= 1;
  }
  return ans;

}


int main(){
  //     # f(a, b, c) = f(a, b, c - 1) ^ b = f(a, b, c - 2) ^ b ^ b = f(a, b, 1) ^ b1 ^ b2 ... ^ b_c-1,
  LL n;
  cin >> n;
  while (n--){
    LL a, b, c;
    cin >> a >> b >> c;
    if (c == 0){
      cout << a % 1000000007 << endl;
      continue;
    }
    LL ans = exp(a, b);
    REP(i, c - 1){
      ans = exp(ans, b);
      ans %= 1000000007;
    }
    cout << ans << endl;
  }
  
  return 0;
}
