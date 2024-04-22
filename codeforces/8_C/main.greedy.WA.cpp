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

LL dist[30][30];
LL dist2bag[30];
int used[30];


// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int xb, yb, n, x, y;
    LL w, h;
    LL best = -1;
    LL base = 0;
    vector<PII> ans;
    vector<PII> ob;
    std::cin >> xb >> yb >> n;
    REP (i, n) {
      std::cin >> x >> y;
      ob.PB(MP(x, y));
    }

    REP(i, n) {
      FOR(j, i + 1, n - 1){
        w = ob[i].first - ob[j].first;
        h = ob[i].second - ob[j].second;
        dist[i][j] = w * w + h * h;
      }
      w = ob[i].first - xb;
      h = ob[i].second - yb;
      dist2bag[i] = w * w + h * h;
      base += dist2bag[i];
      used[i] = 0;
    }

    for(int i = 0; i * 2 <= n; ++i){
      LL cur = 0;
      vector<PII> anst;
      int n_pairs = 0;
      while (n_pairs < i){
        LL min_v = -1;
        int min_k, min_j = -1;
        REP(j, n){
          if (used[j]) continue;
          FOR(k, j + 1, n - 1){
            if (used[k]) continue;
            if (min_j < 0 || dist[j][k] - dist2bag[j] - dist2bag[k] < min_v){
              min_v = dist[j][k] - dist2bag[j] - dist2bag[k];
              min_j = j;
              min_k = k;
            }
          }
        }
        if (min_j < 0) break;

        cur += dist[min_j][min_k];
        anst.PB(MP(min_j, min_k));
        n_pairs++;
        
        used[min_j] = 1;
        used[min_k] = 1;


      }
      REP(j, n) {
        if (!used[j]) {
          cur += dist2bag[j];
          anst.PB(MP(j, -1));
        }
      }
      if (best < 0 || best > cur){
        best = cur;
        ans = anst;
      }
      REP(j, n) used[j] = 0;

    }

    cout << best + base << endl;
    cout << "0 ";
    REP(i, SIZE(ans)){
      //      cout << "debug" << ans[i].first << " " << ans[i].second << endl;
      if (i) cout << " ";
      if (ans[i].first >= 0) cout << ans[i].first + 1 << " ";
      if (ans[i].second >= 0) cout << ans[i].second + 1 << " ";
      cout << "0";
    }
    cout << endl;

    return 0;
}