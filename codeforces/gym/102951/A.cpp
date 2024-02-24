#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 100000000;

vector<int> get_list_from_line() {
    string line;
    getline(cin, line);
    vector<int> result;
    int num = 0;
    for (char c : line) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else {
            result.push_back(num);
            num = 0;
        }
    }
    if (num != 0) {
        result.push_back(num);
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    //    cin.ignore(); // Ignore the newline character after reading N
    
    //    vector<int> x_list = get_list_from_line();
    //    vector<int> y_list = get_list_from_line();
    vector<int> x_list;
    vector<int> y_list;
    int num;
    for (int i = 0; i < N; ++i) {
      cin >> num;
      x_list.push_back(num);
    }
    for (int i = 0; i < N; ++i) {
      cin >> num;
      y_list.push_back(num);
    }

    int best = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int w = x_list[i] - x_list[j];
            int h = y_list[i] - y_list[j];
            best = max(best, h * h + w * w);
        }
    }

    cout << best << endl;

    return 0;
}
