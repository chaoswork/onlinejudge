/*
ID:huangch7
PROB:prime3
LANG:C++
*/
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

bool is_prime(int x){
  if (x <= 1) return false;
  for(int i = 2; i * i <= x; ++i){
    if (x % i == 0) return false;
  }
  return true;
}

int get_sum(int x){
  int ans = 0;
  while(x){
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

int trie[10000][10];
int trie_r[10000][10];
bool stop[10000];
int cur = 0;
void insert(int x){
  VI digits;
  while (x){
    digits.PB(x % 10);
    x /= 10;
  }
  int ind = 0;
  FORD(i, 4, 0){
    int d = digits[i];
    if (trie[ind][d] == 0) trie[ind][d] = ++cur;
    ind = trie[ind][d];
  }
  stop[ind] = true;

  ind = 0;
  FOR(i, 0, 4){
    int d = digits[i];
    if (trie_r[ind][d] == 0) trie_r[ind][d] = ++cur;
    ind = trie_r[ind][d];
  }
  
}

int total, start;
VI primes;
VVI prime_nums;
int matrix[5][5];
int n_solution = 0;

void fill_digits(int cur_row){
  //  cout << "depth=" << cur_row << endl;
  if (cur_row == 5) {
    if (n_solution++) cout << endl;
    REP(i, 5) {
      REP(j, 5) cout << matrix[i][j];
      cout << endl;
    }
    return;
  }
  
  REP(i, SIZE(primes)){
    


    if (cur_row == 0 && prime_nums[i][0] != start) continue;

    // add to matrix
    REP(j, 5) matrix[cur_row][j] = prime_nums[i][j];
    // check
    bool ok = true;
    REP(j, 5){
      // check col      
      int ind = 0;
      int t = 0;
      FOR(r, 0, cur_row){

        if (trie[ind][matrix[r][j]] == 0) {
          ok = false;
          break;
        }
        ind = trie[ind][matrix[r][j]];

        t += matrix[r][j];
      }
      if (t > total || t + 9 * (4 - cur_row) < total) {
        ok = false;
        break;
      }
      
      if (!ok) break;
    }
    //    cout << primes[i] << " " << ok << endl;
    if (!ok) continue;
    
    // check diag backslash
    int ind = 0;
    int t = 0;
    FOR(j, 0, cur_row){
      if (trie[ind][matrix[j][j]] == 0) {
        ok = false;
        break;
      }
      ind = trie[ind][matrix[j][j]];
      t += matrix[j][j];

    }

    if (t > total || t + 9 * (4 - cur_row) < total) {
      ok = false;
    }

    if (!ok) continue;
    
    
    // check diag / 

    ind = 0;
    t = 0;
    // 0, 4 | 1, 3 | 2, 2 | 
    FOR(j, 0, cur_row){
      if (trie_r[ind][matrix[j][4 - j]] == 0) {
        ok = false;
        break;
      }
      ind = trie_r[ind][matrix[j][4 - j]];
      t += matrix[j][4 - j];
    }
    if (t > total || t + 9 * (4 - cur_row) < total) {
      ok = false;
    }

    if (!ok) continue;

    
    /*
    if (cur_row == 4){
      ind = 0;
      FOR(j, 0, cur_row){
        if (trie[ind][matrix[4 - j][j]] == 0) {
          ok = false;
          break;
        }
        ind = trie[ind][matrix[4 - j][j]];
      }
      if (!ok) continue;
    }*/
    if (!ok) continue;
    
    fill_digits(cur_row + 1);
  }
}

int main(){
  freopen("prime3.in","r",stdin);
  freopen("prime3.out","w",stdout);
  
  

  memset(trie, 0, sizeof(trie));
  memset(matrix, 0, sizeof(matrix));

  cin >> total >> start;

  FOR(i, 10000, 99999){
    if(is_prime(i) && get_sum(i) == total) {
      primes.PB(i);
      insert(i);
      prime_nums.PB(VI());
      prime_nums[SIZE(prime_nums) - 1].resize(5);
      int x = i;
      int j = 4;
      
      while (x){
        prime_nums[SIZE(prime_nums) - 1][j--] = x % 10;
        x /= 10;
      }

    }
  }

  fill_digits(0);

  if (n_solution == 0){
    cout << "NONE" << endl;
  }

  return 0;
}
