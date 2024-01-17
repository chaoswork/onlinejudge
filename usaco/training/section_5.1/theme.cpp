/*
ID: huangch7
LANG: C++
TASK: theme
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int INF = 100000000;

int kmpGetNext(int b[], string p) {
    int i = 0;
    int j = -1;
    b[i] = j;
    while (i < p.size()) {
        while (j >= 0 && p[i] != p[j]) {
            j = b[j];
        }
        i++;
        j++;
        b[i] = j;
    }
    return b[p.size()];
}

void kmpSearch(int b[], string t, string p, int ans[], int& best) {
    int i = 0;
    int j = 0;
    while (i < t.size()) {
        while (j >= 0 && t[i] != p[j]) {
            j = b[j];
        }
        i++;
        j++;
        best = max(best, j);
        if (j == p.size()) {
            ans[++ans[0]] = i - j;
            j = b[j];
        }
    }
}

int main() {
    ifstream fin("theme.in");
    ofstream fout("theme.out");

    int N;
    fin >> N;
    if (N == 1) {
        fout << "0\n";
    } else if (N < 4) {
        fout << "1\n";
    } else {
        int seqs[10000];
        int seqsIndex = 0;
        while (true) {
            int part;
            fin >> part;
            if (fin.eof()) break;
            seqs[seqsIndex++] = part;
        }

        int diff[10000];
        for (int i = 1; i < seqsIndex; ++i) {
            diff[i - 1] = seqs[i] - seqs[i - 1];
        }

        int best = 0;
        for (int i = 1; i < seqsIndex - 2; ++i) {
            int b[10000];
            memset(b, 0, sizeof(b));
            int ans[10000] = {0};
            kmpGetNext(b, string(diff + i + 1, diff + seqsIndex - 1));
            int cur = 0;
            kmpSearch(b, string(diff, diff + i), string(diff + i + 1, diff + seqsIndex - 1), ans, cur);
            best = max(cur, best);
        }
        best = best + 1;
        if (best < 5) {
            best = 0;
        }
        fout << best << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
