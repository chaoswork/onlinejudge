/*
ID: huangch7
LANG: C++
TASK: humble
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("humble.in");
    ofstream fout("humble.out");

    int K, N;
    fin >> K >> N;

    vector<int> primes(K);
    for (int i = 0; i < K; ++i) {
        fin >> primes[i];
    }
    sort(primes.begin(), primes.end());

    vector<int> primes_index(K, 0);
    vector<int> ans;
    ans.push_back(1);

    for (int j = 0; j < N; ++j) {
        int min_value = -1;
        int min_index = -1;

        for (int i = 0; i < K; ++i) {
            while (ans[primes_index[i]] * primes[i] <= ans.back()) {
                primes_index[i]++;
            }

            int num = ans[primes_index[i]] * primes[i];
            if (min_value == -1 || min_value > num) {
                min_value = num;
                min_index = i;
            }
        }
        ans.push_back(min_value);
        primes_index[min_index]++;
    }

    fout << ans.back() << endl;
    fout.close();
    return 0;
}
