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
#include <ctime>
#include <unordered_map>

using namespace std;

template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}

#define MIN_HEAP(type1, type2) priority_queue<pair<type1, type2>, vector<pair<type1, type2> >, greater<pair<type1, type2> > >
#define MAX_HEAP(type) priority_queue<type>
#define ADJ(type1, type2) vector<pair<type1, type2> > 

#define MP(A,B) make_pair(A,B)
#define PB push_back
#define SIZE(X) ((int)(X.size()))
#define REP(i, n) for(int i=0; i<(n); ++i)
#define REPN(n) for(int _=0; _<(n); ++_)
#define FOR(i, l, h) for(int i=(l); i<=(h); ++i)
#define FORD(i, h, l) for(int i=(h); i>=(l);--i)
#define ALL(A) A.begin(),A.end()
#define MATRIX(n, m, v) vector<vector<int> >((n), vector<int>((m), (v)))
#define DISP_SET(S)   {int iforset = 0;for(auto e: S){if (iforset++) cout << " ";cout << e;} cout << endl;}
#define DISP_PAIR(P)   {cout << P.first << " " << P.second << endl;}
#define DISP_VEC(vec)   REP(i, SIZE(vec)){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_VEC_N(vec, n)   REP(i, n){if (i) cout << " ";cout << vec[i];} cout << endl;
#define DISP_MAT(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1000000007;
const LL INF = 1LL<<62;  //std::numeric_limits<LL>::max();
const int MAXN = 2e5 + 64;


class JumpTree{
private:
  int N;
  int powlen;
  vector<int> par;
  vector<vector<int> > jump_table;
  
public:
  JumpTree(const vector<int> &parent, int max_k){
    N = parent.size();
    powlen = 0;
    while ((1 << powlen) < max(N, max_k)) powlen++;
    // powlen++;
    // cout << powlen << endl;
    jump_table = vector<vector<int> > (N, vector<int>(powlen, -1));

    for (int i = 0; i < N; ++i) jump_table[i][0] = parent[i];
    for (int p = 1; p < powlen; ++p){
      for(int i = 0; i < N; ++i){
        int halfway = jump_table[i][p - 1];
        if (jump_table[halfway][p - 1] != -1)
          jump_table[i][p] = jump_table[halfway][p - 1];
      }
    }
      
  }

  int find_kth_parent(int x, int k){
    int at = x;
    for (int p = 0; p < powlen; ++p){
      if (k & (1 << p)) at = jump_table[at][p];
      if (at == -1) break;
    }
    return at;
  }
  
};


int main(){
  optimize;
  int n, m, a, b;
  cin >> n >> m;

  VI par(n, 0);
  REP(i, n){
    cin >> a;
    // a is i's parent
    par[i] = a - 1;
    // DISP_VEC(g.adj[i]);
  }
  JumpTree tree(par, MOD);
  REP(i, m){
    cin >> a >> b;
    cout << tree.find_kth_parent(a - 1, b) + 1<< '\n';
  }

  return 0;
}
