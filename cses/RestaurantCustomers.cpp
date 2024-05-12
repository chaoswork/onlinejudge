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
/*
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
Input
The first input line has an integer n: the number of customers.
After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.
Output
Print one integer: the maximum number of customers.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a < b \le 10^9

Example
Input:
3
5 8
2 4
3 9

Output:
2
*/
int main(){
  int t, s, e;
  int ans = 0;
  vector<PII> customers;
  priority_queue<int> Q;
  cin >> t;
  REP(i, t){
    cin >> s >> e;
    customers.PB(MP(s, e));
  }
  sort(ALL(customers));
  REP(i, t){
    while (SIZE(Q) && -Q.top() < customers[i].first) Q.pop();
    Q.push(-customers[i].second);
    ans = max(ans, SIZE(Q));
  }
  cout << ans << endl;
  return 0;
}
