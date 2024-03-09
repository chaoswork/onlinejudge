/*
ID: huangch7
LANG: C++
TASK: vans
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;


// *|#
// _|   -> f(n - 1)
// *|#

// *_|#
// *_|  -> f(n - 2)
// **|#

// *_|#
// **|# -> f(n - 2) - f(n - 3)
// *_|#

// **|#
// *_|  -> f(n - 2)
// *_|#

// **|##
// *_|__  -> 1
// **|##

// *_|#
// **|# -> 0
// **|

// f(n) = f(n-1) + 3f(n-2) - f(n-3) + 1

// f(1) = 0
// f(2) = 1
// f(3) = 2
// f(4) = 6
// f(5) =

int ans[1024];

int main() {
    ifstream fin("cowxor.in");
    ofstream fout("cowxor.out");

    int N;
    fin >> N;

    memset(ans, 0, sizeof(ans));

    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 2;
    
    for (int i = 4; i < N + 1; ++i){
      ans[i] = ans[i - 1] + 3 * ans[i - 2] - ans[i - 3] + 1;
    }
    fout << ans[N] * 2 << endl;
    
    
    
}
