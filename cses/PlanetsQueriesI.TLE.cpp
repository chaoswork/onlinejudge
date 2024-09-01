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


struct Graph{
  int N;
  vector<vector<int> > adj;
  vector<unordered_map<int, int> > index;
  VVI seqs;
  VI prefix;



  void init(int n){
    N = n;
    adj = vector<vector<int> >(n, vector<int>());
    seqs = vector<vector<int> >(n, vector<int>());    
    prefix = vector<int>(n, -1);
    index = vector<unordered_map<int, int> > (n, unordered_map<int, int>());
    
  }

  void add_edge(int a, int b){
    adj[a].push_back(b);
  }

  int forward(int x, int k){
    // cout << "iter " << x << " " << k << endl;
    // DISP_VEC(seqs[x]);
    // DISP_VEC(prefix);
    if (prefix[x] != -1){
      return seqs[x][prefix[x] + (k - prefix[x]) % (SIZE(seqs[x]) - prefix[x])];
    }
    if (k < SIZE(seqs[x])){
      return seqs[x][k];
    }

    if (SIZE(seqs[x]) == 0){
      seqs[x].PB(x);
      index[x][x] = 0;
    }
    int kk = SIZE(seqs[x]) - 1;
    int y = seqs[x][kk];
    while (kk < k){
      kk++;
      y = adj[y][0];
      if (index[x].find(y) != index[x].end()){
        prefix[x] = index[x][y];
        break;
      }
      seqs[x].PB(y);
      
    }
    // DISP_VEC(seqs[x]);
    // DISP_VEC(prefix);
    if (prefix[x] != -1){
      return seqs[x][prefix[x] + (k - prefix[x]) % (SIZE(seqs[x]) - prefix[x])];
    }
    return y;
    
  }


};

int main(){
  optimize;
  int n, m, a, b;
  cin >> n >> m;
  Graph g;
  g.init(n);
  REP(i, n){
    cin >> a;
    g.add_edge(i, a - 1);
    // DISP_VEC(g.adj[i]);
  }
  REP(i, m){
    cin >> a >> b;
    cout << g.forward(a - 1, b) + 1 << endl;
  }

  return 0;
}
