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
#include <tuple>
#include <unordered_set>

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

unordered_set<LL> cache;

bool check(LL x, int n){
  LL key = x * 10000000 + n;
  if (cache.find(key) != cache.end()) return true;
  if (x - n == 0) {
    cache.insert(key);
    return true;
  }
  if (n > 0 && x - n >= 0 && check(x - n, n - 1)){
    cache.insert(key);
    return true;
  }
  if (n > 0 && check(x, n - 1)) {
    cache.insert(key);
    return true;
  }
  return false;
}

int main(){
  LL n;
  cin >> n;
  LL total = (n + 1) * n / 2;
  if (total & 1) {
    cout << "NO" << endl;
  } else {
    LL target = total / 2;
    unordered_set<int> S;
    int p = n;
    // cout << target << endl;
    while (target) {
      if (target >= p) {// && check(target, p)){
        target -= p;
        S.insert(p);
      }
      p--;
    }
    if (target) cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      cout << SIZE(S) << endl;
      p = 0;
      FOR(i, 1, n) {
        if (S.find(i) != S.end()) {
          if (p++) cout << " ";
          cout << i;
        }
      }
      cout << endl;
      cout << n - SIZE(S) << endl;
      p = 0;
      FOR(i, 1, n) {
        if (S.find(i) == S.end()) {
          if (p++) cout << " ";
          cout << i;
        }
      }
      cout << endl;

    }
    
  }
  
  return 0;
}
