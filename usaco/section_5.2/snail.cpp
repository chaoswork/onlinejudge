/*
ID: huangch7
LANG: C++
TASK: snail
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int INF = 100000000;

int N, B;
set<pair<int, int> > barriers;
vector<vector<int> > visited;

int direction_map[][2] = {
    {0, 1},   // >
    {1, 0},   // V
    {0, -1},  // <
    {-1, 0}   // ^
};

void displayVisited() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << visited[i][j];
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

int move(int row, int col, int direction) {
    int total = 0;
    vector<pair<int, int>> buffer;
    int cur_steps = 0;
    bool is_end = false;
    vector<int> cur = {row, col};

    while (true) {
        cur[0] += direction_map[direction][0];
        cur[1] += direction_map[direction][1];

        if (barriers.count(make_pair(cur[0], cur[1])) || cur[0] < 0 || cur[0] >= N || cur[1] < 0 || cur[1] >= N) {
            break;
        }

        if (visited[cur[0]][cur[1]]) {
            is_end = true;
            break;
        }

        visited[cur[0]][cur[1]] = 1;
        cur_steps++;
        buffer.emplace_back(make_pair(cur[0], cur[1]));
    }

    cur[0] -= direction_map[direction][0];
    cur[1] -= direction_map[direction][1];

    if (!is_end && (cur[0] != row || cur[1] != col)) {
        cur_steps += max(move(cur[0], cur[1], (direction + 1) % 4), move(cur[0], cur[1], (direction + 3) % 4));
    }

    for (const auto& pos : buffer) {
        visited[pos.first][pos.second] = 0;
    }

    return cur_steps;
}

int main() {
    ifstream fin("snail.in");
    ofstream fout("snail.out");

    fin >> N >> B;
    visited.resize(N, vector<int>(N, 0));

    for (int i = 0; i < B; ++i) {
        char c;
        int row;
        fin >> c >> row;
        int col = c - 'A';
        barriers.emplace(make_pair(row - 1, col));
    }

    visited[0][0] = 1;
    int best = move(0, 0, 0);
    best = max(move(0, 0, 1), best);

    fout << best + 1 << endl;

    fin.close();
    fout.close();

    return 0;
}
