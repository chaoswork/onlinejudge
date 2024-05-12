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
#include <unordered_map>
#include <unordered_set>

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

int at(int x, int k){
  int kk = 5 - k;
  while(kk--){
    x /= 10;
  }
  return x % 10;
}

int check(int a, int b, int c, int d, int e, int t){
  if (!is_prime(a) || get_sum(a) != t) return false;
  if (!is_prime(b) || get_sum(b) != t) return false;
  if (!is_prime(c) || get_sum(c) != t) return false;
  if (!is_prime(d) || get_sum(d) != t) return false;
  if (!is_prime(e) || get_sum(e) != t) return false;

  

  int aa = at(a, 1) * 10000 + at(b, 1) * 1000 + at(c, 1) * 100 + at(d, 1) * 10 + at(e, 1);
  int bb = at(a, 2) * 10000 + at(b, 2) * 1000 + at(c, 2) * 100 + at(d, 2) * 10 + at(e, 2);
  int cc = at(a, 3) * 10000 + at(b, 3) * 1000 + at(c, 3) * 100 + at(d, 3) * 10 + at(e, 3);
  int dd = at(a, 4) * 10000 + at(b, 4) * 1000 + at(c, 4) * 100 + at(d, 4) * 10 + at(e, 4);
  int ee = at(a, 5) * 10000 + at(b, 5) * 1000 + at(c, 5) * 100 + at(d, 5) * 10 + at(e, 5);
  
  if (!is_prime(aa) || get_sum(aa) != t) return false;
  if (!is_prime(bb) || get_sum(bb) != t) return false;
  if (!is_prime(cc) || get_sum(cc) != t) return false;
  if (!is_prime(dd) || get_sum(dd) != t) return false;
  if (!is_prime(ee) || get_sum(ee) != t) return false;

  int x = at(a, 1) * 10000 + at(b, 2) * 1000 + at(c, 3) * 100 + at(d, 4) * 10 + at(e, 5);
  int y = at(e, 1) * 10000 + at(d, 2) * 1000 + at(c, 3) * 100 + at(b, 4) * 10 + at(a, 5);
  
  if (!is_prime(x) || get_sum(x) != t) return false;
  if (!is_prime(y) || get_sum(y) != t) return false;
  return true;
  
}


int main(){
  freopen("prime3.in","r",stdin);
  freopen("prime3.out","w",stdout);

  int total, start;
  unordered_set<int> primes;
  int n_solution = 0;
  VS ans;

  unordered_map<int, unordered_set<int> > map0;
  unordered_map<int, unordered_set<int> > map04;
  unordered_map<int, unordered_set<int> > map024;
  unordered_map<int, unordered_set<int> > map123;  
  unordered_map<int, unordered_set<int> > map0134;  
  cin >> total >> start;

  FOR(i, 10000, 99999){
    if(is_prime(i) && get_sum(i) == total) {
      primes.insert(i);

      int x = i;
      VI digits;
      
      while (x){
        digits.PB(x % 10);
        x /= 10;
      }
      reverse(ALL(digits));
      if (map0.find(digits[0]) == map0.end()) map0[digits[0]] = unordered_set<int>();
      int key04 = digits[0] * 10000 + digits[4];
      int key024 = digits[0] * 10000 + digits[2] * 100 + digits[4];
      int key123 = digits[1] * 1000 + digits[2] * 100 + digits[3] * 10;
      int key0134 = digits[0] * 10000 + digits[1] * 1000 + digits[3] * 10 + digits[4];
      if (map04.find(key04) == map04.end()) map04[key04] = unordered_set<int>();
      if (map024.find(key024) == map024.end()) map024[key024] = unordered_set<int>();
      if (map0134.find(key0134) == map0134.end()) map0134[key0134] = unordered_set<int>();
      if (map123.find(key123) == map123.end()) map123[key123] = unordered_set<int>();            
      map0[digits[0]].insert(i);
      map04[key04].insert(i);
      map024[key024].insert(i);
      map0134[key0134].insert(i);
      map123[key123].insert(i);
    }
  }

  

  if (map0.find(start) != map0.end()){
    // first line
    for(auto row1: map0[start]){
      for(auto row5: primes){
        int diag1_key = row1 / 10000 * 10000 + row5 % 10;
        int diag2_key = row5 /10000 * 10000 + row1 % 10;        
        if (map04.find(diag1_key) == map04.end()) continue;
        if (map04.find(diag2_key) == map04.end()) continue;
        for(auto diag1: map04[diag1_key]){
          for(auto diag2: map04[diag2_key]){
            if (at(diag1, 3) != at(diag2, 3)) continue;
            int v33 = at(diag1, 3);
            int v22 = at(diag1, 2);
            int v44 = at(diag1, 4);
            int v42 = at(diag2, 2);
            int v24 = at(diag2, 4);
            int key1 = at(row1, 2) * 10000 + v22 * 1000 + v42 * 10 + at(row5, 2);
            int key2 = at(row1, 4) * 10000 + v24 * 1000 + v44 * 10 + at(row5, 4);
            if (map0134.find(key1) == map0134.end()) continue;
            if (map0134.find(key2) == map0134.end()) continue;
            for (auto col2: map0134[key1]) for(auto col4: map0134[key2]){
                int v32 = at(col2, 3);
                int v34 = at(col4, 3);
                int key3 = at(row1, 3) * 10000 + v33 * 100 + at(row5, 3);
                if (map024.find(key3) == map024.end()) continue;
                for (auto col3: map024[key3]){
                  int v23 = at(col3, 2);
                  int v43 = at(col3, 4);
                  int key4 = v22 * 1000 + v23 * 100 + v24 * 10;
                  int key5 = v32 * 1000 + v33 * 100 + v34 * 10;
                  int key6 = v42 * 1000 + v43 * 100 + v44 * 10;
                  if (map123.find(key4) == map123.end()) continue;
                  if (map123.find(key5) == map123.end()) continue;
                  if (map123.find(key6) == map123.end()) continue;
                  for(auto row2: map123[key4]) for(auto row3: map123[key5]) for(auto row4: map123[key6]){
                        int key7 = at(row1, 1) * 10000 + at(row2, 1) * 1000 + at(row3, 1) * 100 + at(row4, 1) * 10 + at(row5, 1);
                        int key8 = at(row1, 5) * 10000 + at(row2, 5) * 1000 + at(row3, 5) * 100 + at(row4, 5) * 10 + at(row5, 5);
                        if (primes.find(key7) == primes.end()) continue;
                        if (primes.find(key8) == primes.end()) continue;
                        // cout << check(row1, row2, row3, row4, row5, total) << endl;
                        ans.PB(to_string(row1) + "\n" + to_string(row2) + "\n" + to_string(row3) + "\n" + to_string(row4) + "\n" + to_string(row5));
                  }
                  
                }
            }
            
          }
        }
      }
    }
  }


  


  if (SIZE(ans) == 0){
    cout << "NONE" << endl;
  } else {
    sort(ALL(ans));
    REP(i, SIZE(ans)){
      if(i) cout << endl;
      cout << ans[i] << endl;
    }
  }

  return 0;
}
