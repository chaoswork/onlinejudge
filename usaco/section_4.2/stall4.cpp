/*
ID: huangch7
LANG: C++
TASK: stall4
*/
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

const int INF = 100000000;

int main() {
    ifstream fin("stall4.in");
    ofstream fout("stall4.out");

    int N, M;
    fin >> N >> M;
    unordered_map<int, unordered_map<int, int> > adj;

    for (int i = 1; i <= N; ++i) {
        adj[0][i] = 1;
        int num;
        fin >> num;
        for (int j = 0; j < num; ++j) {
            int stall;
            fin >> stall;
            adj[i][stall + N] = 1;
        }
    }

    for (int j = N + 1; j <= N + M; ++j) {
        adj[j][N + M + 1] = 1;
    }

    int total_flow = 0;
    int start = 0;
    int end = N + M + 1;
    int total_node = N + M + 2;

    while (true) {
        int visited[410] = {0};
        int prev[410];
        int flow[410] = {0};
        flow[start] = INF;

        while (true) {
            int max_flow = 0;
            int max_loc = -1;
            for (int i = 0; i < total_node; ++i) {
                if (visited[i]) continue;
                if (max_flow < flow[i]) {
                    max_flow = flow[i];
                    max_loc = i;
                }
            }
            if (max_loc == -1) break;
            if (max_loc == end) break;
            visited[max_loc] = 1;

            for (auto &i : adj[max_loc]) {
                if (flow[i.first] < min(max_flow, adj[max_loc][i.first])) {
                    flow[i.first] = min(max_flow, adj[max_loc][i.first]);
                    prev[i.first] = max_loc;
                }
            }
        }

        if (flow[end] == 0) break;
        total_flow += flow[end];
        int cur = end;
        while (cur != 0) {
            adj[prev[cur]][cur] -= flow[end];
            adj[cur][prev[cur]] += flow[end];
            cur = prev[cur];
        }
    }

    fout << total_flow << endl;
    fout.close();
    return 0;
}
