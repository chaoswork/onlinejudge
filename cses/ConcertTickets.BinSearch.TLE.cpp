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
  int n, m, x;
  cin >> n >> m;
  VI tickets;
  VI used;
  
  
  REP(i, n){
    cin >> x;
    tickets.PB(x);
    used.PB(0);
  }
  sort(ALL(tickets));
  // add next and prev pointer??
  REP(i, m){
    cin >> x;
    // find the tickets <= x
    int L = -1, R = SIZE(tickets);
    while (L + 1 != R){
      int mid = L + (R - L) / 2;
      if (tickets[mid] > x) {
        R = mid;
      } else {
        L = mid;
      }
    }
    // tickets[L] <= x < tickets[R]
    if (L == -1){
      cout << -1 << endl;
    } else {
      while (L >= 0 && used[L] == 1){
        L--;
      }
      if (L == -1){
        cout << -1 << endl;
      } else{
        cout << tickets[L] << endl;
        used[L] = 1;
      }
    }
    if (i + 1 % 1000 == 0){
      VI tmp;
      REP(j, SIZE(tickets)){
        if (used[j]) continue;
        tmp.PB(tickets[j]);
      }
      tickets = tmp;
      used.clear();
      used.resize(SIZE(tickets));
      fill_n(used.begin(), SIZE(used), 0);
    }
  }
  return 0;
}
