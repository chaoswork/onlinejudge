#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("censor.in");
ofstream fout("censor.out");

const int INF = 100000000;

string S, T;

void readInput() {
    fin >> S >> T;
}



void kmpGetNext(int b[], string p)
{
    int i=0, j=-1;
    b[i]=j;
    while (i < int(p.size()))
    {
        while (j>=0 && p[i]!=p[j]) j=b[j];
        i++; j++;
        b[i]=j;
    }
}

int kmpSearch(int b[], string t, string p)
{
    int i=0, j=0;
    while (i < int(t.size()))
    {
        while (j>=0 && t[i]!=p[j]) j=b[j];
        i++; j++;
        if (j == int(p.size()))
        {
          return i-j;
          j=b[j];
        }
    }
    return -1;
}

int main() {
    readInput();
    string ans;
      int b[128];
      memset(b, 0, sizeof(b));
      kmpGetNext(b, T);    
    while (true) {
        // size_t idx = S.find(T[0]);
        // if (idx != string::npos) {
        //   ans += S.substr(0, idx);
        //   S.erase(0, idx);
        // }
      //size_t idx = S.find(T);

      int idx = kmpSearch(b, S, T);

        bool found = false;
        //        if (idx != string::npos) {
        if (idx != -1) {
          //S.erase(idx, T.length());
          size_t idx_start = idx;
          size_t idx_end = idx + T.length();
          while (true){
            //            cout<< idx_start << " " << idx_end <<endl;
            size_t start = idx_start;
            for(start = idx_start - 1; start > max(0, int(idx_start - T.length())); --start) {
                if (S[start] == T[0]){
                  found = true;
                  break;
                }
              }
              if (found){
                string s = S.substr(start, idx_start - start) + S.substr(idx_end, T.length() - (idx_start - start));
                // cout << s << endl;
                if (s == T){
                  idx_end = idx_end + T.length() - (idx_start - start);
                  idx_start = start;
                }
                else{
                  break;
                }
                
              } else {
                break;
              }
              

          }
          S.erase(idx_start, idx_end - idx_start);
        } else {
            break;
        }
        
    }
    fout << ans  << S << "\n";

    fin.close();
    fout.close();

    return 0;
}
