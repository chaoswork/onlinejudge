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


// H(n) -> 2 * H(n - 1) + 1
// H(1) -> 1
// H(2) -> 3 = 1 + 2 H(1)
// H(3) -> 7 = 1 + 2 H(2)
// H(4) -> 15 = 1 + 2 H(3)

int cnt(int n){
  int ans = 0;
  REP(i, n){
    ans = ans * 2 + 1;
  }
  return ans;
}

void move_step(int n, int src, int tgt, int mid){
  if (n == 1){
    cout << src << " " << tgt << endl;

    return;
  }
  move_step(n - 1, src, mid, tgt);
  cout << src << " " << tgt << endl;
  move_step(n - 1, mid, tgt, src);
}

int main(){
  int n;
  cin >> n;
  cout << cnt(n) << endl;
  move_step(n, 1, 3, 2);
  return 0;
}
