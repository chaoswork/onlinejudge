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
  string s;
  cin >> s;
  int cnt[30];
  memset(cnt, 0, sizeof(cnt));
  REP(i, SIZE(s)){
    cnt[s[i] - 'A']++;
  }
  string left, right;
  int n_odd = 0;
  string mid;
  bool ok = true;
  REP(i, 26){
    char x = char(i + 'A');
    int n = cnt[i];
    if (n & 1){
      n_odd++;
      REP(j, n){
        mid += x;
      }
      if (n_odd > 1) {
        ok = false;
        break;
      }
    } else {
      left += string(n/2, x);
      /*
      REP(j, n / 2){
        left = left + x;
        //right = x + right;
      }*/
    }
  }
  if (ok){
    cout << left << mid;
    reverse(ALL(left));
    cout << left << endl;
  }
  else cout << "NO SOLUTION" << endl;
  return 0;
}
