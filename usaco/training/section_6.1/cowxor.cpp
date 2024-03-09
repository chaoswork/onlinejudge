/*
ID: huangch7
LANG: C++
TASK: cowxor
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

const int INF = 100000000;

vector<int> get_list_from_line(istream &fin) {
    string line;
    getline(fin, line);
    vector<int> result;
    int num;
    istringstream iss(line);
    while (iss >> num) {
        result.push_back(num);
    }
    return result;
}

typedef struct node{
  node *left;
  node *right;
  int pos;
  node(): left(0), right(0), pos(-1){}
} node;

void add_to_node(int x, int pos, node *root){
  node *p = root;
  int xbin[24];
  memset(xbin, 0, sizeof(xbin));
  int i = 23;
  while (x) {
    xbin[i] = x % 2;
    x = x / 2;
    --i;
  }
  for (int i = 0; i < 24; ++i){
    if (xbin[i] == 0) {
      if (p->left == 0) {p->left = new node();}
      p = p->left;
    } else {
      if (p->right == 0) {p->right = new node();}
      p = p->right;
    }
  }
  p->pos = pos;
}
int find_best(int x, node * root){
  node *p = root;
  int xbin[24];
  memset(xbin, 0, sizeof(xbin));
  int i = 23;
  while (x) {
    xbin[i] = x % 2;
    x = x / 2;
    --i;
  }
  for (int i = 0; i < 24; ++i){
    if (xbin[i] == 0) {
      if (p->right) {p = p->right;}
      else{p = p->left;}
    } else {
      if (p->left) {p = p->left;}
      else {p = p->right;}
    }
  }
  return p->pos;
}

int main() {
    ifstream fin("cowxor.in");
    ofstream fout("cowxor.out");

    int N;
    fin >> N;
    fin.ignore(); // Ignore the newline character

    vector<int> xor_res(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        vector<int> x = get_list_from_line(fin);
        xor_res[i] = xor_res[i - 1] ^ x[0];
    }

    int best = -1;
    int best_s = -1;
    int best_e = -1;
    node root = node();
    add_to_node(0, 0, &root);
    for (int i = 1; i <= N; ++i){
      int j = find_best(xor_res[i], &root);
      //      cout << j << endl;
      int cur = xor_res[i] ^ xor_res[j];
      if (best < cur) {
        best = cur;
        best_s = j;
        best_e = i;
      }else if(best == cur){
        if (i == best_e && i - j < best_e - best_s){
          best_s = j;
          best_e = i;
        }
      }
      add_to_node(xor_res[i], i, &root);
        
      
    }
    
    /*
    for (int i = 0; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            int res = xor_res[i] ^ xor_res[j];
            if (res == best) {
                if (j - i - 1 < best_e - best_s) {
                    best_s = i + 1;
                    best_e = j;
                }
            } else if (res > best) {
                best = res;
                best_s = i + 1;
                best_e = j;
            }
        }
    }
    */
    fout << best << " " << best_s + 1 << " " << best_e << endl;

    fin.close();
    fout.close();

    return 0;
}
