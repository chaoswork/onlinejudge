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
#include <unordered_map>
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


bool cmp(VI a, VI b){
  if (a[1] == b[1]) return a[0] > b[0];
  return a[1] < b[1];
}
bool cmp2(VI a, VI b){
  if (a[0] == b[0]) return a[1] > b[1];
  return a[0] < b[0];
}

int get_or_default(unordered_map<int, int> & bit, int x){
  if (bit.find(x) == bit.end()) return 0;
  return bit[x];
}

int query(unordered_map<int, int>& bit, int x){
  int total = 0;
  while (x > 0){
    total += get_or_default(bit, x);
    x -= x & -x;
  }
  return total;
}

void update(unordered_map<int, int> & bit, int maxv,  int x){
  while (x <= maxv){
    if (bit.find(x) == bit.end()) bit[x] = 0;
    bit[x] += 1;
    x += x & -x;
  }
}

int main(){
  optimize;
  int n, x, y;
  cin >> n;

  VVI ranges = MATRIX(n, 3, 0);
  int maxv = 0;
  REP(i, n){
    cin >> x >> y;
    maxv = max(x, maxv);
    maxv = max(y, maxv);
    ranges[i][0] = x;
    ranges[i][1] = y;
    ranges[i][2] = i;
  }

  sort(ALL(ranges), cmp);
  /*
  REP(i, n){
    cout << ranges[i][0] << " " << ranges[i][1] << " " << ranges[i][2] << endl;
  }
  */
  //  multiset<int> starts;
  // vector<int> bit(maxv + 1, 0);
  unordered_map<int, int> bit;
  bit.reserve(102400);
  bit.max_load_factor(0.25);

  VI ans1(n, 0);
  REP(i, n){
    /*
    auto it = starts.lower_bound(ranges[i][0]);
    int dist = distance(it, starts.end()); // TLE here
    
    ans1[ranges[i][2]] = dist;
    
    starts.insert(ranges[i][0]);
    */
    ans1[ranges[i][2]] = i - query(bit, ranges[i][0] - 1);
    update(bit, maxv, ranges[i][0]);

  }

  sort(ALL(ranges), cmp2);
  //  multiset<int> ends;
  // fill(ALL(bit), 0);
  bit.clear();
  bit.reserve(102400);
  bit.max_load_factor(0.25);
  
  VI ans2(n, 0);
  REP(i, n){
    /*
    auto it = ends.lower_bound(ranges[i][1]);
    int dist = distance(it, ends.end()); // TLE here
    ans2[ranges[i][2]] = dist;
    
    ends.insert(ranges[i][1]);
    */
    ans2[ranges[i][2]] = i - query(bit, ranges[i][1] - 1);
    //    cout << "debug " << query(bit, ranges[i][1]) << endl;
    update(bit, maxv, ranges[i][1]);
    
  }

  REP(i, n){
    if (i) cout << " ";
    cout << ans1[i];
  }
  cout << endl;
  REP(i, n){
    if (i) cout << " ";
    cout << ans2[i];
  }
  cout << endl;

  return 0;
}