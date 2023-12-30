/*
ID: huangch7
LANG: C++
TASK: bigbrn
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("bigbrn.in");
    ofstream fout("bigbrn.out");

    int N, T;
    fin >> N >> T;

    vector<vector<int>> dp(N, vector<int>(N, 1)); // Initialize with 1s
    vector<pair<int, int>> barns;
    
    for (int i = 0; i < T; ++i) {
        int x, y;
        fin >> x >> y;
        barns.push_back({x - 1, y - 1}); // Adjust indices to 0-based
        dp[x - 1][y - 1] = 0;
    }

    int best = 0;
    for (int i = 0; i < N; ++i) {
        best = max(dp[i][0], best);
        best = max(dp[0][i], best);
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            if (dp[i][j] == 0) continue;
            if (dp[i - 1][j] == 0) continue;
            if (dp[i][j - 1] == 0) continue;
            
            int n = min(dp[i][j - 1], dp[i - 1][j]);
            if (dp[i - n][j - n]) {
                dp[i][j] = max(n + 1, dp[i][j]);
            }
            else{
              dp[i][j] = max(n, dp[i][j]);
            }

            if (best < dp[i][j]) {
                best = dp[i][j];
            }
        }
    }

    fout << best << endl;

    fin.close();
    fout.close();

    return 0;
}
