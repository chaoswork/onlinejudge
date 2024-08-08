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
  /*
  multimap<int, int> test;
  // 1 2 3 4 |4 4 4 4 4 |5 6  7  8  9
  // 0 1 2 3 |4 5 6 7 8 |9 10 11 12 13
  FOR(i, 1, 4){
    test.insert(MP(i, i - 1));
  }
  REP(i, 5) test.insert(MP(4, i + 4));
  FOR(i, 5, 9) test.insert(MP(i, i + 4));

  cout << test.lower_bound(4)->second << " " << test.upper_bound(4)->second << endl;
  cout << test.lower_bound(0)->second << " " << test.upper_bound(0)->second << endl;
  cout << test.lower_bound(10) == test.end() << endl;
  */
  int n, k, s, e;
  cin >> n >> k;

  multiset<PII> movies;
  REP(i, n){
    cin >> s >> e;
    movies.insert(MP(e, s));
  }
  multimap<int, int> men;
  int ans = 1;
  men.insert(*movies.begin());
  movies.erase(movies.begin());
  /*
  REP(i, k){
    if (SIZE(men) == 0){
      men.insert(*movies.begin());
    } else {
      int s = movies.begin()->second;
    }
    movies.erase(movies.begin());
    ans++;
  }
  */
  
  while (SIZE(movies)){
    int s = movies.begin()->second;
    // int e = movies.begin()->first;
    // find the first less or equal node
    
    auto it = men.upper_bound(s);
    if (it != men.begin()){
      --it;
      men.erase(it);
      men.insert(*movies.begin());
      ans++;
    } else if (SIZE(men) < k){
      men.insert(*movies.begin());
      ans++;
    }
    /*
    if (men.begin()->first <= s){
      men.erase(men.begin());
      men.insert(*movies.begin());
      ans++;
    }
    */
    movies.erase(movies.begin());
  }
  cout << ans << endl;

  return 0;
}
