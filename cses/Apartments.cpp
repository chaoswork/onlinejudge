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


typedef struct node{
  node(int _cnt, int _id):cnt(_cnt), id(_id){}
  int cnt;
  int id;
  bool operator < (const node& that) const{
    return that.cnt < cnt;
  }
} node;

int main(){
  int n, m, k, x;
  cin >> n >> m >> k;
  VI man;
  VI apm;
  REP(i, n){
    cin >> x;
    man.PB(x);
  }
  REP(j, m){
    cin >> x;
    apm.PB(x);
  }
  sort(ALL(man));
  sort(ALL(apm));
  
  int i = 0, j = 0, ans=0;
  while (i < n){
    while(j < m){
      if (apm[j] < man[i] - k) {
        ++j;
        continue;
      }
      // apm[j] >= man[i] - k now
      break;
    }
    if (j == m) break;
    if (apm[j] > man[i] + k) {i++;}
    else{
      ans++;
      i++;
      j++;
    }
  }
  cout << ans << endl;
  return 0;

}
