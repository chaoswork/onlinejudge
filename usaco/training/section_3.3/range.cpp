/*
ID: huangch7
LANG: C++
TASK: range
*/


#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("range.in");
    ofstream fout("range.out");

    int N;
    fin >> N;

    int right_attach[N][N], down_attach[N][N];
    string square[N];

    for (int i = 0; i < N; ++i) {
        fin >> square[i];
    }

    // Initialize right_attach and down_attach arrays
    for (int i = 0; i < N; ++i) {
        right_attach[i][N - 1] = square[i][N - 1] - '0';
        for (int j = N - 2; j >= 0; --j) {
            if (square[i][j] == '0') {
                right_attach[i][j] = 0;
            } else {
                right_attach[i][j] = 1 + right_attach[i][j + 1];
            }
        }
    }

    for (int j = 0; j < N; ++j) {
        down_attach[N - 1][j] = square[N - 1][j] - '0';
        for (int i = N - 2; i >= 0; --i) {
            if (square[i][j] == '0') {
                down_attach[i][j] = 0;
            } else {
                down_attach[i][j] = 1 + down_attach[i + 1][j];
            }
        }
    }

    int ans[N + 1];
    fill_n(ans, N + 1, 0);
    // for(int i= 0; i < N + 1; ++i){
    //   cout << ans[i] << " " << endl;
    //}

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int v = min(right_attach[i][j], down_attach[i][j]);
            if (v < 2) {
                continue;
            }
            for (int k = 1; k < N; ++k) {
                if (j + k >= N || i + k >= N) {
                    break;
                }
                v = min(min(v, down_attach[i][j + k]), right_attach[i + k][j]);
                if (v < k + 1) {
                    break;
                }
                ans[k + 1]++;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (ans[i] != 0) {
            fout << i << " " << ans[i] << "\n";
        }
    }

    fout.close();
    return 0;
}
