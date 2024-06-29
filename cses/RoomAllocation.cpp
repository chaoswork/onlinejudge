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

typedef struct node{
  node(int _id, int _t, int _o):id(_id), t(_t), o(_o){}
  int id;
  int t;
  int o;
  bool operator < (const node &other) const{
    if (t == other.t) return o < other.o;
    return t < other.t;
  }
}node;

int main(){
  int n, a, b;
  cin >> n;
  vector<node> v;
  REP(i, n){
    cin >> a >> b;
    v.PB(node(i, a, 1));
    v.PB(node(i, b + 1, -1));
  }
  sort(ALL(v));
  set<int> in_use;
  set<int> not_use;
  map<int, int> use_room;
  map<int, int> ans_room;

  int cur = 0;
  int best = 0;
  REP(i, SIZE(v)){
    // cout << "debug " << v[i].id << " " << v[i].t << " " << v[i].o << endl;
    if(v[i].o == -1){
      cur -= 1;
      int room_id = use_room[v[i].id];
      use_room.erase(v[i].id);
      not_use.insert(room_id);
    } else {
      cur += 1;
      int room_id = -1;
      if (SIZE(not_use) == 0){
        room_id = SIZE(use_room) + 1;
      } else {
        room_id = *not_use.begin();
        not_use.erase(room_id);
      }
      use_room[v[i].id] = room_id;
      ans_room[v[i].id] = room_id;

    }
    best = max(cur, best);
    
  }
  cout << best << endl;
  REP(i, n){
    if (i) cout << " ";
    cout << ans_room[i];
  }
  cout << endl;
  return 0;
}
