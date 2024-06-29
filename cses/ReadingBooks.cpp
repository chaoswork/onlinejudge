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
  LL n, x;
  vector<LL> nums;
  cin >> n;
  LL total = 0;
  
  REP(i, n){
    cin >> x;
    total += x;
    nums.PB(x);
  }
  sort(ALL(nums));
  LL largest = nums[n - 1];
  LL left = total - largest;
  if (largest > left) cout << largest * 2 << endl;
  else cout << total << endl;
  return 0;
}
/*
int main(){
  LL n, x;
  cin >> n;
  multiset<LL> books;
  REP(i, n){
    cin >> x;
    books.insert(x);
  }
  LL ans = *books.rbegin();
  LL cur = ans;
  books.erase(std::prev(books.rbegin().base()));

  while (1){
    if (books.empty()) break;
    auto it = books.upper_bound(cur);
    if (it == books.begin()){
      // 所有元素都大于 cur
      ans -= cur;
      cur = *books.rbegin();
      ans += cur;
      books.erase(std::prev(books.rbegin().base()));
      
    } else {
      --it;
      cur -= *it;
      books.erase(it);
    }
    
  }
  cout << ans * 2 << endl;
  return 0;
}
*/
