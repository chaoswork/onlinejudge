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


#pragma GCC optimize("O3,unroll-loops,Ofast")
//#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define sp << " " << 
#define vi vector<int>
const int N = 5e5+100,inf = 1e9,MOD = 998244353;
 
vi pi(string s) {
    int n = (int)s.length();
    vi pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
 
void solve() {
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    string ss = t+"$"+s;
    vi p = pi(ss);
    vi ans;
    for (int i=m-1;i<=n;i++) if (p[m+i] == m) ans.push_back(i-m+1);
    cout << ans.size() << '\n';
}
                 
                             
signed main() { 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef Dodi
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t = 1;
    //cin >> t; 
    while (t --> 0) solve();
}
/*
VI pi(string s) {
    int n = (int)s.length();
    VI pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
        cout << s[i] << " " << pi[i]  << endl;
    }
    return pi;
}

int main(){

  

  string s = "12345$23";
  pi(s);
  
  return 0;
}
*/
