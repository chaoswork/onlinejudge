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


int check_prev(int check_pos, int old_pos, int new_pos){

  bool flag1 = old_pos > check_pos; 
  bool flag2 = new_pos > check_pos;
  // cout << "check_prev" << check_pos << " " << old_pos << " " << new_pos << "|" << flag1 << " " << flag2 << endl;
  if (flag1 == flag2) return 0;
  else if (flag1 == true){
    return 1;
  } else if (flag2 == true){
    return -1;
  }
  return 0;
}

int check_next(int check_pos, int old_pos, int new_pos){
  bool flag1 = old_pos < check_pos;
  bool flag2 = new_pos < check_pos;
  //   cout << "check_next" << check_pos << " " << old_pos << " " << new_pos << "|" << flag1 << " " << flag2 << endl;  
  if (flag1 == flag2) return 0;
  else if (flag1 == true){
    return 1;
  } else if (flag2 == true){
    return -1;
  }
  return 0;
}

int main(){
  int n, x, q, a, b;
  cin >> n >> q;
  int ans = 0;
  VI pos(n + 2, 0);
  VI nums;
  nums.PB(0);
  REP(i, n){
    cin >> x;
    pos[x] = i + 1;
    nums.PB(x);
  }
  nums.PB(n + 1);
  pos[n + 1] = n + 1;
  /*
  REP(i, n + 2){
    cout << nums[i] << "|" << pos[i] << endl;
  }
  */
  
  FOR(i, 2, n){
    if (pos[i - 1] > pos[i]){
      ans++;
    }
  }
  // cout << ans + 1<< endl;
  ans++;
  // cout << ans << endl;

  REP(i, q){
    cin >> a >> b;
    if (a == b) {
      cout << ans << endl;
      continue;
    }
    a = nums[a];
    b = nums[b];
    if (a + 1 == b){
      if (pos[a] < pos[b]) ans++;
      else ans--;
      // cout << ans << endl;
      ans += check_prev(pos[a - 1], pos[a], pos[b]);
      // cout << ans << endl;
      ans += check_next(pos[b + 1], pos[b], pos[a]);
      // cout << ans << endl << endl;      
    } else if (b + 1 == a){
      if (pos[b] < pos[a]) ans++;
      else ans--;
      // cout << ans << endl;      
      ans += check_prev(pos[b - 1], pos[b], pos[a]);
      // cout << ans << endl;      
      ans += check_next(pos[a + 1], pos[a], pos[b]);
      // cout << ans << endl;      
    } else {
      /*
      if (a < b){
        if (pos[a] < pos[b]) ans++;
        else ans--;
      } else {
        if (pos[b] < pos[a]) ans++;
        else ans--;
      }
      */
      // cout << "debug" << check_prev(14, 12, 20) << endl;
      // cout << ans << endl;
      ans += check_prev(pos[a - 1], pos[a], pos[b]);
      // cout << ans << endl;
      ans += check_next(pos[b + 1], pos[b], pos[a]);
      // cout << ans << endl;
      ans += check_prev(pos[b - 1], pos[b], pos[a]);
      // cout << ans << endl;
      ans += check_next(pos[a + 1], pos[a], pos[b]);
      // cout << ans << endl;

    }
    cout << ans << endl;
    int pos_a = pos[a];
    int pos_b = pos[b];
    swap(nums[pos_a], nums[pos_b]);
    swap(pos[a], pos[b]);
    /*
    REP(i, n + 2){
      cout << nums[i] << "|" << pos[i] << endl;
      }*/
  }
  return 0;
}
