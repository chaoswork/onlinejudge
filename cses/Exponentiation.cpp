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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

int main(){
  int n, a, b;
  cin >> n;
  REP(i, n){
    cin >> a >> b;
    if (a == 1 || b == 0) {cout << 1 << endl; continue;}
    if (a == 0) {cout << 0 << endl; continue;}
    else{
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
      cout << ans << endl;
    }
  }
}
