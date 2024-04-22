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




std::string solve(std::string moves) {
  // build a map, then floodfill find a shortest path
  map<char, PII > dirs;
  dirs['L'] = MP(-1, 0);
  dirs['R'] = MP(1, 0);
  dirs['U'] = MP(0, -1);
  dirs['D'] = MP(0, 1);
  
  vector<PII> paths;
  const int MAX_N = 1024;
  int boards[MAX_N][MAX_N];
  memset(boards, 0, sizeof(boards));
  int dp[MAX_N][MAX_N];
  //  memset(dp, 0, sizeof(boards));
  fill_n(&dp[0][0], MAX_N * MAX_N, 1024);

  
  int x = 0, y = 0;
  int max_x = 0, min_x = 0, max_y = 0, min_y = 0;
  string all_dir = "LRUD";
  PII start, end;
  paths.PB(MP(x, y));
  REP(i, SIZE(moves)){
    x += dirs[moves[i]].first;
    y += dirs[moves[i]].second;
    paths.PB(MP(x, y));
    max_x = max(max_x, x);
    min_x = min(min_x, x);
    max_y = max(max_y, y);
    min_y = min(min_y, y);
  }
  REP(i, SIZE(paths)) {
    x = paths[i].first + (max_x - min_x);
    y = paths[i].second + (max_y - min_y);
    if (i == SIZE(paths) - 1) end = MP(x, y);
    
    boards[x][y] = 1;
  }

  queue<PII > Q;
  start = MP(max_x - min_x, max_y - min_y);
  Q.push(start);
  dp[start.first][start.second] = 0;


  while (Q.size()){
    auto cur = Q.front();
    Q.pop();
    if (cur == end) break;
    REP(i, 4){
      PII next = MP(cur.first + dirs[all_dir[i]].first,
                    cur.second + dirs[all_dir[i]].second);
      if (boards[next.first][next.second] && dp[next.first][next.second] > dp[cur.first][cur.second] + 1){
        dp[next.first][next.second] = dp[cur.first][cur.second] + 1;
        Q.push(next);
      }
    }
  }
  if (dp[end.first][end.second] == SIZE(moves)) return "OK";
  
  return "BUG";
  
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string a;
    std::cin >> a;
    auto ans = solve(a);
    std::cout << ans << '\n';
    return 0;
}