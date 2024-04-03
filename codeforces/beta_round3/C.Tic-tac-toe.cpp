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


bool win(const VS &board, char c){
  REP(i, 3) {
    if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
    if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
  }
  if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
  if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;

  return false;
}

int main(){
  string line;
  VS board;
  int nX = 0;
  int nO = 0;
  
  REP(i, 3){
    cin >> line;
    board.PB(line);
    REP(j, 3){
      if (line[j] == '0') ++nO;
      else if(line[j] == 'X') ++nX;
    }
  }

  if (nX - nO > 1 || nX - nO < 0){ cout << "illegal" << endl; return 0;}
  // nX = nO or nX = nO + 1
  bool Awin = win(board, 'X');
  bool Bwin = win(board, '0');
  if (Awin && Bwin) {cout << "illegal" << endl; return 0;}
  if (Awin) {
    // nX must great than nO
    if (nX > nO) cout << "the first player won" << endl;
    else cout << "illegal" << endl;
    return 0;
  }
  if (Bwin) {
    // nX must equal to nO
    if (nX == nO) cout << "the second player won" << endl;
    else cout << "illegal" << endl;
    return 0;
  }
  if (nX + nO == 9) {  cout << "draw" << endl; return 0;}
  
  if (nX > nO) {cout << "second" << endl; return 0;}
    else {cout << "first" << endl; return 0;}

  return 0;
}
