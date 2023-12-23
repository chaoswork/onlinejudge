/*
ID: huangch7
LANG: C++
TASK: stamps
*/

#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");

    int K, N;
    fin >> K >> N;

    vector<int> coins;
    vector<int> dp(2000010, numeric_limits<int>::max());
    dp[0] = 0;

    int coinValue;
    while (coins.size() < N) {
        fin >> coinValue;
        coins.push_back(coinValue);
    }

    int ans = 0;
    for (int i = 1; i < dp.size(); ++i) {
        int best = numeric_limits<int>::max();
        
        for (int j = 0; j < coins.size(); ++j) {
            int prev = i - coins[j];
            if (prev >= 0 && dp[prev] != numeric_limits<int>::max() && dp[prev] <= K - 1) {
                best = min(best, dp[prev] + 1);
            }
        }

        if (best == numeric_limits<int>::max()) {
            ans = i - 1;
            break;
        }
        dp[i] = best;
    }

    fout << ans << endl;
    fout.close();

    return 0;
}
