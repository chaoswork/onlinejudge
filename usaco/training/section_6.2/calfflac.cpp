/*
ID: huangch7
LANG: C++
TASK: calfflac
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("calfflac.in");
ofstream fout("calfflac.out");

string s;

bool is_alpha(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

int main() {
    string line;
    while (getline(fin, line)) {
        s += line + '\n';
    }

    int best_n = 0;
    int best_left = -1;
    int best_right = -1;

    for (int i = 0; i < s.length(); ++i) {
        int left = i, right = i;
        if (!is_alpha(s[left]) || !is_alpha(s[right])) {
            continue;
        }
        int n = 0;
        while (left >= 0 && right < s.length() && tolower(s[left]) == tolower(s[right])) {
            int length = 2 * n + 1;
            if (best_n < length) {
                best_n = length;
                best_left = left;
                best_right = right;
            }
            ++n;
            --left;
            ++right;
            while (left >= 0 && !is_alpha(s[left])) {
                --left;
            }
            while (right < s.length() && !is_alpha(s[right])) {
                ++right;
            }
        }
    }

    for (int i = 0; i < s.length() - 1; ++i) {
        int left = i;
        if (!is_alpha(s[left])) {
            continue;
        }
        int right = i + 1;
        while (right < s.length() && !is_alpha(s[right])) {
            ++right;
        }
        if (right == s.length()) {
            continue;
        }
        int n = 1;
        while (left >= 0 && right < s.length() && tolower(s[left]) == tolower(s[right])) {
          int length = 2 * n;
            if (best_n < length) {
                best_n = length;
                best_left = left;
                best_right = right;
            }
            ++n;
            --left;
            ++right;
            while (left >= 0 && !is_alpha(s[left])) {
                --left;
            }
            while (right < s.length() && !is_alpha(s[right])) {
                ++right;
            }
        }
    }

    fout << best_n << endl;
    fout << s.substr(best_left, best_right - best_left + 1) << endl;

    return 0;
}
