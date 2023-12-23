/*
ID: huangch7
LANG: C++
TASK: ratios
*/


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("ratios.in");
    ofstream fout("ratios.out");

    int t1, t2, t3;
    fin >> t1 >> t2 >> t3;

    int x1, x2, x3, y1, y2, y3, z1, z2, z3;
    fin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3 >> z1 >> z2 >> z3;

    int best[4];
    fill_n(best, 4, -1);
    bool found = false;

    for (int a = 0; a <= 100; ++a) {
        for (int b = 0; b <= 100; ++b) {
            for (int c = 0; c <= 100; ++c) {
                int p1 = a * x1 + b * y1 + c * z1;
                int p2 = a * x2 + b * y2 + c * z2;
                int p3 = a * x3 + b * y3 + c * z3;

                if (t1 == 0 && p1 != 0) {
                    continue;
                }

                if (p1 % t1 != 0) {
                    continue;
                }

                int d = p1 / t1;

                if (d != 0 && t2 * d == p2 && t3 * d == p3) {
                    if (best[0] < 0 || best[0] + best[1] + best[2] > a + b + c) {
                      best[0] = a;
                      best[1] = b;
                      best[2] = c;
                      best[3] = d;
                        found = true;
                    }
                }
            }
        }
    }

    if (!found) {
        fout << "NONE" << endl;
    } else {
        for (int i = 0; i < 4; ++i) {
            fout << best[i];
            if (i != 3) {
                fout << " ";
            }
        }
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
