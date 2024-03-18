/*
ID: huangch7
LANG: C++
TASK: cryptcow
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;

ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");

const string target = "Begin the Escape execution at the Break of Dawn";
int found = 0;
int n_crypt = 0;

const int MODU = 199991;  // 999991 can pass, 1999991 can't, 199991 can, probability
int hash_t[MODU];


unsigned int ELFhash(const char *str)
{
    unsigned int h = 0, g;
    while (*str)
    {
        h = (h << 4) + (*str++);
        if (g = h & 0xf0000000l)
        {
            h ^= g >> 24;
        }
        h &= ~g;
    }
    return h % MODU;
}


void decrypt(string s, int n) {


  unsigned int h = ELFhash(s.c_str());
  if (hash_t[h]) return;
    hash_t[h] = 1;    
    if (found) {
        return;
    }
    if (s.size() == target.size()) {
        if (s == target) {
            found = 1;
            n_crypt = n;
        }
        return;
    }
    if (s.size() < target.size()) {
        return;
    }

    size_t prefix = 0;
    while (prefix < s.size()){
      if (s[prefix] == 'O') return;
      if (s[prefix] == 'W') return;
      if (s[prefix] == 'C') break;
      ++prefix;
    }
    if (prefix == s.size() and s != target) return;
    if (prefix > 0 and s.substr(0, prefix) != target.substr(0, prefix)) return;

    int suffix = s.size() - 1;
    while (suffix >= 0){
      if (s[suffix] == 'C') return;
      if (s[suffix] == 'O') return;
      if (s[suffix] == 'W') break;
      --suffix;
    }
    if (suffix == -1 and s != target) return;
    if (s.substr(suffix + 1, s.size() - suffix - 1) != target.substr(target.size() - s.size() + suffix + 1, s.size() - suffix - 1)) return;

    int p = prefix;
    int q = p;
    p += 1;
    while (p < suffix){
      if (s[p] == 'C' or s[p] == 'O' or s[p] == 'W'){
        string cur = s.substr(q + 1, p - q - 1);
        if (cur.size() and target.find(cur) == string::npos) return;
        q = p;
      }
      ++p;
    }
    //    cout << s << " " << n << endl;    

    for (int j = prefix + 1; j < suffix; ++j) {
        if (s[j] != 'O') {
            continue;
        }
        for (int i = prefix; i < j; ++i) {
            if (s[i] != 'C') {
                continue;
            }
            //            for (int k = j + 1; k <= suffix; ++k) {
            for (int k = suffix; k > j; --k) {
                if (s[k] != 'W') {
                    continue;
                }
                decrypt(s.substr(0, i) + s.substr(j + 1, k - j - 1) + s.substr(i + 1, j - i - 1) + s.substr(k + 1), n + 1);
            }
        }
    }
    /*
    for (int i = prefix; i < s.size(); ++i) {
        if (s[i] != 'C') {
            continue;
        }
        for (int j = i + 1; j < suffix; ++j) {
            if (s[j] != 'O') {
                continue;
            }
            //            for (int k = j + 1; k <= suffix; ++k) {
            for (int k = suffix; k > j; --k) {
                if (s[k] != 'W') {
                    continue;
                }
                decrypt(s.substr(0, i) + s.substr(j + 1, k - j - 1) + s.substr(i + 1, j - i - 1) + s.substr(k + 1), n + 1);
            }
        }
    }*/
}

int main() {
  memset(hash_t, 0, sizeof(hash_t));
    string source;
    getline(fin, source);
    bool match = true;
    if (count(source.begin(), source.end(), 'C') != count(source.begin(), source.end(), 'O')){
      match = false;
    }
    if (count(source.begin(), source.end(), 'C') != count(source.begin(), source.end(), 'W')){
      match = false;
    }
    if (match){
      decrypt(source, 0);
    }

    fout << found << " " << n_crypt << endl;

    return 0;
}
