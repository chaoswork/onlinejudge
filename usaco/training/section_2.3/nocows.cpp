/* 
ID: huangch7
LANG:C++
TASK: nocows
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include<sstream>
#include<cstdio>
#include <cmath>


using namespace std;



const int MOD = 9901;

int N, K;
int nocows[210][110];
int limit[8];

//std::memset(nocows, -1, sizeof(nocows));

int dfs_dp(int n, int k) {
  if ((n & 1) == 0) {
    return 0;
  }
  if (nocows[n][k] >= 0) {
    return nocows[n][k];
  }
  //  if (!(int(log2(n + 1)) <= k <= (n + 1) / 2)) {
  // 1 -> 1, 3 -> 1, 5 -> 2, 7 -> 2, 9 -> 3, 15 -> 3, 17 -> 4
  //  if (!(((n + 1) <= (1 << k)) && (k <= (n + 1) / 2))) {
  if (2 * k > n + 1) {
    nocows[n][k] = 0;
    return 0;
  }
  //if ((int(log2(n + 1)) <= k) != (n + 1 <= (1 << k))) {
  //  cout << n << " " << k <<endl;
  //  cout << int(log2(n + 1)) << " " << k <<endl;
  //  cout << n + 1 << " " << (1 << k) <<endl;
  //}
  //if (!(int(log2(n + 1)) <= k)){
  if(k < 8 && !(n + 1 <= (limit[k]))){
    nocows[n][k] = 0;
    return 0;
  }
  if ((n == 1) && (k == 1)) {
    return 1;
  }
  int count = 0;
  for (int i = 1; i < n; i += 2) {
    // 之前是两层循环, 过不了
    //for (int k1 = 1; k1 < k - 1; k1++) {
    //  for (int k2 = 1; k2 < k - 1; k2++) {
    //    if (max(k1, k2) != k - 1){
    //      continue;
    //    }
    //  }
    //}
    
    for (int k1 = 1; k1 < k - 1; k1++) {
        if (i < n - i - 1) {
          count += (dfs_dp(i, k1) * dfs_dp(n - i - 1, k - 1) * 2) % MOD;
        } else if (i == n - i - 1) {
          count += (dfs_dp(i, k1) * dfs_dp(n - i - 1, k - 1)) % MOD;
        }
    }
      
      for (int k2 = 1; k2 < k - 1; k2++) {
        if (i < n - i - 1) {
          count += (dfs_dp(i, k - 1) * dfs_dp(n - i - 1, k2) * 2) % MOD;
        } else if (i == n - i - 1) {
          count += (dfs_dp(i, k - 1) * dfs_dp(n - i - 1, k2)) % MOD;
        }
      }
        if (i < n - i - 1) {
          count += (dfs_dp(i, k - 1) * dfs_dp(n - i - 1, k - 1) * 2) % MOD;
        } else if (i == n - i - 1) {
          count += (dfs_dp(i, k - 1) * dfs_dp(n - i - 1, k - 1)) % MOD;
        }
      
      //}
  }
  nocows[n][k] = count % MOD;
  return nocows[n][k];
}

int main() {
  freopen("nocows.in","r",stdin);
  freopen("nocows.out","w",stdout);
  for(int i = 0; i < 210; i++){
    for(int j = 0; j < 110; j++){
      nocows[i][j] = -1;
    }
  }
  for(int i = 0; i < 8; i++){
    limit[i] = 1 << i;
  }
  
  cin >> N >> K;
  cout << dfs_dp(N, K) << endl;
  return 0;
}
