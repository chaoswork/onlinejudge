#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("censor.in");
ofstream fout("censor.out");

const int INF = 100000000;

string S, T;

int nextp[100010];
int prevp[100010];


void readInput() {
    fin >> S >> T;
    S = "#" + S;
    for (int i = 0; i < 100008; ++i){
      nextp[i] = i + 1;
      prevp[i + 1] = i;
    }
    
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

pair<int, int> kmpSearch(int b[], string t, string p)
{
    int i=0, j=0;
    while (i < int(t.size()))
    {
        while (j>=0 && t[i]!=p[j]) j=b[j];
        //i++;
        i = nextp[i];
        j++;
        if (j == int(p.size()))
        {
          int end = i;
          int ans = i;
          while (j){
            ans = prevp[ans];
            --j;
          }
          return make_pair(ans, end);
          j=b[j];
        }
    }
    return make_pair(-1, -1);
}

int main() {
    readInput();

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

      pair<int, int> ans = kmpSearch(b, S, T);
      int start = ans.first;
      int end = ans.second;

      //        bool found = false;
      //        if (idx != string::npos) {
        if (start != -1) {
          // S.erase(idx, T.length());
          // 01234
          //          cout << start << " " << end << endl;
          nextp[start - 1] = end;
          prevp[end] = start - 1;
//          for (int i = 0; i < int(S.size()); ++i){
//            cout << "nextp " << prevp[i] << "<-" << i << "->" << nextp[i] << " " << S[i] <<endl;
//          }

          // begin to look forward and back
          // size_t idx_start = idx;
          // size_t idx_end = idx + T.length();
          // while (true){
          //   //            cout<< idx_start << " " << idx_end <<endl;
          //   size_t start = idx_start;
          //   for(start = idx_start - 1; start > max(0, int(idx_start - T.length())); --start) {
          //       if (S[start] == T[0]){
          //         found = true;
          //         break;
          //       }
          //     }
          //     if (found){
          //       string s = S.substr(start, idx_start - start) + S.substr(idx_end, T.length() - (idx_start - start));
          //       // cout << s << endl;
          //       if (s == T){
          //         idx_end = idx_end + T.length() - (idx_start - start);
          //         idx_start = start;
          //       }
          //       else{
          //         break;
          //       }
          //       
          //     } else {
          //       break;
          //     }
          //     
          // 
          // }
          // S.erase(idx_start, idx_end - idx_start);
          // end of looking forward and back
          
        } else {
            break;
        }
        
    }
    int p = nextp[0];
    while (p < int(S.length())){
      fout << S[p];
      p = nextp[p];
    }
    fout << "\n";
    
    
    //fout << ans  << S << "\n";

    fin.close();
    fout.close();

    return 0;
}
