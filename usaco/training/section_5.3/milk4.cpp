/*
ID: huangch7
LANG: C++
TASK: milk4
*/

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0R1(i, a) for (int i=1; i<=(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i=a; i>0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())

#define INF 1000000010
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define pA first
#define pB second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define ll long long
#define MOD (int)(2e+9+11)
#define SET(vec, val, size) for (int i = 0; i < size; i++) vec[i] = val;
#define SET2D(arr, val, dim1, dim2) F0R(i, dim1) F0R(j, dim2) arr[i][j] = val;
#define SET3D(arr, val, dim1, dim2, dim3) F0R(i, dim1) F0R(j, dim2) F0R(k, dim3) arr[i][j][k] = val;
#define READGRID(arr, dim) F0R(i, dim) F0R(j, dim) cin >> arr[i][j];
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<ii> vii;
typedef vector<ll> vl;

int Q, N;
int buckets[101];
set<int> comb[20001];
int ans[20001];

void updateComb(int x, int y) {
    if (ans[x + y] == -1) {
        comb[x + y] = comb[x];
        comb[x + y].insert(buckets[y]);
        ans[x + y] = ans[x] + 1;
    } else {
        set<int> new_comb = comb[x];
        new_comb.insert(buckets[y]);
        if (new_comb.size() < comb[x + y].size() || (new_comb.size() == comb[x + y].size() && new_comb < comb[x + y])) {
            comb[x + y] = new_comb;
            ans[x + y] = ans[x] + 1;
        }
    }
}

int main() {
    ifstream fin("milk4.in");
    ofstream fout("milk4.out");

    fin >> Q >> N;
    for (int i = 0; i < N; ++i) {
        fin >> buckets[i];
    }
    
    memset(ans, -1, sizeof(ans));
    si one_ans;
    F0R(i, N){
      int cur = buckets[i];
      while (cur <= Q){
        ans[cur] = 1;
        one_ans.insert(cur);
        if (comb[cur].size() == 0){
          comb[cur].insert(buckets[i]);
        }
        cur += buckets[i];
      }
    }
    si cands;
    int cnt = 2;
    cands.insert(one_ans.begin(), one_ans.end());
    while (ans[Q] == -1){
      si new_cands;
      for (auto itx=one_ans.begin(); itx != one_ans.end(); ++itx){
        for (auto ity=cands.begin(); ity != cands.end(); ++ity){
          int x = *itx;
          int y = *ity;
          if (x + y > Q) continue;
          if (ans[x + y] == -1){
            new_cands.insert(x + y);
            ans[x + y] = cnt;
            comb[x + y].insert(comb[x].begin(), comb[x].end());
            comb[x + y].insert(comb[y].begin(), comb[y].end());
          }
          else {
            if (ans[x + y] == cnt){
              si new_comb;
              new_comb.insert(comb[x].begin(), comb[x].end());
              new_comb.insert(comb[y].begin(), comb[y].end());
              if(comb[x + y] > new_comb){
                comb[x + y] = new_comb;
              }
              
            }
          }
        }

      }
        cnt += 1;
        cands = new_cands;
    }

    fout << ans[Q];
    for (int x : comb[Q]) {
        fout << " " << x;
    }
    fout << endl;

    fin.close();
    fout.close();

    return 0;
}
