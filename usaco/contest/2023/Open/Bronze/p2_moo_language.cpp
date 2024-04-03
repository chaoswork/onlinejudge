#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
  int T, N, C, P;
  cin >> T;
  while (T--){
    cin >> N >> C >> P;
    vector<string> nouns, conns, tv, itv;
    int best = 0;
    string best_str = "";
    
    while (N--){
      string word, tp;
      cin >> word >> tp;
      if (tp == "conjunction") conns.push_back(word);
      else if (tp == "noun") nouns.push_back(word);
      else if (tp == "transitive-verb") tv.push_back(word);
      else itv.push_back(word);
    }
    for (int t1 = 0; t1 <= itv.size(); ++t1){
      for (int t2 = 0; t2 <= tv.size(); ++t2){
        if (t1 + 2 * t2 > nouns.size()) continue;
        int cur_words = 2 * t1 + 3 * t2;

        int nc = min( (t1 + t2) / 2, int(conns.size()));
        cur_words += nc;

        if (t1 + t2 - nc > P) continue;
        int nco = 0;
        if (t2) nco = min(C, int(nouns.size()) - t1 - 2 * t2);
        cur_words += nco;

        if (best < cur_words){
          best = cur_words;
          
          vector<string> s;
          for (int i = 0; i < t1; ++i) s.push_back(nouns[i] + " " + itv[i]);
          for (int i = 0; i < t2; ++i) s.push_back(nouns[t1 + 2 * i] + " " + tv[i] + " " + nouns[t1 + 2 * i + 1]);

          if (t2) {
            vector<string> sc;            
            for (int i = t1 + t2 * 2; i < min(int(nouns.size()), t1 + t2 * 2 + nco); ++i) sc.push_back(", " + nouns[i]);
            for (int i = 0; i < sc.size(); ++i) s[s.size() - 1] += sc[i];
          }

          vector<string> lines;
          for (int i = 0; i < nc; ++i) lines.push_back(s[i * 2] + " " + conns[i] + " " + s[i * 2 + 1] + ".");
          for (int i = 2 * nc; i < s.size(); ++i) lines.push_back(s[i] + ".");
                    
          string ans = "";
          for (int i = 0; i < lines.size(); ++i){
            if (i) ans += " ";
            ans += lines[i];
          }
          best_str = ans;
          
                                         
        }
          
          
      }
    }
    cout << best << endl;
    cout << best_str << endl;
  }
}
