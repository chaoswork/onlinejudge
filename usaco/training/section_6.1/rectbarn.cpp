/*
ID: huangch7
LANG: C++
TASK: rectbarn
*/

#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int MAX_R = 3000;
const int MAX_C = 3000;
const int INF = 100000000;

ifstream fin("rectbarn.in");
ofstream fout("rectbarn.out");

int R, C, P;

// int field[MAX_R + 1][MAX_C + 1];
// int height[MAX_R + 1][MAX_C + 2];

int get_int() {
    string line;
    getline(fin, line);
    return stoi(line);
}

int main() {
  int R, C, P;
  fin >> R >> C >> P;

  //  int** field = new int*[R + 1];
  //  int** height = new int*[R + 1];
  int** height = new int*[2];  
  for (int i = 0; i < 2; ++i) {
    //    field[i] = new int[C + 2];
    height[i] = new int[C + 2];
  }  
  /*
    for (int i = 0; i <= R; ++i) {
        for (int j = 0; j <= C; ++j) {
            field[i][j] = 0;
        }
    }

    for (int i = 0; i < P; ++i) {
      int x, y;
      fin >> x >> y;
        field[x][y] = 1;
    }
  */
  unordered_set<int> dmg;
  for (int i = 0; i < P; ++i) {
    int x, y;
    fin >> x >> y;
    dmg.insert(x * 5000 + y);
  }
  /*    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= C; ++j) {
            height[i][j] = 1;
        }
    }
  */
    int best = 0;
    for (int i = 1; i <= R; ++i) {
      for(int j = 0; j <= C; ++j){
        height[i % 2][j] = 1;
      }
      height[i % 2][C + 1] = 0;      
        for (int j = 1; j <= C; ++j) {
          //            if (field[i][j] == 1) {
          if (dmg.find(i * 5000 + j) != dmg.end()){
            height[i % 2][j] = 0;
          } else if (i > 1) {
            height[i % 2][j] = height[(i - 1) % 2][j] + 1;
          }
        }

        //    }


        //    for (int i = 1; i <= R; ++i) {
        stack<pair<int, int> > st;
        for (int j = 1; j <= C + 1; ++j) {
            int idx = -1, h = -1;
            while (!st.empty() && st.top().second > height[i % 2][j]) {
                idx = st.top().first;
                h = st.top().second;
                st.pop();
                int area = (j - idx) * h;
                best = max(best, area);
            }
            if (idx == -1) {
                st.push({j, height[i % 2][j]});
            } else {
                st.push({idx, height[i % 2][j]});
            }
        }
    }

    fout << best << endl;

  for (int i = 0; i < 2; ++i) {
    //    delete[] field[i];
    delete[] height[i];
  }
  //  delete [] field;
  delete [] height;

    return 0;
}
