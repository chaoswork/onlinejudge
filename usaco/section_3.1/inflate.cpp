/*
ID: huangch7
LANG: C++
TASK: inflate
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");

    int M, N;
    fin >> M >> N;

    vector<pair<int, int> > info(N);

    for (int i = 0; i < N; ++i) {
        int point, time;
        fin >> point >> time;
        info[i] = make_pair(point, time);
    }

    // dp[v] 表示容量为v能的到的最大分
    vector<int> dp(M + 1, 0);

    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < N; ++j) {
            int prev = i - info[j].second;
            if (prev >= 0) {
                dp[i] = max(dp[i], dp[prev] + info[j].first);
            }
        }
    }

    fout << dp[M] << endl;
    fout.close();

    return 0;
}
