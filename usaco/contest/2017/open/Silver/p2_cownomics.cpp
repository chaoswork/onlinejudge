#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

const int INF = 100000000;

vector<string> get_strs_from_line(istream &fin) {
    string line;
    getline(fin, line);
    vector<string> result;
    size_t pos = 0, next_pos;
    while ((next_pos = line.find(' ', pos)) != string::npos) {
        result.push_back(line.substr(pos, next_pos - pos));
        pos = next_pos + 1;
    }
    result.push_back(line.substr(pos));
    return result;
}

int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");

    int N, M;
    fin >> N >> M;
    fin.ignore(); // Ignore the newline character after reading M

    vector<string> spot(N), plain(N);
    for (int i = 0; i < N; ++i) {
      fin >> spot[i]; //get_strs_from_line(fin)[0];
    }
    for (int i = 0; i < N; ++i) {
      fin >> plain[i]; // = get_strs_from_line(fin)[0];
    }

    int ans = 0;

    for (int k = 0; k < M; ++k) {
        for (int p = k + 1; p < M; ++p) {
            for (int j = p + 1; j < M; ++j) {
                unordered_set<string> spot_set, plain_set;
                for (int i = 0; i < N; ++i) {
                  string s_spot = string(1, spot[i][j]) + string(1, spot[i][p]) + string(1, spot[i][k]);
                  string s_plain = string(1, plain[i][j]) + string(1, plain[i][p]) + string(1, plain[i][k]);
                  spot_set.insert(s_spot);
                    plain_set.insert(s_plain);
                }
                int found = 0;
                if (spot_set.size() < plain_set.size()){
                    for (string x: spot_set){
                      if (plain_set.find(x) != plain_set.end()){
                        found = 1;
                    }
                 }
                }
                else {
                    for (string x: plain_set){
                      if (spot_set.find(x) != spot_set.end()){
                        found = 1;
                    }
                 }
                }

                    if (found == 0) ++ans;
            }
        }
    }

    fout << ans << endl;

    return 0;
}
