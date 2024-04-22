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

void dfs(vector<string>& board, int i, int j){

  if (i < 0 || i >= SIZE(board)) return;
  if (j < 0 || j >= SIZE(board[0])) return;
  if (board[i][j] == '#') return;  
  board[i][j] = '#';
  dfs(board, i + 1, j);
  dfs(board, i, j + 1);
  dfs(board, i - 1, j);
  dfs(board, i, j - 1);

    
}

int main(){
  int n, m;
  cin >> n >> m;
  int ans = 0;
  vector<string> board;
  REP(i, n){
    string s;
    cin >> s;
    board.PB(s);
  }
  REP(i, n) REP(j, m){
    if (board[i][j] == '.') ans++;
    dfs(board, i, j);
  }
  cout << ans << endl;
  return 0;
}
