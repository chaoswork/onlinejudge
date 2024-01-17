/*
ID: huangch7
LANG: C++
TASK: picture
*/  


#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("picture.in");
ofstream fout("picture.out");

const int INF = 100000000;

struct Rect {
    int x1, y1, x2, y2;
};

struct Info {
    int value;
    int type;
    int start;
    int end;
};

int N;
Rect coods[5100];

void get_list_from_line(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        fin >> arr[i];
    }
}

void readInput() {
    fin >> N;
    for (int i = 0; i < N; ++i) {
        int rect[4];
        get_list_from_line(rect, 4);
        coods[i] = {rect[0], rect[1], rect[2], rect[3]};
    }
}

bool compareInfo(const Info &a, const Info &b) {
    if (a.value == b.value) {
        return a.type < b.type;
    }
    return a.value < b.value;
}

int main() {
    readInput();

    int visited_pos[20010] = {0};  // Initialized to zero
    int *visited = visited_pos + 10000;

    Info v_coods[20010];
    Info h_coods[20010];
    int v_count = 0, h_count = 0;

    for (int i = 0; i < N; ++i) {
        v_coods[v_count++] = {coods[i].x1, 0, coods[i].y1, coods[i].y2};
        v_coods[v_count++] = {coods[i].x2, 1, coods[i].y1, coods[i].y2};
        h_coods[h_count++] = {coods[i].y1, 0, coods[i].x1, coods[i].x2};
        h_coods[h_count++] = {coods[i].y2, 1, coods[i].x1, coods[i].x2};
    }

    sort(v_coods, v_coods + v_count, compareInfo);
    sort(h_coods, h_coods + h_count, compareInfo);

    int ans = 0;

    for (int i = 0; i < v_count; ++i) {
        for (int j = v_coods[i].start; j < v_coods[i].end; ++j) {
            if (v_coods[i].type == 0) {
                if (visited[j] == 0) {
                    ++ans;
                }
                ++visited[j];
            } else {
                --visited[j];
                if (visited[j] == 0) {
                    ++ans;
                }
            }
        }
    }

    for (int i = 0; i < h_count; ++i) {
        for (int j = h_coods[i].start; j < h_coods[i].end; ++j) {
            if (h_coods[i].type == 0) {
                if (visited[j] == 0) {
                    ++ans;
                }
                ++visited[j];
            } else {
                --visited[j];
                if (visited[j] == 0) {
                    ++ans;
                }
            }
        }
    }

    fout << ans << "\n";

    fin.close();
    fout.close();

    return 0;
}
