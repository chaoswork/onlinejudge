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
  int n, t, x;
  cin >> n >> t;
  map<int, set<int> > S;
  VI nums;
  REP(i, n){
    cin >> x;
    nums.PB(x);
    if (S.find(x) == S.end()){
      S[x] = set<int>();
    }
    S[x].insert(i);
  }
  /*
  for(auto e: S){
    for(int ee: e.second){
      cout << e.first << ":" << ee << endl;
    }
  }
  */

  REP(i, n){
    FOR(j, i + 1, n - 1){
      int left = t - nums[i] - nums[j];
      //      cout << i << " " << j << " " << left << " " << endl;
      if (S.find(left) == S.end()) continue;
      for(int e: S[left]){

        if (e == i || e == j) continue;
        cout << i + 1 << " " << j + 1 << " " << e + 1 << endl;
        return 0;
      }
      
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
