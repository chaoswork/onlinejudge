/*
ID: huangch7
LANG: C++
TASK: shopping
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_S = 1000;
const int MAX_B = 5;
const int MAX_C = 6;
// const int INF = 1e9;

int special_offers[MAX_S][MAX_C];
int prices[MAX_B];
int needs[MAX_B];
unordered_map<int, int> id_map;
unordered_map<int, int> res;

int get_id(int c) {
    if (id_map.find(c) == id_map.end()) {
        id_map[c] = id_map.size();
    }
    return id_map[c];
}

int merge(int alist[MAX_B]) {
    int res = 0;
    for (int i = 0; i < MAX_B; ++i) {
        res *= 10;
        res += alist[i];
    }
    return res;
}

void split(int x, int res[MAX_B]) {
  fill(res, res + MAX_B, 0);
    int p = MAX_B - 1;
    while (x) {
        res[p] = x % 10;
        x /= 10;
        p--;
    }
}

int dp(int target_list[MAX_B], int S) {
    int target_num = merge(target_list);
    if (target_num == 0) {
        return 0;
    }
    if (res.find(target_num) != res.end()) {
        return res[target_num];
    }
    int best = 0;
    for (int i = 0; i < MAX_B; ++i) {
        best += target_list[i] * prices[i];
    }
    for (int i = 0; i < S; ++i) {
        int left[MAX_B] = {0};
        bool valid = true;
        for (int j = 0; j < MAX_B; ++j) {
            left[j] = target_list[j] - special_offers[i][j];
            if (left[j] < 0) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            continue;
        }
        best = min(best, dp(left, S) + special_offers[i][MAX_C - 1]);
    }
    res[target_num] = best;
    return best;
}

int main() {
    ifstream fin("shopping.in");
    ofstream fout("shopping.out");

    int S, B;
    fin >> S;
    for (int i = 0; i < S; ++i) {
        int n, p;
        fin >> n;
        for (int j = 0; j < n; ++j) {
            int c, k;
            fin >> c >> k;
            special_offers[i][get_id(c)] = k;
        }
        fin >> p;
        special_offers[i][MAX_C - 1] = p;
    }

    fill(prices, prices + MAX_B, 0);
    fill(needs, needs + MAX_B, 0);

    fin >> B;
    for (int i = 0; i < B; ++i) {
        int c, k, p;
        fin >> c >> k >> p;
        prices[get_id(c)] = p;
        needs[get_id(c)] = k;
    }
    // for (int i = 0; i < MAX_B; ++i){
    //   cout<< prices[i] << " ";
    // }
    // cout <<endl;
    // for (int i = 0; i < MAX_B; ++i){
    //   cout<< needs[i] << " ";
    // }
    // cout <<endl;
    // for (int i = 0; i < S; ++i){
    //   for (int j = 0; j < MAX_C; ++j){
    //     cout<< special_offers[i][j] << " ";
    //   }
    // cout <<endl;      
    // }


    fout << dp(needs, S) << "\n";

    fin.close();
    fout.close();

    return 0;
}
