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


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;


class BIT{
private:
  LL maxv;
  vector<int> values;
public:
  BIT(LL _maxv){
    maxv = _maxv;
    values = vector<int> (maxv, 0);
  }

  void update(LL x, int v){
    while(x <= maxv){
      values[x] += v;
      x += (x & -x);
    }
  }

  int query(int x){
    int res = 0;
    while (x > 0){
      res += values[x];
      x -= (x & -x);
    }
    return res;
  }
  
};

int main(){
  int n, m, k, x, a, b;
  char c;
  cin >> n >> m;
  VI nums;
  set<int> shrink;

  vector<char> cmds;
  vector<PII> args;
  REP(i, n){
    cin >> x;
    nums.PB(x);
    shrink.insert(x);
    // bit.update(x, 1);
  }
  // cout << bit.query(2) << endl;
  REP(i, m){
    cin >> c;
    if (c == '!'){
      cin >> k >> x;
      // bit.update(nums[k - 1], -1);
      // nums[k - 1] = x;
      // bit.update(x, 1);
      cmds.PB(c);
      args.PB(MP(k, x));
      shrink.insert(x);
      
    } else {
      cin >> a >> b;
      cmds.PB(c);
      args.PB(MP(a, b));
      shrink.insert(a);
      shrink.insert(b);
      // cout << bit.query(b) - bit.query(a - 1) << endl;
    }
  }

  unordered_map<int, int> id_map;
  id_map.reserve(10240);
  id_map.max_load_factor(0.25);
  
  int start = 1;
  for(int e: shrink) id_map[e] = start++;
  /*
  for(auto e: id_map){
    cout << e.first << " " << e.second << endl;
  }
  */
  BIT bit = BIT(start + 10);
  REP(i, n){
     bit.update(id_map[nums[i]], 1);    
  }


  REP(i, m){
    if (cmds[i] == '!'){
      k = args[i].first;
      x = args[i].second;
      bit.update(id_map[nums[k - 1]], -1);
      nums[k - 1] = x;
      bit.update(id_map[x], 1);
    } else {
      a = args[i].first;
      b = args[i].second;
      cout << bit.query(id_map[b]) - bit.query(id_map[a] - 1) << '\n';      
    }

  }
  
  return 0;
}
