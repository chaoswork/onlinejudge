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

typedef struct node{
  node(){
    endpoint = 0;
    REP(i, 26) child[i] = 0;
  }
  node * child[26];
  int endpoint;
} node;
node root = node();

void add_tree(string s){
  node *p = &root;

  FORD(i, SIZE(s) - 1, 0){

    int key = s[i] - 'a';
    if (p->child[key] == 0){
      node *q = new node();
      p->child[key] = q;
      
    }
    p = p->child[key];
  }
  p->endpoint = 1;
}




int main(){
  string tgt;
  VS words;
  LL dp[5001];
  fill_n(dp, 5001, 0);
  dp[0] = 1;


  
  int k;
  cin >> tgt;
  int n = SIZE(tgt);
  cin >> k;
  REP(i, k){
    string s;
    cin >> s;
    if (SIZE(s) <= SIZE(tgt)){
      //words.PB(s);
      add_tree(s);
    }
  }
  FOR(i, 1, n){
    node *p = &root;    
    FORD(j, i  - 1, 0){
      // match trie

      int key = tgt[j] - 'a';
      //      cout << "key=" << key << " " << p->child[key] << endl;
      if (p->child[key]){
        if (p->child[key]->endpoint){
          //          cout << "hit:" << i - j << " " << dp[j] << endl;
          dp[i] += dp[j];
          dp[i] %= 1000000007;
        }
        p = p->child[key];
      } else break;

      
    }
    //    cout << dp[i] << endl;
    /*
    REP(j, k){
      int last = i - SIZE(words[j]);
      if (last >= 0){
        if (words[j] == tgt.substr(last, SIZE(words[j]))){
          dp[i] += dp[last];
          dp[i] %= 1000000007;
        }
          
      }
      }*/
    // cout << dp[i] << endl;
  }
  cout << dp[n] << endl;
  
}
