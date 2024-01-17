/*
ID: huangch7
LANG: C++
TASK: buylow
*/  
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int INF = 100000000;
const int BIGINT_LEN = 100;

class bigint {
  public:
  int *value = new int[BIGINT_LEN];
  int length;

    bigint() {
      for (int i = 0; i < BIGINT_LEN; ++i){
        value[i] = 0;
      }
      length = 0;
    }
  bigint(int x){
    for (int i = 0; i < BIGINT_LEN; ++i){
      value[i] = 0;
    }
    length = 0;
    while (x){
      value[length] = x % 10;
      x = x / 10;
      length += 1;
    }

  }
 void add(bigint b) {
   int max_length = max(length, b.length);
   int carry = 0;
   for (int i = 0; i < max_length; ++i){
     value[i] += b.value[i] + carry;
     if (value[i] >= 10){
       value[i] = value[i] % 10;
       carry = 1;
     }
     else{
       carry = 0;
     }
   }
   
   if (carry) {
     value[max_length] = 1;
   }
   length = max_length + carry;
 }
  string to_str(){
    string res = "";
    for (int i = length - 1; i >= 0; --i){
      res += to_string(value[i]);
    }
    return res;
  }
};


int main() {
    ifstream fin("buylow.in");
    ofstream fout("buylow.out");

    int N;
    fin >> N;

    int stock[5010];
    for (int i = 0; i < N; ++i) {
        fin >> stock[i];

    }

    int dp[5000];
    bigint *path = new bigint[5000];
    //    int path_int[5000];
    int best = 0;

    for (int i = 0; i < N; ++i) {
        dp[i] = 1;
        path[i] = bigint(1);
        //        path_int[i] = 1;
    }

    for (int i = 0; i < N; ++i) {
        unordered_map<int, int> cands;
        //        unordered_map<int, int> cands_int;
        for (int j = 0; j < i; ++j) {
            if (stock[i] < stock[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cands.clear();
                    cands[stock[j]] = j;
                    //                    cands_int[stock[j]] = path_int[j];
                } else if (dp[j] + 1 == dp[i]) {
                    cands[stock[j]] = j;
                    //          cands_int[stock[j]] = path_int[j];
                }
            }
        }
        // path[i] = max(1, accumulate(cands.begin(), cands.end(), 0, [](int sum, auto &p) { return sum + p.second; }));
        if (cands.size()){
          path[i] = bigint(0);
          for (auto it = cands.begin(); it != cands.end(); ++it){
            path[i].add(path[it->second]);
          }
          //          path_int[i] = 0;
          //          for (auto it = cands_int.begin(); it != cands_int.end(); ++it){
          //            path_int[i] += it->second;
          //          }
        }
        // if (stoi(path[i].to_str()) != path_int[i]){
        //  cout << i << " " << path[i].to_str() << " " << path_int[i] << endl;
        //}


        if (best < dp[i]) {
            best = dp[i];
        }
        //        cout << i << " " << stock[i] << " " << dp[i] << " " << path[i].to_str() << endl;

    }

    unordered_map<int, int> cands;
    for (int i = 0; i < N; ++i) {
        if (best == dp[i]) {
            cands[stock[i]] = i;
        }
    }

    bigint best_n = bigint(0);
    //    int best_nn = 0;
    // accumulate(cands.begin(), cands.end(), 0, [](int sum, auto &p) { return sum + p.second; });
    for (auto it = cands.begin(); it != cands.end(); ++it){
      best_n.add(path[it->second]);
      //      best_nn += path_int[it->second];
    }
    //    cout << best_nn << endl;
    fout << best << " " << best_n.to_str() << endl;
    
    fout.close();
    delete []path;
    return 0;
}
