#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int INF = 100000000;

int word_base[26];
unordered_map<int, vector<string> > ldict;
vector<string> words;
unordered_map<char, int> score = {
    {'q', 7}, {'w', 6}, {'e', 1}, {'r', 2}, {'t', 2}, {'y', 5}, {'u', 4}, {'i', 1}, {'o', 3}, {'p', 5},
    {'a', 2}, {'s', 1}, {'d', 4}, {'f', 6}, {'g', 5}, {'h', 5}, {'j', 7}, {'k', 6}, {'l', 3},
    {'z', 7}, {'x', 7}, {'c', 4}, {'v', 6}, {'b', 5}, {'n', 2}, {'m', 5}
};

int get_index(string word) {
    int res = 0x755782FF;
    string str = word;
    sort(str.begin(), str.end());
    for (char ch : str) {
      res += (ch - 'a' + 1) + 53473 * res;
      res = res % 200000001;
    }
    return res;
}

int main() {
    ifstream fin("lgame.in");
    ifstream fdict("lgame.dict");
    ofstream fout("lgame.out");

    string inputs;
    fin >> inputs;

    string word;
    while (true) {
        fdict >> word;
        if (word == "." || word == "") {
            break;
        }
        ldict[get_index(word)].push_back(word);
        words.push_back(word);
    }
    for (int i = 0; i < int(words.size()); ++i){
      for (int j = i; j < int(words.size()); ++j){
        if (words[i].size() + words[j].size() != inputs.size()){
          continue;
        }
        string value = words[i] + " " + words[j];
        if (words[i] > words[j]) {
          value = words[j] + " " + words[i];
        }
        ldict[get_index(words[i] + words[j])].push_back(value);
      }
    }

    int best = 0;
    for (char x : inputs) {
        best += score[x];
    }
    cout<<"debug "<<get_index(inputs)<<endl;
    cout<<"debug "<<get_index("program")<<endl;
    
    vector<string> result = ldict[get_index(inputs)];

    fout << best << endl;
    sort(result.begin(), result.end());
    for (string word : result) {
        fout << word << endl;
    }

    fin.close();
    fdict.close();
    fout.close();
    return 0;
}
