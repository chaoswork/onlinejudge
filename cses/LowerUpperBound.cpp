#pragma GCC optimize("O3,unroll-loops,Ofast")
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
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

int main(){
  optimize;

  multimap<int, int> test;
  // 1 2 3 4 |4 4 4 4 4 |5 7  7  8  9
  // 0 1 2 3 |4 5 6 7 8 |9 10 11 12 13
  FOR(i, 1, 4){
    test.insert(MP(i, i - 1));
  }
  REP(i, 5) test.insert(MP(4, i + 4));
  test.insert(MP(5, 9));
  test.insert(MP(7, 10));  
  FOR(i, 7, 9) test.insert(MP(i, i + 4));
  REP(i, 10){
    cout << i << " " << test.lower_bound(i)->second << " " << test.upper_bound(i)->second << endl;
  }
  cout << (test.lower_bound(10) == test.end()) << endl;  
  /*
  cout << test.lower_bound(4)->second << " " << test.upper_bound(4)->second << endl;
  cout << test.lower_bound(0)->second << " " << test.upper_bound(0)->second << endl;
  cout << test.lower_bound()->second << " " << test.upper_bound(6)->second << endl;    
  cout << test.lower_bound(6)->second << " " << test.upper_bound(6)->second << endl;
  */  


  return 0;
}
